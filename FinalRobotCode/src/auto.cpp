#include "vex.h"

#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"
#include "encoderDrive.cpp"

extern brain Brain;
extern armLift lift;
extern rollerIntake gripper;
extern arcadeDrive driveTrain;
extern encDrive encoderDrive;

extern int autoLength;

class auto1{
public:

void runAuto(){
//Main auto code goes here


    
gripper.fullSmartGripper("In");
// Brain.Screen.clearScreen();
// Brain.Screen.setCursor(0,0);
// Brain.Screen.print("Yeet");
//lift.armToAngle(0, true);

lift.armToFloor(1, true);
lift.armToFloor(0, true);
lift.armToFloor(2, true);
lift.armToFloor(0, true);
lift.armToFloor(3, true);
lift.armToFloor(0, true);
lift.armToFloor(4, true);
gripper.fullSmartGripper("Out");
lift.armToFloor(1,true);






Brain.Screen.clearScreen();
Brain.Screen.setCursor(0,0);
Brain.Screen.print("Driving backwards 10 inches");
encoderDrive.driveDistance(-10, true);
Brain.Screen.clearScreen();
Brain.Screen.setCursor(0,0);

Brain.Screen.print("Driving forwards 10 inches");
encoderDrive.driveDistance(10, true);
Brain.Screen.clearScreen();
//while(true){}

  // while(Brain.Timer.value()<autoLength){
      
  //   Brain.Screen.clearScreen();
  //   Brain.Screen.setCursor(0,0);
  //   Brain.Screen.print(autoLength-Brain.Timer.value());
  //   task::sleep(1000);

      
  //   }
  //   Brain.Screen.print("Auto Ended");
  }
};