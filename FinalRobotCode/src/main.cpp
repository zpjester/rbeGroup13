// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         8               
// Arm_B                motor         9               
// Gripper_L            motor         6               
// Gripper_R            motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         8               
// Arm_B                motor         9               
// Gripper_L            motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         8               
// Arm_B                motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         3               
// R_Drive              motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         3               
// R_Drive              motor         2               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\zpjes                                            */
/*    Created:      Tue Dec 03 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         1               
// R_Drive              motor         2               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "declarations.h"
#include "matchParameters.h"
#include "auto.cpp"
#include "teleopMode.cpp"
#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"


arcadeDrive driveTrain;


auto1 autoRoutine1;
teleop teleRoutine;


armLift lift;
rollerIntake gripper;
int test = 3;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Timer.reset();

  //Set arm parameters
  lift.armLength = 12;
  lift.resetAngle = -45;
  lift.shaftHeight = 10.236;
  lift.manipOffset = -1;
  lift.speedRatio = 0.1;
  lift.resetArmPos();



  autoRoutine1.runAuto();
  teleRoutine.runTeleop();
  

  
}
