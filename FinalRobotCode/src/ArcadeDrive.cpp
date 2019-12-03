
#include "vex.h"

using namespace vex;

class arcadeDrive{

public:
motor Left_Drive;
motor Right_Drive;
controller Controller;









float max(float a,float b){
    if(b>a){
        return b;
    }
    else{
        return a;
    }
}

void trueArcade(int x,int y){
    float outputL=0;//Setup
    float outputR=0;
    
    //Set drive values
    if(x>=0&&y>=0){//Quadrant 1
        outputL=max(x,y);
        outputR=y-x;
    }
    else if(x<0&&y>=0){//Quadrant 2
        outputL=x+y;
        outputR=max((-x),y);
    }
    else if(x<0 && y<0){
        outputL=-max((-x),(-y));
        outputR=y-x;
    }
    else{
        outputL=x+y;
        outputR=-max(x,(-y));
    }
    Left_Drive.spin(directionType::fwd, outputL/1.27, velocityUnits::pct);
    Right_Drive.spin(directionType::fwd, outputR/1.27, velocityUnits::pct);
}//True arcade drive, faster than standard arcade. Needs the max(x,y) function


void driveArcade(char stick){

  if(stick=='r'){
  trueArcade(Controller.Axis4.value(),Controller.Axis3.value());
  }
  else{
  trueArcade(Controller.Axis2.value(),Controller.Axis1.value());  
  }
}



};