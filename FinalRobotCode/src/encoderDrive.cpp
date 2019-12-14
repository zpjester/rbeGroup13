#ifndef encProt
#define encProt
#include "vex.h"
class encDrive{

private:


public:
//Drive train parameters
float wheelRadius=2;
float drivenGear = 10;
float driveGear = 4;
float gearRatio=(driveGear/drivenGear);


float calculateRotations(double targetDistance){//Calculates motor rotations needed to drive a wheel a certain distance
    return targetDistance/((wheelRadius*2*3.1416))/gearRatio;
}



void driveArc(float radius, char driveDirection, char turnDirection, float angle, bool await){//Drives the robot along an arc of set radius, direction and angle.
    
    //Robot parameters
    float treadWidth=13.75;//inches
    float motorMaxSpeed=75;//percent
    
    //Find the distance for each motor to drive
    float IWheelDistance=(radius - treadWidth/2)*3.1416*2*angle/360;//inches
    float OWheelDistance=(radius + treadWidth/2)*3.1416*2*angle/360;//inches
    
    //Finds the number of rotations for each motor to drive
    float IWheelRotations=calculateRotations(IWheelDistance);
    float OWheelRotations=calculateRotations(OWheelDistance);
    
    if (driveDirection=='b'){//If drive direction is backwards, reverse the motor directions
        IWheelRotations=IWheelRotations*-1;
        OWheelRotations=OWheelRotations*-1;
    }
    
    
    if(turnDirection=='r'){
        L_Drive.setVelocity(motorMaxSpeed, percent);//Start driving
        R_Drive.setVelocity(motorMaxSpeed*IWheelDistance/OWheelDistance, percent);
        L_Drive.spinFor(OWheelRotations, turns, false);
        R_Drive.spinFor(IWheelRotations, turns, await);
    }
    else if(turnDirection=='l'){
        R_Drive.setVelocity(motorMaxSpeed, percent);//Start driving
        L_Drive.setVelocity(motorMaxSpeed*IWheelDistance/OWheelDistance, percent);
        R_Drive.spinFor(OWheelRotations, turns, false);
        L_Drive.spinFor(IWheelRotations, turns, await);
        
    }
    else{//Send a print if the turn direction is invalid
        Brain.Screen.print("Error, invalid turn direction");
        task::sleep(1000);
    }
}

void driveDistance(float distance, bool await){//Drives a ser distance
    float motorMaxSpeed=100;//percent
    float motorRot = calculateRotations(distance);
    R_Drive.setVelocity(motorMaxSpeed, percent);
    L_Drive.setVelocity(motorMaxSpeed, percent);
    R_Drive.spinFor(motorRot, turns, false);
    L_Drive.spinFor(motorRot, turns, await);
}




};
#endif