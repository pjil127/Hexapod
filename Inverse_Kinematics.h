/*
* Jillian Pantig and Saurav Kshetri
* Helper header file for Hexapod: Inverse Kinematics
*/

#ifndef INVERSE_KINEMATICS_HEADER
#define INVERSE_KINEMATICS_HEADER

#include "Coordinates.h"
#include "Angles.h"

Angles calculate_inverse_kinematics(Coordinates c){
    // Inverse kinematics here
    Angles angle;
    angle.servo0 = 0;
    angle.servo1 = 0;
    angle.servo2 = 0;

    return angle;
}

#endif /* INVERSE_KINEMATICS_HEADER */