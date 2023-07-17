/*
* Jillian Pantig and Saurav Kshetri
* Hexapod Arduino File
*/

//--------------LIBRARIES----------------------
#include <Arduino.h>

#include "Bezier_Curve.h"
#include "Inverse_Kinematics.h"
#include "Leg.h"
#include "Angles.h"
#include "Coordinates.h"
#include "Command.h"
//--------------LIBRARIES----------------------

//--------------HEXAPOD LEGS-------------------
struct Hexapod {
  Leg leg1;
  Leg leg2;
  Leg leg3;
  Leg leg4;
  Leg leg5;
  Leg leg6;
};

// We need to change the pins below
struct Hexapod {
  {2, 3, 4},    // leg1 servo pins
  {5, 6, 7},    // leg2 servo pins
  {8, 9, 10},   // leg3 servo pins
  {11, 12, 13}, // leg4 servo pins
  {14, 15, 16}, // leg5 servo pins
  {17, 18, 19}  // leg6 servo pins
};
//--------------HEXAPOD LEGS-------------------

//--------------VARIABLES----------------------
Command commander;
//--------------VARIABLES----------------------

//Setup hardware and connections
void setup() {
  Serial.begin(115200);
  
  commander.setup_servo();
}

void loop() {
    Coordinates start = {0, 0, 0};
    Coordinates end = {1, 1, 1};
    Coordinates control_point = generate_control_point(start, end);

    // Want 0 <= t <= 1 for Bezier Curve
    for (int i = 0; i <= 100; i++) {
        float t = i / 100.0;
        Coordinates points = calculateBezierPoint(t, p0, p1, p2);
        Angles angles = calculate_inverse_kinematics(points);
        commander.move_leg(angles, Hexapod.leg1);
    }
}
