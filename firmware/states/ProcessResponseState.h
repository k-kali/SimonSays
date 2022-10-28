#ifndef PROCESSRESPONSESTATE_H_
#define PROCESSRESPONSESTATE_H_

#include "GameState.h"
#include "IODriver.h"

class ProcessResponseState : public GameState {
    public:
        /*
      @breif
      @param button_input
      @return
    */
    GameState_e run(int difficulty_lvl) override;
};

#endif