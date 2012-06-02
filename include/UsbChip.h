#ifndef USB_CHIP_H
#define USB_CHIP_H

#include "BaseChip.h"
#include "DynamicString.h"
#include "PcbPad.h"
#include "StdPackages.h"


class UsbChip: public BaseChip{
 public:
  UsbChip();
 private:
  char * buildChip(int pId);
};

#endif
