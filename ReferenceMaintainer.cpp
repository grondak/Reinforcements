#include "ReferenceMaintainer.h"

  ReferenceMaintainer::ReferenceMaintainer()
  {

  }

  void ReferenceMaintainer::initialize(int speaker_pin, char initializedNames[], int initializedTones[], int numTones)
  {
    MyPlayer.initialize(speaker_pin, initializedNames, initializedTones, numTones);
    RearWheels.initialize(pin_esc);
    FrontWheels.initialize(pin_steering);
    Deadman.initialize(throttle_signal_int, pin_radio, &calcInput);
    //   MyPlayer.beep(3);

    //   MyPlayer.beep(2);
    LocalEnvironment.initialize();
    Helm.initialize(&Reinforcements, &LocalEnvironment);
    // Beep 3 times on the window if you want me
    justDoneWithDeadman = false;
    MyPlayer.beep(3);
  }

