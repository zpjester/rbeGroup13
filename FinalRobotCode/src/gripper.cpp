#ifndef gripperProtect
#define gripperProtect
#include "vex.h"

class rollerIntake{
private:
double freeTorqueThresh = 0.2;//N*M
double backTorqueThresh = 1.0;//N*M


public:

void stopGripper(){
  Gripper_L.stop();
  Gripper_R.stop();
}
void runIntake(){
  Gripper_L.spin(forward, 100, pct);
  Gripper_R.spin(forward, 100, pct);
}
void runEject(){
  Gripper_L.spin(reverse, 100, pct);
  Gripper_R.spin(reverse, 100, pct);
}


double getGripperTorque(){
  double averageTorque = (Gripper_L.torque(Nm) + Gripper_R.torque(Nm))/2;
  return averageTorque;
}

bool smartGripper(std::string direction){
  if(direction == "In" || direction == "in"){
    
    if(getGripperTorque() < backTorqueThresh){
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      Brain.Screen.print("Intaking");
      runIntake();
      return false;     
    }
    else{
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      stopGripper();
      return true;
    }
  }
  else{
    
    if(getGripperTorque() > freeTorqueThresh){
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      Brain.Screen.print("Ejecting");
      runEject();
      return false;     
    }
    else{
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      stopGripper();
      return true;
    }
  }
}
void fullSmartGripper(std::string direction){
  bool complete = false;
  while(!complete){
    complete = smartGripper(direction);
  }
}






};
#endif