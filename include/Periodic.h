/******************************************************************************/
//	Periodic.h
/******************************************************************************/
#ifndef PeriodicIncluded
#define PeriodicIncluded
/******************************************************************************/

/******************************************************************************/
//	includes
/******************************************************************************/

#include "Generic.h"

/******************************************************************************/
//	types
/******************************************************************************/

//	interrupt handler type
typedef void (*PeriodicHandlerT)(void);

typedef struct {
    s8 status;
    bool on_time;
} MeasureResult;

/******************************************************************************/
//	variables
/******************************************************************************/

/******************************************************************************/
//	macros
/******************************************************************************/
#define SysTick_CTRL_ENABLE_Msk      0x00000001
#define SysTick_CTRL_TICKINT_Msk     0x00000002
#define SysTick_CTRL_CLKSOURCE_Msk   0x00000004
/******************************************************************************/
//	service functions
/******************************************************************************/

/******************************************************************************/
//	configure a channel
/*
        - channel rollover frequency will be set to closest possible match to
   Freq parameter
        - if Handler is null, rollover interrupt will not be enabled under any
   circumstances
        - Handler is registered directly with the interrupt controller.	- upon
   return from configuration, channel will be in the Stopped and IruptDisabled
   states
*/
#define PeriodicFreqHzMax ((f32)1000000)

//	set the rollover frequency and assign an interrupt handler
void PeriodicConfig(f32 FreqHz, PeriodicHandlerT Handler);

/******************************************************************************/
//	start the channel's counting from zero
void PeriodicStart(void);

/******************************************************************************/
//	stop the channel's counting
void PeriodicStop(void);

/******************************************************************************/
//	enable the channel's rollover interrupt
void PeriodicIruptEnable(void);

/******************************************************************************/
//	disable the channel's rollover interrupt
void PeriodicIruptDisable(void);

/******************************************************************************/
//	dismiss the channel's rollover interrupt flag
void PeriodicIruptFlagClear(void);

/******************************************************************************/
//	administrative functions
/******************************************************************************/

/******************************************************************************/
//	initialize the overall module, call before using any of the above
// functions
void PeriodicModuleInit(void);

void ExecuteAndMeasure(void (*operation)(void), u32 time_limit);

/******************************************************************************/
#endif //  PeriodicIncluded
/******************************************************************************/
//  end of Periodic.h
/******************************************************************************/
