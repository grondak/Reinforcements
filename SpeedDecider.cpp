#include "SpeedDecider.h"


  SpeedDecider::SpeedDecider(Navigator *inNavigator)
  {
    _pnavigator = inNavigator;
  }

  speed_t SpeedDecider::nextSpeed(Environment *myEnvironment, turning_direction_t currentDirection)
  {
    switch(_pnavigator->course())
    {
    case free_roam: // there is only one course answer from the navigator at this point
      return freeRoamSpeedDecision(myEnvironment, currentDirection);
      break;
    default:
      return freeRoamSpeedDecision(myEnvironment, currentDirection);
    }
  }

//enum turning_direction_t {turn_straight = 90, turn_left = 0, turn_right = 180};
//enum range_direction_t {range_straight = 1, range_left = 0, range_right = 2};

  range_direction_t SpeedDecider::convertDirectionDecisionToRange(turning_direction_t inputDirection)
  {
    switch(inputDirection)
    {
      case turn_straight:
        return range_straight;
        break;
      case turn_left:
        return range_left;
        break;
      case turn_right:
        return range_right;
    }
  }

  speed_t SpeedDecider::freeRoamSpeedDecision(Environment *myEnvironment, turning_direction_t currentDirection)
  {
    
    //const int min_decision_distance = 100; // if our measured distance is greater than this distance in cm, we will steer straight on
    //const int min_driving_distance = 40; // if our measured distance is greater than this distance in cm, we will stop
    speed_t decision = fast;
    int ranges[3]; // left, middle, right
    myEnvironment->getRanges(ranges);
    range_direction_t currentRangeDirection = convertDirectionDecisionToRange(currentDirection);
    if(ranges[currentRangeDirection] <= min_movement_distance) // if we are too close to something, we gotta stop
    {
      decision = stopped;
    }
    else
    {
      if(ranges[currentRangeDirection] > min_straight_distance) // easy case where the next thing to hit is far in the distance
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
    
    
    duration_t SpeedDecider::nextDuration(Environment *myEnvironment, turning_direction_t currentDirection)
    {
      switch(_pnavigator->course())
      {
        case free_roam:
          return freeRoamDurationDecision(myEnvironment, currentDirection);
          break;
        default:
          return freeRoamDurationDecision(myEnvironment, currentDirection);
      }
    }
    
    duration_t SpeedDecider::freeRoamDurationDecision(Environment *myEnvironment, turning_direction_t currentDirection)
    {
      duration_t decision = going_straight_duration;  // if we are going straight, drive for a long time
      if(currentDirection != turn_straight) // if we are not going straight, make more decisions per second
        decision = turning_duration;
      
      return decision;
    }
    


