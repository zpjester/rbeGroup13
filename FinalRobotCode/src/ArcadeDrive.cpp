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
  driveArcade(Controller1.Axis4.value(),Controller1.Axis3.value());
  }

  else{
  driveArcade(Controller1.Axis2.value(),Controller1.Axis1.value());  
  }
}




};
#endif
