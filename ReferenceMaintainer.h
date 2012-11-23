#ifndef ReferenceMaintainer_h
#define ReferenceMaintainer_h
#include "Reinforcements.h"
#include "Song.h"
#include "Player.h"
#include "DeadmanSwitch.h"
#include "DriveWheels.h"
#include "SteeringWheels.h"
#include "Map.h"
#include "Environment.h"
#include "Navigator.h"
#include "Helmsman.h"
class ReferenceMaintainer
{

public:
  ReferenceMaintainer();
  void initialize(int speaker_pin, char initializedNames[], int initializedTones[], int numTones);

  Player MyPlayer;
  //    Song TwinkleTwinkle(length, notes, beats, tempo); // just a placeholder, can put in other tunes
  DriveWheels RearWheels;
  SteeringWheels FrontWheels;
  DeadmanSwitch Deadman;
  Environment LocalEnvironment;
  Navigator Reinforcements;
  Helmsman Helm;
  boolean justDoneWithDeadman;
};

#endif
