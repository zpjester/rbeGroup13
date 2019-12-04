#include "vex.h"

#include "ArcadeDrive.cpp"

using namespace vex;

extern arcadeDrive driveTrain;
extern int autoLength;

class auto1{
public:

void runAuto(){


  while(Brain.Timer.value()<autoLength){
      //Main auto code goes here
    Brain.Screen.print(30-Brain.Timer.value());
    task::sleep(1000);

      
    }
  }
};