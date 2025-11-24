__int64 PoFxInitPowerManagement()
{
  __int64 result; // rax

  stru_140F0C840.Header.Size = 6;
  *(_QWORD *)&PopFxResidentTimer.Header.Lock = 9LL;
  qword_140F0C578 = (__int64)&PopFxDeviceList;
  PopFxDeviceList = (ULONG_PTR)&PopFxDeviceList;
  qword_140F0C588 = (__int64)&PopFxAcpiDeviceList;
  PopFxAcpiDeviceList = (__int64)&PopFxAcpiDeviceList;
  qword_140F0C778 = (__int64)&PopWorkOrderList;
  PopWorkOrderList = (__int64)&PopWorkOrderList;
  qword_140F0C7F0 = (__int64)PopFxResidentTimeoutRoutine;
  qword_140F0C830 = (__int64)&qword_140F0C828;
  qword_140F0C828 = (__int64)&qword_140F0C828;
  stru_140F0C840.Header.WaitListHead.Blink = &stru_140F0C840.Header.WaitListHead;
  stru_140F0C840.Header.WaitListHead.Flink = &stru_140F0C840.Header.WaitListHead;
  PopFxResidentDpc.DeferredRoutine = (PKDEFERRED_ROUTINE)PopFxResidentTimeoutDpcRoutine;
  PopFxResidentTimer.Header.WaitListHead.Blink = &PopFxResidentTimer.Header.WaitListHead;
  PopFxResidentTimer.Header.WaitListHead.Flink = &PopFxResidentTimer.Header.WaitListHead;
  qword_140F0C4E8 = (__int64)&PopFxPluginList;
  PopFxPluginList = (ULONG_PTR)&PopFxPluginList;
  PopFxDeviceRegisterHead = (__int64)&PopFxPluginList;
  PopFxActiveIdleThreshold *= 10000;
  PopFxDeviceListLock = 0LL;
  PopFxPluginLock = 0LL;
  PopWorkOrderLock = 0LL;
  qword_140F0C7F8 = 0LL;
  PopFxResidentWorkItem = 0LL;
  PopFxBlockingDeviceListLock = 0LL;
  PopFxUpdateDripsConstraintContext = 0LL;
  LOWORD(stru_140F0C840.Header.Lock) = 0;
  stru_140F0C840.Header.SignalState = 1;
  PopFxResidentDpc.TargetInfoAsUlong = 275;
  PopFxResidentDpc.DeferredContext = 0LL;
  PopFxResidentDpc.DpcData = 0LL;
  PopFxResidentDpc.ProcessorHistory = 0LL;
  PopFxResidentTimer.DueTime.QuadPart = 0LL;
  PopFxResidentTimer.Period = 0;
  PopFxResidentTimer.Processor = 0;
  if ( (unsigned int)PopFxActiveIdleLevel >= 3 )
    PopFxActiveIdleLevel = 1;
  PopFxGlobalDeviceAccountingLock = 0LL;
  memset_0(&byte_140F0C701, 0, 0x6FuLL);
  PopFxGlobalDeviceAccountingInfo = 1;
  if ( !PopSleepStudyDisabled )
  {
    if ( (PopSleepStudyDeviceAccountingLevel & 1) != 0 )
    {
      PopFxAccountingGroup = 1;
    }
    else if ( (PopSleepStudyDeviceAccountingLevel & 2) != 0 )
    {
      PopFxAccountingGroup = 2;
    }
    else if ( (PopSleepStudyDeviceAccountingLevel & 4) != 0 )
    {
      PopFxAccountingGroup = 3;
    }
  }
  qword_140F0C818 = (__int64)&SocSubsystemsList;
  SocSubsystemsList = (__int64)&SocSubsystemsList;
  PopFxInitializeWorkPool(&PopFxSystemWorkPool, 0LL);
  PopFxInitializeWorkPool(&PopFxNoFaultSystemWorkPool, 0LL);
  *(_QWORD *)&PopPepIdleTimer.Header.Lock = 9LL;
  qword_140F05DD8 = (__int64)&PopPepDeviceList;
  PopPepDeviceList = (__int64)&PopPepDeviceList;
  qword_140F05D30 = (__int64)PopPepIdleTimeoutRoutine;
  PopPepIdleDpc.DeferredRoutine = (PKDEFERRED_ROUTINE)PopPepIdleTimeoutDpcRoutine;
  PopPepIdleTimer.Header.WaitListHead.Blink = &PopPepIdleTimer.Header.WaitListHead;
  PopPepIdleTimer.Header.WaitListHead.Flink = &PopPepIdleTimer.Header.WaitListHead;
  qword_140F05770 = 0LL;
  PopPepDeviceListLock = 0LL;
  qword_140F05D38 = 0LL;
  PopPepIdleWorkItem = 0LL;
  PopPepIdleDpc.TargetInfoAsUlong = 275;
  PopPepIdleDpc.DeferredContext = 0LL;
  PopPepIdleDpc.DpcData = 0LL;
  PopPepIdleDpc.ProcessorHistory = 0LL;
  PopPepIdleTimer.DueTime.QuadPart = 0LL;
  PopPepIdleTimer.Period = 0;
  PopPepIdleTimer.Processor = 0;
  PopFxDirectedPowerUpTimeoutMs = 0;
  PopFxPlatformInterface = 0LL;
  if ( PopWatchdogResumeTimeout )
    PopFxDirectedPowerUpTimeoutMs = 1000 * (PopWatchdogResumeTimeout + 120);
  result = (unsigned int)PopWatchdogSleepTimeout;
  PopFxDirectedPowerDownTimeoutMs = 0;
  if ( (_DWORD)PopWatchdogSleepTimeout )
  {
    result = (unsigned int)(PopWatchdogSleepTimeout + 120);
    PopFxDirectedPowerDownTimeoutMs = 1000 * result;
  }
  return result;
}