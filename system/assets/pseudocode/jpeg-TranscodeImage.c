__int64 __fastcall TranscodeImage(
  struct IShellItem *a1,
  __int64 a2,
  struct IStream *a3,
  unsigned int *a4,
  unsigned int *a5,
  bool a6,
  float *a7)
{
float *v8; // r15
HRESULT Instance; // edi
bool v10; // r13
char v11; // si
unsigned int v12; // r14d
int v13; // r12d
IWICBitmapSource *v14; // rbx
__int64 v15; // rcx
float v17; // xmm1_4
unsigned int v18; // ecx
unsigned int v19; // eax
int v20; // ecx
unsigned int v21; // eax
int v22; // edx
double v23; // xmm2_8
double v24; // xmm1_8
unsigned int v25; // eax
int v26; // edx
HRESULT DefaultDevice; // esi
std::_Ref_count_base *v28; // r15
char v29; // si
GUID *v30; // rdx
LPVOID *ppv; // [rsp+28h] [rbp-E0h]
char v32; // [rsp+38h] [rbp-D0h]
bool v33; // [rsp+3Ch] [rbp-CCh]
_QWORD v36[3]; // [rsp+58h] [rbp-B0h] BYREF
__int128 v37; // [rsp+70h] [rbp-98h]
IWICBitmapSource *v38; // [rsp+80h] [rbp-88h] BYREF
unsigned int v39; // [rsp+88h] [rbp-80h] BYREF
struct IUnknown *v40; // [rsp+90h] [rbp-78h] BYREF
int v41; // [rsp+98h] [rbp-70h] BYREF
struct IUnknown *v42; // [rsp+A0h] [rbp-68h] BYREF
__int64 v43; // [rsp+A8h] [rbp-60h] BYREF
struct IWICImagingFactory *v44; // [rsp+B0h] [rbp-58h] BYREF
struct IWICBitmapSource *v45; // [rsp+B8h] [rbp-50h] BYREF
IWICBitmapSource *pISrc; // [rsp+C0h] [rbp-48h] BYREF
__int64 v47; // [rsp+C8h] [rbp-40h] BYREF
struct IWICBitmapDecoder *v48; // [rsp+D0h] [rbp-38h] BYREF
float v49; // [rsp+D8h] [rbp-30h] BYREF
__int64 v50; // [rsp+E0h] [rbp-28h] BYREF
IWICBitmapSource *ppIDst; // [rsp+E8h] [rbp-20h] BYREF
IWICBitmapSource *v52; // [rsp+F0h] [rbp-18h] BYREF
struct IWICBitmapFrameDecode *v53; // [rsp+F8h] [rbp-10h] BYREF
GUID v54; // [rsp+108h] [rbp+0h] BYREF
__int64 v55; // [rsp+118h] [rbp+10h] BYREF
struct IWICMetadataQueryReader *v56; // [rsp+120h] [rbp+18h] BYREF
struct _GUID v57; // [rsp+128h] [rbp+20h] BYREF
__int64 v58; // [rsp+138h] [rbp+30h] BYREF
__int64 v59; // [rsp+140h] [rbp+38h] BYREF
std::_Ref_count_base *v60[2]; // [rsp+148h] [rbp+40h] BYREF
__int64 v61; // [rsp+158h] [rbp+50h]
GUID dstFormat; // [rsp+168h] [rbp+60h] BYREF
__int128 v63; // [rsp+178h] [rbp+70h] BYREF
__int128 v64; // [rsp+188h] [rbp+80h] BYREF
wil::details::in1diag3 *retaddr; // [rsp+1F0h] [rbp+E8h]

v8 = a7;
*(_QWORD *)&v54.Data1 = a7;
v58 = 0LL;
v59 = 0LL;
v49 = 0.0;
if ( a4 )
*a4 = 0;
if ( a5 )
*a5 = 0;
if ( a7 )
*a7 = 0.0;
v44 = 0LL;
Instance = CoCreateInstance(
         &CLSID_WICImagingFactory2,
         0LL,
         1u,
         &GUID_ec5ec8a9_c395_4314_9c77_54d7a935ff70,
         (LPVOID *)&v44);
v10 = 0;
v45 = 0LL;
v53 = 0LL;
v48 = 0LL;
v63 = 0LL;
v11 = 0;
v32 = 0;
v33 = 0;
if ( Instance >= 0 )
{
v42 = 0LL;
ppv = (LPVOID *)&v42;
Instance = ((__int64 (__fastcall *)(struct IShellItem *, _QWORD, const GUID *, GUID *))a1->lpVtbl->BindToHandler)(
           a1,
           0LL,
           &BHID_Stream,
           &GUID_0000000c_0000_0000_c000_000000000046);
if ( Instance >= 0 )
{
ppv = (LPVOID *)&v48;
Instance = ((__int64 (__fastcall *)(struct IWICImagingFactory *, struct IUnknown *, _QWORD, _QWORD))v44->lpVtbl->CreateDecoderFromStream)(
             v44,
             v42,
             0LL,
             0LL);
if ( Instance >= 0 )
{
  if ( ((int (__fastcall *)(struct IWICBitmapDecoder *, __int128 *))v48->lpVtbl->GetContainerFormat)(v48, &v63) >= 0 )
    v10 = (unsigned __int8)_(&v63, &GUID_ContainerFormatPng) != 0;
  LODWORD(v40) = 0;
  Instance = ((__int64 (__fastcall *)(struct IWICBitmapDecoder *, struct IUnknown **))v48->lpVtbl->GetFrameCount)(
               v48,
               &v40);
  if ( Instance >= 0 )
  {
    if ( (_DWORD)v40 )
    {
      Instance = ((__int64 (__fastcall *)(struct IWICBitmapDecoder *, _QWORD, struct IWICBitmapFrameDecode **))v48->lpVtbl->GetFrame)(
                   v48,
                   0LL,
                   &v53);
      if ( Instance >= 0 )
      {
        Instance = ((__int64 (__fastcall *)(struct IWICBitmapFrameDecode *, GUID *, struct IWICBitmapSource **))v53->lpVtbl->QueryInterface)(
                     v53,
                     &GUID_00000120_a8f2_4877_ba0a_fd2b6645fb94,
                     &v45);
        if ( Instance >= 0 )
        {
          v57 = 0LL;
          if ( ((int (__fastcall *)(struct IWICBitmapSource *, struct _GUID *))v45->lpVtbl->GetPixelFormat)(
                 v45,
                 &v57) >= 0 )
            v33 = IsWICPixelFormatHDR(&v57);
          ((void (__fastcall *)(struct IWICBitmapSource *, __int64 *, __int64 *))v45->lpVtbl->GetResolution)(
            v45,
            &v58,
            &v59);
          v11 = 1;
          v32 = 1;
        }
      }
    }
    else
    {
      Instance = -2147418113;
    }
  }
}
}
if ( v42 )
((void (__fastcall *)(struct IUnknown *))v42->lpVtbl->Release)(v42);
}
if ( v45 )
{
if ( Instance >= 0 )
Instance = ValidateBitmapProportions(v45);
}
else if ( Instance >= 0 )
{
Instance = -2147418113;
}
v52 = 0LL;
v12 = -1;
v13 = -1;
v39 = 0;
v41 = 0;
if ( Instance >= 0 )
{
Instance = ((__int64 (__fastcall *)(struct IWICBitmapSource *, unsigned int *, int *))v45->lpVtbl->GetSize)(
           v45,
           &v39,
           &v41);
if ( Instance >= 0 )
{
LODWORD(v40) = 0;
LODWORD(v38) = 0;
if ( (int)SHRegGetDWORD(
            HKEY_CURRENT_USER,
            L"Control Panel\\Desktop",
            L"MaxVirtualDesktopDimension",
            (unsigned int *)&v40) < 0
  || (int)SHRegGetDWORD(
            HKEY_CURRENT_USER,
            L"Control Panel\\Desktop",
            L"MaxMonitorDimension",
            (unsigned int *)&v38) < 0 )
{
  v20 = v39;
  v13 = v41;
}
else
{
  v20 = v39;
  v13 = v41;
  v21 = (int)fmax(
               (double)(int)v38 * ((double)(int)v39 / (double)v41),
               (double)(int)v38 / ((double)(int)v39 / (double)v41));
  if ( (unsigned int)v40 > v21 )
    v21 = (unsigned int)v40;
  if ( v21 != -1 )
    v12 = v21;
}
v22 = v12;
if ( v20 > v12 || v13 > v12 )
{
  v24 = (double)v20;
  if ( v12 >= (int)((double)(int)v12 / (double)v13 * (double)v20) )
    v12 = (int)((double)(int)v12 / (double)v13 * (double)v20);
  v23 = (double)v13;
  v25 = (int)((double)v22 / v24 * (double)v13);
  v13 = v22;
  if ( v22 >= v25 )
    v13 = (int)((double)v22 / v24 * v23);
  if ( v12 <= 1 )
    v12 = 1;
  if ( (unsigned int)v13 <= 1 )
    v13 = 1;
  v42 = 0LL;
  Instance = ((__int64 (__fastcall *)(struct IWICImagingFactory *, struct IUnknown **))v44->lpVtbl->CreateBitmapScaler)(
               v44,
               &v42);
  if ( Instance >= 0 )
  {
    if ( (unsigned __int8)_(&v63, &GUID_ContainerFormatJpeg) || (v26 = 3, v39 / v12 < 2) )
      v26 = 1;
    LODWORD(ppv) = v26;
    Instance = ((__int64 (__fastcall *)(struct IUnknown *, struct IWICBitmapSource *, _QWORD, _QWORD))v42->lpVtbl[2].Release)(
                 v42,
                 v45,
                 v12,
                 (unsigned int)v13);
    if ( Instance >= 0 )
      Instance = ((__int64 (__fastcall *)(struct IUnknown *, GUID *, IWICBitmapSource **))v42->lpVtbl->QueryInterface)(
                   v42,
                   &GUID_00000120_a8f2_4877_ba0a_fd2b6645fb94,
                   &v52);
  }
  ATL::CComPtr<IUICommandWithBackgroundColor>::~CComPtr<IUICommandWithBackgroundColor>(&v42);
}
else
{
  v12 = v20;
  Instance = ((__int64 (__fastcall *)(struct IWICBitmapSource *, GUID *, IWICBitmapSource **))v45->lpVtbl->QueryInterface)(
               v45,
               &GUID_00000120_a8f2_4877_ba0a_fd2b6645fb94,
               &v52);
}
}
}
v14 = v52;
v42 = (struct IUnknown *)v52;
if ( v52 )
((void (__fastcall *)(IWICBitmapSource *))v52->lpVtbl->AddRef)(v52);
v56 = 0LL;
if ( Instance >= 0
&& WICIsOrientationSupported(v48)
&& ((int (__fastcall *)(struct IWICBitmapFrameDecode *, struct IWICMetadataQueryReader **))v53->lpVtbl->GetMetadataQueryReader)(
   v53,
   &v56) >= 0 )
{
ATL::AtlComPtrAssign(&v42, 0LL);
Instance = WICCreateCachedOrientedBitmapSource(v44, v52, v56, (struct IWICBitmapSource **)&v42);
v14 = (IWICBitmapSource *)v42;
if ( Instance >= 0 )
{
LODWORD(v40) = 0;
LODWORD(v38) = 0;
Instance = ((__int64 (__fastcall *)(struct IUnknown *, struct IUnknown **, IWICBitmapSource **))v42->lpVtbl[1].QueryInterface)(
             v42,
             &v40,
             &v38);
if ( Instance >= 0 )
{
  v18 = v39;
  if ( (unsigned int)v40 >= (unsigned int)v38 )
  {
    if ( v39 <= v41 )
    {
LABEL_83:
      v39 = v41;
      v41 = v18;
      v19 = v12;
      v12 = v13;
      v13 = v19;
      goto LABEL_15;
    }
    if ( (unsigned int)v40 > (unsigned int)v38 )
      goto LABEL_15;
  }
  if ( v39 < v41 )
    goto LABEL_15;
  goto LABEL_83;
}
}
}
LABEL_15:
pISrc = v14;
if ( v14 )
((void (__fastcall *)(IWICBitmapSource *))v14->lpVtbl->AddRef)(v14);
if ( Instance < 0 || !v11 )
goto LABEL_18;
if ( !v33 )
{
LABEL_86:
ATL::AtlComPtrAssign((struct IUnknown **)&pISrc, 0LL);
Instance = ColorCorrectImageWithWIC(v44, v53, v14, &pISrc);
goto LABEL_18;
}
DefaultDevice = -2147467259;
CWallpaperRenderer::s_GetSharedComposition(v60);
v28 = v60[0];
if ( v60[0] )
{
v64 = 0LL;
DefaultDevice = ((__int64 (__fastcall *)(IWICBitmapSource *, __int128 *))v14->lpVtbl->GetPixelFormat)(v14, &v64);
if ( DefaultDevice >= 0 )
{
v38 = 0LL;
if ( (unsigned __int8)_(&v64, &GUID_WICPixelFormat64bppRGBAHalf) )
{
  ATL::AtlComPtrAssign((struct IUnknown **)&v38, (struct IUnknown *)v14);
}
else
{
  DefaultDevice = WICConvertBitmapSource(&GUID_WICPixelFormat64bppRGBAHalf, v14, &v38);
  if ( DefaultDevice < 0 )
  {
LABEL_152:
    ATL::CComPtr<IUICommandWithBackgroundColor>::~CComPtr<IUICommandWithBackgroundColor>(&v38);
    goto LABEL_153;
  }
}
v57 = 0LL;
DefaultDevice = Composition::GetDefaultDevice(v28, &v57);
if ( DefaultDevice >= 0 )
{
  v40 = 0LL;
  DefaultDevice = HDRToneMap(
                    (unsigned int)&v57,
                    (_DWORD)v44,
                    (unsigned int)&v49,
                    (_DWORD)v38,
                    FLOAT_80_0,
                    (__int64)&v40);
  if ( DefaultDevice >= 0 )
    ATL::AtlComPtrAssign((struct IUnknown **)&pISrc, v40);
  ATL::CComPtr<IUICommandWithBackgroundColor>::~CComPtr<IUICommandWithBackgroundColor>(&v40);
}
if ( *(_QWORD *)v57.Data4 )
  std::_Ref_count_base::_Decref(*(std::_Ref_count_base **)v57.Data4);
goto LABEL_152;
}
}
LABEL_153:
if ( DefaultDevice >= 0 )
{
v29 = 0;
}
else
{
wil::details::in1diag3::_Log_Hr(
retaddr,
(void *)0x282,
(unsigned int)"shell\\shell32\\unicpp\\transcode.cpp",
(const char *)(unsigned int)DefaultDevice,
(int)ppv);
v29 = v32;
}
if ( v60[1] )
std::_Ref_count_base::_Decref(v60[1]);
v8 = *(float **)&v54.Data1;
if ( v29 )
goto LABEL_86;
LABEL_18:
ppIDst = pISrc;
if ( pISrc )
((void (__fastcall *)(IWICBitmapSource *))pISrc->lpVtbl->AddRef)(pISrc);
dstFormat = GUID_WICPixelFormat24bppRGB;
if ( Instance >= 0 )
{
v54 = 0LL;
Instance = ((__int64 (__fastcall *)(IWICBitmapSource *, GUID *))pISrc->lpVtbl->GetPixelFormat)(pISrc, &v54);
if ( Instance >= 0 )
{
if ( v10
  || (unsigned __int8)_(&v54, &GUID_WICPixelFormat8bppGray)
  || (unsigned __int8)_(&v54, &GUID_WICPixelFormat24bppRGB) )
{
  dstFormat = v54;
}
else
{
  if ( (unsigned __int8)_(&v54, &GUID_WICPixelFormatBlackWhite)
    || (unsigned __int8)_(&v54, &GUID_WICPixelFormat2bppGray)
    || (unsigned __int8)_(&v54, &GUID_WICPixelFormat4bppGray) )
  {
    dstFormat = GUID_WICPixelFormat8bppGray;
  }
  if ( ppIDst )
    ((void (__fastcall *)(IWICBitmapSource *))ppIDst->lpVtbl->Release)(ppIDst);
  ppIDst = 0LL;
  Instance = WICConvertBitmapSource(&dstFormat, pISrc, &ppIDst);
}
}
}
v55 = 0LL;
if ( Instance >= 0 )
{
Instance = ((__int64 (__fastcall *)(struct IWICImagingFactory *, __int64 *))v44->lpVtbl->CreateStream)(v44, &v55);
if ( Instance >= 0 )
Instance = (*(__int64 (__fastcall **)(__int64, struct IStream *))(*(_QWORD *)v55 + 112LL))(v55, a3);
}
v50 = 0LL;
if ( Instance >= 0 )
{
v30 = &GUID_ContainerFormatPng;
if ( !v10 )
v30 = &GUID_ContainerFormatJpeg;
Instance = ((__int64 (__fastcall *)(struct IWICImagingFactory *, GUID *, GUID *, __int64 *))v44->lpVtbl->CreateEncoder)(
           v44,
           v30,
           &GUID_VendorMicrosoft,
           &v50);
if ( Instance >= 0 )
Instance = (*(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v50 + 24LL))(v50, v55, 2LL);
}
v43 = 0LL;
v15 = 0LL;
v47 = 0LL;
if ( Instance >= 0 )
{
Instance = (*(__int64 (__fastcall **)(__int64, __int64 *, __int64 *))(*(_QWORD *)v50 + 80LL))(v50, &v43, &v47);
if ( Instance >= 0 )
{
if ( v10 )
  goto LABEL_64;
v17 = *(float *)&dword_1806A5BA8;
if ( *(float *)&dword_1806A5BA8 == 0.0 )
{
  LODWORD(v38) = 0;
  if ( (int)SHRegGetDWORD(
              HKEY_CURRENT_USER,
              L"Control Panel\\Desktop",
              L"JPEGImportQuality",
              (unsigned int *)&v38) < 0 )
  {
    v17 = FLOAT_85_0;
  }
  else
  {
    v17 = fmaxf((float)(int)v38, 60.0);
    if ( v17 > 100.0 )
      v17 = FLOAT_100_0;
  }
  dword_1806A5BA8 = LODWORD(v17);
}
v36[0] = 0LL;
v36[1] = 0LL;
v37 = 0LL;
v36[2] = L"ImageQuality";
*(_OWORD *)v60 = 0LL;
v61 = 0LL;
LOWORD(v60[0]) = 4;
*(float *)&v60[1] = v17 / 100.0;
Instance = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD *, std::_Ref_count_base **))(*(_QWORD *)v47 + 32LL))(
             v47,
             1LL,
             v36,
             v60);
if ( Instance >= 0 )
{
LABEL_64:
  Instance = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v43 + 24LL))(v43, v47);
  if ( Instance >= 0 )
  {
    Instance = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v43 + 40LL))(v43);
    if ( Instance >= 0 )
    {
      Instance = (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v43 + 32LL))(
                   v43,
                   v12,
                   (unsigned int)v13);
      if ( Instance >= 0 )
      {
        (*(void (__fastcall **)(__int64, GUID *))(*(_QWORD *)v43 + 48LL))(v43, &dstFormat);
        if ( !v10 )
        {
          v38 = 0LL;
          if ( ((int (__fastcall *)(struct IWICImagingFactory *, IWICBitmapSource **))v44->lpVtbl->CreateColorContext)(
                 v44,
                 &v38) >= 0
            && ((int (__fastcall *)(IWICBitmapSource *, __int64))v38->lpVtbl->GetResolution)(v38, 1LL) >= 0 )
          {
            (*(void (__fastcall **)(__int64, __int64, IWICBitmapSource **))(*(_QWORD *)v43 + 56LL))(
              v43,
              1LL,
              &v38);
          }
          if ( v38 )
            ((void (__fastcall *)(IWICBitmapSource *))v38->lpVtbl->Release)(v38);
        }
        Instance = (*(__int64 (__fastcall **)(__int64, IWICBitmapSource *, _QWORD))(*(_QWORD *)v43 + 88LL))(
                     v43,
                     ppIDst,
                     0LL);
        if ( Instance >= 0 )
        {
          Instance = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v43 + 96LL))(v43);
          if ( Instance >= 0 )
          {
            Instance = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v50 + 88LL))(v50);
            if ( Instance >= 0 )
            {
              if ( a4 )
                *a4 = v39;
              if ( a5 )
                *a5 = v41;
              if ( v8 )
              {
                if ( v33 && v49 > 0.0 )
                  *v8 = v49;
                else
                  *v8 = 80.0;
              }
            }
          }
        }
      }
    }
  }
}
}
v15 = v47;
}
if ( v15 )
(*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16LL))(v15);
if ( v43 )
(*(void (__fastcall **)(__int64))(*(_QWORD *)v43 + 16LL))(v43);
if ( v50 )
(*(void (__fastcall **)(__int64))(*(_QWORD *)v50 + 16LL))(v50);
if ( v55 )
(*(void (__fastcall **)(__int64))(*(_QWORD *)v55 + 16LL))(v55);
if ( ppIDst )
((void (__fastcall *)(IWICBitmapSource *))ppIDst->lpVtbl->Release)(ppIDst);
if ( pISrc )
((void (__fastcall *)(IWICBitmapSource *))pISrc->lpVtbl->Release)(pISrc);
if ( v56 )
((void (__fastcall *)(struct IWICMetadataQueryReader *))v56->lpVtbl->Release)(v56);
if ( v14 )
((void (__fastcall *)(IWICBitmapSource *))v14->lpVtbl->Release)(v14);
if ( v52 )
((void (__fastcall *)(IWICBitmapSource *))v52->lpVtbl->Release)(v52);
if ( v48 )
((void (__fastcall *)(struct IWICBitmapDecoder *))v48->lpVtbl->Release)(v48);
if ( v53 )
((void (__fastcall *)(struct IWICBitmapFrameDecode *))v53->lpVtbl->Release)(v53);
if ( v45 )
((void (__fastcall *)(struct IWICBitmapSource *))v45->lpVtbl->Release)(v45);
if ( v44 )
((void (__fastcall *)(struct IWICImagingFactory *))v44->lpVtbl->Release)(v44);
return (unsigned int)Instance;
}