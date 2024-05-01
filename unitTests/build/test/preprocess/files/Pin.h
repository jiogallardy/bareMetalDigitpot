#include "../Generic.h"










typedef enum {

  PinCSA

  ,

  PinCSB

  ,

  PinUDA

  ,

  PinUDB

  ,

  PinINCA

  ,

  PinINCB

  ,

  PinQuan

} PinT;

void PinWrite(PinT Pin, unsigned char Value);















void PinModuleInit(void);
