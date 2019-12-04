#include "vex.h"
using namespace vex;


class arcadeDrive{

public:
//Bind drive motors here
  motor Left_Drive = L_Drive;
  motor Right_Drive = R_Drive;
  controller baseController = Controller1;



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
    Left_Drive.spin(directionType::fwd, outputL/1.27, velocityUnits::pct);
    Right_Drive.spin(directionType::fwd, outputR/1.27, velocityUnits::pct);
}//True arcade drive, faster than standard arcade. Needs the max(x,y) function


void driveController(char stick){

  if(stick=='r'){
  driveArcade(baseController.Axis4.value(),baseController.Axis3.value());
  }

  else{
  driveArcade(baseController.Axis2.value(),baseController.Axis1.value());  
  }
}




};