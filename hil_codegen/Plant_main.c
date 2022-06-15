#include "plexim/HIL_Framework.h"
#include "plexim/ScopeBuffer.h"
#include "plexim/hw_wrapper.h"
#include <math.h>
#include "Plant.h"

#define MODEL_PREFIX Plant
#define MODEL_NAME "Plant"
#define CONCAT_(a, b) a ## b
#define CONCAT(a, b) CONCAT_(a, b)
#define MODEL_FLOAT_TYPE CONCAT(MODEL_PREFIX, _FloatType)
#define MODEL_SAMPLE_TIME CONCAT(MODEL_PREFIX, _sampleTime)
#define MODEL_STEP CONCAT(MODEL_PREFIX, _step)
#define MODEL_SYNC CONCAT(MODEL_PREFIX, _sync)
#define MODEL_ERROR_STATUS CONCAT(MODEL_PREFIX, _errorStatus)
#define MODEL_CHECKSUM CONCAT(MODEL_PREFIX, _checksum)
#define MODEL_INITIALIZE CONCAT(MODEL_PREFIX, _initialize)
#define MODEL_TERMINATE CONCAT(MODEL_PREFIX, _terminate)

#define min(a, b) ((a) < (b)) ? a : b
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

#define MULTITASKING 1

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
#define MODEL_NUM_EXT_MODE_SIGNALS CONCAT(MODEL_PREFIX, _NumExtModeSignals)
#define MODEL_EXT_MODE_SIGNALS CONCAT(MODEL_PREFIX, _ExtModeSignals)
#define MODEL_NUM_TUNABLE_PARAMETERS CONCAT(MODEL_PREFIX, _NumTunableParameters)
#define MODEL_TUNABLE_PARAMETERS CONCAT(MODEL_PREFIX, _P)

#pragma pack(push, 4)

struct ArmResponse
{
   int msg;
   int mMsgLength;
   int mTransactionId;
   int mLength;
   float mSampleTime;
   int mBufferIndex;
   int mOffset;
   int mNumActiveSignals;
   unsigned short mActiveSignals[MODEL_NUM_EXT_MODE_SIGNALS];
};

struct TriggerInfo
{
   int mTransactionId;
   int mLength;
   int mEdge; 
   float mTriggerValue;
   int mTriggerChannel;
   int mDecimation;
   int mTriggerDelay;
   int mNumActiveSignals;
   unsigned short mActiveSignals[MODEL_NUM_EXT_MODE_SIGNALS];
   const MODEL_FLOAT_TYPE* mTriggerChannelValue;
   const MODEL_FLOAT_TYPE* mActiveSignalValues[MODEL_NUM_EXT_MODE_SIGNALS];
};

#pragma pack(pop)

static volatile struct TriggerInfo mTriggerInfo;

static void initializeScopeTrigger()
{
   if (mTriggerInfo.mTriggerChannel >= 0)
      mTriggerInfo.mTriggerChannelValue = MODEL_EXT_MODE_SIGNALS[mTriggerInfo.mTriggerChannel];
   else
      mTriggerInfo.mTriggerChannelValue = MODEL_EXT_MODE_SIGNALS[0];
   int i=0;
   for (i=0; i<mTriggerInfo.mNumActiveSignals; i++)
   {
      int signalIdx = min(mTriggerInfo.mActiveSignals[i], MODEL_NUM_EXT_MODE_SIGNALS-1);
      mTriggerInfo.mActiveSignalValues[i] = MODEL_EXT_MODE_SIGNALS[signalIdx];
   }
}

static void checkScopeTrigger()
{
   static float lastTriggerSignal = 0;
   static int decimationCounter = 1;

   if (scopeArmed)
   {
      float triggerSignal = *mTriggerInfo.mTriggerChannelValue;
      decimationCounter--;
      if (!decimationCounter)
      {
         struct ScopeBuffer* currentBufferPtr = &plxScopeBuffer[plxCurrentWriteBuffer];
         int i=0;
         for (; i < mTriggerInfo.mNumActiveSignals; i++)
         {
            addToScopeBuffer(currentBufferPtr, *mTriggerInfo.mActiveSignalValues[i]);
         }
         if (!scopeTriggered && getScopeBufferNumValidElements(currentBufferPtr) * mTriggerInfo.mDecimation > -mTriggerInfo.mTriggerDelay * mTriggerInfo.mNumActiveSignals )
         {
            if (mTriggerInfo.mEdge == 0 && lastTriggerSignal < mTriggerInfo.mTriggerValue && triggerSignal >= mTriggerInfo.mTriggerValue) scopeTriggered = TRUE;
            else if (mTriggerInfo.mEdge == 1 && lastTriggerSignal > mTriggerInfo.mTriggerValue && triggerSignal <= mTriggerInfo.mTriggerValue) scopeTriggered = TRUE;
            if (scopeTriggered)
               setScopeBufferNumValidElements(currentBufferPtr, (-mTriggerInfo.mTriggerDelay / mTriggerInfo.mDecimation + 1) * mTriggerInfo.mNumActiveSignals);
         }
         lastTriggerSignal = triggerSignal;
         if (scopeTriggered)
         {
            if (getScopeBufferNumValidElements(currentBufferPtr) >= getScopeBufferSize(currentBufferPtr))
            {
               scopeArmed = FALSE;
               setScopeBufferFull(currentBufferPtr, TRUE);
               scopeTriggered = FALSE;
               plxCurrentWriteBuffer = !plxCurrentWriteBuffer;
            }
         }
         decimationCounter = mTriggerInfo.mDecimation;
      }
   }
   else
   {
      lastTriggerSignal = NAN;
   }
}

static void copyTunableParameters(const double* aData) { (void)aData; }

#else
void initializeScopeTrigger() {}
void copyTunableParameters(const double* aData) { (void)aData; }
#define checkScopeTrigger()
#endif /* defined(EXTERNAL_MODE) */

const char* plxGetModelName()
{
   static const char* modelName = MODEL_NAME;
   return modelName;
}

const char* plxGetA2l() 
{ 
   return "";
}



int plxPlatform_poll();
static void modelInitFunction()
{
   MODEL_INITIALIZE(0);
   postInitCode();
   // Run step functions a few times to have code in cache
   for (int i=0; i<10; i++)
   {
      if (!plxErrorFlag)
      {
         MODEL_STEP(0);
         plxPlatform_poll();
         plxMulticoreSyncedStep();
      }
   }
   if (!plxErrorFlag)
   {
      MODEL_TERMINATE();
   }
   MODEL_INITIALIZE(0);
   postInitCode();
}


static void modelSyncFunction()
{
   MODEL_SYNC();
}



void modelStepFunction0()
{
   /* Execute base task. */
   MODEL_STEP(0);
   if(unlikely((size_t)MODEL_ERROR_STATUS))
   {
      plxStopTimer();
      plxUserMessage(PLXUSERMSG_NEEDS_ATTENTION, "%s\n", MODEL_ERROR_STATUS);
      plxErrorFlag = 1;

      plxWaitForIrqAck();

   }
   if (unlikely(plxErrorFlag))
      return;
   
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
   checkScopeTrigger();
#endif /* defined(EXTERNAL_MODE) */

}

void modelStepFunction1()
{
   MODEL_STEP(1);
}

void modelStepFunction2()
{
   MODEL_STEP(2);
}

void plxXcpRegisterExtModeSignals(
   const void* const* aSignals,
   uint32_t aNumSignals,
   void* aParameters,
   uint32_t aNumParameters);

void plxStartup(void)
{
   int useExternalMode = 0;
   int numExtModeSignals = 0;
   void* tunableParameterValues = NULL;
   int numTunableParameters = 0;
   struct PlxTriggerInfo* trigger = NULL;
   struct PlxArmResponse* armResponse = NULL;
   struct PlxModelFunctions modelFunctions = 
   {
      .init = &modelInitFunction,
      .sync = &modelSyncFunction,
      .step = &modelStepFunction0,
      .step1 = &modelStepFunction1,
      .step2 = &modelStepFunction2,
      .terminate = &MODEL_TERMINATE,
      .initializeScopeTrigger = &initializeScopeTrigger,
      .copyTunableParams = &copyTunableParameters
   };
   struct PlxCoreTiming coreTiming = 
   {
      .mCore1Tick = 0,
      .mCore1Period = 1,
      .mCore2Tick = 0,
      .mCore2Period = 10
   };
   
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
   useExternalMode = 1;
   numExtModeSignals = MODEL_NUM_EXT_MODE_SIGNALS;
   memset((void*)&mTriggerInfo, 0, sizeof(struct PlxTriggerInfo));
   trigger = (struct PlxTriggerInfo*)&mTriggerInfo;
   static struct ArmResponse armResponseInst;
   armResponse = (struct PlxArmResponse*)&armResponseInst;
#if (MODEL_NUM_TUNABLE_PARAMETERS > 0)
   numTunableParameters = MODEL_NUM_TUNABLE_PARAMETERS;
   tunableParameterValues = &MODEL_TUNABLE_PARAMETERS;
#endif
   plxXcpRegisterExtModeSignals(
      (const void* const*)MODEL_EXT_MODE_SIGNALS,
      MODEL_NUM_EXT_MODE_SIGNALS,
      tunableParameterValues,
      MODEL_NUM_TUNABLE_PARAMETERS
   );
#endif
   plxRegisterStandaloneBackgroundTask();
#if defined(MULTITASKING) && MULTITASKING
   double sampleTime = MODEL_SAMPLE_TIME[0][0];
#else
   double sampleTime = MODEL_SAMPLE_TIME;
#endif

   plxStartSimulationModel(sampleTime, sizeof(MODEL_FLOAT_TYPE),
                           useExternalMode, numExtModeSignals, numTunableParameters,
                           trigger, armResponse, MODEL_CHECKSUM, MODEL_NAME,
                           &modelFunctions, &coreTiming, 1,
                           1);
}
