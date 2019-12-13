#ifndef liftProtect
#define liftProtect

#include "vex.h"

class armLift{
private:



public:

double armLength;//Inches
double resetAngle;//Arm angle at reset position
double shaftHeight;//Height of lower shaft
double manipOffset;//Vertical offset of the bottom of the manipulator vs. its bottom pivot. Positive value -> manipulator above pivot
double speedRatio;//Speed Ratio of 4-bar transmission



float getAngle(double gripperHeight){//Gives the angle OF THE ARM for an intended height
  double endHeight = gripperHeight - manipOffset;
  double armDelta = endHeight - shaftHeight;
  double armAngleRads = asin(armDelta/armLength);
  double armAngleDegrees = armAngleRads*57.2957;
  return armAngleDegrees;
}
void releaseArm(){//Temporarily releases the arm, allowing it to return to its natural position. Used in the construction zone auto to zero the arm after crossing into the zone.
  Arm_A.setStopping(coast);
  Arm_A.stop();
  Arm_B.setStopping(coast);
  Arm_B.stop();
  task::sleep(1000);
  Arm_A.setStopping(hold);
  Arm_B.setStopping(hold);

}

void resetArmPos(){//Resets arm encoders
  Arm_B.setPosition(0, deg);
  Arm_A.setPosition(0, deg);
  Brain.Screen.print(Arm_A.position(degrees));
}
void armMotorsToAngle(double angle, bool await){//Sets the arm motors to an angle
    Arm_B.spinToPosition(angle, deg, false);
    Arm_A.spinToPosition(angle, deg, await);
  }

void armToAngle(double angle, bool await){//Sets the arm to an angle (0 is level)
  double motorAngle = (resetAngle-angle) / speedRatio;
  armMotorsToAngle(motorAngle, await);
}
void armToHeight(double height, bool await){//Sets the arm to a given height
  double armAngle = getAngle(height);
  armToAngle(armAngle, await);
}

void armToFloor(int floor, bool await){//Sets the arm to a given floor, from the allowed floors. If invalid floor is given, return the arm to its home position.
  if(floor == 0){
   armToHeight(-.25, await); 
  }
  else if(floor == 1){
   armToHeight(5, await); 
  }
  else if(floor == 2){
   armToHeight(9.8, await); 
  }
  else if(floor == 3){
   armToHeight(14.1, await); 
  }
  else if(floor == 4){
   armToHeight(18.8, await); 
  }
  else{
   armToHeight(0, await); 
  }
 
}





  
};





#endif