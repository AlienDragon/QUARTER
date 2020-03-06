#include <Arduino.h>
#include "Dof.h"

Dof::Dof(int p){
    pinMode(p, OUTPUT);
    pin = p;
}

void Dof::changePos(uint16_t newPos, Adafruit_PWMServoDriver &pwm){
  if(newPos > 150 && newPos <= 600){
    pwm.setPWM(pin, 0, newPos);
    currentPos = newPos;
  }
}

void Dof::setmaxForward(int pos){
  maxForward = pos;
}
void Dof::setmaxBackward(int pos){
  maxBackward = pos;
}
const int Dof::getmaxForward(){return maxForward;}
const int Dof::getmaxBackward(){return maxBackward;}
