#include "vex.h"
#include "ArcadeDrive.cpp"


extern arcadeDrive driveTrain;
extern int matchLength;




class teleop{
public:

void runTeleop(){
  while(true){

    driveTrain.driveController('L');
    //Brain.Screen.print("testing");
    task::sleep(20);      
  
  }
}
};
