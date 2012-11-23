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
    myDecision.directionDecision = _pdirectionDecider->nextDirection(_environment);
    myDecision.speedDecision = _pspeedDecider->nextSpeed(_environment);

    return &myDecision;
  }

