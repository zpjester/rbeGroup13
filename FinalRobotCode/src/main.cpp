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
int test = 159;
bool firstTele = true;
using namespace vex;

char autoColor;
char autoSide;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Timer.reset();

  //Set arm parameters
  lift.armLength = 13;
  lift.resetAngle = -46;
  lift.shaftHeight = 10.236;
  lift.manipOffset = -1.75;//Needs measurement
  lift.speedRatio = .135;
  
int screenX = 480;
int screenY = 272;

  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(0, 0, screenX/2, screenY/2);
  Brain.Screen.drawRectangle(0, screenY/2, screenX/2, screenY/2);
  Brain.Screen.drawRectangle(screenX/2, 0, screenX/2, screenY/2);
  Brain.Screen.drawRectangle(screenX/2,  screenY/2, screenX/2, screenY/2);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 0, screenX/2, screenY/2);
  Brain.Screen.drawRectangle(0, screenY/2, screenX/2, screenY/2);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(screenX/2, 0, screenX/2, screenY/2);
  Brain.Screen.drawRectangle(screenX/2,  screenY/2, screenX/2, screenY/2);

  

  while(!Brain.Screen.pressing()){}
  int touchX = Brain.Screen.xPosition();
  int touchY = Brain.Screen.yPosition();
  

  if(touchX < screenX/2){
    autoColor = 'r';
  }
  else{
    autoColor = 'b';
  }
  if(touchY < screenY/2){
    autoSide = '3';
  }
  else{
    autoSide = 'c';
  }
  Brain.Screen.clearScreen();





  lift.resetArmPos();


  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}



void autonomous(void) {
  Brain.Screen.print(test);

if(autoColor == 'r'){
  if(autoSide == '3'){
    autoRoutine1.runAutoRedTriple();
  }
  else{
    autoRoutine1.runAutoRedConstruct();
  }
}
else{
  if(autoSide == '3'){
    autoRoutine1.runAutoBlueTriple();
  }
  else{
    autoRoutine1.runAutoBlueConstruct();
  }
}

  
}



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
