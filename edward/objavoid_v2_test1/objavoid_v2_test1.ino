
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <SPI.h>

int trigPin = 10;      // trig pin of HC-SR04
int echoPin = 11;     // Echo pin of HC-SR04
long duration, distance;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

uint8_t i;

void setup()
{
  Serial.begin(9600);
  AFMS.begin();  // create with the default frequency 1.6KHz
  StopMoving(); // this probably isn't necessary... but i'm leaving it.
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);
}

void loop()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);

  if (distance <= 20)
  {
    TurnLeft();
    delay(850);
  }
  else
  {
    //GoForward();
    RampUpForward(); //this is a test.  2July2021 switched to this function untested
  }
}

void RampUpForward(int driveTime)
{

  motor1->run(FORWARD);
  motor2->run(FORWARD);
  for (i = 0; i < 120; i++) {
    motor1->setSpeed(i);
    motor2->setSpeed(i);
    delay(10);
    if (i == 119)
    {
      delay(driveTime);
    }
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
  motor1->setSpeed(100);
  motor2->setSpeed(100);
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
