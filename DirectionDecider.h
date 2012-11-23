#ifndef DirectionDecider_h
#define DirectionDecider_h
#include "Arduino.h"
#include "Reinforcements.h"
#include "Navigator.h"
#include "Environment.h"

class DirectionDecider
{
public:
  DirectionDecider(Navigator *inNavigator);
  turning_direction_t nextDirection(Environment *myEnvironment);

 

private:
  Navigator *_pnavigator;
  turning_direction_t freeRoamDecision(Environment *myEnvironment);

};

#endif

