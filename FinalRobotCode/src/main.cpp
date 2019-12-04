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
#include "arcadeDrive.cpp"
using namespace vex;


arcadeDrive drive;



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  drive.driveController('R');
  task::sleep(20);
}
