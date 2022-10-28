#ifndef GAMEDRIVER_H_
#define GAMEDRIVER_H_

#include "IdleState.h"
#include "ShowPatternState.h"
#include "ProcessResponseState.h"
//#include "DisplayResultsState.h"
#include "IODriver.h"

class GameDriver {

  IdleState idle;
  ShowPatternState show_pattern;
  ProcessResponseState process_respose;
  //      ShowResultsState show_results;
  GameState::GameState_e state_e;
  GameState* state;
  IODriver& IO;                 //
  uint8_t curr_lvl = 0;

  public:

    GameDriver(IODriver& _IO):
      IO(_IO),
      show_pattern(_IO)
    {
      state_e = GameState::Idle;
      idle.displayMsg();
      IO.pin_setup();
    }

    void run();

    void set_state(GameState* next_state, GameState::GameState_e next_state_e){
      if(state_e != next_state_e){
        state = next_state;
        state_e = next_state_e;
      }
    }
  
};

#endif
