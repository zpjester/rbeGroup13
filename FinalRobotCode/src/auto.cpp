#include "vex.h"

#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"
#include "encoderDrive.cpp"


extern armLift lift;
extern rollerIntake gripper;
extern arcadeDrive driveTrain;
extern encDrive encoderDrive;

extern int autoLength;

class auto1{
public:

void runAuto(){
//Main auto code goes here


    

lift.armToFloor(1, true);
task::sleep(1000);
lift.armToFloor(2, true);
task::sleep(1000);
lift.armToFloor(3, true);
task::sleep(1000);
lift.armToFloor(4, true);
task::sleep(1000);
lift.armToFloor(5, true);
gripper.fullSmartGripper("Out");
task::sleep(1000);

Brain.Screen.clearScreen();
Brain.Screen.setCursor(0,0);
Brain.Screen.print("Driving backwards 10 inches");
encoderDrive.driveDistance(-10, true);
Brain.Screen.clearScreen();
Brain.Screen.setCursor(0,0);
task::sleep(1000);
Brain.Screen.print("Driving forwards 10 inches");
encoderDrive.driveDistance(10, true);
Brain.Screen.clearScreen();


  while(Brain.Timer.value()<autoLength){
      
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(0,0);
    Brain.Screen.print(autoLength-Brain.Timer.value());
    task::sleep(1000);

      
    }
    Brain.Screen.print("Auto Ended");
  }
};