/*
 * Implementation file for: hil/Controller
 * Generated with         : PLECS 4.6.4
 *                          TI2806x 1.5.4
 * Generated on           : 15 Jun 2022 17:55:31
 */
#include "Controller.h"
#ifndef PLECS_HEADER_Controller_h_
#error The wrong header file "Controller.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_Controller_h_ */
#if defined(__GNUC__) && (__GNUC__ > 4)
#   define _ALIGNMENT 16
#   define _RESTRICT __restrict
#   define _ALIGN __attribute__((aligned(_ALIGNMENT)))
#   if defined(__clang__)
#      if __has_builtin(__builtin_assume_aligned)
#         define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#      else
#         define _ASSUME_ALIGNED(a) a
#      endif
#   else
#      define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#   endif
#else
#   ifndef _RESTRICT
#      define _RESTRICT
#   endif
#   ifndef _ALIGN
#      define _ALIGN
#   endif
#   ifndef _ASSUME_ALIGNED
#      define _ASSUME_ALIGNED(a) a
#   endif
#endif
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "plx_hal.h"
#define PLECSRunTimeError(msg) Controller_errorStatus = msg
struct CScriptStruct
{
   int numInputTerminals;
   int numOutputTerminals;
   int* numInputSignals;
   int* numOutputSignals;
   int numContStates;
   int numDiscStates;
   int numZCSignals;
   int numSampleTimes;
   int numParameters;
   int isMajorTimeStep;
   float time;
   const float ***inputs;
   float ***outputs;
   float *contStates;
   float *contDerivs;
   float *discStates;
   float *zCSignals;
   const int *paramNumDims;
   const int **paramDims;
   const int *paramNumElements;
   const float **paramRealData;
   const char **paramStringData;
   const char * const *sampleHits;
   const float *sampleTimePeriods;
   const float *sampleTimeOffsets;
   float *nextSampleHit;
   const char** errorStatus;
   const char** warningStatus;
   const char** rangeErrorMsg;
   int* rangeErrorLine;
   void (*writeCustomStateDouble)(void*, float);
   float (*readCustomStateDouble)(void*);
   void (*writeCustomStateInt)(void*, int);
   void (*writeCustomStateData)(void*, const void*, int);
   void (*readCustomStateData)(void*, void*, int);
};
static struct CScriptStruct Controller_cScriptStruct[1];
static char Controller_isMajorStep = '\001';
static const uint32_t Controller_subTaskPeriod[3]= {
   /* [0.0004, 0], Base Task */
   8,
   /* [0.0022, 0], Base Task */
   44,
   /* [0.5, 0], LED Task */
   5
};
static uint32_t Controller_subTaskTick[3];
static char Controller_subTaskHit[3];
static const float Controller_UNCONNECTED = 0;
static float Controller_D_float[5];
static volatile int Controller_Sema[1];
static float Controller_deriv[5] _ALIGN;
void Controller_0_cScriptStart(const struct CScriptStruct *cScriptStruct);
void Controller_0_cScriptOutput(const struct CScriptStruct *cScriptStruct);
void Controller_0_cScriptUpdate(const struct CScriptStruct *cScriptStruct);
void Controller_0_cScriptDerivative(const struct CScriptStruct *cScriptStruct);
void Controller_0_cScriptTerminate(const struct CScriptStruct *cScriptStruct);
static uint32_t Controller_tickLo[4];
static int32_t Controller_tickHi[4];
Controller_BlockOutputs Controller_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const float * const Controller_ExtModeSignals[] = {
   &Controller_B.Load[0],
   &Controller_B.Fcn_1,
   &Controller_B.Fcn1,
   &Controller_B.Controller,
   &Controller_B.Saturation,
   &Controller_B.Fcn,
   &Controller_B.ADC[3],
   &Controller_B.Controller_i1[1],
   &Controller_B.ADC[0],
   &Controller_B.ADC[1],
   &Controller_B.ADC[2],
   &Controller_B.ADC[3],
   &Controller_B.En
};
#endif /* defined(EXTERNAL_MODE) */
Controller_ModelStates Controller_X _ALIGN;
const char * Controller_errorStatus;
const float Controller_sampleTime[4][2] = {
   /* Task "Base Task" */
   {5e-05f, 0.f},
   /* Task "Voltage Control Task" */
   {0.0004f, 0.f},
   /* Task "MPP Control Task" */
   {0.0022f, 0.f},
   /* Task "LED Task" */
   {0.1f, 0.f}
};
const char * const Controller_checksum =
   "40775cb739a44b827b170b286cdefc05da407c7c";
/* Target declarations */
extern void Controller_initHal();

void Controller_initialize(float time)
{
   float remainder;
   Controller_errorStatus = NULL;
   Controller_tickHi[0] = floor(
                                time/
                                (4294967296.0*Controller_sampleTime[0][0]));
   remainder = time - Controller_tickHi[0]*4294967296.0*
               Controller_sampleTime[0][0];
   Controller_tickLo[0] = floor(remainder/Controller_sampleTime[0][0] + .5);
   remainder -= Controller_tickLo[0]*Controller_sampleTime[0][0];
   if (fabsf(remainder) > 1e-6*fabsf(time))
   {
      Controller_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   Controller_subTaskTick[0] = 0;   /* Base Task, [0.0004, 0] */
   Controller_subTaskTick[1] = 0;   /* Base Task, [0.0022, 0] */
   Controller_subTaskTick[2] = 0;   /* LED Task, [0.5, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Controller_tickHi[0]);
      for (i = 0; i < 3; ++i)
      {
         delta = -Controller_subTaskPeriod[i];
         delta %= Controller_subTaskPeriod[i];
         if (Controller_tickHi[0] < 0)
         {
            delta = Controller_subTaskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            Controller_subTaskTick[i] =
               (Controller_subTaskTick[i] +
                delta) % Controller_subTaskPeriod[i];
         }
         Controller_subTaskTick[i] =
            (Controller_subTaskTick[i] + Controller_tickLo[0] %
             Controller_subTaskPeriod[i]) % Controller_subTaskPeriod[i];
      }
   }

   /* Target pre-initialization */
   Controller_initHal();


   /* Initialization for Subsystem : 'Controller' */
   Controller_D_float[0] = 0;

   /* Initialization for Subsystem : 'Controller' */
   Controller_D_float[1] = 0;
   Controller_D_float[2] = 0;

   /* Initialization for Integrator : 'Controller/Current\ncontroller/Integrator' */
   Controller_X.Integrator_x = 0.f;

   /* Initialization for Integrator : 'Controller/Current\ncontroller/Integrator1' */
   Controller_X.Integrator1_x = 0.f;

   /* Initialization for Subsystem : 'Controller' */
   Controller_B.Controller_i2[0] = 0;
   Controller_B.Controller_i2[1] = 0;

   /* Initialization for Subsystem : 'Controller' */
   Controller_Sema[0] = 0;
   Controller_D_float[3] = 0;
   Controller_D_float[4] = 0;

   /* Initialization for Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s' */
   Controller_X.s_x = 0.f;

   /* Initialization for Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s^2' */
   Controller_X.s_2_x = 0.f;

   /* Initialization for Subsystem : 'Controller' */
   Controller_B.Controller_i4[0] = 0;
   Controller_B.Controller_i4[1] = 0;
   Controller_B.Controller_i4[2] = 0;

   /* Initialization for Integrator : 'Controller/MPP\ncontroller/Integrator' */
   Controller_X.Integrator_1_x = 388.f;

   /* Initialization for C-Script : 'Controller/MPP\ncontroller/dP\/dV calc' */
   {
      static int numInputSignals[] = {
         2
      };
      static const float* inputPtrs[] = {
         &Controller_B.Controller_i4[1], &Controller_B.Controller_i4[0]
      };
      static const float** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         1
      };
      static float* outputPtrs[] = {
         &Controller_B.dP_dVCalc
      };
      static float** outputs[] = {
         &outputPtrs[0]
      };
      static float nextSampleHit;
      static const char * sampleHits[] = {
         &Controller_isMajorStep
      };
      static float sampleTimePeriods[] = {
         0.0022
      };
      static float sampleTimeOffsets[] = {
         0
      };
      static const char* errorStatus;
      static const char* warningStatus;
      static const char* rangeErrorMsg;
      errorStatus = NULL;
      warningStatus = NULL;
      rangeErrorMsg = NULL;
      Controller_cScriptStruct[0].isMajorTimeStep = 1;
      Controller_cScriptStruct[0].numInputTerminals = 1;
      Controller_cScriptStruct[0].numInputSignals = numInputSignals;
      Controller_cScriptStruct[0].inputs = inputs;
      Controller_cScriptStruct[0].numOutputTerminals = 1;
      Controller_cScriptStruct[0].numOutputSignals = numOutputSignals;
      Controller_cScriptStruct[0].outputs = outputs;
      Controller_cScriptStruct[0].numContStates = 0;
      Controller_cScriptStruct[0].contStates = NULL;
      Controller_cScriptStruct[0].contDerivs = NULL;
      Controller_cScriptStruct[0].numDiscStates = 2;
      Controller_cScriptStruct[0].discStates = &Controller_X.dP_dVCalc[0];
      Controller_cScriptStruct[0].numZCSignals = 0;
      Controller_cScriptStruct[0].numParameters = 0;
      Controller_cScriptStruct[0].paramNumDims = NULL;
      Controller_cScriptStruct[0].paramDims = NULL;
      Controller_cScriptStruct[0].paramNumElements = NULL;
      Controller_cScriptStruct[0].paramRealData = NULL;
      Controller_cScriptStruct[0].paramStringData = NULL;
      Controller_cScriptStruct[0].numSampleTimes = 1;
      Controller_cScriptStruct[0].sampleTimePeriods = sampleTimePeriods;
      Controller_cScriptStruct[0].sampleTimeOffsets = sampleTimeOffsets;
      Controller_cScriptStruct[0].numSampleTimes = 1;
      Controller_cScriptStruct[0].sampleHits = sampleHits;
      Controller_cScriptStruct[0].nextSampleHit = &nextSampleHit;
      Controller_cScriptStruct[0].errorStatus = &errorStatus;
      Controller_cScriptStruct[0].warningStatus = &warningStatus;
      Controller_cScriptStruct[0].rangeErrorMsg = &rangeErrorMsg;
      Controller_0_cScriptStart(&Controller_cScriptStruct[0]);
      if (*Controller_cScriptStruct[0].errorStatus)
         Controller_errorStatus = *Controller_cScriptStruct[0].errorStatus;
   }

   /* Initialization for Delay : 'Controller/Delay1' */
   Controller_X.Delay1 = 0.f;
}

void Controller_step(int task_id)
{
   if (Controller_errorStatus)
   {
      return;
   }
   switch(task_id)
   {
   case 0: /* Task "Base Task" */
   {
      {
         size_t i;
         for (i = 0; i < 2; ++i)
         {
            Controller_subTaskHit[i] = (Controller_subTaskTick[i] == 0);
         }
      }
      if (Controller_subTaskHit[1])
      {
         /* Subsystem : 'Controller' */
         Controller_B.Controller = Controller_D_float[0];
      }
      if (Controller_subTaskHit[0])
      {
         /* Subsystem : 'Controller' */
         Controller_B.Controller_i1[0] = Controller_D_float[1];
         Controller_B.Controller_i1[1] = Controller_D_float[2];
      }
      /* CPU Load : 'Controller/Load' */
      Controller_B.Load[0] = PLXHAL_DISPR_getTask0LoadInPercent();
      Controller_B.Load[1] = PLXHAL_DISPR_getTimeStamp0();
      Controller_B.Load[2] = PLXHAL_DISPR_getTimeStampB();
      Controller_B.Load[3] = PLXHAL_DISPR_getTimeStampD();
      Controller_B.Load[4] = PLXHAL_DISPR_getTimeStampP();

      /* ADC : 'Controller/ADC' */
      Controller_B.ADC[0] = PLXHAL_ADC_getIn(0, 0);
      Controller_B.ADC[1] = PLXHAL_ADC_getIn(0, 1);
      Controller_B.ADC[2] = PLXHAL_ADC_getIn(0, 2);
      Controller_B.ADC[3] = PLXHAL_ADC_getIn(0, 3);

      /* Saturation : 'Controller/Saturation' */
      Controller_B.Saturation = Controller_B.ADC[0];
      if (Controller_B.Saturation > 760.f)
      {
         Controller_B.Saturation = 760.f;
      }
      else if (Controller_B.Saturation < 38.f)
      {
         Controller_B.Saturation = 38.f;
      }

      /* Digital In : 'Controller/En' */
      Controller_B.En = PLXHAL_DIO_get(0);

      /* Function : 'Controller/Current\nreference/Fcn' */
      Controller_B.Fcn = Controller_B.Controller_i1[0] * Controller_B.ADC[2];

      /* Sum : 'Controller/Sum1' */
      Controller_B.Sum1 = Controller_B.Fcn - Controller_B.ADC[3];

      /* Integrator : 'Controller/Current\ncontroller/Integrator' */
      if ((Controller_X.Integrator_prevReset && !Controller_B.En))
      {
         Controller_X.Integrator_x = 0.f;
      }
      Controller_B.Integrator = Controller_X.Integrator_x;

      /* Sum : 'Controller/Current\ncontroller/Sum'
       * incorporates
       *  Gain : 'Controller/Current\ncontroller/Kp'
       */
      Controller_B.Sum = (20.f*Controller_B.Sum1) + Controller_B.Integrator;

      /* Saturation : 'Controller/Current\ncontroller/Saturation' */
      Controller_B.Saturation_1 = Controller_B.Sum;
      if (Controller_B.Saturation_1 > 325.f)
      {
         Controller_B.Saturation_1 = 325.f;
      }
      else if (Controller_B.Saturation_1 < -325.f)
      {
         Controller_B.Saturation_1 = -325.f;
      }

      /* Product : 'Controller/Unipolar\nduty/Product' */
      Controller_B.Product = 1.f / Controller_B.Saturation *
                             Controller_B.Saturation_1;

      /* Function : 'Controller/Unipolar\nduty/Fcn' */
      Controller_B.Fcn_1 = (Controller_B.Product / 2.f) + 0.5f;

      /* Function : 'Controller/Unipolar\nduty/Fcn1' */
      Controller_B.Fcn1 = ((-Controller_B.Product) / 2.f) + 0.5f;

      /* PWM  : 'Controller/PWM' */
      {
         PLXHAL_PWM_setDuty(0, Controller_B.Fcn_1);
      }
      {
         PLXHAL_PWM_setDuty(1, Controller_B.Fcn1);
      }
      /* Powerstage Protection : 'Controller/Power' */
      {
         if((Controller_B.En) > 0)
         {
            PLXHAL_PWR_setEnableRequest(true);
         }
         else
         {
            PLXHAL_PWR_setEnableRequest(false);
         }
      }

      /* PWM  : 'Controller/Oszi' */
      {
         PLXHAL_PWM_setDuty(2, Controller_B.Fcn_1);
      }
      {
         PLXHAL_PWM_setDuty(3, Controller_B.Fcn1);
      }
      /* Integrator : 'Controller/Current\ncontroller/Integrator1' */
      if ((Controller_X.Integrator1_prevReset && !Controller_B.En))
      {
         Controller_X.Integrator1_x = 0.f;
      }
      Controller_B.Integrator1 = Controller_X.Integrator1_x;

      /* Sum : 'Controller/Current\ncontroller/Sum1'
       * incorporates
       *  Sum : 'Controller/Current\ncontroller/Sum3'
       *  Gain : 'Controller/Current\ncontroller/Ki'
       *  Gain : 'Controller/Current\ncontroller/Gain2'
       *  Sum : 'Controller/Current\ncontroller/Sum2'
       *  Gain : 'Controller/Current\ncontroller/w0^2'
       */
      Controller_B.Sum1_1 =
         ((2000.f*
           Controller_B.Sum1) -
          (100.f*
           (Controller_B.Sum -
            Controller_B.Saturation_1))) -
         (98696.044f*Controller_B.Integrator1);
      if (Controller_subTaskHit[0])
      {

         /* Task transfer to 'Voltage Control Task' (Zero-Order Hold) */
         Controller_B.Controller_i2[0] = Controller_B.Saturation;
         Controller_B.Controller_i2[1] = Controller_B.En;
      }
      if (Controller_subTaskHit[1])
      {

         /* Task transfer to 'MPP Control Task' (Zero-Order Hold) */
         Controller_B.Controller_i4[0] = Controller_B.ADC[1];
         Controller_B.Controller_i4[1] = Controller_B.Saturation;
         Controller_B.Controller_i4[2] = Controller_B.En;
      }
      if (Controller_errorStatus)
      {
         return;
      }

      /* Update for Integrator : 'Controller/Current\ncontroller/Integrator' */
      Controller_X.Integrator_prevReset = !!(Controller_B.En);

      /* Update for PWM  : 'Controller/PWM' */
      PLXHAL_PWR_syncdPwmEnable();

      /* Update for Integrator : 'Controller/Current\ncontroller/Integrator1' */
      Controller_X.Integrator1_prevReset = !!(Controller_B.En);
      /* Increment sub-task tick counters */
      {
         size_t i;
         for (i = 0; i < 2; ++i)
         {
            Controller_subTaskTick[i]++;
            if (Controller_subTaskTick[i] >= Controller_subTaskPeriod[i])
            {
               Controller_subTaskTick[i] = 0;
            }
         }
      }

      /* Derivatives for Integrator : 'Controller/Current\ncontroller/Integrator' */
      Controller_deriv[0] = Controller_B.Sum1_1;

      /* Derivatives for Integrator : 'Controller/Current\ncontroller/Integrator1' */
      Controller_deriv[1] = Controller_B.Integrator;

      /* Update continuous states */
      Controller_X.Integrator_x += 5e-05f*Controller_deriv[0];
      Controller_X.Integrator1_x += 5e-05f*Controller_deriv[1];
      break;
   }

   case 1:                                                                                                                        /* Task "Voltage Control Task" */
   {

      /* Subsystem : 'Controller' */

      /* Task transfer from 'MPP Control Task' (Double Buffer) */
      if (Controller_Sema[0])
      {
         Controller_B.Controller_i3 = Controller_D_float[4];
      }
      else
      {
         Controller_B.Controller_i3 = Controller_D_float[3];
      }

      /* Sum : 'Controller/Sum'
       * incorporates
       *  Subsystem : 'Controller'
       */
      Controller_B.Sum_1 = -Controller_B.Controller_i3 +
                           Controller_B.Controller_i2[0];

      /* Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s' */
      if ((!Controller_X.s_prevReset && Controller_B.Controller_i2[1]))
      {
         Controller_X.s_x = 0.f;
      }
      if (Controller_X.s_x > 40.f)
      {
         Controller_X.s_x = 40.f;
      }
      else if (Controller_X.s_x < -40.f)
      {
         Controller_X.s_x = -40.f;
      }
      Controller_B.s = Controller_X.s_x;

      /* Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s^2' */
      if ((!Controller_X.s_2_prevReset && Controller_B.Controller_i2[1]))
      {
         Controller_X.s_2_x = 0.f;
      }
      if (Controller_X.s_2_x > 40.f)
      {
         Controller_X.s_2_x = 40.f;
      }
      else if (Controller_X.s_2_x < -40.f)
      {
         Controller_X.s_2_x = -40.f;
      }
      Controller_B.s_2 = Controller_X.s_2_x;

      /* Saturation : 'Controller/Voltage\ncontroller/Type 2 controller/Saturation'
       * incorporates
       *  Gain : 'Controller/Voltage\ncontroller/Type 2 controller/d9'
       *  Sum : 'Controller/Voltage\ncontroller/Type 2 controller/Sum9'
       *  Sum : 'Controller/Voltage\ncontroller/Type 2 controller/Sum10'
       *  Gain : 'Controller/Voltage\ncontroller/Type 2 controller/d8'
       *  Gain : 'Controller/Voltage\ncontroller/Type 2 controller/d5'
       *  Gain : 'Controller/Voltage\ncontroller/Type 2 controller/d10'
       */
      Controller_B.Saturation_2 = 2368.71403f*
                                  (((0.f*
                                     Controller_B.Sum_1) +
                                    (0.004f*
                                     Controller_B.s)) +
                                   (0.1f*Controller_B.s_2));
      if (Controller_B.Saturation_2 > 40.f)
      {
         Controller_B.Saturation_2 = 40.f;
      }
      else if (Controller_B.Saturation_2 < -40.f)
      {
         Controller_B.Saturation_2 = -40.f;
      }

      /* Sum : 'Controller/Voltage\ncontroller/Type 2 controller/Sum8'
       * incorporates
       *  Sum : 'Controller/Voltage\ncontroller/Type 2 controller/Sum'
       *  Gain : 'Controller/Voltage\ncontroller/Type 2 controller/d7'
       *  Gain : 'Controller/Voltage\ncontroller/Type 2 controller/d6'
       */
      Controller_B.Sum8 = Controller_B.Sum_1 -
                          ((0.f*
                            Controller_B.s_2) + (94.2748182f*Controller_B.s));
      /* Task transfer to 'Base Task' (Unit Delay) */
      Controller_D_float[1] = 0.00307692308f*Controller_B.Saturation_2;
      Controller_D_float[2] = Controller_B.Saturation_2;
      if (Controller_errorStatus)
      {
         return;
      }

      /* Update for Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s'
       * incorporates
       *  Subsystem : 'Controller'
       */
      Controller_X.s_prevReset = !!(Controller_B.Controller_i2[1]);

      /* Update for Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s^2'
       * incorporates
       *  Subsystem : 'Controller'
       */
      Controller_X.s_2_prevReset = !!(Controller_B.Controller_i2[1]);

      /* Derivatives for Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s' */
      if ((Controller_X.s_x >= 40.f &&
           Controller_B.Sum8 > 0) ||
          (Controller_X.s_x <= -40.f && Controller_B.Sum8 < 0))
      {
         Controller_deriv[2] = 0;
      }
      else
      {
         Controller_deriv[2] = Controller_B.Sum8;
      }

      /* Derivatives for Integrator : 'Controller/Voltage\ncontroller/Type 2 controller/s^2' */
      if ((Controller_X.s_2_x >= 40.f &&
           Controller_B.s > 0) ||
          (Controller_X.s_2_x <= -40.f && Controller_B.s < 0))
      {
         Controller_deriv[3] = 0;
      }
      else
      {
         Controller_deriv[3] = Controller_B.s;
      }

      /* Update continuous states */
      Controller_X.s_x += 0.0004f*Controller_deriv[2];
      Controller_X.s_2_x += 0.0004f*Controller_deriv[3];
      break;
   }

   case 2:                                                                                                         /* Task "MPP Control Task" */
   {

      /* Integrator : 'Controller/MPP\ncontroller/Integrator' */
      if ((!Controller_X.Integrator_1_prevReset &&
           Controller_B.Controller_i4[2]))
      {
         Controller_X.Integrator_1_x = 388.f;
      }
      if (Controller_X.Integrator_1_x > 600.f)
      {
         Controller_X.Integrator_1_x = 600.f;
      }
      else if (Controller_X.Integrator_1_x < 300.f)
      {
         Controller_X.Integrator_1_x = 300.f;
      }
      Controller_B.Integrator_1 = Controller_X.Integrator_1_x;

      /* C-Script : 'Controller/MPP\ncontroller/dP\/dV calc' */
      Controller_0_cScriptOutput(&Controller_cScriptStruct[0]);
      if (*Controller_cScriptStruct[0].errorStatus)
         Controller_errorStatus = *Controller_cScriptStruct[0].errorStatus;

      /* Gain : 'Controller/MPP\ncontroller/ki' */
      Controller_B.ki = 10.f*Controller_B.dP_dVCalc;
      /* Task transfer to 'Voltage Control Task' (Double Buffer) */
      {
         bool flag = Controller_Sema[0];
         if (flag)
         {
            Controller_D_float[3] = Controller_B.Integrator_1;
         }
         else
         {
            Controller_D_float[4] = Controller_B.Integrator_1;
         }
         Controller_Sema[0] = !flag;
      }
      /* Task transfer to 'Base Task' (Unit Delay) */
      Controller_D_float[0] = Controller_B.Integrator_1;
      if (Controller_errorStatus)
      {
         return;
      }

      /* Update for Integrator : 'Controller/MPP\ncontroller/Integrator'
       * incorporates
       *  Subsystem : 'Controller'
       */
      Controller_X.Integrator_1_prevReset = !!(Controller_B.Controller_i4[2]);

      /* Update for C-Script : 'Controller/MPP\ncontroller/dP\/dV calc' */
      Controller_0_cScriptUpdate(&Controller_cScriptStruct[0]);
      if (*Controller_cScriptStruct[0].errorStatus)
         Controller_errorStatus = *Controller_cScriptStruct[0].errorStatus;

      /* Derivatives for Integrator : 'Controller/MPP\ncontroller/Integrator' */
      if ((Controller_X.Integrator_1_x >= 600.f &&
           Controller_B.ki > 0) ||
          (Controller_X.Integrator_1_x <= 300.f && Controller_B.ki < 0))
      {
         Controller_deriv[4] = 0;
      }
      else
      {
         Controller_deriv[4] = Controller_B.ki;
      }

      /* Update continuous states */
      Controller_X.Integrator_1_x += 0.0022f*Controller_deriv[4];
      break;
   }

   case 3:                                                                  /* Task "LED Task" */
   {
      {
         size_t i;
         for (i = 2; i < 3; ++i)
         {
            Controller_subTaskHit[i] = (Controller_subTaskTick[i] == 0);
         }
      }
      if (Controller_subTaskHit[2])
      {
         /* Delay : 'Controller/Delay1' */
         Controller_B.Delay1 = Controller_X.Delay1;

         /* Logical Operator : 'Controller/Logical\nOperator1' */
         Controller_B.LogicalOperator1 = !Controller_B.Delay1;
      }

      /* Digital Out : 'Controller/LED Blinking' */
      PLXHAL_DIO_set(0, Controller_B.LogicalOperator1);
      if (Controller_errorStatus)
      {
         return;
      }
      if (Controller_subTaskHit[2])
      {
         /* Update for Delay : 'Controller/Delay1' */
         Controller_X.Delay1 = Controller_B.LogicalOperator1;
      }

      /* Increment sub-task tick counters */
      {
         size_t i;
         for (i = 2; i < 3; ++i)
         {
            Controller_subTaskTick[i]++;
            if (Controller_subTaskTick[i] >= Controller_subTaskPeriod[i])
            {
               Controller_subTaskTick[i] = 0;
            }
         }
      }
      break;
   }
   }
}

void Controller_terminate()
{
   /* Termination for C-Script : 'Controller/MPP\ncontroller/dP\/dV calc' */
   Controller_0_cScriptTerminate(&Controller_cScriptStruct[0]);
   if (*Controller_cScriptStruct[0].errorStatus)
      Controller_errorStatus = *Controller_cScriptStruct[0].errorStatus;
}
