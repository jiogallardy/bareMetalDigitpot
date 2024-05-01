/*******************************************************************************/
//	Pin.h
/*******************************************************************************/
#ifndef PinIncluded
#define PinIncluded
/*******************************************************************************/

/*******************************************************************************/
//	includes
/*******************************************************************************/

#include "Generic.h"

/*******************************************************************************/
//	types
/*******************************************************************************/

typedef enum {
  PinCSA //	pin 1 on MAX5389
  ,
  PinCSB //	pin 14 on MAX5389
  ,
  PinUDA //	pin 2 on MAX5389
  ,
  PinUDB //	pin 3 on MAX5389
  ,
  PinINCA //	pin 13 on MAX5389
  ,
  PinINCB //	pin 12 on MAX5389
  ,
  PinQuan //  quantity of supported pins
} PinT;

/*******************************************************************************/
//	variables
/*******************************************************************************/

/*******************************************************************************/
//	macros
/*******************************************************************************/

/*******************************************************************************/
//	service functions
/*******************************************************************************/

/*******************************************************************************/
//	write to a pad that is configured as a GPIO output
void PinWrite(PinT Pin, bool Value);
/******************************************************************************/
//	administrative functions
/******************************************************************************/

/******************************************************************************/
//	initialize the overall module (call before using any of the above
// functions)
void PinModuleInit(void);

/*******************************************************************************/
#endif //  PinIncluded
/*******************************************************************************/
//  end of Pin.h
/*******************************************************************************/
