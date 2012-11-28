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
  speed_t nextSpeed(Environment *myEnvironment, turning_direction_t currentDirection);
  duration_t nextDuration(Environment *myEnvironment, turning_direction_t currentDirection);

private:
  Navigator *_pnavigator;
  speed_t freeRoamSpeedDecision(Environment *myEnvironment, turning_direction_t currentDirection);
  duration_t freeRoamDurationDecision(Environment *myEnvironment, turning_direction_t currentDirection);
  range_direction_t convertDirectionDecisionToRange(turning_direction_t inputDirection);
};

#endif
