/*
 * Header file for: hil/Plant
 * Generated with : PLECS 4.6.4
 *                  PLECS RT Box 2 2.2.2
 * Generated on   : 17 Jun 2022 16:25:24
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
   double SODMeas_x;                /* Plant/ESS 200 V 100 kWh/SOD meas */
   double SODMeas_1_x;              /* Plant/ESS 200 V 100 kWh1/SOD meas */
   double SODMeas_2_x;              /* Plant/ESS 200 V 100 kWh2/SOD meas */
   double SODMeas_3_x;              /* Plant/ESS 200 V 100 kWh3/SOD meas */
   double Plant_PM1_x;              /* Plant */
   double Plant_PM2_x[33];          /* Plant */
   bool Plant_PM2_s[6];             /* Plant */
   bool Monoflop;                   /* Plant/Total Harmonic Distortion U1/Turn-on Delay/Monoflop */
   bool Monoflop_1;                 /* Plant/Total Harmonic Distortion I1/Turn-on Delay/Monoflop */
   bool Monoflop_2;                 /* Plant/Total Harmonic Distortion U2/Turn-on Delay/Monoflop */
   bool Monoflop_3;                 /* Plant/Total Harmonic Distortion I2/Turn-on Delay/Monoflop */
   bool Monoflop_4;                 /* Plant/Total Harmonic Distortion U4/Turn-on Delay/Monoflop */
   bool Monoflop_5;                 /* Plant/Total Harmonic Distortion I4/Turn-on Delay/Monoflop */
} Plant_ModelStates;
extern Plant_ModelStates Plant_X;


/* Block outputs */
typedef struct
{
   double Plant[18];                /* Plant */
   bool Plant_i1[6];                /* Plant */
   double Plant_i2[18];             /* Plant */
   double Saturation1[3];           /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Saturation1 */
   double Saturation[3];            /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Saturation */
   bool Monoflop;                   /* Plant/Total Harmonic Distortion U1/Turn-on Delay/Monoflop */
   double Saturation1_1[3];         /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Saturation1 */
   double Saturation_1[3];          /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Saturation */
   bool Monoflop_1;                 /* Plant/Total Harmonic Distortion I1/Turn-on Delay/Monoflop */
   double Saturation1_2[3];         /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Saturation1 */
   double Saturation_2[3];          /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Saturation */
   bool Monoflop_2;                 /* Plant/Total Harmonic Distortion U2/Turn-on Delay/Monoflop */
   double Saturation1_3[3];         /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Saturation1 */
   double Saturation_3[3];          /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Saturation */
   bool Monoflop_3;                 /* Plant/Total Harmonic Distortion I2/Turn-on Delay/Monoflop */
   double Saturation1_4[3];         /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Saturation1 */
   double Saturation_4[3];          /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Saturation */
   bool Monoflop_4;                 /* Plant/Total Harmonic Distortion U4/Turn-on Delay/Monoflop */
   double Saturation1_5[3];         /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Saturation1 */
   double Saturation_5[3];          /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Saturation */
   bool Monoflop_5;                 /* Plant/Total Harmonic Distortion I4/Turn-on Delay/Monoflop */
   double Plant_i3[7];              /* Plant */
   double Plant_i4;                 /* Plant */
   double Generator[3];             /* Plant/Generator */
   double TransportDelay;           /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s1/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_1;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s2/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_2;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s3/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_3;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_r1/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_4;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay1_r2/Configurable Subsystem/Non-zero delay/Transport Delay */
   double TransportDelay_5;         /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay1_r3/Configurable Subsystem/Non-zero delay/Transport Delay */
   double SODMeas;                  /* Plant/ESS 200 V 100 kWh/SOD meas */
   double As_mAh;                   /* Plant/ESS 200 V 100 kWh/As->mAh */
   double SODMeas_1;                /* Plant/ESS 200 V 100 kWh1/SOD meas */
   double SODMeas_2;                /* Plant/ESS 200 V 100 kWh2/SOD meas */
   double SODMeas_3;                /* Plant/ESS 200 V 100 kWh3/SOD meas */
   double p_wm;                     /* Plant/Squirrel-Cage IM/p*wm */
   double x_w_psirq;                /* Plant/Squirrel-Cage IM/-w*psirq */
   double w_psird;                  /* Plant/Squirrel-Cage IM/w*psird */
   double SoD_mAh_SoC_;             /* Plant/ESS 200 V 100 kWh/SoD(mAh)->SoC(%) */
   double Gain_s1[3];               /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_s1 */
   double Sum_s1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_s1 */
   double Gain_r1[3];               /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_r1 */
   double Sum_r1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_r1 */
   double AdjustCurrentForParallelCellStr; /* Plant/ESS 200 V 100 kWh/Adjust Current for Parallel Cell Strings */
   double AdjustCurrentForParallelCellS_1; /* Plant/ESS 200 V 100 kWh1/Adjust Current for Parallel Cell Strings */
   double AdjustCurrentForParallelCellS_2; /* Plant/ESS 200 V 100 kWh2/Adjust Current for Parallel Cell Strings */
   double AdjustCurrentForParallelCellS_3; /* Plant/ESS 200 V 100 kWh3/Adjust Current for Parallel Cell Strings */
   double MovingAverage[3];         /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_1[3];       /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_2[3];       /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain[3];                  /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain */
   double MovingAverage_3[3];       /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1[3];                 /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain1 */
   double Gain2[3];                 /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain2 */
   double Constant1;                /* Plant/Total Harmonic Distortion U1/Constant1 */
   bool Switch;                     /* Plant/Total Harmonic Distortion U1/Switch */
   double MovingAverage_4[3];       /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_5[3];       /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_6[3];       /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_1[3];                /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain */
   double MovingAverage_7[3];       /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_1[3];               /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain1 */
   double Gain2_1[3];               /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain2 */
   double Constant1_1;              /* Plant/Total Harmonic Distortion I1/Constant1 */
   bool Switch_1;                   /* Plant/Total Harmonic Distortion I1/Switch */
   double MovingAverage_8[3];       /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_9[3];       /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_10[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_2[3];                /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain */
   double MovingAverage_11[3];      /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_2[3];               /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain1 */
   double Gain2_2[3];               /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain2 */
   double Constant1_2;              /* Plant/Total Harmonic Distortion U2/Constant1 */
   bool Switch_2;                   /* Plant/Total Harmonic Distortion U2/Switch */
   double MovingAverage_12[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_13[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_14[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_3[3];                /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain */
   double MovingAverage_15[3];      /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_3[3];               /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain1 */
   double Gain2_3[3];               /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain2 */
   double Constant1_3;              /* Plant/Total Harmonic Distortion I2/Constant1 */
   bool Switch_3;                   /* Plant/Total Harmonic Distortion I2/Switch */
   double MovingAverage_16[3];      /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_17[3];      /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_18[3];      /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_4[3];                /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Gain */
   double MovingAverage_19[3];      /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_4[3];               /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Gain1 */
   double Gain2_4[3];               /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Gain2 */
   double Constant1_4;              /* Plant/Total Harmonic Distortion U4/Constant1 */
   bool Switch_4;                   /* Plant/Total Harmonic Distortion U4/Switch */
   double MovingAverage_20[3];      /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average/Moving Average */
   double MovingAverage_21[3];      /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average1/Moving Average */
   double MovingAverage_22[3];      /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average2/Moving Average */
   double Gain_5[3];                /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Gain */
   double MovingAverage_23[3];      /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average3/Moving Average */
   double Gain1_5[3];               /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Gain1 */
   double Gain2_5[3];               /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Gain2 */
   double Constant1_5;              /* Plant/Total Harmonic Distortion I4/Constant1 */
   bool Switch_5;                   /* Plant/Total Harmonic Distortion I4/Switch */
   double Sine;                     /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Sine */
   double Cosine;                   /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Cosine */
   double Sine_1;                   /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Sine */
   double Cosine_1;                 /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Cosine */
   double Sine_2;                   /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Sine */
   double Cosine_2;                 /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Cosine */
   double Sine_3;                   /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Sine */
   double Cosine_3;                 /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Cosine */
   double Sine_4;                   /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Sine */
   double Cosine_4;                 /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Cosine */
   double Sine_5;                   /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Sine */
   double Cosine_5;                 /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Cosine */
   float PWM[12];                   /* Plant/PWM */
   bool Switch1;                    /* Plant/Switch1 */
} Plant_BlockOutputs;
extern Plant_BlockOutputs Plant_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Plant_NumExtModeSignals 56
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
