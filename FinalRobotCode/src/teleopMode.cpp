#include "vex.h"
#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"
#include "encoderDrive.cpp"



extern armLift lift;
extern rollerIntake gripper;
extern arcadeDrive driveTrain;
extern int matchLength;
extern encDrive encoderDrive;



class teleop{
public:

void runTeleop(){
  int currentFloor = 0;
  float targetHeight = currentFloor*4.92;
  bool floorSelecting = false;
  bool floorMode = false;
  while(true){
    //Drive
    driveTrain.driveController('L');

    //Gripper controls
    if(Controller1.ButtonR2.pressing()){
      gripper.runEject();
      // gripper.smartGripper("out");
    }
    else if(Controller1.ButtonR1.pressing()){
      gripper.runIntake();
      // gripper.smartGripper("In");
    }
    else{
      gripper.stopGripper();
    }

  //Arm floor controls

  //Set the current floor
  if(Controller1.ButtonL1.pressing()){
    floorMode = true;
    if(!floorSelecting && currentFloor < 4){
      floorSelecting = true;
      currentFloor++;
      targetHeight = currentFloor*4.92;
    }
  }
  else if(Controller1.ButtonL2.pressing()){
    floorMode = true;
    if(!floorSelecting && currentFloor > 0){
      floorSelecting = true;
      currentFloor--;
      targetHeight = currentFloor*4.92;
    }
  }
  
  else if(Controller1.ButtonRight.pressing()){
    floorMode = true;
    floorSelecting = false;
  }
  else{
    floorSelecting = false;
  }
  
  //Manual height control

  if(Controller1.ButtonUp.pressing()){
    floorMode = false;
    targetHeight+=.05;
    //currentFloor = targetHeight;
  }
  else if(Controller1.ButtonDown.pressing()){
    floorMode = false;
    targetHeight-=.05;
    //currentFloor = targetHeight;
  }

  if(currentFloor > 4){
    currentFloor = 4;
  }
  else if (currentFloor < 0){
    currentFloor = 0;
  }



  lift.armToHeight(targetHeight, false);//Set arm to current target height
  

  task::sleep(10);

  //End looped teleop code
  }
}
};
