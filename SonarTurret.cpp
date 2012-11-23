#include "Reinforcements.h"
#include "SonarTurret.h"
  // gets the ranges and stuffs them in an array of left range, straight range, right range
  // TODO: this is kind of dumb; in the future we can fix this so there is a struct with named variables for these data

  SonarTurret::SonarTurret()
  {

  }

  void SonarTurret::initialize(int inTurretServoPin, int inSonarSendPin, int inSonarReceivePin)
  {

    static Servo turretServo;
    _pturretServo = &turretServo;
    _turretServoPin = inTurretServoPin;
    _pturretServo->attach(_turretServoPin);
    _turretHeadings[0] = turretCalibration_90-70;
    _turretHeadings[1] = turretCalibration_90;
    _turretHeadings[2] = turretCalibration_90+70;
    _turretHeading = 0;
    _totalHeadings = sizeof(_turretHeadings)/sizeof(_turretHeadings[0]);
    _turretMovementDirection = 1;
    _pturretServo->write(_turretHeadings[_turretHeading]); // initialize the turret to the far left.
    delay(turretServoSettleDelay);


    _sonarSendPin = inSonarSendPin;
    _sonarReceivePin = inSonarReceivePin;
    static NewPing sonar(_sonarSendPin, _sonarReceivePin, maxDistance);
    _psonar = &sonar;
    _currentRanges[0] = 10;
    _currentRanges[1] = 10;
    _currentRanges[2] = 10;
  }

  void SonarTurret::getRanges(int *ranges)
  {

    for (int i = 0; i < _totalHeadings; i++)
    {
      *ranges++ = _currentRanges[i];
      Serial.print("Range[");
      Serial.print(i);
      Serial.print("]: ");
      Serial.println(_currentRanges[i]);
    }
    return;
  }

  void SonarTurret::next()
  {

    _turretHeading += _turretMovementDirection;
    if(_turretHeading < 0)
    {
      _turretHeading = 1;
      _turretMovementDirection = 1;
    }
    else if(_turretHeading >= _totalHeadings)
    {
      _turretHeading = 1;
      _turretMovementDirection = -1;
    }
    _pturretServo->write(_turretHeadings[_turretHeading]);
    delay(turretServoSettleDelay); // to allow the servo to settle down
    
    
    int uS = _psonar->ping(); // get a distance
    int distance = uS / US_ROUNDTRIP_CM;
    if (distance == 0) // someone has their hand over the sonar, or we have exceeded maxDistance
      distance = maxDistance;  // force to maxDistance
    Serial.print("Sonar range: ");
    Serial.println(distance);
    Serial.print("Turret heading: ");
    Serial.println(_turretHeading);
    _currentRanges[_turretHeading] = distance;  // keep it for the environment
  }



