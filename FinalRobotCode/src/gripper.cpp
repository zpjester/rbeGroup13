#ifndef gripperProtect
#define gripperProtect
#include "vex.h"

class rollerIntake{
private:
double freeTorqueThresh = 0.3;//N*M
double backTorqueThresh = .5;//N*M


public:

void stopGripper(){
  Gripper_M.stop();
  
}
void runIntake(){
  Gripper_M.spin(forward, 100, pct);
  
}
void runEject(){
  Gripper_M.spin(reverse, 100, pct);
  
}


double getGripperTorque(){
  double mTorque = Gripper_M.torque(Nm);
  return mTorque;
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
    runEject();
    task::sleep(100);
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
      task::sleep(100);
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