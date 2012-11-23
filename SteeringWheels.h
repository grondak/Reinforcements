#ifndef SteeringWheels_h
#define SteeringWheels_h
#include "Arduino.h"
#include <Servo.h>
class SteeringWheels
{
public:
  SteeringWheels();
   void initialize(int inSteeringPin);
   void setDirection(turning_direction_t desiredDirection);
   void goStraight();
   void turnLeft();
   void turnRight();


private:
  Servo *_psteering;
  int _pinSteering;
  turning_direction_t _currentDirection;
};



#endif
