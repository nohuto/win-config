#include <windows.h>
#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <thread>
#include <vector>

namespace {
constexpr UINT GET_DELAY = 0x6a, SET_DELAY = 0x6b;
constexpr wchar_t KEY[] = L"Control Panel\\Desktop", NAME[] = L"MenuShowDelay";
struct Ticks { std::atomic<long long> input{0}, opened{0}; };
Ticks ticks;
HWND owner;
HMENU root, child;
HANDLE rootReady, childReady;
RECT target{};
std::atomic<bool> armed{false};
LARGE_INTEGER frequency;

long long now() { LARGE_INTEGER t; QueryPerformanceCounter(&t); return t.QuadPart; }
double ms(long long begin) {
    return begin ? 1000.0 * (ticks.opened.load() - begin) / frequency.QuadPart : -1.0;
}
void stamp(POINT p) {
    if (!armed || !PtInRect(&target, p)) return;
    long long zero = 0;
    ticks.input.compare_exchange_strong(zero, now());
}
LRESULT CALLBACK filterHook(int code, WPARAM wp, LPARAM lp) {
    if (code == MSGF_MENU && lp) {
        auto msg = reinterpret_cast<MSG*>(lp);
        if (msg->message == WM_MOUSEMOVE) stamp(msg->pt);
    }
    return CallNextHookEx(nullptr, code, wp, lp);
}
LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_INITMENUPOPUP) {
        if (reinterpret_cast<HMENU>(wp) == root) SetEvent(rootReady);
        if (reinterpret_cast<HMENU>(wp) == child) {
            ticks.opened = now();
            SetEvent(childReady);
        }
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}
bool getSpi(DWORD& value) { return SystemParametersInfoW(GET_DELAY, 0, &value, 0) != 0; }
bool setSpi(DWORD value) { return SystemParametersInfoW(SET_DELAY, value, nullptr, 0) != 0; }
bool parseNumber(const wchar_t* text, DWORD& out) {
    if (!text || !*text || *text == L'-') return false;
    wchar_t* end;
    unsigned long n = wcstoul(text, &end, 10);
    if (*end || n > 60000) return false;
    out = n;
    return true;
}
struct Settings {
    HKEY key{};
    std::vector<BYTE> original;
    DWORD type{}, oldSpi{};
    bool changedSpi = false;
    ~Settings() {
        if (changedSpi && !setSpi(oldSpi)) fwprintf(stderr, L"warning: failed to restore SPI\n");
        if (key) RegCloseKey(key);
    }
    bool open(bool needRegistry) {
        if (!getSpi(oldSpi)) return false;
        if (!needRegistry) return true;
        if (RegOpenKeyExW(HKEY_CURRENT_USER, KEY, 0, KEY_QUERY_VALUE, &key)) return false;
        DWORD size = 0;
        if (RegQueryValueExW(key, NAME, nullptr, &type, nullptr, &size) ||
            type != REG_SZ || size < sizeof(wchar_t) || size % sizeof(wchar_t)) return false;
        original.resize(size);
        return RegQueryValueExW(key, NAME, nullptr, &type, original.data(), &size) == ERROR_SUCCESS;
    }
    bool registryDelay(DWORD& value) const {
        auto text = reinterpret_cast<const wchar_t*>(original.data());
        if (reinterpret_cast<const wchar_t*>(original.data() + original.size())[-1] != 0) return false;
        return parseNumber(text, value);
    }
    bool apply(DWORD value) {
        if (!setSpi(value)) return false;
        changedSpi = true;
        DWORD check = 0;
        return getSpi(check) && check == value;
    }
};

// The menu must be measured in a fresh process. Repeat TrackPopupMenuEx calls can
// disappear immediately on this machine despite a foreground owner and WM_NULL.
int childRun(DWORD delay) {
    QueryPerformanceFrequency(&frequency);
    DWORD live = 0;
    if (!getSpi(live) || live != delay) return 2;
    SetCursorPos(50, 50);
    Sleep(25);
    rootReady = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    childReady = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    WNDCLASSW wc{};
    wc.lpfnWndProc = wndProc;
    wc.lpszClassName = L"MenuDelayProbe";
    if (!RegisterClassW(&wc)) return 2;
    owner = CreateWindowExW(0, wc.lpszClassName, L"Menu delay probe", WS_OVERLAPPEDWINDOW,
                            100, 100, 180, 90, nullptr, nullptr, nullptr, nullptr);
    if (!owner) return 2;
    ShowWindow(owner, SW_SHOW);
    child = CreatePopupMenu(); root = CreatePopupMenu();
    if (!child || !root || !AppendMenuW(child, MF_STRING, 101, L"Child") ||
        !AppendMenuW(root, MF_POPUP, reinterpret_cast<UINT_PTR>(child), L"Hover here")) return 2;
    HHOOK hook = SetWindowsHookExW(WH_MSGFILTER, filterHook, nullptr, GetCurrentThreadId());
    if (!hook) return 2;
    std::atomic<bool> openedInTime{false};
    std::thread worker([delay, &openedInTime] {
        if (WaitForSingleObject(rootReady, 3000) == WAIT_OBJECT_0) {
            Sleep(75); // WM_INITMENUPOPUP occurs before the menu is visible.
            if (GetMenuItemRect(owner, root, 0, &target)) {
                armed = true;
                SetCursorPos((target.left + target.right) / 2, (target.top + target.bottom) / 2);
                openedInTime = WaitForSingleObject(childReady, std::max<DWORD>(1000, delay + 1000)) == WAIT_OBJECT_0;
            }
        }
        PostMessageW(owner, WM_CANCELMODE, 0, 0);
    });
    SetForegroundWindow(owner);
    TrackPopupMenuEx(root, TPM_NOANIMATION, 300, 300, owner, nullptr);
    PostMessageW(owner, WM_NULL, 0, 0);
    worker.join();
    UnhookWindowsHookEx(hook);
    DestroyMenu(root);
    DestroyWindow(owner);
    CloseHandle(rootReady); CloseHandle(childReady);
    if (!openedInTime || !ticks.opened || !ticks.input) return 2;
    printf("%.4f\n", ms(ticks.input));
    return 0;
}

bool runChild(const std::wstring& exe, DWORD delay, double& result) {
    SECURITY_ATTRIBUTES sa{sizeof(sa), nullptr, TRUE};
    HANDLE read{}, write{};
    if (!CreatePipe(&read, &write, &sa, 0)) return false;
    SetHandleInformation(read, HANDLE_FLAG_INHERIT, 0);
    STARTUPINFOW si{sizeof(si)};
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdOutput = write;
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    PROCESS_INFORMATION pi{};
    std::wstring command = L"\"" + exe + L"\" --child " + std::to_wstring(delay);
    BOOL started = CreateProcessW(exe.c_str(), command.data(), nullptr, nullptr, TRUE,
                                  CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi);
    CloseHandle(write);
    if (!started) { CloseHandle(read); return false; }
    if (WaitForSingleObject(pi.hProcess, std::max<DWORD>(5000, delay + 5000)) == WAIT_TIMEOUT) {
        TerminateProcess(pi.hProcess, 3);
        WaitForSingleObject(pi.hProcess, 1000);
    }
    std::string output;
    char buffer[128]; DWORD count;
    while (ReadFile(read, buffer, sizeof(buffer), &count, nullptr) && count) output.append(buffer, count);
    CloseHandle(read);
    DWORD exit = 1;
    GetExitCodeProcess(pi.hProcess, &exit);
    CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
    return exit == 0 && sscanf_s(output.c_str(), "%lf", &result) == 1;
}
double average(const std::vector<double>& values) {
    double sum = 0;
    for (double value : values) sum += value;
    return sum / values.size();
}
}

int wmain(int argc, wchar_t** argv) {
    if (argc == 3 && wcscmp(argv[1], L"--child") == 0) {
        DWORD delay;
        return parseNumber(argv[2], delay) ? childRun(delay) : 2;
    }
    DWORD tries = 10, delay = 0;
    bool hasDelay = false;
    for (int i = 1; i < argc; ++i) {
        if ((!wcscmp(argv[i], L"--tries") || !wcscmp(argv[i], L"--delay")) && i + 1 < argc) {
            bool isTries = !wcscmp(argv[i], L"--tries");
            DWORD n;
            if (!parseNumber(argv[++i], n) || (isTries && (n < 1 || n > 1000))) goto usage;
            if (isTries) tries = n;
            else { delay = n; hasDelay = true; }
        } else goto usage;
    }
    {
        struct Cursor { POINT old; Cursor() { GetCursorPos(&old); }
                        ~Cursor() { SetCursorPos(old.x, old.y); } } cursor;
        Settings setting;
        if (!setting.open(!hasDelay)) { fwprintf(stderr, L"cannot read MenuShowDelay\n"); return 1; }
        if (!hasDelay && !setting.registryDelay(delay)) {
            fwprintf(stderr, L"invalid MenuShowDelay\n"); return 1;
        }
        if (!setting.apply(delay)) {
            fwprintf(stderr, L"cannot apply MenuShowDelay\n"); return 1;
        }
        wchar_t path[MAX_PATH];
        if (!GetModuleFileNameW(nullptr, path, MAX_PATH)) return 1;
        std::vector<double> times;
        DWORD attempts = 0;
        while (times.size() < tries && attempts < tries + 10) {
            ++attempts;
            double value;
            if (runChild(path, delay, value)) times.push_back(value);
        }
        printf("delay=%lums source=%s tries=%zu/%lu avg=%.2fms",
               delay, hasDelay ? "arg" : "reg", times.size(), tries,
               times.empty() ? -1.0 : average(times));
        if (attempts > times.size()) printf(" skipped=%zu", attempts - times.size());
        putchar('\n');
        return times.size() == tries ? 0 : 1;
    }
usage:
    fwprintf(stderr, L"usage: msd_test [--tries 1-1000] [--delay 0-60000]\n");
    return 2;
}
