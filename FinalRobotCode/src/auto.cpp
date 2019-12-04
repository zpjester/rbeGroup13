#include "vex.h"
#include "ArcadeDrive.cpp"
using namespace vex;


arcadeDrive autonomousDrive;

class auto1{
public:

void runAuto(){


  while(Brain.Timer.value()<30){
      //Main auto code goes here
    Brain.Screen.print(30-Brain.Timer.value());
    task::sleep(1000);

      
    }
  }
};