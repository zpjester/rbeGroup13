#ifndef gripperProtect
#define gripperProtect
#include "vex.h"

class rollerIntake{
private:
//Set thresholds for automatic operation
double freeTorqueThresh = 0.3;//N*M
double backTorqueThresh = .6;//N*M


public:

void stopGripper(){//Stop the gripper motor
  Gripper_M.stop();
  
}
void runIntake(){//Sets gripper motor to intake
  Gripper_M.spin(forward, 100, pct);
  
}
void runEject(){//Sets gripper motor to eject
  Gripper_M.spin(reverse, 100, pct);
  
}


double getGripperTorque(){//Reads the torque of the gripper, and returns it
  double mTorque = Gripper_M.torque(Nm);
  return mTorque;
}

bool smartGripper(std::string direction){//Runs the gripper in the specified direction, will shut down the gripper and return true if the pizza reaches its intended position (fully gripped or released)
  if(direction == "In" || direction == "in"){//If set to intake
    if(getGripperTorque() < backTorqueThresh){//If the gripper is still intaking,
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      Brain.Screen.print("Intaking");
      runIntake();//run the intake
      return false;//and return false
    }
    else{//If the pizza has reached the back of the gripper,
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      stopGripper();//stop the intake
      return true;//and return true
    }
  }
  else{//If set to eject
    runEject();
    task::sleep(100);//Start the motor for a short time, to allow the motor to spin up and build torque
    if(getGripperTorque() > freeTorqueThresh){//Check the torque, if the motor is loaded,
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      Brain.Screen.print("Ejecting");
      runEject();//Continue running the motor
      return false;//and return false
    }
    else{//If motor is free spinning,
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(0,0);
      task::sleep(100);
      stopGripper();//Stop the gripper
      return true;//and return false
    }
  }
}
void fullSmartGripper(std::string direction){//Runs the smart gripper command and waits for it to return true.
  bool complete = false;
  while(!complete){
    complete = smartGripper(direction);
  }
}






};
#endif