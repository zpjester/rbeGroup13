using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor L_Drive;
extern motor R_Drive;
extern controller Controller1;
extern motor Arm_A;
extern motor Arm_B;
extern motor Gripper_M;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );