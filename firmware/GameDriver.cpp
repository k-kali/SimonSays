#include "GameDriver.h"

/**
 * 
*/
void GameDriver::run(){
  unsigned int button_input = IO.read_button_input();

  switch(state){
    case GameState::Idle:
      idle.run(button_input);
      break;
      
    case GameState::ShowPattern:
      state = show_pattern.run(curr_lvl);
      break;
      
    case GameState::ProcessResponse:
//      state = process_response.run();
      break;
      //if button input - debounce(?) and check if correct
      //correct pattern - increment level #, transition to ShowPattern
      //incorrect button(s) - display "wrong pattern msg" for 3 seconds, transition to showResults (display results msg)
      //timeout - show timeout msg, transition to showResults (display results msg)
      
    case GameState::ShowResults:
//      state = show_results.run();
      break;
      //if button input - transition to Idle (display start msg)
    default:
      //error
      break;
  }
  
}
