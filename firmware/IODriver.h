#ifndef IODRIVER_H_
#define IODRIVER_H_

#include "stdint.h"

/**
 * @class
 * @brief
*/
class IODriver{
  
  public:

    virtual void pin_setup();

    //assumes buttons are connected in resistor ladder as shown in the circuit schematic in the hardware folder
    virtual int read_button_input();

    // 0 <= x < 4
    virtual void LEDx_high(uint8_t x);
    virtual void LEDx_low(uint8_t x);

    virtual uint8_t rand_in_range(int min_inc, int max_exc);

    virtual void delay_ms(uint16_t ms);
};

#endif
