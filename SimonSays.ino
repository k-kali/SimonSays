#include <SimonSays_lib.h>
#include "src\firmware\GameDriver.h"
#include "UnoIODriver.h"
#include <time.h>

UnoIODriver uno_io_driver;
GameDriver simonsays(uno_io_driver);

void setup(){  
  randomSeed(time(0));
}

void loop(){
  simonsays.run();
}
