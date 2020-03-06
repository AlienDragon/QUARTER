#include <Arduino.h>
#include "Quad.h"

Quad::Quad(Leg &fl, Leg &fr, Leg &bl, Leg &br) : FL(fl), FR(fr), BL(bl), BR(br)
{
};

void Quad::walk(Adafruit_PWMServoDriver &pwm){
  int Lpause = 1000;
  int Spause = 200;

  FL.liftFoot(pwm);
  delay(Spause);
  FL.reachForward(pwm);
  delay(Spause);
  FL.lowerFoot(pwm);
  delay(Lpause);
  //Serial.println("Leg1");

  BR.liftFoot(pwm);
  delay(Spause);
  BR.reachForward(pwm);
  delay(Spause);
  BR.lowerFoot(pwm);
  delay(Lpause);
  //Serial.println("Leg2");

  FR.liftFoot(pwm);
  delay(Spause);
  FR.reachForward(pwm);
  delay(Spause);
  FR.lowerFoot(pwm);
  delay(Lpause);
  //Serial.println("Leg3");
  
  BL.liftFoot(pwm);
  delay(Spause);
  BL.reachForward(pwm);
  delay(Spause);
  BL.lowerFoot(pwm);
  delay(Lpause);
  //Serial.println("Leg4");

  FL.pushBack(pwm);
  BL.pushBack(pwm);
  FR.pushBack(pwm);
  BR.pushBack(pwm);
  
  delay(Lpause);
  //Serial.println("All Legs");
}

void Quad::stand(Adafruit_PWMServoDriver &pwm){
  FL.pushBack(pwm);
  BL.pushBack(pwm);
  FR.pushBack(pwm);
  BR.pushBack(pwm);
}


void Quad::turnL(Adafruit_PWMServoDriver &pwm){
  int pausePeriod = 5000;
  
  FL.rotateCC(pwm);
  delay(pausePeriod);
  BR.rotateCC(pwm);
  delay(pausePeriod);
  FR.rotateCC(pwm);
  delay(pausePeriod);
  BL.rotateCC(pwm);
  delay(pausePeriod);

  stand(pwm);
  
}
void Quad::turnR(Adafruit_PWMServoDriver &pwm){
  int pausePeriod = 250;
  
  FL.rotateC(pwm);
  delay(pausePeriod);
  BR.rotateC(pwm);
  delay(pausePeriod);
  FR.rotateC(pwm);
  delay(pausePeriod);
  BL.rotateC(pwm);
  delay(pausePeriod);

  stand(pwm);
}

void Quad::demo(Adafruit_PWMServoDriver &pwm){
  //Just runs through many of the pre-programmed features of the robot in sequence
}
