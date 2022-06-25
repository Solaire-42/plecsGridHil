/*
 * Header file for: hil/Plant
 * Generated with : PLECS 4.6.4
 *                  PLECS RT Box 2 2.2.2
 * Generated on   : 25 Jun 2022 09:41:00
 */
#ifndef PLECS_HEADER_Plant_h_
#define PLECS_HEADER_Plant_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef float Plant_FloatType;

/* Model checksum */
extern const char * const Plant_checksum;

/* Model error status */
extern const char * Plant_errorStatus;


/* Model sample time */
extern const float Plant_sampleTime[3][2];


/*
 * Model states */
typedef struct
{
   float Plant_PM0_x[9];            /* Plant */
   float Delay;                     /* Plant/coupling circuit5/Voltage Source/Delay */
   float Plant_PM1_x;               /* Plant */
   float Plant_PM2_x[33];           /* Plant */
   bool Plant_PM2_s[6];             /* Plant */
   bool Monoflop;                   /* Plant/Total Harmonic Distortion U1/Turn-on Delay/Monoflop */
   bool Monoflop_1;                 /* Plant/Total Harmonic Distortion I1/Turn-on Delay/Monoflop */
   bool Monoflop_2;                 /* Plant/Total Harmonic Distortion U2/Turn-on Delay/Monoflop */
   bool Monoflop_3;                 /* Plant/Total Harmonic Distortion I2/Turn-on Delay/Monoflop */
   bool Monoflop_4;                 /* Plant/Total Harmonic Distortion U4/Turn-on Delay/Monoflop */
   bool Monoflop_5;                 /* Plant/Total Harmonic Distortion I4/Turn-on Delay/Monoflop */
   float SODMeas_x;                 /* Plant/ESS 200 V 100 kWh/SOD meas */
   float SODMeas_1_x;               /* Plant/ESS 200 V 100 kWh1/SOD meas */
   float SODMeas_2_x;               /* Plant/ESS 200 V 100 kWh2/SOD meas */
   float SODMeas_3_x;               /* Plant/ESS 200 V 100 kWh3/SOD meas */
} Plant_ModelStates;
extern Plant_ModelStates Plant_X;


/* Block outputs */
typedef struct
{
   float Plant[18];                 /* Plant */
   float Plant_i1[12];              /* Plant */
   float Plant_i2[18];              /* Plant */
   float Saturation1[3];            /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Saturation1 */
   float Saturation[3];             /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Saturation */
   bool Monoflop;                   /* Plant/Total Harmonic Distortion U1/Turn-on Delay/Monoflop */
   float Saturation1_1[3];          /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Saturation1 */
   float Saturation_1[3];           /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Saturation */
   bool Monoflop_1;                 /* Plant/Total Harmonic Distortion I1/Turn-on Delay/Monoflop */
   float Saturation1_2[3];          /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Saturation1 */
   float Saturation_2[3];           /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Saturation */
   bool Monoflop_2;                 /* Plant/Total Harmonic Distortion U2/Turn-on Delay/Monoflop */
   float Saturation1_3[3];          /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Saturation1 */
   float Saturation_3[3];           /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Saturation */
   bool Monoflop_3;                 /* Plant/Total Harmonic Distortion I2/Turn-on Delay/Monoflop */
   float Saturation1_4[3];          /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Saturation1 */
   float Saturation_4[3];           /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Saturation */
   bool Monoflop_4;                 /* Plant/Total Harmonic Distortion U4/Turn-on Delay/Monoflop */
   float Saturation1_5[3];          /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Saturation1 */
   float Saturation_5[3];           /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Saturation */
   bool Monoflop_5;                 /* Plant/Total Harmonic Distortion I4/Turn-on Delay/Monoflop */
   float Plant_i3[7];               /* Plant */
   float Plant_i4;                  /* Plant */
   float Generator[3];              /* Plant/Generator */
   float TransportDelay;            /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s1/Configurable Subsystem/Non-zero delay/Transport Delay */
   float TransportDelay_1;          /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s2/Configurable Subsystem/Non-zero delay/Transport Delay */
   float TransportDelay_2;          /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_s3/Configurable Subsystem/Non-zero delay/Transport Delay */
   float TransportDelay_3;          /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay_r1/Configurable Subsystem/Non-zero delay/Transport Delay */
   float TransportDelay_4;          /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay1_r2/Configurable Subsystem/Non-zero delay/Transport Delay */
   float TransportDelay_5;          /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Transport Delay1_r3/Configurable Subsystem/Non-zero delay/Transport Delay */
   float Delay;                     /* Plant/coupling circuit5/Voltage Source/Delay */
   float Offset;                    /* Plant/VSI1/Sub-cycle average/HBa/Sub-cycle average/Offset */
   float Offset_1;                  /* Plant/VSI1/Sub-cycle average/HBb/Sub-cycle average/Offset */
   float Offset_2;                  /* Plant/VSI1/Sub-cycle average/HBc/Sub-cycle average/Offset */
   float p_wm;                      /* Plant/Squirrel-Cage IM/p*wm */
   float Sum;                       /* Plant/VSI1/Sub-cycle average/HBa/Sub-cycle average/Sum */
   float Sum_1;                     /* Plant/VSI1/Sub-cycle average/HBb/Sub-cycle average/Sum */
   float Sum_2;                     /* Plant/VSI1/Sub-cycle average/HBc/Sub-cycle average/Sum */
   float x_w_psirq;                 /* Plant/Squirrel-Cage IM/-w*psirq */
   float w_psird;                   /* Plant/Squirrel-Cage IM/w*psird */
   float Gain_s1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_s1 */
   float Sum_s1[3];                 /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_s1 */
   float Gain_r1[3];                /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Gain_r1 */
   float Sum_r1[3];                 /* Plant/NA2XS(FL)2Y 12/20 kV/Distributed Parameter Line/3-P-Line1/Sub/Sum_r1 */
   float MovingAverage[3];          /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average/Moving Average */
   float MovingAverage_1[3];        /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   float MovingAverage_2[3];        /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   float Gain[3];                   /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain */
   float MovingAverage_3[3];        /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   float Gain1[3];                  /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain1 */
   float Gain2[3];                  /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Gain2 */
   float Constant1;                 /* Plant/Total Harmonic Distortion U1/Constant1 */
   bool Switch;                     /* Plant/Total Harmonic Distortion U1/Switch */
   float MovingAverage_4[3];        /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average/Moving Average */
   float MovingAverage_5[3];        /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average1/Moving Average */
   float MovingAverage_6[3];        /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average2/Moving Average */
   float Gain_1[3];                 /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain */
   float MovingAverage_7[3];        /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Moving Average3/Moving Average */
   float Gain1_1[3];                /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain1 */
   float Gain2_1[3];                /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Gain2 */
   float Constant1_1;               /* Plant/Total Harmonic Distortion I1/Constant1 */
   bool Switch_1;                   /* Plant/Total Harmonic Distortion I1/Switch */
   float MovingAverage_8[3];        /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average/Moving Average */
   float MovingAverage_9[3];        /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   float MovingAverage_10[3];       /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   float Gain_2[3];                 /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain */
   float MovingAverage_11[3];       /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   float Gain1_2[3];                /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain1 */
   float Gain2_2[3];                /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Gain2 */
   float Constant1_2;               /* Plant/Total Harmonic Distortion U2/Constant1 */
   bool Switch_2;                   /* Plant/Total Harmonic Distortion U2/Switch */
   float MovingAverage_12[3];       /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average/Moving Average */
   float MovingAverage_13[3];       /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average1/Moving Average */
   float MovingAverage_14[3];       /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average2/Moving Average */
   float Gain_3[3];                 /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain */
   float MovingAverage_15[3];       /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Moving Average3/Moving Average */
   float Gain1_3[3];                /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain1 */
   float Gain2_3[3];                /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Gain2 */
   float Constant1_3;               /* Plant/Total Harmonic Distortion I2/Constant1 */
   bool Switch_3;                   /* Plant/Total Harmonic Distortion I2/Switch */
   float MovingAverage_16[3];       /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average/Moving Average */
   float MovingAverage_17[3];       /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average1/Moving Average */
   float MovingAverage_18[3];       /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average2/Moving Average */
   float Gain_4[3];                 /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Gain */
   float MovingAverage_19[3];       /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Moving Average3/Moving Average */
   float Gain1_4[3];                /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Gain1 */
   float Gain2_4[3];                /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Gain2 */
   float Constant1_4;               /* Plant/Total Harmonic Distortion U4/Constant1 */
   bool Switch_4;                   /* Plant/Total Harmonic Distortion U4/Switch */
   float MovingAverage_20[3];       /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average/Moving Average */
   float MovingAverage_21[3];       /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average1/Moving Average */
   float MovingAverage_22[3];       /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average2/Moving Average */
   float Gain_5[3];                 /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Gain */
   float MovingAverage_23[3];       /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Moving Average3/Moving Average */
   float Gain1_5[3];                /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Gain1 */
   float Gain2_5[3];                /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Gain2 */
   float Constant1_5;               /* Plant/Total Harmonic Distortion I4/Constant1 */
   bool Switch_5;                   /* Plant/Total Harmonic Distortion I4/Switch */
   float Sine;                      /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Sine */
   float Cosine;                    /* Plant/Total Harmonic Distortion U1/SampleTime Settings/continuous/Cosine */
   float Sine_1;                    /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Sine */
   float Cosine_1;                  /* Plant/Total Harmonic Distortion I1/SampleTime Settings/continuous/Cosine */
   float Sine_2;                    /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Sine */
   float Cosine_2;                  /* Plant/Total Harmonic Distortion U2/SampleTime Settings/continuous/Cosine */
   float Sine_3;                    /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Sine */
   float Cosine_3;                  /* Plant/Total Harmonic Distortion I2/SampleTime Settings/continuous/Cosine */
   float Sine_4;                    /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Sine */
   float Cosine_4;                  /* Plant/Total Harmonic Distortion U4/SampleTime Settings/continuous/Cosine */
   float Sine_5;                    /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Sine */
   float Cosine_5;                  /* Plant/Total Harmonic Distortion I4/SampleTime Settings/continuous/Cosine */
   float PWM[12];                   /* Plant/PWM */
   bool Switch1;                    /* Plant/Switch1 */
   float Switch1_i1[12];            /* Plant/Switch1 */
   float SODMeas;                   /* Plant/ESS 200 V 100 kWh/SOD meas */
   float As_mAh;                    /* Plant/ESS 200 V 100 kWh/As->mAh */
   float SODMeas_1;                 /* Plant/ESS 200 V 100 kWh1/SOD meas */
   float As_mAh_1;                  /* Plant/ESS 200 V 100 kWh1/As->mAh */
   float SODMeas_2;                 /* Plant/ESS 200 V 100 kWh2/SOD meas */
   float As_mAh_2;                  /* Plant/ESS 200 V 100 kWh2/As->mAh */
   float SODMeas_3;                 /* Plant/ESS 200 V 100 kWh3/SOD meas */
   float As_mAh_3;                  /* Plant/ESS 200 V 100 kWh3/As->mAh */
   float AdjustCurrentForParallelCellStr; /* Plant/ESS 200 V 100 kWh/Adjust Current for Parallel Cell Strings */
   float AdjustCurrentForParallelCellS_1; /* Plant/ESS 200 V 100 kWh1/Adjust Current for Parallel Cell Strings */
   float AdjustCurrentForParallelCellS_2; /* Plant/ESS 200 V 100 kWh2/Adjust Current for Parallel Cell Strings */
   float AdjustCurrentForParallelCellS_3; /* Plant/ESS 200 V 100 kWh3/Adjust Current for Parallel Cell Strings */
} Plant_BlockOutputs;
extern Plant_BlockOutputs Plant_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Plant_NumExtModeSignals 65
extern const float * const Plant_ExtModeSignals[];
/* Tunable parameters */
#define Plant_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void Plant_initialize(float time);
void Plant_step(int task_id);
void Plant_terminate(void);
void Plant_sync(void);
#endif /* PLECS_HEADER_Plant_h_ */
