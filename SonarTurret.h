#ifndef SonarTurret_h
#define SonarTurret_h
#include "Reinforcements.h"
#include <Servo.h>
#include <NewPing.h>

class SonarTurret
{

  // gets the ranges and stuffs them in an array of left range, straight range, right range
  // TODO: this is kind of dumb; in the future we can fix this so there is a struct with named variables for these data
public:
  SonarTurret();
  void initialize(int inTurretServoPin, int inSonarSendPin, int inSonarReceivePin);
  void getRanges(int *ranges);
  void next();
 
private:
  Servo *_pturretServo;
  int _turretServoPin;
  int _turretHeading;
  int _turretMovementDirection;
  int _turretHeadings[3];
  int _totalHeadings;
  static const int turretCalibration_90 = 97; // the turret isn't on straight but the servo doesn't care, so adjust the actual heading by 7 degrees
  static const int turretServoSettleDelay = 100; // the time the turret takes to settle to the new position
  
  NewPing *_psonar;
  int _sonarSendPin;
  int _sonarReceivePin;
  int _currentRanges[3];
  static const int maxDistance = 250; // the max distance we will try will accept from the sonar



};


#endif
