#ifndef SHOWPATTERNSTATE_H_
#define SHOWPATTERNSTATE_H_

#include "GameState.h"
#include "..\IODriver.h"

#define DEFAULT_PATTERN_LEN 3
#define FLASH_DELAY_mS      100

class ShowPatternState : public GameState {

  IODriver& device_driver;

  public:

    ShowPatternState(IODriver& _device_driver):
      device_driver(_device_driver)
    {}

    /*
      @breif
      @param button_input
      @return
    */
    GameState_e run(int difficulty_lvl) override {

      //display "Level x - Simon Says..." on LCD

      displayLEDPattern(difficulty_lvl);

      //display "Level x - Your Turn!" on LCD

      return ProcessResponse;
    }

  private:

    //should this be inlined? probably not, is big / uses loop so overhead for function call probably not significant in comparison
    void displayLEDPattern(uint8_t lvl) {
      int dual_LED_flashes = 0;
      uint8_t pattern_len = DEFAULT_PATTERN_LEN + lvl;
      
      for (int i = 0; i < pattern_len; i++) {
        //randomly select dual or single LED flash. Number of dual LED flashes in pattern must be <= pattern length / 2 
         bool is_dual = 0;
         if(dual_LED_flashes <= (pattern_len >> 1)) is_dual = device_driver.rand_in_range(0,2);

         //randomly select which LED(s) to flash
         uint8_t LED1 = device_driver.rand_in_range(0,4);
         uint8_t LED2 = LED1;
         if (is_dual) {
           //randomly select a 2nd LED that is not same as 1st LED
           while(LED2 == LED1) LED2 = device_driver.rand_in_range(0,4);
           dual_LED_flashes++;

         //drive selected LED(s) high
           device_driver.LEDx_high(LED2);
         }
         device_driver.LEDx_high(LED1);

         //allow LEDs to remain lighted for specified time
         device_driver.delay_ms(FLASH_DELAY_mS);

         //drive selected LED(s) back to low
         device_driver.LEDx_low(LED1);
         if(is_dual) device_driver.LEDx_low(LED2);

         //ensure specified time in between LED flashes
         device_driver.delay_ms(FLASH_DELAY_mS);
      }
    }

    

};

#endif
