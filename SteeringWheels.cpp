#include "Reinforcements.h"
#include "SteeringWheels.h"


SteeringWheels::SteeringWheels()
  {

  }

  void SteeringWheels::initialize(int inSteeringPin)
  {
    static Servo mySteering;
    _psteering = &mySteering;
    _pinSteering = inSteeringPin;
    _currentDirection = turn_straight;
    _psteering->attach(_pinSteering);
    setDirection(_currentDirection);
  }

  void SteeringWheels::setDirection(turning_direction_t desiredDirection)
  {
    _currentDirection = desiredDirection;
    if(run_mode)
    _psteering->write(desiredDirection);
  }

  void SteeringWheels::goStraight()
  {
    setDirection(turn_straight);
  }

  void SteeringWheels::turnLeft()
  {
    setDirection(turn_left);
  }

  void SteeringWheels::turnRight()
  {
    setDirection(turn_right);
  }

