/*
 * Header file for: hil/Plant
 * Generated with : PLECS 4.6.4
 *                  PLECS RT Box 2 2.2.2
 * Generated on   : 14 Jun 2022 18:27:49
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
extern const double Plant_sampleTime[3][2];


/*
 * Model states */
typedef struct
{
   double Plant_PM0_x[9];           /* Plant */
   double Plant_PM1_x;              /* Plant */
   double Plant_PM2_x;              /* Plant */
   double Plant_PM3_x[30];          /* Plant */
   bool Plant_PM3_s[8];             /* Plant */
   double Assertion;                /* Plant/MFB1/Sub-cycle average/Assertion1/Assert/Assertion */
   double Assertion_1;              /* Plant/MFB1/Sub-cycle average/Assertion2/Assert/Assertion */
   bool Monoflop;                   /* Plant/Total Harmonic Distortion U/Turn-on Delay/Monoflop */
   bool Monoflop_1;                 /* Plant/Total Harmonic Distortion I/Turn-on Delay/Monoflop */
   bool Monoflop_2;                 /* Plant/Total Harmonic Distortion U1/Turn-on Delay/Monoflop */
   bool Monoflop_3;                 /* Plant/Total Harmonic Distortion I1/Turn-on Delay/Monoflop */
   bool Monoflop_4;                 /* Plant/Total Harmonic Distortion U2/Turn-on Delay/Monoflop */
   bool Monoflop_5;                 /* Plant/Total Harmonic Distortion I2/Turn-on Delay/Monoflop */
   bool Monoflop_6;                 /* Plant/Total Harmonic Distortion U3/Turn-on Delay/Monoflop */
   bool Monoflop_7;                 /* Plant/Total Harmonic Distortion I3/Turn-on Delay/Monoflop */
} Plant_ModelStates;
extern Plant_ModelStates Plant_X;


/* Block outputs */
typedef struct
{
   double Plant[24];                /* Plant */
   double Plant_i1[4];              /* Plant */
   double Irradiance;               /* Plant/Irradiance */
   double TriangularWave;           /* Plant/Controller/Sine PWM/ PWM/Configurable Subsystem/Natural/Triangular Wave */
   double Plant_i2[24];             /* Plant */
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
   double Saturation1_6[3];         /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Saturation1 */
   double Saturation_6[3];          /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Saturation */
   bool Monoflop_6;                 /* Plant/Total Harmonic Distortion U3/Turn-on Delay/Monoflop */
   double Saturation1_7[3];         /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Saturation1 */
   double Saturation_7[3];          /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Saturation */
   bool Monoflop_7;                 /* Plant/Total Harmonic Distortion I3/Turn-on Delay/Monoflop */
   double Plant_i3[4];              /* Plant */
   double Plant_i4;                 /* Plant */
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
   double SinePWMReferenceVoltage[3]; /* Plant/Controller/Sine PWM/Sine PWM Reference Voltage */
   double p_wm;                     /* Plant/Squirrel-Cage IM/p*wm */
   double Gain;                     /* Plant/Controller/Sine PWM/Gain */
   double Switch[3];                /* Plant/Controller/Sine PWM/ PWM/Configurable Subsystem/Natural/Switch */
   double Gain_s1[3];               /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_s1 */
   double Sum_s1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_s1 */
   double Gain_r1[3];               /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_r1 */
   double Sum_r1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_r1 */
   double MovingAverage[3];         /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_1[3];       /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_2[3];       /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_1[3];                /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Gain */
   double MovingAverage_3[3];       /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1[3];                 /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Gain1 */
   double Gain2[3];                 /* Plant/Total Harmonic Distortion U/SampleTime Settings/continuous/Gain2 */
   double Constant1;                /* Plant/Total Harmonic Distortion U/Constant1 */
   bool Switch_1;                   /* Plant/Total Harmonic Distortion U/Switch */
   double MovingAverage_4[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_5[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_6[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_2[3];                /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Gain */
   double MovingAverage_7[3];       /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_1[3];               /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Gain1 */
   double Gain2_1[3];               /* Plant/Total Harmonic Distortion I/SampleTime Settings/continuous/Gain2 */
   double Constant1_1;              /* Plant/Total Harmonic Distortion I/Constant1 */
   bool Switch_2;                   /* Plant/Total Harmonic Distortion I/Switch */
   double MovingAverage_8[3];       /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_9[3];       /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_10[3];      /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_3[3];                /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain */
   double MovingAverage_11[3];      /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_2[3];               /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain1 */
   double Gain2_2[3];               /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain2 */
   double Constant1_2;              /* Plant/Total Harmonic Distortion U1/Constant1 */
   bool Switch_3;                   /* Plant/Total Harmonic Distortion U1/Switch */
   double MovingAverage_12[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_13[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_14[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_4[3];                /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain */
   double MovingAverage_15[3];      /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_3[3];               /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain1 */
   double Gain2_3[3];               /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain2 */
   double Constant1_3;              /* Plant/Total Harmonic Distortion I1/Constant1 */
   bool Switch_4;                   /* Plant/Total Harmonic Distortion I1/Switch */
   double MovingAverage_16[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_17[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_18[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_5[3];                /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain */
   double MovingAverage_19[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_4[3];               /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain1 */
   double Gain2_4[3];               /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain2 */
   double Constant1_4;              /* Plant/Total Harmonic Distortion U2/Constant1 */
   bool Switch_5;                   /* Plant/Total Harmonic Distortion U2/Switch */
   double MovingAverage_20[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_21[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_22[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_6[3];                /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain */
   double MovingAverage_23[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_5[3];               /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain1 */
   double Gain2_5[3];               /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain2 */
   double Constant1_5;              /* Plant/Total Harmonic Distortion I2/Constant1 */
   bool Switch_6;                   /* Plant/Total Harmonic Distortion I2/Switch */
   double MovingAverage_24[3];      /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_25[3];      /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_26[3];      /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_7[3];                /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Gain */
   double MovingAverage_27[3];      /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_6[3];               /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Gain1 */
   double Gain2_6[3];               /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Gain2 */
   double Constant1_6;              /* Plant/Total Harmonic Distortion U3/Constant1 */
   bool Switch_7;                   /* Plant/Total Harmonic Distortion U3/Switch */
   double MovingAverage_28[3];      /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_29[3];      /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_30[3];      /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_8[3];                /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Gain */
   double MovingAverage_31[3];      /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_7[3];               /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Gain1 */
   double Gain2_7[3];               /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Gain2 */
   double Constant1_7;              /* Plant/Total Harmonic Distortion I3/Constant1 */
   bool Switch_8;                   /* Plant/Total Harmonic Distortion I3/Switch */
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
   double Sine_6;                   /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Sine */
   double Cosine_6;                 /* Plant/Total Harmonic Distortion U3/SampleTime Settings/continuous/Cosine */
   double Sine_7;                   /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Sine */
   double Cosine_7;                 /* Plant/Total Harmonic Distortion I3/SampleTime Settings/continuous/Cosine */
   float PWM[4];                    /* Plant/PWM */
   bool Switch_9;                   /* Plant/Switch */
   double Switch_9_i1[4];           /* Plant/Switch */
} Plant_BlockOutputs;
extern Plant_BlockOutputs Plant_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Plant_NumExtModeSignals 66
extern const double * const Plant_ExtModeSignals[];
/* Tunable parameters */
#define Plant_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void Plant_initialize(double time);
void Plant_step(int task_id);
void Plant_terminate(void);
void Plant_sync(void);
#endif /* PLECS_HEADER_Plant_h_ */
