#include <Stepper.h>

const int stepsPerRevolution = 200;
int delayTime = 50;

// initialize the stepper library on the motor shield
Stepper myStepper(stepsPerRevolution, 12, 13);

// give the motor control pins names:
const int pwmA = 3;
const int pwmB = 11;
const int brakeA = 9;
const int brakeB = 8;
const int dirA = 12;
const int dirB = 13;

int stepRepeat = 80;
int stepSpeed = 10;
int lightLevel_0 = 0;
int lightLevel_1 = 0;

void setup()
{
  Serial.begin(9600);
  // set the PWM and brake pins so that the direction pins
  // can be used to control the motor:
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, HIGH);
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);

  // set the motor speed (for multiple steps only):
  myStepper.setSpeed(10);
}

void loop() {
  lightLevel_0 = analogRead(A0);
  lightLevel_1 = analogRead(A1);
  Serial.println("The Light value is: ");
  Serial.print("Light_level_00: ");
  Serial.println(lightLevel_0);

  Serial.print("Light_level_01: ");
  Serial.println(lightLevel_1);


  int light_level_total = 0;

  light_level_total = lightLevel_0 + lightLevel_1;
  Serial.println(light_level_total);
  
  if(light_level_total >= 0 && light_level_total < 220) {
    stepSpeed = 10;
    stepRepeat = 80;
    myStepper.setSpeed(stepSpeed);
    myStepper.step(stepRepeat);
    myStepper.step(-stepRepeat);
    delay(delayTime);
  }
  else if (light_level_total >= 220 && light_level_total < 230) {
    stepSpeed = 40;
    stepRepeat = 200;
    myStepper.setSpeed(stepSpeed);
    myStepper.step(stepRepeat);
    delay(delayTime);
  }
  else if (light_level_total >= 230 && light_level_total < 330) {
    stepSpeed = 60;
    stepRepeat = 200;
    myStepper.setSpeed(stepSpeed);
    myStepper.step(stepRepeat);
    delay(delayTime);
  }
  else if (light_level_total >= 330) {
    stepSpeed = 80;
    stepRepeat = 200;
    myStepper.setSpeed(stepSpeed);
    myStepper.step(stepRepeat);
    delay(delayTime);
  }

  //myStepper.step(-stepRepeat);
  delay(delayTime);
}
