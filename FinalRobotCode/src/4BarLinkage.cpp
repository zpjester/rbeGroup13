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
void releaseArm(){
  Arm_A.setStopping(coast);
  Arm_A.stop();
  Arm_B.setStopping(coast);
  Arm_B.stop();
  task::sleep(1000);
  Arm_A.setStopping(hold);
  Arm_B.setStopping(hold);

}

void resetArmPos(){
  Arm_B.setPosition(0, deg);
  Arm_A.setPosition(0, deg);
  Brain.Screen.print(Arm_A.position(degrees));
}
void armMotorsToAngle(double angle, bool await){
  
    Arm_B.spinToPosition(angle, deg, false);
    Arm_A.spinToPosition(angle, deg, await);
    

    // if(await){
    //   int currentPosition = Arm_A.position(deg);
    //   int delta = angle - currentPosition;
    //   Brain.Screen.print(delta);
    //   int estTime = abs((delta / 90) * 1.1);
    //   task::sleep(estTime*1000);
    // }
  }
void armToAngle(double angle, bool await){
  double motorAngle = (resetAngle-angle) / speedRatio;
 armMotorsToAngle(motorAngle, await);
 
}


void armToHeight(double height, bool await){//Height in inches
double armAngle = getAngle(height);
armToAngle(armAngle, await);
}

void armToFloor(int floor, bool await){
    //Brain.Screen.clearScreen();
    // Brain.Screen.setCursor(0,0);
    // Brain.Screen.print("Moving to floor", floor);
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