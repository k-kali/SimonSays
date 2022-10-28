#include "GameDriver.h"

/**
 * 
*/
void GameDriver::run(){
      GameState::GameState_e next_state = state->run(IO.read_button_input());
      switch(next_state){
            case GameState::Idle:
                  set_state(&idle, next_state);
                  break;
            case GameState::ShowPattern:
                  set_state(&show_pattern, next_state);
                  break;
            case GameState::ProcessResponse:
                  set_state(&idle, next_state);
                  break;
      }
}
