#pragma once
#include <Arduino.h>
#include "Dof.h"

class Leg
{
private:
  Dof base;
  Dof base2;
  Dof knee;

public:
  Leg(int pins[], String legPos);
  void reachForward(Adafruit_PWMServoDriver &pwm);
  void pushBack(Adafruit_PWMServoDriver &pwm);
  void lowerFoot(Adafruit_PWMServoDriver &pwm);
  void liftFoot(Adafruit_PWMServoDriver &pwm);
  void rotateC(Adafruit_PWMServoDriver &pwm);
  void rotateCC(Adafruit_PWMServoDriver &pwm);
};