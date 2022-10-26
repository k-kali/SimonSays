#include "GameDriver.h"

void GameDriver::run(){
  unsigned int button_input = IO.read_button_input();

  switch(state){
    case GameState::Idle:
      {//if button input - transition to simonsays
      IdleState idle;
      state = idle.run(button_input);
      }
      break;
      
    case GameState::ShowPattern:
//      ShowPatternState show_pattern;
//      state = show_pattern.run();
      break;
      //display "Level x - Simon Says..."
      //displayLEDPattern();
      // display "Level x - Your Turn!"
      
    case GameState::ProcessResponse:
//      ProcessResponseState process_respose;
//      state = process_response.run();
      break;
      //if button input - debounce(?) and check if correct
      //correct pattern - increment level #, transition to ShowPattern
      //incorrect button(s) - display "wrong pattern msg" for 3 seconds, transition to showResults (display results msg)
      //timeout - show timeout msg, transition to showResults (display results msg)
      
    case GameState::ShowResults:
//      ShowResultsState show_results;
//      state = show_results.run();
      break;
      //if button input - transition to Idle (display start msg)
    default:
      //error
      break;
  }
  
}
