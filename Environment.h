#ifndef Environment_h
#define Environment_h
#include "Reinforcements.h"
#include "Arduino.h"
#include "SonarTurret.h"


class Environment  // for now, delegate to the SonarTurret because that is all we know
{
public:
  Environment();
  void initialize();
  void lookAround();
  void getRanges(int *ranges);

private:
  SonarTurret *_pFrontSonar;
};

#endif
