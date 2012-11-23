#ifndef DriveWheels_h
#define DriveWheels_h
#include "Arduino.h"
#include <Servo.h>

class DriveWheels
{
public:
  DriveWheels();
  void initialize(int inESCPin);
   void setVelocity(speed_t desiredSpeed);
  void halt();
  void pause(int duration);
  void goFast();
  void goFast(int duration);
  void fastBurst(int duration);
  void goSlow();
  void goSlow(int duration);
  void slowBurst(int duration);

private:
  Servo *_pESC;
  int _pinESC;
  speed_t _currentSpeed;
};
#endif
