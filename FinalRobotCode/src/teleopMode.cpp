//Include files and set up objects
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




void runTeleop(bool firstRun){//Run the teleop
//Setup variables
  int currentFloor = 0;
  int targetHeight = currentFloor*4.92;
  int floorSelecting = false;
  int floorMode = false;

  while(true){
    
    driveTrain.driveController('L');//Drive using the left stick in arcade drive mode

    //Gripper controls
    if(Controller1.ButtonR2.pressing()){//If lower right trigger pressed, eject pizza
      gripper.runEject();
      
    }
    else if(Controller1.ButtonR1.pressing()){//If upper right trigger pressed, intake pizza
      gripper.runIntake();
      
    }
    else{
      gripper.stopGripper();//Otherwise, stop the gripper motor
    }

  

  //Set the current floor based on controller inputs
  if(Controller1.ButtonL1.pressing()){//If left upper trigger is pressed
    floorMode = true;//Set arm to intelligent floor mode
    if(!floorSelecting && currentFloor < 4){//If able to increase floor safely
      floorSelecting = true;
      currentFloor++;//Increase the set floor
      targetHeight = currentFloor*4.92;//Change the height setpoint
    }
  }
  else if(Controller1.ButtonL2.pressing()){//If left lower trigger is pressed
    floorMode = true;//Set arm to intelligent floor mode
    if(!floorSelecting && currentFloor > 0){//If able to decrease floor safely
      floorSelecting = true;
      currentFloor--;//Decrease the set floor
      targetHeight = currentFloor*4.92;//Change the height setpoint
    }
  }
  
  else if(Controller1.ButtonRight.pressing()){//If in manual mode, the right arrow button sets it to intelligent floor mode
    floorMode = true;
    floorSelecting = false;
  }
  else{//If no intelligent floor inputs are active, reset the floorSelecting variable to allow inputs again
    floorSelecting = false;
  }
  
  //Manual height control

  if(Controller1.ButtonUp.pressing()){//Up arrow moves setpoint up
    floorMode = false;
    targetHeight+=.05;
    
  }
  else if(Controller1.ButtonDown.pressing()){//Down arrow moves setpoint down
    floorMode = false;
    targetHeight-=.05;
    
  }

  if(currentFloor > 4){//Prevent invalid heights (outside of arm limits)
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
