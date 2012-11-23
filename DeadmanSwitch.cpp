
#include "DeadmanSwitch.h"
DeadmanSwitch:: DeadmanSwitch()
{

}

void DeadmanSwitch::initialize(int inInterruptPin, int inRadioPin, void (*functocall)() )
{
  nThrottleIn = neutral_throttle;
  ulStartPeriod = 0;
  bNewThrottleSignal = false;
  interruptPin = inInterruptPin;
  radioPin = inRadioPin;
  attachInterrupt(interruptPin, (*functocall), CHANGE); // calcInput must be a regular function with access to globals
}

int DeadmanSwitch::getRadioPin()
{
  return radioPin;
}

boolean DeadmanSwitch::hasRadioSignal()
{
  return bNewThrottleSignal;  // obtained from calcInput
}

boolean DeadmanSwitch::isActive()  // obtained from calcInput
{
  return nThrottleIn > deadman_threshhold;
}

void DeadmanSwitch::discardCurrentSignal()
{
  bNewThrottleSignal = false;
}

int DeadmanSwitch::interruptPin;
int DeadmanSwitch::radioPin;
volatile int DeadmanSwitch::nThrottleIn; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
volatile unsigned long DeadmanSwitch::ulStartPeriod; // set in the interrupt
volatile boolean DeadmanSwitch::bNewThrottleSignal; // set in the interrupt and read in the loop
