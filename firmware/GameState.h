#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameState {

  public:

    typedef enum{
      Idle = 0b00,
      ShowPattern = 0b01,
      ProcessResponse = 0b10,
      ShowResults = 0b11
    }GameState_e;

    virtual GameState_e run(int button_input);
  
};

#endif
