#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include <WiFi.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

int targetDistance = 12;
int trolleySpeed = 0;  // in feet per second
int distance = 12;

// Set the motor speed to 50 (0 to 255, where 0 is off and 255 is full speed)

int speed = 50;

// Initialize the motor shield
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Create motor objects
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Inside setup");
  AFMS.begin();
  Serial.println("After AFMS.begin");
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("Inside indefinite loop");
  // put your main code here, to run repeatedly:
  int counter=0;
  // change the condition to check if the user and device are paired. For testing testing the condition 1==1 is used which will always return true.
  //if (true) {
    counter++;
    distance = checkDistance();
    Serial.println(String(counter)+":distance is:"+ String(distance));
    if(distance < 12){
      Serial.println("Distance is less than 12:"+ String(distance));
      moveTrolleyBackward(targetDistance-distance);
    }
    
    delay(1000);
  //}
  
}

int checkDistance() {
  //int actualDistance=0; // distance  in inches
  // how to find distance between the user(paired device) and the troller
  // whether we are going to user ultrasonic sensor or wi-fi signal strength (RSSI)?
  // return distance in inches
  //return 13; // to move forward
 // return 12; // to stop
  //return 11; // to move backward
  int actualDistance = random(1, 13);
  Serial.println(String(actualDistance)+":actualDistance is:"+ String(actualDistance));
  return actualDistance; // calcualte the actualDistance
}

void moveTrolleyForward(int distanceToMove){
  // Move the trolley forward at the specified speed
  //leftMotor->setSpeed(speed);
  //rightMotor->setSpeed(speed);
  Serial.println("Moving trolley forward:"+ String(distanceToMove));
  //leftMotor->run(FORWARD);
  //rightMotor->run(FORWARD);
}

void moveTrolleyBackward(int distanceToMove){
  Serial.println("Moving trolley backward:"+ String(distanceToMove));
  // Move the trolley forward at the specified speed
  //leftMotor->setSpeed(speed);
  //rightMotor->setSpeed(speed);
  stopTrolley();
  //  while reversing set it to half speed for safety purpose,we can change the computation as required.
  //leftMotor->setSpeed(speed/2);
  //rightMotor->setSpeed(speed/2);
  //leftMotor->run(BACKWARD);
  //rightMotor->run(BACKWARD);
}

void stopTrolley(){
  Serial.println("Stopping trolley ");
  //leftMotor->setSpeed(0);
  //rightMotor->setSpeed(0);
}