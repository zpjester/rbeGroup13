#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor L_Drive = motor(PORT2, ratio18_1, true);
motor R_Drive = motor(PORT1, ratio18_1, false);
controller Controller1 = controller(primary);
motor Arm_A = motor(PORT8, ratio18_1, false);
motor Arm_B = motor(PORT9, ratio18_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}