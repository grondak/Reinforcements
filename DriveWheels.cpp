#include "Reinforcements.h"
#include "DriveWheels.h"


DriveWheels::DriveWheels()
  {

  }

  void DriveWheels::initialize(int inESCPin)
  {
    static Servo myStaticServo;
    
    _pinESC = inESCPin;
    _pESC = &myStaticServo;
    _currentSpeed = stopped;

    _pESC->attach(_pinESC);
    setVelocity(_currentSpeed);
  }

  void DriveWheels::setVelocity(speed_t desiredSpeed)
  {
    _currentSpeed = desiredSpeed;
    Serial.print("DriveWheels setting speed: ");
    Serial.println(_currentSpeed);
    if(run_mode)
      _pESC->write(_currentSpeed);
  }

  void DriveWheels::halt()
  {
    setVelocity(stopped);
  }

  void DriveWheels::pause(int duration)
  {
    speed_t previousSpeed = _currentSpeed;
    halt();
    delay(duration);
    setVelocity(previousSpeed);
  }

  void DriveWheels::goFast()
  {
    setVelocity(fast);
  }

  void DriveWheels::goFast(int duration)
  {
    goFast();
    delay(duration);
  }

  void DriveWheels::fastBurst(int duration)
  {
    goFast(duration);
    halt();
  }

  void DriveWheels::goSlow()
  {
    setVelocity(slow);
  }

  void DriveWheels::goSlow(int duration)
  {
    goSlow();
    delay(duration);

  }

  void DriveWheels::slowBurst(int duration)
  {
    goSlow(duration);
    halt();
  }

