#include "Helmsman.h"


Helmsman::Helmsman()
  {

    
  }
  
void Helmsman::initialize(Navigator *inNavigator, Environment *inEnvironment)
{
  _navigator = inNavigator;
  _environment = inEnvironment;
  static DirectionDecider _localDirectionDecider(_navigator);
  _pdirectionDecider = &_localDirectionDecider;
  static SpeedDecider _localSpeedDecider(_navigator);
  _pspeedDecider = &_localSpeedDecider;

}
  HelmDecision* Helmsman::getHelmDecision()
  {
    _environment->lookAround();
    myDecision.courseDecision = _navigator->course();
    myDecision.directionDecision = _pdirectionDecider->nextDirection(_environment);
    myDecision.speedDecision = _pspeedDecider->nextSpeed(_environment);
    myDecision.durationDecision = _pspeedDecider->nextDuration(_environment);
    _environment->getRanges(myDecision.ranges);

    return &myDecision;
  }

