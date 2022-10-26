#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include "GameState.h"

class IdleState : public GameState {

  public:
    IdleState(){}
  
    GameState_e run(int button_input) override {
      if(button_input){ //might need to raise the limit for what counts as "not pressed"
        return ShowPattern;
      }
      return Idle;
    }

    void displayMsg(){}
  
};

#endif
