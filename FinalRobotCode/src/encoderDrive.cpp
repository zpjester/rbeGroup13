#ifndef encProt
#define encProt
#include "vex.h"
class encDrive{

private:


public:
float wheelRadius=2;
float drivenGear = 10;
float driveGear = 4;
float gearRatio=(driveGear/drivenGear);


float calculateRotations(double targetDistance){
    return targetDistance/((wheelRadius*2*3.1416))/gearRatio;
}



void driveArc(float radius, char driveDirection, char turnDirection, float angle, bool await){
    
    
    float treadWidth=10.875;//inches
    float motorMaxSpeed=100;//percent
    
    float IWheelDistance=(radius - treadWidth/2)*3.1416*2*angle/360;//inches
    float OWheelDistance=(radius + treadWidth/2)*3.1416*2*angle/360;//inches
    
    
    float IWheelRotations=calculateRotations(IWheelDistance);
    float OWheelRotations=calculateRotations(OWheelDistance);
    
    if (driveDirection=='b'){
        IWheelRotations=IWheelRotations*-1;
        OWheelRotations=OWheelRotations*-1;
    }
    
    
    if(turnDirection=='r'){
        L_Drive.setVelocity(motorMaxSpeed, percent);
        R_Drive.setVelocity(motorMaxSpeed*IWheelDistance/OWheelDistance, percent);
        L_Drive.spinFor(OWheelRotations, turns, false);
        R_Drive.spinFor(IWheelRotations, turns, await);
    }
    else if(turnDirection=='l'){
        R_Drive.setVelocity(motorMaxSpeed, percent);
        L_Drive.setVelocity(motorMaxSpeed*IWheelDistance/OWheelDistance, percent);
        R_Drive.spinFor(OWheelRotations, turns, false);
        L_Drive.spinFor(IWheelRotations, turns, await);
        
    }
    else{
        Brain.Screen.print("Error, invalid turn direction");
        task::sleep(1000);
    }
}

void driveDistance(float distance, bool await){
    float motorMaxSpeed=75;//percent
    float motorRot = calculateRotations(distance);
    R_Drive.setVelocity(motorMaxSpeed, percent);
    L_Drive.setVelocity(motorMaxSpeed, percent);
    R_Drive.spinFor(motorRot, turns, false);
    L_Drive.spinFor(motorRot, turns, await);
}




};
#endif