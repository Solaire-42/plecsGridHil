/*
 * Implementation file for: hil/Controller
 * Generated with         : PLECS 4.6.4
 *                          TI2806x 1.5.4
 * Generated on           : 18 Jun 2022 14:39:51
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
static bool Controller_D_bool[6];
static float Controller_D_float[12];
static volatile int Controller_Sema[1];
static uint32_t Controller_tickLo[4];
static int32_t Controller_tickHi[4];
Controller_BlockOutputs Controller_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const float * const Controller_ExtModeSignals[] = {
   &Controller_B.Load[0],
   &Controller_B.ADC[0],
   &Controller_B.ADC[1],
   &Controller_B.ADC[2],
   &Controller_B.ADC[3],
   &Controller_B.ADC[4],
   &Controller_B.ADC[5],
   &Controller_B.ADC[6]
};
#endif /* defined(EXTERNAL_MODE) */
Controller_ModelStates Controller_X _ALIGN;
const char * Controller_errorStatus;
const float Controller_sampleTime[4][2] = {
   /* Task "Base Task" */
   {5e-05f, 0.f},
   /* Task "Switch Task" */
   {0.0004f, 0.f},
   /* Task "Control Task" */
   {0.0022f, 0.f},
   /* Task "LED Task" */
   {0.1f, 0.f}
};
const char * const Controller_checksum =
   "0b5fd1dae3faa9523228f43d4a74192972cfecca";
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
   Controller_D_bool[0] = 0;
   Controller_D_bool[1] = 0;
   Controller_D_bool[2] = 0;
   Controller_D_bool[3] = 0;
   Controller_D_bool[4] = 0;
   Controller_D_bool[5] = 0;

   /* Initialization for Subsystem : 'Controller' */
   Controller_Sema[0] = 0;
   Controller_D_float[0] = 0;
   Controller_D_float[1] = 0;
   Controller_D_float[2] = 0;
   Controller_D_float[3] = 0;
   Controller_D_float[4] = 0;
   Controller_D_float[5] = 0;

   /* Initialization for Subsystem : 'Controller' */
   Controller_B.Controller_i2 = 0;

   /* Initialization for Sine Wave Generator : 'Controller/Controller/Sine PWM/Sine PWM\nReference Voltage' */
   Controller_D_float[6] = sinf(314.159265f*time);
   Controller_D_float[7] = cosf(314.159265f*time);
   Controller_D_float[8] = sinf(314.159265f*time);
   Controller_D_float[9] = cosf(314.159265f*time);
   Controller_D_float[10] = sinf(314.159265f*time);
   Controller_D_float[11] = cosf(314.159265f*time);

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
      if (Controller_subTaskHit[0])
      {
         /* Subsystem : 'Controller' */
         Controller_B.Controller[0] = Controller_D_bool[0];
         Controller_B.Controller[1] = Controller_D_bool[1];
         Controller_B.Controller[2] = Controller_D_bool[2];
         Controller_B.Controller[3] = Controller_D_bool[3];
         Controller_B.Controller[4] = Controller_D_bool[4];
         Controller_B.Controller[5] = Controller_D_bool[5];
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
      Controller_B.ADC[4] = PLXHAL_ADC_getIn(0, 4);
      Controller_B.ADC[5] = PLXHAL_ADC_getIn(0, 5);
      Controller_B.ADC[6] = PLXHAL_ADC_getIn(0, 6);

      /* PWM  : 'Controller/PWM' */
      {
         PLXHAL_PWM_setDuty(0, Controller_B.Controller[0]);
      }
      {
         PLXHAL_PWM_setDuty(1, Controller_B.Controller[1]);
      }
      {
         PLXHAL_PWM_setDuty(2, Controller_B.Controller[2]);
      }
      {
         PLXHAL_PWM_setDuty(3, Controller_B.Controller[3]);
      }
      {
         PLXHAL_PWM_setDuty(4, Controller_B.Controller[4]);
      }
      {
         PLXHAL_PWM_setDuty(5, Controller_B.Controller[5]);
      }
      /* Powerstage Protection : 'Controller/Power' */
      {
         if((PLXHAL_DIO_get(0)) > 0)
         {
            PLXHAL_PWR_setEnableRequest(true);
         }
         else
         {
            PLXHAL_PWR_setEnableRequest(false);
         }
      }
      if (Controller_subTaskHit[1])
      {

         /* Task transfer to 'Control Task' (Zero-Order Hold) */
         Controller_B.Controller_i2 = Controller_B.ADC[6];
      }
      if (Controller_errorStatus)
      {
         return;
      }

      /* Update for PWM  : 'Controller/PWM' */
      PLXHAL_PWR_syncdPwmEnable();
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
      break;
   }

   case 1:                                                                                                                                                                          /* Task "Switch Task" */
   {

      /* Subsystem : 'Controller' */

      /* Task transfer from 'Control Task' (Double Buffer) */
      if (Controller_Sema[0])
      {
         Controller_B.Controller_i1[0] = Controller_D_float[1];
         Controller_B.Controller_i1[1] = Controller_D_float[3];
         Controller_B.Controller_i1[2] = Controller_D_float[5];
      }
      else
      {
         Controller_B.Controller_i1[0] = Controller_D_float[0];
         Controller_B.Controller_i1[1] = Controller_D_float[2];
         Controller_B.Controller_i1[2] = Controller_D_float[4];
      }
      /* Task transfer to 'Base Task' (Unit Delay) */
      Controller_D_bool[0] = Controller_B.Controller_i1[0] > 0.f;
      Controller_D_bool[1] = Controller_B.Controller_i1[0] < 0.f;
      Controller_D_bool[2] = Controller_B.Controller_i1[1] > 0.f;
      Controller_D_bool[3] = Controller_B.Controller_i1[1] < 0.f;
      Controller_D_bool[4] = Controller_B.Controller_i1[2] > 0.f;
      Controller_D_bool[5] = Controller_B.Controller_i1[2] < 0.f;
      if (Controller_errorStatus)
      {
         return;
      }
      break;
   }

   case 2:                                                                                                                                                                                                                                                                                                                                                                                                                /* Task "Control Task" */
   {

      /* Sine Wave Generator : 'Controller/Controller/Sine PWM/Sine PWM\nReference Voltage' */
      Controller_B.SinePWMReferenceVoltage[0] = 0.f + 1334.1417f *
                                                (0.275400628f*
                                                 Controller_D_float[6] +
                                                 0.961329545f*
                                                 Controller_D_float[7]);
      Controller_B.SinePWMReferenceVoltage[1] = 0.f + 1334.1417f *
                                                (0.694835493f*
                                                 Controller_D_float[8] +
                                                 -0.719168713f*
                                                 Controller_D_float[9]);
      Controller_B.SinePWMReferenceVoltage[2] = 0.f + 1334.1417f *
                                                (-0.970236121f*
                                                 Controller_D_float[10] +
                                                 -0.242160832f*
                                                 Controller_D_float[11]);

      /* Gain : 'Controller/Controller/Sine PWM/Gain'
       * incorporates
       *  Subsystem : 'Controller'
       */
      Controller_B.Gain = 0.5f*Controller_B.Controller_i2;

      /* Triangular Wave Generator : 'Controller/Controller/Sine PWM/ PWM/Configurable\nSubsystem/Natural/Triangular Wave' */
      {
         float frac;
         Controller_B.TriangularWave = -1.f;
      }

      /* Signal Switch : 'Controller/Controller/Sine PWM/ PWM/Configurable\nSubsystem/Natural/Switch'
       * incorporates
       *  Relational Operator : 'Controller/Controller/Sine PWM/ PWM/Configurable\nSubsystem/Natural/Relational\nOperator'
       *  Product : 'Controller/Controller/Sine PWM/Divide'
       *  Constant : 'Controller/Controller/Sine PWM/ PWM/Configurable\nSubsystem/Natural/Constant1'
       *  Constant : 'Controller/Controller/Sine PWM/ PWM/Configurable\nSubsystem/Natural/Constant'
       */
      Controller_B.Switch[0] =
         (((Controller_B.SinePWMReferenceVoltage[0] / Controller_B.Gain) >=
           Controller_B.TriangularWave) != 0.f) ? 1.f : (-1.f);
      Controller_B.Switch[1] =
         (((Controller_B.SinePWMReferenceVoltage[1] / Controller_B.Gain) >=
           Controller_B.TriangularWave) != 0.f) ? 1.f : (-1.f);
      Controller_B.Switch[2] =
         (((Controller_B.SinePWMReferenceVoltage[2] / Controller_B.Gain) >=
           Controller_B.TriangularWave) != 0.f) ? 1.f : (-1.f);
      /* Task transfer to 'Switch Task' (Double Buffer) */
      {
         bool flag = Controller_Sema[0];
         if (flag)
         {
            Controller_D_float[0] = Controller_B.Switch[0];
            Controller_D_float[2] = Controller_B.Switch[1];
            Controller_D_float[4] = Controller_B.Switch[2];
         }
         else
         {
            Controller_D_float[1] = Controller_B.Switch[0];
            Controller_D_float[3] = Controller_B.Switch[1];
            Controller_D_float[5] = Controller_B.Switch[2];
         }
         Controller_Sema[0] = !flag;
      }
      if (Controller_errorStatus)
      {
         return;
      }

      /* Update for Sine Wave Generator : 'Controller/Controller/Sine PWM/Sine PWM\nReference Voltage' */
      {
         float scaling, scaledX, scaledY;
         scaling = 1.f +
                   (0.5f *
                    (Controller_D_float[6]*Controller_D_float[6] +
                     Controller_D_float[7]*Controller_D_float[7] - 1.f));
         scaledX = Controller_D_float[6] / scaling;
         scaledY = Controller_D_float[7] / scaling;
         Controller_D_float[6] = 0.770513243f * scaledX + 0.63742399f *
                                 scaledY;
         Controller_D_float[7] = -0.63742399f * scaledX + 0.770513243f *
                                 scaledY;
         scaling = 1.f +
                   (0.5f *
                    (Controller_D_float[8]*Controller_D_float[8] +
                     Controller_D_float[9]*Controller_D_float[9] - 1.f));
         scaledX = Controller_D_float[8] / scaling;
         scaledY = Controller_D_float[9] / scaling;
         Controller_D_float[8] = 0.770513243f * scaledX + 0.63742399f *
                                 scaledY;
         Controller_D_float[9] = -0.63742399f * scaledX + 0.770513243f *
                                 scaledY;
         scaling = 1.f +
                   (0.5f *
                    (Controller_D_float[10]*Controller_D_float[10] +
                     Controller_D_float[11]*Controller_D_float[11] - 1.f));
         scaledX = Controller_D_float[10] / scaling;
         scaledY = Controller_D_float[11] / scaling;
         Controller_D_float[10] = 0.770513243f * scaledX + 0.63742399f *
                                  scaledY;
         Controller_D_float[11] = -0.63742399f * scaledX + 0.770513243f *
                                  scaledY;
      }
      break;
   }

   case 3:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           /* Task "LED Task" */
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
}
