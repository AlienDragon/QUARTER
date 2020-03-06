#include <Arduino.h>
#include "Leg.h"

Leg::Leg(int pins[], String legPos) : base(pins[2]), base2(pins[1]), knee(pins[0])
{
  //This is a very clunky system!!
  //Needs removing and changing
  if (legPos == "BR"){
       base.setmaxForward(600);
       base.setmaxBackward(150);
       }
     else if(legPos == "BL"){
        base.setmaxForward(150);
        base.setmaxBackward(600);
     }
     else if(legPos == "FL"){
        base.setmaxForward(150);
        base.setmaxBackward(600);
     }
     else if (legPos == "FR"){
        base.setmaxForward(600);
        base.setmaxBackward(150);
     }
};
/*  
  //reach leg out
  pwm.setPWM(frontRight[0] ,0 ,450);
  pwm.setPWM(frontRight[1] ,0 ,375);
  pwm.setPWM(frontRight[2] ,0 ,375);
 */
void Leg::reachForward(Adafruit_PWMServoDriver &pwm){
  int pos = base.getmaxForward();
  if(pos > 375){
    pos -= 150;
  }
  else{
    pos += 150;
  }
  base.changePos(pos, pwm);
  base2.changePos(375, pwm);
  knee.changePos(375, pwm);
}


void Leg::lowerFoot(Adafruit_PWMServoDriver &pwm){
  knee.changePos(600, pwm);
}
void Leg::liftFoot(Adafruit_PWMServoDriver &pwm){
  base2.changePos(450, pwm);
}

/*
  //move front legs back
  pwm.setPWM(frontRight[0] ,0 ,600);
  pwm.setPWM(frontRight[1] ,0 ,400);
  pwm.setPWM(frontRight[2] ,0 ,200);
*/
void Leg::pushBack(Adafruit_PWMServoDriver &pwm){
  int pos = base.getmaxBackward();
  if(pos > 375){
    pos -= 150;
  }
  else {
    pos += 150;
  }
  base.changePos(pos, pwm);
  base2.changePos(375, pwm);  //375 is half way
  knee.changePos(600, pwm);   //max flex in the*= knee (90 bend)
}


void Leg::rotateC(Adafruit_PWMServoDriver &pwm){
  liftFoot(pwm);
  base.changePos(base.getmaxBackward(), pwm);
  lowerFoot(pwm);
}
void Leg::rotateCC(Adafruit_PWMServoDriver &pwm){
  liftFoot(pwm);
  base.changePos(base.getmaxForward(), pwm);
  lowerFoot(pwm);
}
