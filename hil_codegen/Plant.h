/*
 * Header file for: hil/Plant
 * Generated with : PLECS 4.6.4
 *                  PLECS RT Box 2 2.2.2
 * Generated on   : 11 Jun 2022 16:38:34
 */
#ifndef PLECS_HEADER_Plant_h_
#define PLECS_HEADER_Plant_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Plant_FloatType;

/* Model checksum */
extern const char * const Plant_checksum;

/* Model error status */
extern const char * Plant_errorStatus;


/* Model sample time */
extern const double Plant_sampleTime;


/*
 * Model states */
typedef struct
{
   bool Monoflop;                   /* Plant/Total Harmonic Distortion U/Turn-on Delay/Monoflop */
   bool Monoflop_1;                 /* Plant/Total Harmonic Distortion I/Turn-on Delay/Monoflop */
   double Plant_PM0_x;              /* Plant */
   double Plant_PM1_x[21];          /* Plant */
   bool Plant_PM1_s[2];             /* Plant */
   double Assertion;                /* Plant/MFB1/Sub-cycle average/Assertion1/Assert/Assertion */
   double Assertion_1;              /* Plant/MFB1/Sub-cycle average/Assertion2/Assert/Assertion */
} Plant_ModelStates;
extern Plant_ModelStates Plant_X;


/* Block outputs */
typedef struct
{
   double Saturation1[3];           /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Saturation1 */
   double Saturation[3];            /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Saturation */
   bool Monoflop;                   /* Plant/Total Harmonic Distortion U/Turn-on Delay/Monoflop */
   double Saturation1_1[3];         /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Saturation1 */
   double Saturation_1[3];          /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Saturation */
   bool Monoflop_1;                 /* Plant/Total Harmonic Distortion I/Turn-on Delay/Monoflop */
   double Irradiance;               /* Plant/Irradiance */
   float PWM[4];                    /* Plant/PWM */
   bool Power;                      /* Plant/Power */
   bool Switch;                     /* Plant/Switch */
   double Switch_i1[4];             /* Plant/Switch */
   double MovingAverage[3];         /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_1[3];       /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_2[3];       /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain[3];                  /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Gain */
   double MovingAverage_3[3];       /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1[3];                 /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Gain1 */
   double Gain2[3];                 /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Gain2 */
   double Constant1;                /* Plant/Total Harmonic Distortion U/Constant1 */
   bool Switch_1;                   /* Plant/Total Harmonic Distortion U/Switch */
   double x_[3];                    /* Plant/% */
   double MovingAverage_4[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_5[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_6[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_1[3];                /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Gain */
   double MovingAverage_7[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_1[3];               /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Gain1 */
   double Gain2_1[3];               /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Gain2 */
   double Constant1_1;              /* Plant/Total Harmonic Distortion I/Constant1 */
   bool Switch_2;                   /* Plant/Total Harmonic Distortion I/Switch */
   double x_2[3];                   /* Plant/%2 */
   double Generator[3];             /* Plant/Generator */
   double Offset1;                  /* Plant/MFB1/Sub-cycle average/Offset1 */
   double x3D_Table;                /* Plant/PV/3D-Table */
   double Offset2;                  /* Plant/MFB1/Sub-cycle average/Offset2 */
   double Sine;                     /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Sine */
   double Cosine;                   /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Cosine */
   double Sine_1;                   /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Sine */
   double Cosine_1;                 /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Cosine */
} Plant_BlockOutputs;
extern Plant_BlockOutputs Plant_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Plant_NumExtModeSignals 30
extern const double * const Plant_ExtModeSignals[];
/* Tunable parameters */
#define Plant_NumTunableParameters 3
#endif /* defined(EXTERNAL_MODE) */


/* Block parameters */
typedef struct
{
   /* Parameter 'Value' of
    *  Constant : 'Plant/Temp [0:50] ºC'
    */
   double Constant_Value;
   /* Parameter 'Hi' of
    *  Pulse Generator : 'Plant/Irradiance'
    */
   double Irradiance_Hi;
   /* Parameter 'Lo' of
    *  Pulse Generator : 'Plant/Irradiance'
    */
   double Irradiance_Lo;
} Plant_Parameters;
extern Plant_Parameters Plant_P;

/* Entry point functions */
void Plant_initialize(double time);
void Plant_step(void);
void Plant_terminate(void);
void Plant_sync(void);
#endif /* PLECS_HEADER_Plant_h_ */
