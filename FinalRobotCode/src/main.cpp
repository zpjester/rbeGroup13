// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         17              
// Arm_B                motor         18              
// Gripper_M            motor         6               
// L_Line               line          H               
// R_Line               line          G               
// backBump             bumper        A               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         17              
// Arm_B                motor         18              
// Gripper_M            motor         6               
// L_Line               line          H               
// R_Line               line          G               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         17              
// Arm_B                motor         18              
// Gripper_M            motor         6               
// L_Line               line          F               
// R_Line               line          G               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         17              
// Arm_B                motor         18              
// Gripper_M            motor         6               
// L_Line               line          F               
// R_Line               line          H               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         17              
// Arm_B                motor         18              
// Gripper_M            motor         6               
// L_Line               line          G               
// R_Line               line          H               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Drive              motor         2               
// R_Drive              motor         1               
// Controller1          controller                    
// Arm_A                motor         17              
// Arm_B                motor         18              
// Gripper_M            motor         6               
// L_Line               line          G               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
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
int test = 111;
bool firstTele = true;
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Timer.reset();

  //Set arm parameters
  lift.armLength = 13;
  lift.resetAngle = -46;
  lift.shaftHeight = 10.236;
  lift.manipOffset = -1;//Needs measurement
  lift.speedRatio = .135;
  
  lift.resetArmPos();

  
  
  

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Brain.Screen.print(test);
  autoRoutine1.runAuto();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
 
 // while (1) {

    
    teleRoutine.runTeleop(firstTele);
    firstTele = false;
    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  //}
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
