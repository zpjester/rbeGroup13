#include "vex.h"

#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"



extern armLift lift;
extern rollerIntake gripper;
extern arcadeDrive driveTrain;

extern int autoLength;

class auto1{
public:

void runAuto(){


  while(Brain.Timer.value()<autoLength){
      //Main auto code goes here
    Brain.Screen.clearScreen();

    Brain.Screen.print(autoLength-Brain.Timer.value());
    task::sleep(1000);

      
    }
    Brain.Screen.print("Auto Ended");
  }
};