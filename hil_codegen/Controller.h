/*
 * Header file for: hil/Controller
 * Generated with : PLECS 4.6.4
 *                  TI2806x 1.5.4
 * Generated on   : 17 Jun 2022 17:34:06
 */
#ifndef PLECS_HEADER_Controller_h_
#define PLECS_HEADER_Controller_h_

#include <stdbool.h>
#include <stdint.h>

/* Target declarations */
typedef int_fast8_t int8_t;
typedef uint_fast8_t uint8_t;
extern void Controller_background(void);


/* Model floating point type */
typedef float Controller_FloatType;

/* Model checksum */
extern const char * const Controller_checksum;

/* Model error status */
extern const char * Controller_errorStatus;


/* Model sample time */
extern const float Controller_sampleTime[4][2];


/*
 * Model states */
typedef struct
{
   bool Delay1;                     /* Controller/Delay1 */
} Controller_ModelStates;
extern Controller_ModelStates Controller_X;


/* Block outputs */
typedef struct
{
   bool Controller[6];              /* Controller */
   float Controller_i1[3];          /* Controller */
   float Controller_i2;             /* Controller */
   float TriangularWave;            /* Controller/Controller/Sine PWM/ PWM/Configurable Subsystem/Natural/Triangular Wave */
   bool LogicalOperator1;           /* Controller/Logical Operator1 */
   float Load[5];                   /* Controller/Load */
   float ADC[7];                    /* Controller/ADC */
   float SinePWMReferenceVoltage[3]; /* Controller/Controller/Sine PWM/Sine PWM Reference Voltage */
   float Gain;                      /* Controller/Controller/Sine PWM/Gain */
   float Switch[3];                 /* Controller/Controller/Sine PWM/ PWM/Configurable Subsystem/Natural/Switch */
   bool Delay1;                     /* Controller/Delay1 */
} Controller_BlockOutputs;
extern Controller_BlockOutputs Controller_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Controller_NumExtModeSignals 4
extern const float * const Controller_ExtModeSignals[];
/* Tunable parameters */
#define Controller_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void Controller_initialize(float time);
void Controller_step(int task_id);
void Controller_terminate(void);

#endif /* PLECS_HEADER_Controller_h_ */
