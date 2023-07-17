/*
* Jillian Pantig and Saurav Kshetri
* Helper header file for Hexapod: Quadratic Bezier Curve
*/

#ifndef BEZIER_HEADER
#define BEZIER_HEADER

#include <math.h>
#include "coordinates.h"

// Quadratic Bezier's Curve takes in 3 points/coordinates. This function
// generates the control point -- the point between start and end points.
// Calculates the midpoint of start and end points!
Coordinates generate_control_point(Coordinates c0, Coordinates c2) {
    Coordinates c1;
    c1.x = (c1.x + c1.x) / 2;
    c1.y = (c1.y + c1.y) / 2;
    c1.z = (c1.z + c1.z) / 2;
    return c1;
}

// Quadratic Bezier's Curve that gives back x,y,z points.
// c0 = start point, c1 = control point, c2 = end point
// t = time interval
Coordinates calculate_bezier_points(float t, Coordinates c0, Coordinates c1, Coordinates c2) {
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    
    Coordinates points;
    points.x = pow((1 - t), 2) * c0.x + 2 * (1 - t) * t * c1.x + (t * t) * c2.x;
    points.y = pow((1 - t), 2) * c0.y + 2 * (1 - t) * t * c1.y + (t * t) * c2.y;
    points.z = pow((1 - t), 2) * c0.z + 2 * (1 - t) * t * c1.z + (t * t) * c2.z;

  return points;
}

#endif /*BEZIER_HEADER*/