#include "SpeedyStepper.h"

SpeedyStepper armStepper;

int microStepping = 8;
float armAccel = 3;
float armSpeed = .5;
int steps = 200;
int transmissionRatio = 2;

float maxDistance = 1.0;
int HOME_LIMIT_SWITCH_PIN = A1;


void setup() {
  // put your setup code here, to run once:
  // pinMode(HOME_LIMIT_SWITCH_PIN, INPUT_PULLUP);
  armStepper.connectToPort(1);
  armStepper.setAccelerationInRevolutionsPerSecondPerSecond(armAccel);
  armStepper.setStepsPerRevolution(transmissionRatio * microStepping * steps);
  armStepper.setSpeedInRevolutionsPerSecond(armSpeed);

  armStepper.moveToHomeInRevolutions(1, armSpeed, maxDistance, HOME_LIMIT_SWITCH_PIN);

  delay(1000);

  armStepper.moveToPositionInRevolutions(-.74);

  delay(1000);

  armStepper.moveRelativeInRevolutions(.16);



}

void loop() {
  // put your main code here, to run repeatedly:

}
