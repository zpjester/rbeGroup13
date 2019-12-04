#include "vex.h"
#include "arcadeDrive.cpp"
using namespace vex;


arcadeDrive drive;

class teleop{
public:

void runTeleop(){
  while(Brain.Timer.value()<150){
    drive.driveController('R');
    task::sleep(20);


      
  }
}
};