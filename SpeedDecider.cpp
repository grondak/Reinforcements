#include "SpeedDecider.h"


  SpeedDecider::SpeedDecider(Navigator *inNavigator)
  {
    _pnavigator = inNavigator;
  }

  speed_t SpeedDecider::nextSpeed(Environment *myEnvironment)
  {
    switch(_pnavigator->course())
    {
    case free_roam: // there is only one course answer from the navigator at this point
      return freeRoamDecision(myEnvironment);
      break;
    default:
      return freeRoamDecision(myEnvironment);
    }
  }

  speed_t SpeedDecider::freeRoamDecision(Environment *myEnvironment)
  {
    
    //const int min_decision_distance = 100; // if our measured distance is greater than this distance in cm, we will steer straight on
    //const int min_driving_distance = 40; // if our measured distance is greater than this distance in cm, we will stop
    speed_t decision = fast;
    int ranges[3]; // left, middle, right
    myEnvironment->getRanges(ranges);

    if(ranges[range_straight] <= min_movement_distance) // if we are too close to something, we gotta stop
    {
      decision = stopped;
    }
    else
    {
      if(ranges[range_straight] > min_straight_distance) // easy case where the next thing to hit is far in the distance
      {
        decision = fast;
      }
      else // if we are between the place to run wild and the place to stop, we should go slowly. We might be turning.
      {
        decision = slow;
      }
    }
    return decision;
  }

