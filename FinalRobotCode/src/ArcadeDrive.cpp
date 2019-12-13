//Arcade drive and unused line follow functions

#ifndef arcadeDriveProtect
#define arcadeDriveProtect


#include "vex.h"





class arcadeDrive{

public:


float max(float a,float b){//return the larger of two values
    if(b>a){
        return b;
    }
    else{
        return a;
    }
}

void driveArcade(int arcadeSteer,int arcadeThrottle){//Arcade drive based on X and Y input values
    float outputL=0;//Setup
    float outputR=0;
    
    //Set drive values
    if(arcadeSteer>=0&&arcadeThrottle>=0){//Quadrant 1
        outputL=max(arcadeSteer,arcadeThrottle);
        outputR=arcadeThrottle-arcadeSteer;
    }
    else if(arcadeSteer<0&&arcadeThrottle>=0){//Quadrant 2
        outputL=arcadeSteer+arcadeThrottle;
        outputR=max((-arcadeSteer),arcadeThrottle);
    }
    else if(arcadeSteer<0 && arcadeThrottle<0){
        outputL=-max((-arcadeSteer),(-arcadeThrottle));
        outputR=arcadeThrottle-arcadeSteer;
    }
    else{
        outputL=arcadeSteer+arcadeThrottle;
        outputR=-max(arcadeSteer,(-arcadeThrottle));
    }
    L_Drive.spin(forward, outputL, percent);
    R_Drive.spin(forward, outputR, percent);
}


void driveController(char stick){//Arcade drive using a selected stick

  if(stick=='L'){

    
   driveArcade(Controller1.Axis4.value(),Controller1.Axis3.value());
 
  }

  else{
    driveArcade(Controller1.Axis2.value(),Controller1.Axis1.value());
  }
}

bool basicLineFollow(){//Basic line following, unused due to inconsistent values when moving over colored tape on the field
  int lineThreshold = 12;
  int offSteer = 50;
  bool L_Tripped;
  bool R_Tripped;
  if(L_Line.reflectivity() < lineThreshold){
    L_Tripped = true;
  }
  else{
    L_Tripped = false;
  }
  if(R_Line.reflectivity() < lineThreshold){
    R_Tripped = true;
  }
  else{
    R_Tripped = false;
  }
  if(L_Tripped && R_Tripped){
    driveArcade(0,0);
    return true;
  }
  else if(L_Tripped){
    driveArcade(offSteer, 0);
    return false;
  }
  else if(R_Tripped){
    driveArcade(-offSteer, 0);
    return false;
  }
  else{
    driveArcade(0, 50);
    return false;
  }
}


};
#endif
