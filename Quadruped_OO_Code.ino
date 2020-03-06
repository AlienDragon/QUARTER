#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <Arduino.h>
#include "Quad.h"


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

//Joystick test code
#define X_PIN 0
#define Y_PIN 1
#define BUTTON_PIN 2
bool walk = false;

int frontRight[] = {0,1,2};
int frontLeft[] = {4,5,6};
int backLeft[] = {10,9,8};
int backRight[] = {14,13,12};

Leg FR(frontRight, "FR");
Leg FL(frontLeft, "FL");
Leg BR(backRight, "BR");
Leg BL(backLeft, "BL");
  
Quad robot(FL, FR, BL, BR);

bool ON = false;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  
  pinMode(13, OUTPUT);
  delay(1500);
  digitalWrite(13, HIGH);
}

void loop() {
  if(ON){
    digitalWrite(13, LOW);
    ON = !ON;
  }
  else{
    digitalWrite(13, HIGH);
    ON = !ON;
  }
    
  
  if(digitalRead(BUTTON_PIN) == LOW){
    walk = !walk;
  }
  Serial.println(digitalRead(BUTTON_PIN));
  if(walk)
    robot.walk(pwm);
  else
    robot.stand(pwm);  

}
