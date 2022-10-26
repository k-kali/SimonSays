#include "GameState.h"

void setup(){
  //pin mux
  //led pins
  //button pins/pin?
  //p pin?
  
}

void loop(){
  enum{
    Idle = 0b00,
    SimonSays = 0b01,
    PlayerResponds = 0b10,
    ShowResults = 0b11
  } GameState;

  Gamestate state = Idle;

  switch(state){
    case Idle:

    case SimonSays:

    case PlayerResponds:

    case ShowResults:

    default:
  }
}
