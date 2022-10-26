#ifndef UNOIODRIVER_H_
#define UNOIODRIVER_H_

#include <Arduino.h>
#include "IODriver.h"

class UnoIODriver : public IODriver{
 
  int analog_in_buttons = A0;
  int LED_outs[4] = {3,4,5,6};
  
public: 

  /**
  * @brief Initialize pin type.
  */
    void pin_setup() override {
      pinMode(analog_in_buttons, INPUT);
      for(int i = 0; i < 4; i++) pinMode(LED_outs[i], OUTPUT);    
    }

    //analog inpit has 10 bit resolution for Uno board
    int read_button_input() override {
      return analogRead(analog_in_buttons);
    }

    void flash_LEDx(int x) override{
      digitalWrite(x, HIGH);
      delay(500);
      digitalWrite(x, LOW);
    }
};

#endif
