#pragma once

#include <Arduino.h>
#include "Leg.h"

class Quad
{
private:
	Leg FL;
	Leg FR;
	Leg BL;
	Leg BR;

public:
	Quad(Leg &fl, Leg &fr, Leg &bl, Leg &br);
	void walk(Adafruit_PWMServoDriver &pwm);
	void turnL(Adafruit_PWMServoDriver &pwm);
	void turnR(Adafruit_PWMServoDriver &pwm);
	void stand(Adafruit_PWMServoDriver &pwm); //used to reset the robot to a standing position
	void demo(Adafruit_PWMServoDriver &pwm);
};