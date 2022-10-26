#ifndef GAMEDRIVER_H_
#define GAMEDRIVER_H_

#include "IdleState.h"
//#include "ShowPatternState.h"
//#include "ProcessResponseState.h"
//#include "DisplayResultsState.h"
#include "IODriver.h"

class GameDriver {

  GameState::GameState_e state;
  IODriver& IO;

  public:

    GameDriver(IODriver& _IO):
      IO(_IO)
    {
      state = GameState::Idle;
      {IdleState idle;
      idle.displayMsg();}
      IO.pin_setup();
    }

    void run();
  
};

#endif
