#include "GameDriver.h"
#include "UnoIODriver.h"

UnoIODriver uno_io_driver;
GameDriver simonsays(uno_io_driver);

void setup(){  
}

void loop(){
  simonsays.run();
}
