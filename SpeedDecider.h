#ifndef SpeedDecider_h
#define SpeedDecider_h
#include "Reinforcements.h"
#include "Navigator.h"
#include "Environment.h"

class SpeedDecider // the speed decider has no idea where it is going, it just knows that going straight means to speed
// and that turning means to slow down
{
public:
  SpeedDecider(Navigator *inNavigator);
  speed_t nextSpeed(Environment *myEnvironment);


private:
  Navigator *_pnavigator;
  speed_t freeRoamDecision(Environment *myEnvironment);
};

#endif
