#ifndef liftProtect
#define liftProtect

#include "vex.h"

class armLift{
private:

double floorHeight = 4.92;//Inches

public:

double armLength;//Inches
double resetAngle;//Arm angle at reset position
double shaftHeight;//Height of lower shaft
double manipOffset;//Vertical offset of the bottom of the manipulator vs. its bottom pivot. Positive value -> manipulator above pivot
double speedRatio;//Speed Ratio of 4-bar transmission



float getAngle(double gripperHeight){//Gives the angle OF THE ARM for an intended height
  double armHeight = gripperHeight - manipOffset;
  double armDelta = armHeight - shaftHeight;
  double armAngle = asin(armDelta/armLength);
  return armAngle;
}

void resetArmPos(){
  Arm_A.setPosition(resetAngle, deg);
  Arm_B.setPosition(resetAngle, deg);
}
void armMotorsToAngle(double angle, bool await){
    Arm_A.spinToPosition(angle, deg, await);
    Arm_B.spinToPosition(angle, deg, await);
  }
void armToAngle(double angle, bool await){
  double motorAngle = angle / speedRatio;
  armMotorsToAngle(motorAngle, await);
}
void armToHeight(double height, bool await){//Height in inches
double armAngle = getAngle(height);
armToAngle(armAngle, await);
}

void armToFloor(int floor, bool await){
  double height = floor*floorHeight;
  armToHeight(height, await);
}





  
};





#endif