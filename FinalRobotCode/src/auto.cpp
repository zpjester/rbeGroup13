//All 4 auto routines

//Include files and set up objects
#include "vex.h"
#include "ArcadeDrive.cpp"
#include "4BarLinkage.cpp"
#include "gripper.cpp"
#include "encoderDrive.cpp"

extern brain Brain;
extern armLift lift;
extern rollerIntake gripper;
extern arcadeDrive driveTrain;
extern encDrive encoderDrive;



class auto1{//Create class
public:

void runAutoBlueConstruct(){//Auto for blue construction zone
   
gripper.fullSmartGripper("In");

lift.armToFloor(1, true);

encoderDrive.driveDistance(24.5, true);
lift.armToFloor(0, true);
gripper.fullSmartGripper("In");
encoderDrive.driveDistance(4, true);
gripper.fullSmartGripper("In");
lift.armToFloor(2, false);
gripper.runIntake();
encoderDrive.driveDistance(21, true);

encoderDrive.driveDistance(-4, true);
encoderDrive.driveDistance(2, true);
gripper.stopGripper();
encoderDrive.driveArc(0, 'f', 'r', 90, true);
driveTrain.driveArcade(0,-50);
while(!backBump.pressing()){}
driveTrain.driveArcade(0,0);
gripper.fullSmartGripper("in");
lift.armToFloor(0, true);
lift.releaseArm();
lift.resetArmPos();
lift.armToFloor(2, true);
encoderDrive.driveDistance(22, true);
gripper.fullSmartGripper("Out");
gripper.runEject();
task::sleep(500);
encoderDrive.driveDistance(-10, true);
gripper.stopGripper();

  }

void runAutoRedConstruct(){//Auto for red construction zone
   
gripper.fullSmartGripper("In");

lift.armToFloor(1, true);

encoderDrive.driveDistance(24.5, true);
lift.armToFloor(0, true);
gripper.fullSmartGripper("In");
encoderDrive.driveDistance(4, true);
gripper.fullSmartGripper("In");
lift.armToFloor(2, false);
gripper.runIntake();
encoderDrive.driveDistance(21, true);
encoderDrive.driveDistance(-4, true);
encoderDrive.driveDistance(2, true);
gripper.stopGripper();
encoderDrive.driveArc(0, 'f', 'l', 90, true);
driveTrain.driveArcade(0,-50);
while(!backBump.pressing()){}
driveTrain.driveArcade(0,0);
gripper.fullSmartGripper("in");
lift.armToFloor(0, true);
lift.releaseArm();
lift.resetArmPos();
lift.armToFloor(2, true);
encoderDrive.driveDistance(22, true);
gripper.fullSmartGripper("Out");
gripper.runEject();
task::sleep(500);
encoderDrive.driveDistance(-10, true);
gripper.stopGripper();

  }


  void runAutoBlueTriple(){//3 pizza auto for blue side
    gripper.fullSmartGripper("In");
    encoderDrive.driveDistance(-10, true);
    lift.armToFloor(1, false);
    encoderDrive.driveDistance(-40, true);
    encoderDrive.driveArc(0, 'f', 'r', 90, true);
    driveTrain.driveArcade(0, -50);
    while(!backBump.pressing()){
    }
    gripper.fullSmartGripper("In");
    encoderDrive.driveDistance(23.5, true);
    gripper.fullSmartGripper("Out");
    gripper.runEject();
//Go to grab pizza 2
    encoderDrive.driveDistance(-16, true);
    gripper.stopGripper();
    encoderDrive.driveArc(0, 'f', 'l', 90, true);
    lift.armToHeight(9, false);
    encoderDrive.driveDistance(40, true);
    gripper.fullSmartGripper("In");

    encoderDrive.driveDistance(-40, true);
    encoderDrive.driveArc(0, 'f', 'r', 90, true);
    driveTrain.driveArcade(0, -50);
    lift.armToFloor(2, false);
    while(!backBump.pressing()){}
    gripper.fullSmartGripper("In");

    encoderDrive.driveDistance(22, true);
    gripper.fullSmartGripper("Out");
    gripper.runEject();

    encoderDrive.driveDistance(-16, true);
    gripper.stopGripper();
//Go to grab pizza 3
    encoderDrive.driveArc(0, 'f', 'l', 90, true);
    lift.armToHeight(9, false);
    encoderDrive.driveDistance(37, true);
    gripper.fullSmartGripper("In");

    encoderDrive.driveDistance(-45, true);
    encoderDrive.driveArc(0, 'f', 'r', 90, true);
    driveTrain.driveArcade(0, -50);
    lift.armToFloor(3, false);
    while(!backBump.pressing()){}
    gripper.fullSmartGripper("In");

    encoderDrive.driveDistance(24, true);
    gripper.fullSmartGripper("Out");
    gripper.runEject();

    encoderDrive.driveDistance(-17.5, true);
    gripper.stopGripper();
    
    
  }


  void runAutoRedTriple(){//3 pizza auto for red side
    gripper.fullSmartGripper("In");
    encoderDrive.driveDistance(-10, true);
    lift.armToFloor(1, false);
    encoderDrive.driveDistance(-40, true);
    encoderDrive.driveArc(0, 'f', 'l', 90, true);
    driveTrain.driveArcade(0, -50);
    while(!backBump.pressing()){
    }
    gripper.fullSmartGripper("In");
    encoderDrive.driveDistance(23.5, true);
    gripper.fullSmartGripper("Out");
    gripper.runEject();
//Go to grab pizza 2
    encoderDrive.driveDistance(-16, true);
    gripper.stopGripper();
    encoderDrive.driveArc(0, 'f', 'r', 90, true);
    lift.armToHeight(9, false);
    encoderDrive.driveDistance(44, true);
    gripper.fullSmartGripper("In");

    encoderDrive.driveDistance(-40, true);
    encoderDrive.driveArc(0, 'f', 'l', 90, true);
    driveTrain.driveArcade(0, -50);
    lift.armToFloor(2, false);
    while(!backBump.pressing()){}
    gripper.fullSmartGripper("In");
    encoderDrive.driveDistance(22, true);
    gripper.fullSmartGripper("Out");
    gripper.runEject();

    encoderDrive.driveDistance(-16, true);
    gripper.stopGripper();
//Go to grab pizza 3
    encoderDrive.driveArc(0, 'f', 'r', 90, true);
    lift.armToHeight(9, false);
    encoderDrive.driveDistance(41, true);
    gripper.fullSmartGripper("In");

    encoderDrive.driveDistance(-45, true);
    encoderDrive.driveArc(0, 'f', 'l', 90, true);
    driveTrain.driveArcade(0, -50);
    lift.armToFloor(3, false);
    while(!backBump.pressing()){}
    gripper.fullSmartGripper("In");

    encoderDrive.driveDistance(24, true);
    gripper.fullSmartGripper("Out");
    gripper.runEject();

    encoderDrive.driveDistance(-17.5, true);
    gripper.stopGripper();
    
    
  }
};