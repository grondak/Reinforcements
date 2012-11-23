#ifndef Helmsman_h
#define Helmsman_h
#include "Reinforcements.h"
#include "Navigator.h"
#include "Environment.h"
#include "DirectionDecider.h"
#include "SpeedDecider.h"

class Helmsman
{
public:
  Helmsman();
  void initialize(Navigator *inNavigator, Environment *inEnvironment);
  HelmDecision* getHelmDecision();

private:
  Navigator *_navigator;
  Environment *_environment;
  DirectionDecider *_pdirectionDecider;
  SpeedDecider *_pspeedDecider;
  HelmDecision myDecision;
};


#endif
