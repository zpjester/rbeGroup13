// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         17              
// Arm_B                motor         18              
// Gripper_M            motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"
#include "declarations.h"
#include "matchParameters.h"
#include "auto.cpp"
#include "teleopMode.cpp"
#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"
#include "encoderDrive.cpp"


arcadeDrive driveTrain;
encDrive encoderDrive;


auto1 autoRoutine1;
teleop teleRoutine;


armLift lift;
rollerIntake gripper;
int test = 75;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Timer.reset();

  //Set arm parameters
  lift.armLength = 13;
  lift.resetAngle = -45;
  lift.shaftHeight = 10.236;
  lift.manipOffset = -.9;//Needs measurement
  lift.speedRatio = .135;
  
  lift.resetArmPos();

  
  autoRoutine1.runAuto();
  teleRoutine.runTeleop();
  //lift.armToFloor(3, true);
  while(true){

  }

  
}
