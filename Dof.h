#pragma once

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

class Dof
{
public:
  Dof(int p);
  void changePos(uint16_t newPos, Adafruit_PWMServoDriver &pwm);
  void setmaxForward(int pos);
  void setmaxBackward(int pos);
  const int getmaxForward();
  const int getmaxBackward();

private:
  int pin;
  int currentPos;
  int maxForward;  //used to move leg the correct direction
  int maxBackward; //used to move leg the correct direction
  //int posToDegrees(int pos);  //Reduces resolution of control over servos so isn't necessary
};
