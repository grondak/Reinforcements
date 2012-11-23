#include "Environment.h"

  Environment::Environment()
  { // this constructor does nothing thanks to Arduino!
  }

  void Environment::initialize()
  {
    static SonarTurret mySonarTurret;
    _pFrontSonar = &mySonarTurret;
    _pFrontSonar->initialize(pin_turret, pin_sonar, pin_sonar);
    for (int i = 0 ; i < 3; i++) 
    {
      this->lookAround(); // gather three ranges before taking off
      delay(100);
    }
  }

  void Environment::lookAround()
  {
    _pFrontSonar->next();
  }

  void Environment::getRanges(int *ranges)
  {
    return _pFrontSonar->getRanges(ranges);
  }

