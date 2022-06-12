/*
 * Header file for: hil/Plant
 * Generated with : PLECS 4.6.4
 *                  PLECS RT Box 2 2.2.2
 * Generated on   : 12 Jun 2022 18:43:59
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
   bool Monoflop_2;                 /* Plant/Total Harmonic Distortion U1/Turn-on Delay/Monoflop */
   bool Monoflop_3;                 /* Plant/Total Harmonic Distortion I1/Turn-on Delay/Monoflop */
   bool Monoflop_4;                 /* Plant/Total Harmonic Distortion U2/Turn-on Delay/Monoflop */
   bool Monoflop_5;                 /* Plant/Total Harmonic Distortion I2/Turn-on Delay/Monoflop */
   double Plant_PM0_x[9];           /* Plant */
   double Plant_PM1_x;              /* Plant */
   double Plant_PM2_x;              /* Plant */
   double Plant_PM3_x[27];          /* Plant */
   bool Plant_PM3_s[2];             /* Plant */
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
   double Saturation1_2[3];         /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Saturation1 */
   double Saturation_2[3];          /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Saturation */
   bool Monoflop_2;                 /* Plant/Total Harmonic Distortion U1/Turn-on Delay/Monoflop */
   double Saturation1_3[3];         /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Saturation1 */
   double Saturation_3[3];          /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Saturation */
   bool Monoflop_3;                 /* Plant/Total Harmonic Distortion I1/Turn-on Delay/Monoflop */
   double Saturation1_4[3];         /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Saturation1 */
   double Saturation_4[3];          /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Saturation */
   bool Monoflop_4;                 /* Plant/Total Harmonic Distortion U2/Turn-on Delay/Monoflop */
   double Saturation1_5[3];         /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Saturation1 */
   double Saturation_5[3];          /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Saturation */
   bool Monoflop_5;                 /* Plant/Total Harmonic Distortion I2/Turn-on Delay/Monoflop */
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
   double MovingAverage_8[3];       /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_9[3];       /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_10[3];      /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_2[3];                /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain */
   double MovingAverage_11[3];      /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_2[3];               /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain1 */
   double Gain2_2[3];               /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain2 */
   double Constant1_2;              /* Plant/Total Harmonic Distortion U1/Constant1 */
   bool Switch_3;                   /* Plant/Total Harmonic Distortion U1/Switch */
   double x_1[3];                   /* Plant/%1 */
   double MovingAverage_12[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_13[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_14[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_3[3];                /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain */
   double MovingAverage_15[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_3[3];               /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain1 */
   double Gain2_3[3];               /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain2 */
   double Constant1_3;              /* Plant/Total Harmonic Distortion I1/Constant1 */
   bool Switch_4;                   /* Plant/Total Harmonic Distortion I1/Switch */
   double x_3[3];                   /* Plant/%3 */
   double MovingAverage_16[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_17[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_18[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_4[3];                /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain */
   double MovingAverage_19[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_4[3];               /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain1 */
   double Gain2_4[3];               /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain2 */
   double Constant1_4;              /* Plant/Total Harmonic Distortion U2/Constant1 */
   bool Switch_5;                   /* Plant/Total Harmonic Distortion U2/Switch */
   double x_4[3];                   /* Plant/%4 */
   double MovingAverage_20[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_21[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_22[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_5[3];                /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain */
   double MovingAverage_23[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_5[3];               /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain1 */
   double Gain2_5[3];               /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain2 */
   double Constant1_5;              /* Plant/Total Harmonic Distortion I2/Constant1 */
   bool Switch_6;                   /* Plant/Total Harmonic Distortion I2/Switch */
   double x_5[3];                   /* Plant/%5 */
   double Generator[3];             /* Plant/Generator */
   double TransportDelay;           /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s1/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_1;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s2/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_2;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s3/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_3;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_r1/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_4;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay1_r2/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_5;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay1_r3/Configurable Subsystem/Non-zero delay/Transport Delay */
   double x3D_Table;                /* Plant/PV/3D-Table */
   double Offset2;                  /* Plant/MFB1/Sub-cycle average/Offset2 */
   double Offset1;                  /* Plant/MFB1/Sub-cycle average/Offset1 */
   double p_wm;                     /* Plant/Squirrel-Cage IM/p*wm */
   double x_w_psirq;                /* Plant/Squirrel-Cage IM/-w*psirq */
   double w_psird;                  /* Plant/Squirrel-Cage IM/w*psird */
   double Sine;                     /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Sine */
   double Cosine;                   /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Cosine */
   double Sine_1;                   /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Sine */
   double Cosine_1;                 /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Cosine */
   double Sine_2;                   /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Sine */
   double Cosine_2;                 /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Cosine */
   double Sine_3;                   /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Sine */
   double Cosine_3;                 /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Cosine */
   double Sine_4;                   /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Sine */
   double Cosine_4;                 /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Cosine */
   double Sine_5;                   /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Sine */
   double Cosine_5;                 /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Cosine */
   double Gain_s1[3];               /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_s1 */
   double Sum_s1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_s1 */
   double Gain_r1[3];               /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_r1 */
   double Sum_r1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_r1 */
} Plant_BlockOutputs;
extern Plant_BlockOutputs Plant_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Plant_NumExtModeSignals 54
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
