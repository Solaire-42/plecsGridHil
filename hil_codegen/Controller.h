/*
 * Header file for: hil/Controller
 * Generated with : PLECS 4.6.4
 *                  TI2806x 1.5.4
 * Generated on   : 15 Jun 2022 17:55:31
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
   float Integrator_x;              /* Controller/Current controller/Integrator */
   bool Integrator_prevReset;       /* Controller/Current controller/Integrator */
   float Integrator1_x;             /* Controller/Current controller/Integrator1 */
   bool Integrator1_prevReset;      /* Controller/Current controller/Integrator1 */
   float s_x;                       /* Controller/Voltage controller/Type 2 controller/s */
   bool s_prevReset;                /* Controller/Voltage controller/Type 2 controller/s */
   float s_2_x;                     /* Controller/Voltage controller/Type 2 controller/s^2 */
   bool s_2_prevReset;              /* Controller/Voltage controller/Type 2 controller/s^2 */
   float Integrator_1_x;            /* Controller/MPP controller/Integrator */
   bool Integrator_1_prevReset;     /* Controller/MPP controller/Integrator */
   float dP_dVCalc[2];              /* Controller/MPP controller/dP/dV calc */
   bool Delay1;                     /* Controller/Delay1 */
} Controller_ModelStates;
extern Controller_ModelStates Controller_X;


/* Block outputs */
typedef struct
{
   float Controller;                /* Controller */
   float Controller_i1[2];          /* Controller */
   float Saturation;                /* Controller/Saturation */
   float Saturation_1;              /* Controller/Current controller/Saturation */
   float Controller_i2[2];          /* Controller */
   float Controller_i3;             /* Controller */
   float Saturation_2;              /* Controller/Voltage controller/Type 2 controller/Saturation */
   float Controller_i4[3];          /* Controller */
   float dP_dVCalc;                 /* Controller/MPP controller/dP/dV calc */
   bool LogicalOperator1;           /* Controller/Logical Operator1 */
   float Load[5];                   /* Controller/Load */
   float ADC[4];                    /* Controller/ADC */
   float En;                        /* Controller/En */
   float Fcn;                       /* Controller/Current reference/Fcn */
   float Sum1;                      /* Controller/Sum1 */
   float Integrator;                /* Controller/Current controller/Integrator */
   float Sum;                       /* Controller/Current controller/Sum */
   float Product;                   /* Controller/Unipolar duty/Product */
   float Fcn_1;                     /* Controller/Unipolar duty/Fcn */
   float Fcn1;                      /* Controller/Unipolar duty/Fcn1 */
   float Integrator1;               /* Controller/Current controller/Integrator1 */
   float Sum1_1;                    /* Controller/Current controller/Sum1 */
   float Sum_1;                     /* Controller/Sum */
   float s;                         /* Controller/Voltage controller/Type 2 controller/s */
   float s_2;                       /* Controller/Voltage controller/Type 2 controller/s^2 */
   float Sum8;                      /* Controller/Voltage controller/Type 2 controller/Sum8 */
   float Integrator_1;              /* Controller/MPP controller/Integrator */
   float ki;                        /* Controller/MPP controller/ki */
   bool Delay1;                     /* Controller/Delay1 */
} Controller_BlockOutputs;
extern Controller_BlockOutputs Controller_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Controller_NumExtModeSignals 13
extern const float * const Controller_ExtModeSignals[];
/* Tunable parameters */
#define Controller_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void Controller_initialize(float time);
void Controller_step(int task_id);
void Controller_terminate(void);

#endif /* PLECS_HEADER_Controller_h_ */
