#include "DirectionDecider.h"


DirectionDecider::DirectionDecider(Navigator *inNavigator)
  {
    _pnavigator = inNavigator;
  }

  turning_direction_t DirectionDecider::nextDirection(Environment *myEnvironment)
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

  turning_direction_t DirectionDecider::freeRoamDecision(Environment *myEnvironment)
  {
    turning_direction_t decision = turn_straight;
    int ranges[3]; // left, middle, right
    myEnvironment->getRanges(ranges);

    if(ranges[range_straight] > min_straight_distance) // easy case where the next thing to hit is far in the distance
    {
      decision = turn_straight;
    }
    else
    {
      if(ranges[range_left] >= ranges[range_right]) // this means we can turn left, and we pick left if we can go either way
      {
        decision = turn_left;
      }
      else
      {
        decision = turn_right;
      }
    }
    return decision;
  }

