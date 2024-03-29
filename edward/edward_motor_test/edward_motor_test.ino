
#include <Wire.h>
#include <Adafruit_MotorShield.h>

#include <SPI.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

uint8_t i;

void setup()
{

  Serial.begin(9600);
  AFMS.begin();  // create with the default frequency 1.6KHz
  StopMoving(); // this
}

void loop()
{

RampUpForward();
GoForward();
delay(1500);
RampDown();
RampUpBackward();
GoBackward();
delay(1000);
RampDown();

//  motor1->run(FORWARD);
//  motor2->run(FORWARD);
//  for (i = 0; i < 120; i++) {
//    motor1->setSpeed(i);
//    motor2->setSpeed(i);
//    delay(10);
//  }
//  delay(2000);
//  for (i = 120; i != 0; i--) {
//    motor1->setSpeed(i);
//    motor2->setSpeed(i);
//    delay(10);
//  }
//  delay(1000);
//
//
//  motor1->run(BACKWARD);
//  motor2->run(BACKWARD);
//  for (i = 0; i < 120; i++) {
//    motor1->setSpeed(i);
//    motor2->setSpeed(i);
//    delay(10);
//  }
//  delay(2000);
//  for (i = 120; i != 0; i--) {
//    motor1->setSpeed(i);
//    motor2->setSpeed(i);
//    delay(10);
//  }
//  delay(1000);

}

void RampUpForward()
{

  motor1->run(FORWARD);
  motor2->run(FORWARD);
  for (i = 0; i < 120; i++) {
    motor1->setSpeed(i);
    motor2->setSpeed(i);
    delay(10);
  }

}

void RampDown()
{
  for (i = 120; i != 0; i--) {
    motor1->setSpeed(i);
    motor2->setSpeed(i);
    delay(10);
  }
}

void RampDownForward()
{
  for (i = 120; i != 0; i--) {
    motor1->setSpeed(i);
    motor2->setSpeed(i);
    delay(10);
  }
}

void RampUpBackward()
{
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  for (i = 0; i < 120; i++) {
    motor1->setSpeed(i);
    motor2->setSpeed(i);
    delay(10);
  }
}

void RampDownBackward()
{
    for (i = 120; i != 0; i--) {
    motor1->setSpeed(i);
    motor2->setSpeed(i);
    delay(10);
  }
}


void GoForward()
{
  motor1->setSpeed(120);
  motor2->setSpeed(120);
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  delay(250);
}

void GoBackward()
{
  motor1->setSpeed(120);
  motor2->setSpeed(120);
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  delay(250);
}

void StopMoving()
{
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  delay(250);
}
void TurnLeft()
{
  motor1->setSpeed(50);
  motor2->setSpeed(50);
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  delay(250);
}

void TurnRight()
{
  motor1->setSpeed(50);
  motor2->setSpeed(50);
  motor1->run(BACKWARD);
  motor2->run(FORWARD);
  delay(250);
}
