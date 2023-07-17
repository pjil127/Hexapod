/*
* Jillian Pantig and Saurav Kshetri
* Helper header file for Hexapod: Servo Commands
*/

#ifndef COMMAND_HEADER
#define COMMAND_HEADER

#include <Adafruit_PWMServoDriver.h>
#include "Angles.h"
#include "Leg.h"

// We need to set the values below to the ones we found out during Spring 2023
#define MIDPOINTPWM 290     // Determines clockwise or counterclockwise movement of servo
#define SERVOMINPWM  205    // Angle 0
#define SERVOMAXPWM  375    // Angle 180
#define SERVO_FREQ 50       // Analog servos run at ~50 Hz
#define OSCILLATOR_FREQ 27000000


// We need to add more functions for forwar, backward, turns, etc.
class Command {
    public:      
        Command(){};
        void setup_servo() {
            pwm.begin();
            pwm.setOscillatorFrequency(OSCILLATOR_FREQ);
            pwm.setPWMFreq(SERVO_FREQ);
        }
        
        void angle_to_pulse(int angle) {
            return map(angle, 0, 180, SERVOMINPWM, SERVOMAXPWM);
        }

        void move_leg(Angles angle, Leg leg){
            // We need to add timing to this function
            pwm.setPWM(leg.pin0, 0, angle.servo0);
            pwm.setPWM(leg.pin1, 0, angle.servo1);
            pwm.setPWM(leg.pin2, 0, angle.servo2);
        }

        void stop_leg(Leg leg){
            // Stops all servos in one leg from moving
            pwm.setPWM(leg.pin0, 0, 0);
            pwm.setPWM(leg.pin1, 0, 0);
            pwm.setPWM(leg.pin2, 0, 0);
        }

    private:
        Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
};

#endif /* COMMAND_HEADER */