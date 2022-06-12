/*
 * Hardware configuration file for: TI2806x
 * Generated with                 : PLECS 4.6.4
 * Generated on                   : Sun Jun 12 18:39:52 2022
 */

#include "plx_hal.h"
#include "plx_dispatcher.h"
#include "pil.h"
#include "Controller.h"
#include "plx_sci.h"
#include "plx_ain.h"
#include "plx_dio.h"
#include "plx_pwm.h"
#include "plx_power.h"

void DeviceInit(Uint16 clock_source, Uint16 pllDiv);
void InitFlash();
void DSP28x_usDelay(long LoopCount);

// Clock configurations
#define SYSCLK_HZ 90000000L
#define LSPCLK_HZ (SYSCLK_HZ / 4l)
#define PLL_DIV 18
#define PLL_DIVSEL 2
#define PLL_SRC 0
#define PLX_DELAY_US(A)  DSP28x_usDelay( \
                                        ((((long double) A * \
                                           1000.0L) / \
                                          11.111111L) - 9.0L) / 5.0L)

PIL_Obj_t PilObj;
PIL_Handle_t PilHandle = 0;
PLX_SCI_Obj_t SciObj;
PLX_SCI_Handle_t SciHandle;
uint16_t ScopeBuffer[1026] /*__attribute__((aligned(16)))*/;
extern void PIL_setAndConfigScopeBuffer(PIL_Handle_t aPilHandle,
                                        uint16_t* aBufPtr, uint16_t aBufSize,
                                        uint16_t aMaxTraceWidthInWords);
extern const char * const Controller_checksum;

// external mode helper symbols

PIL_CONFIG_DEF(uint32_t, ExtMode_targetFloat_Size,
               sizeof(Controller_FloatType));

PIL_CONFIG_DEF(uint32_t, ExtMode_targetPointer_Size,
               sizeof(Controller_FloatType*));

PIL_CONFIG_DEF(uint32_t, ExtMode_sampleTime_Ptr,
               (uint32_t)&Controller_sampleTime);

PIL_CONFIG_DEF(uint32_t, ExtMode_checksum_Ptr,
               (uint32_t)&Controller_checksum);

#if defined(Controller_NumTunableParameters) && \
   (Controller_NumTunableParameters > 0)

PIL_CONFIG_DEF(uint32_t, ExtMode_P_Ptr, (uint32_t)&Controller_P);

PIL_CONFIG_DEF(uint32_t, ExtMode_P_Size,
               (uint32_t)Controller_NumTunableParameters);

#endif

#if defined(Controller_NumExtModeSignals) && (Controller_NumExtModeSignals > \
                                              0)

PIL_CONFIG_DEF(uint32_t, ExtMode_ExtModeSignals_Ptr,
               (uint32_t)&Controller_ExtModeSignals[0]);

PIL_CONFIG_DEF(uint32_t, ExtMode_ExtModeSignals_Size,
               (uint32_t)Controller_NumExtModeSignals);

#endif


#define CODE_GUID {0x09, 0x3c, 0x97, 0x5e, 0xdb, 0x2d, 0xb8, 0x40};
PIL_CONST_DEF(unsigned char, Guid[], CODE_GUID);
PIL_CONST_DEF(unsigned char, CompiledDate[], "06/12/2022 06:39 PM");
PIL_CONST_DEF(unsigned char, CompiledBy[], "PLECS Coder");
PIL_CONST_DEF(uint16_t, FrameworkVersion, PIL_FRAMEWORK_VERSION);
PIL_CONST_DEF(char, FirmwareDescription[], "TIC2000 Project");
PIL_CONST_DEF(uint16_t, StationAddress, 0);
PIL_CONST_DEF(uint32_t, BaudRate, 57600);
static void SciPoll(PIL_Handle_t aHandle)
{
   if(PLX_SCI_breakOccurred(SciHandle))
   {
      PLX_SCI_reset(SciHandle);
   }

   while(PLX_SCI_rxReady(SciHandle))
   {
      // assuming that there will be a "break" when FIFO is empty
      PIL_SERIAL_IN(aHandle, (int16)PLX_SCI_getChar(SciHandle));
   }

   int16_t ch;
   if(!PLX_SCI_txIsBusy(SciHandle))
   {
      if(PIL_SERIAL_OUT(aHandle, &ch))
      {
         PLX_SCI_putChar(SciHandle, ch);
      }
   }
}

uint32_t PLXHAL_DISPR_getTimeStamp0()
{
   return DISPR_getTimeStamp0();
}
uint32_t PLXHAL_DISPR_getTimeStamp1()
{
   return DISPR_getTimeStamp1();
}
uint32_t PLXHAL_DISPR_getTimeStamp2()
{
   return DISPR_getTimeStamp2();
}
uint32_t PLXHAL_DISPR_getTimeStamp3()
{
   return DISPR_getTimeStamp3();
}
uint32_t PLXHAL_DISPR_getTimeStampB()
{
   return DISPR_getTimeStampB();
}
uint32_t PLXHAL_DISPR_getTimeStampD()
{
   return DISPR_getTimeStampD();
}
uint32_t PLXHAL_DISPR_getTimeStampP()
{
   return DISPR_getTimeStampP();
}
float PLXHAL_DISPR_getTask0LoadInPercent()
{
   return DISPR_getTask0LoadInPercent();
}
PLX_AIN_Handle_t AdcHandles[1];
PLX_AIN_Obj_t AdcObj[1];
float PLXHAL_ADC_getIn(uint16_t aHandle, uint16_t aChannel)
{
   return PLX_AIN_getInF(AdcHandles[aHandle], aChannel);
}
interrupt void Controller_baseTaskInterrupt(void)
{
   AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;              // clear ADCINT1 flag reinitialize for next SOC
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;  // acknowledge interrupt to PIE (All ADCS in group 1)
   IER |= M_INT1;

   DISPR_dispatch();
}


PLX_DIO_Handle_t DinHandles[1];
PLX_DIO_Obj_t DinObj[1];
bool PLXHAL_DIO_get(uint16_t aHandle)
{
   return PLX_DIO_get(DinHandles[aHandle]);
}
extern PLX_PWM_Handle_t EpwmHandles[];
void PLXHAL_PWM_setDuty(uint16_t aHandle, float aDuty)
{
   PLX_PWM_setPwmDuty(EpwmHandles[aHandle], aDuty);
}
void PLXHAL_PWM_setToPassive(uint16_t aChannel)
{
   PLX_PWM_setOutToPassive(EpwmHandles[aChannel]);
}
void PLXHAL_PWM_setToOperational(uint16_t aChannel)
{
   PLX_PWM_setOutToOperational(EpwmHandles[aChannel]);
}
void PLXHAL_PWM_setSequence(uint16_t aChannel, uint16_t aSequence)
{
   PLX_PWM_setSequence(EpwmHandles[aChannel], (aSequence > 0));
}
void PLXHAL_PWM_prepareSetOutToXTransition(uint16_t aHandle)
{
   PLX_PWM_prepareSetOutToXTransition(EpwmHandles[aHandle]);
}
void PLXHAL_PWM_setScaledDeadTimeCounts(uint16_t aChannel, float aScaling,
                                        uint16_t aNominalCounts)
{
   uint16_t scaledCounts = 0;
   if (aScaling > 0)
   {
      scaledCounts = (uint16_t)((float)aNominalCounts * aScaling);
   }
   PLX_PWM_setDeadTimeCounts(EpwmHandles[aChannel], scaledCounts,
                             scaledCounts);
}

PLX_PWM_Handle_t EpwmHandles[4];
PLX_PWM_Obj_t EpwmObj[4];
extern PIL_Handle_t PilHandle;
DISPR_TaskObj_t TaskObj[4];
extern void Controller_step(int task_id);
extern void Controller_enableTasksInterrupt();
extern void Controller_syncTimers();
static void Tasks(bool aInit, void * const aParam)
{
   if(aInit)
   {
      Controller_enableTasksInterrupt();
   }
   else
   {
      Controller_step(*(int *)aParam);
   }
}


void PLXHAL_PWR_setEnableRequest(bool aEnable)
{
   PLX_PWR_setEnableRequest(aEnable);
   PLX_PWR_runFsm();
}
bool PLXHAL_PWR_isEnabled()
{
   return PLX_PWR_isEnabled();
}
void PLXHAL_PWR_syncdPwmEnable()
{
   PLX_PWR_syncdSwitchingEnable();
}
PLX_DIO_Handle_t DoutHandles[1];
PLX_DIO_Obj_t DoutObj[1];
void PLXHAL_DIO_set(uint16_t aHandle, bool aVal)
{
   PLX_DIO_set(DoutHandles[aHandle], aVal);
}

void Controller_enableTasksInterrupt(void)
{
   IER |= M_INT1;
}

void Controller_syncTimers(void)
{
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;  // start all the timers synced

}

void Controller_background(void)
{

}

static bool HalInitialized = false;
void Controller_initHal()
{
   if(HalInitialized == true)
   {
      return;
   }
   HalInitialized = true;
   DeviceInit(PLL_SRC, PLL_DIV);
   InitFlash();
   // set cpu timers to same clock as ePWM (SYSCLK/2)
   CpuTimer0Regs.TPR.all = 1;
   CpuTimer1Regs.TPR.all = 1;
   CpuTimer2Regs.TPR.all = 1;
   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;  // stop all the TB clocks
   EDIS;

   SciHandle = PLX_SCI_init(&SciObj, sizeof(SciObj));
   PLX_SCI_configure(SciHandle, 0, 22500000);
   (void)PLX_SCI_setupPort(SciHandle, 57600);
   PilHandle = PIL_init(&PilObj, sizeof(PilObj));
   PIL_setGuid(PilHandle, PIL_GUID_PTR);
   PIL_setChecksum(PilHandle, Controller_checksum);
   PIL_setAndConfigScopeBuffer(PilHandle, (uint16_t *)&ScopeBuffer, 1026, 26);
   PIL_setSerialComCallback(PilHandle, (PIL_CommCallbackPtr_t)SciPoll);
   {
      PLX_AIN_sinit(3.300000, 90000000);
      int i;
      for(i=0; i < 1; i++)
      {
         AdcHandles[i] = PLX_AIN_init(&AdcObj[i], sizeof(AdcObj[i]));
      }
   }

   // configure ADC A

   {
      PLX_AIN_AdcParams_t params;
      PLX_AIN_setDefaultAdcParams(&params);
      PLX_AIN_configure(AdcHandles[0], (PLX_AIN_Unit_t)0, &params);
      EALLOW;
      AdcRegs.INTSEL1N2.bit.INT1CONT = 0; // disable ADCINT1 Continuous mode
      AdcRegs.INTSEL1N2.bit.INT1SEL = 3; // setup EOC3 to trigger ADCINT1
      AdcRegs.INTSEL1N2.bit.INT1E = 1; // enable ADCINT1
      AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1; // ADCINT1 trips after AdcResults latch
      EDIS;
      EALLOW;
      PieVectTable.ADCINT1 = Controller_baseTaskInterrupt;
      PieCtrlRegs.PIEIER1.bit.INTx1 = 1;
      PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
      EDIS;

   }
   // configure SOC1 of ADC-A to measure ADCIN4
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale=  2.303030303e+02f;
      params.offset= 0.000000000e+00f;
      // set SOC trigger to PWM1
      params.ADCSOCxCTL.bit.TRIGSEL = 5;
      params.ADCSOCxCTL.bit.ACQPS = 7;
      PLX_AIN_setupChannel(AdcHandles[0], 0, 4, &params);
   }

   // configure SOC2 of ADC-A to measure ADCIN5
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale=  4.784688995e+00f;
      params.offset= 0.000000000e+00f;
      // set SOC trigger to PWM1
      params.ADCSOCxCTL.bit.TRIGSEL = 5;
      params.ADCSOCxCTL.bit.ACQPS = 7;
      PLX_AIN_setupChannel(AdcHandles[0], 1, 5, &params);
   }

   // configure SOC3 of ADC-A to measure ADCIN6
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale=  3.939393939e+02f;
      params.offset= -6.500000000e+02f;
      // set SOC trigger to PWM1
      params.ADCSOCxCTL.bit.TRIGSEL = 5;
      params.ADCSOCxCTL.bit.ACQPS = 7;
      PLX_AIN_setupChannel(AdcHandles[0], 2, 6, &params);
   }

   // configure SOC4 of ADC-A to measure ADCIN7
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale=  2.424242424e+01f;
      params.offset= -4.000000000e+01f;
      // set SOC trigger to PWM1
      params.ADCSOCxCTL.bit.TRIGSEL = 5;
      params.ADCSOCxCTL.bit.ACQPS = 7;
      PLX_AIN_setupChannel(AdcHandles[0], 3, 7, &params);
   }

   {
      PLX_DIO_sinit();
      int i;
      for(i=0; i < 1; i++)
      {
         DinHandles[i] = PLX_DIO_init(&DinObj[i], sizeof(DinObj[i]));
      }
   }

   {
      PLX_DIO_InputProperties_t props = {
         0
      };
      props.type = PLX_DIO_NOPULL;
      props.enableInvert = false;
      PLX_DIO_configureIn(DinHandles[0], 19, &props);
   }
   {
      PLX_PWM_sinit();
      int i;
      for(i=0; i < 4; i++)
      {
         EpwmHandles[i] = PLX_PWM_init(&EpwmObj[i], sizeof(EpwmObj[i]));
      }
   }

   // configure PWM1 at 2500.0 Hz in triangle mode
   // (soc='zp')
   {
      PLX_PWM_Params_t params;
      PLX_PWM_setDefaultParams(&params);
      params.outMode = PLX_PWM_OUTPUT_MODE_DUAL;
      params.reg.TBPRD = 9000;
      params.reg.TBCTL.bit.CTRMODE = 2;
      // active state is high
      params.reg.DBCTL.bit.POLSEL = 2;
      params.reg.TZSEL.bit.CBC1 = 0;
      params.reg.TZSEL.bit.OSHT1 = 0;
      params.reg.TZSEL.bit.CBC2 = 0;
      params.reg.TZSEL.bit.OSHT2 = 0;
      params.reg.TZSEL.bit.CBC3 = 0;
      params.reg.TZSEL.bit.OSHT3 = 0;
      // force low when tripped
      params.reg.TZCTL.bit.TZA = 2;
      params.reg.TZCTL.bit.TZB = 2;
      PLX_PWM_configure(EpwmHandles[0], 1, &params);
      // configure deadtime to 1.000000e-07 seconds
      PLX_PWM_setDeadTimeCounts(EpwmHandles[0], 4, 4);
      // PWM sequence starting with active state
      PLX_PWM_setSequence(EpwmHandles[0], 1);
      EPwm1Regs.ETSEL.bit.SOCASEL = 3;
      EPwm1Regs.ETPS.bit.SOCAPRD = 1;
      EPwm1Regs.ETSEL.bit.SOCAEN = 1;

   }
   // configure PWM2 at 2500.0 Hz in triangle mode
   {
      PLX_PWM_Params_t params;
      PLX_PWM_setDefaultParams(&params);
      params.outMode = PLX_PWM_OUTPUT_MODE_DUAL;
      params.reg.TBPRD = 9000;
      params.reg.TBCTL.bit.CTRMODE = 2;
      // active state is high
      params.reg.DBCTL.bit.POLSEL = 2;
      params.reg.TZSEL.bit.CBC1 = 0;
      params.reg.TZSEL.bit.OSHT1 = 0;
      params.reg.TZSEL.bit.CBC2 = 0;
      params.reg.TZSEL.bit.OSHT2 = 0;
      params.reg.TZSEL.bit.CBC3 = 0;
      params.reg.TZSEL.bit.OSHT3 = 0;
      // force low when tripped
      params.reg.TZCTL.bit.TZA = 2;
      params.reg.TZCTL.bit.TZB = 2;
      PLX_PWM_configure(EpwmHandles[1], 2, &params);
      // configure deadtime to 1.000000e-07 seconds
      PLX_PWM_setDeadTimeCounts(EpwmHandles[1], 4, 4);
      // PWM sequence starting with active state
      PLX_PWM_setSequence(EpwmHandles[1], 1);

   }
   // configure PWM4 at 2500.0 Hz in triangle mode
   {
      PLX_PWM_Params_t params;
      PLX_PWM_setDefaultParams(&params);
      params.outMode = PLX_PWM_OUTPUT_MODE_DUAL;
      params.reg.TBPRD = 9000;
      params.reg.TBCTL.bit.CTRMODE = 2;
      // active state is high
      params.reg.DBCTL.bit.POLSEL = 2;
      params.reg.TZSEL.bit.CBC1 = 0;
      params.reg.TZSEL.bit.OSHT1 = 0;
      params.reg.TZSEL.bit.CBC2 = 0;
      params.reg.TZSEL.bit.OSHT2 = 0;
      params.reg.TZSEL.bit.CBC3 = 0;
      params.reg.TZSEL.bit.OSHT3 = 0;
      // force low when tripped
      params.reg.TZCTL.bit.TZA = 2;
      params.reg.TZCTL.bit.TZB = 2;
      PLX_PWM_configure(EpwmHandles[2], 4, &params);
      // configure deadtime to 1.000000e-07 seconds
      PLX_PWM_setDeadTimeCounts(EpwmHandles[2], 4, 4);
      // PWM sequence starting with active state
      PLX_PWM_setSequence(EpwmHandles[2], 1);

   }
   // configure PWM5 at 2500.0 Hz in triangle mode
   {
      PLX_PWM_Params_t params;
      PLX_PWM_setDefaultParams(&params);
      params.outMode = PLX_PWM_OUTPUT_MODE_DUAL;
      params.reg.TBPRD = 9000;
      params.reg.TBCTL.bit.CTRMODE = 2;
      // active state is high
      params.reg.DBCTL.bit.POLSEL = 2;
      params.reg.TZSEL.bit.CBC1 = 0;
      params.reg.TZSEL.bit.OSHT1 = 0;
      params.reg.TZSEL.bit.CBC2 = 0;
      params.reg.TZSEL.bit.OSHT2 = 0;
      params.reg.TZSEL.bit.CBC3 = 0;
      params.reg.TZSEL.bit.OSHT3 = 0;
      // force low when tripped
      params.reg.TZCTL.bit.TZA = 2;
      params.reg.TZCTL.bit.TZB = 2;
      PLX_PWM_configure(EpwmHandles[3], 5, &params);
      // configure deadtime to 1.000000e-07 seconds
      PLX_PWM_setDeadTimeCounts(EpwmHandles[3], 4, 4);
      // PWM sequence starting with active state
      PLX_PWM_setSequence(EpwmHandles[3], 1);

   }
   DISPR_sinit();
   DISPR_configure((uint32_t)(9000), PilHandle, &TaskObj[0],
                   sizeof(TaskObj)/sizeof(DISPR_TaskObj_t));
   DISPR_registerIdleTask(&Controller_background);
   DISPR_registerSyncCallback(&Controller_syncTimers);
   DISPR_setPowerupDelay(5);
   {
      static int taskId = 0;
      // Task 0 at 5.000000e+03 Hz
      DISPR_registerTask(0, &Tasks, 9000L, (void *)&taskId);
   }
   {
      static int taskId = 1;
      // Task 1 at 2.500000e+03 Hz
      DISPR_registerTask(1, &Tasks, 18000L, (void *)&taskId);
   }
   {
      static int taskId = 2;
      // Task 2 at 4.545455e+02 Hz
      DISPR_registerTask(2, &Tasks, 99000L, (void *)&taskId);
   }
   {
      static int taskId = 3;
      // Task 3 at 1.000000e+01 Hz
      DISPR_registerTask(3, &Tasks, 4500000L, (void *)&taskId);
   }
   {
      PLX_PWR_sinit();
      PLX_DIO_sinit();
      static PLX_DIO_Obj_t doutObj;
      PLX_DIO_Handle_t doutHandle = PLX_DIO_init(&doutObj, sizeof(doutObj));
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = true;
      PLX_DIO_configureOut(doutHandle, 25, &props);
      PLX_PWR_configure(doutHandle, 5000);
   }
   {
      PLX_DIO_sinit();
      int i;
      for(i=0; i < 1; i++)
      {
         DoutHandles[i] = PLX_DIO_init(&DoutObj[i], sizeof(DoutObj[i]));
      }
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.type = PLX_DIO_PUSHPULL;
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[0], 34,  &props);
   }

   // Post init code (for modules that depend on other modules)

   PLX_PWR_registerPwmChannel(EpwmHandles[0]);
   PLX_PWR_registerPwmChannel(EpwmHandles[1]);
   PLX_PWR_registerPwmChannel(EpwmHandles[2]);
   PLX_PWR_registerPwmChannel(EpwmHandles[3]);
}
