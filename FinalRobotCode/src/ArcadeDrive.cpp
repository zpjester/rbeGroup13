#ifndef arcadeDriveProtect
#define arcadeDriveProtect


#include "vex.h"





class arcadeDrive{

public:
//Bind drive motors here
 
  //controller Controller1 = Controller1;



float max(float a,float b){//return the larger of two values
    if(b>a){
        return b;
    }
    else{
        return a;
    }
}

void driveArcade(int arcadeSteer,int arcadeThrottle){
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
}//True arcade drive, faster than standard arcade. Needs the max(x,y) function


void driveController(char stick){

  if(stick=='L'){

    double expX = pow(Controller1.Axis4.value(), 3) / pow(100,3);
    double expY = pow(Controller1.Axis3.value(), 3) / pow(100,3);
   driveArcade(Controller1.Axis4.value(),Controller1.Axis3.value());
  // driveArcade(expX, expY);
  }

  else{
    double expX = pow(Controller1.Axis2.value(), 3) / pow(127,3);
    double expY = pow(Controller1.Axis1.value(), 3) / pow(127,3);
 driveArcade(expX, expY);
  }
}

bool basicLineFollow(){
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
