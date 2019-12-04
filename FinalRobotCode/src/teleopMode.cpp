#include "vex.h"
#include "ArcadeDrive.cpp"


extern arcadeDrive driveTrain;
extern int matchLength;
using namespace vex;



class teleop{
public:

void runTeleop(){
  while(Brain.Timer.value()<=matchLength){
    driveTrain.driveController('L');
    task::sleep(20);      
  }
}
};
