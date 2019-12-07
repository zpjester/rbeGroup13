#include "vex.h"
#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"



extern armLift lift;
extern rollerIntake gripper;
extern arcadeDrive driveTrain;
extern int matchLength;




class teleop{
public:

void runTeleop(){
  while(true){

    driveTrain.driveController('L');
    //Brain.Screen.print("testing");
    task::sleep(20);      
  
  }
}
};
