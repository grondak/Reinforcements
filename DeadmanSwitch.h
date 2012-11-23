#ifndef DeadmanSwitch_h
#define DeadmanSwitch_h
#include "Arduino.h"
#include "Reinforcements.h"
class DeadmanSwitch
{
public:
  DeadmanSwitch();
  void initialize(int inInterruptPin, int inRadioPin, void (*functocall)());
  static int getRadioPin();
  boolean hasRadioSignal();
  boolean isActive(); // obtained from calcInput
  void discardCurrentSignal();
  
  static int interruptPin;  // reserve storage space for static class members
  static int radioPin; // same trick
  
  static volatile int nThrottleIn; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
  static volatile unsigned long ulStartPeriod; // set in the interrupt
  static volatile boolean bNewThrottleSignal; // set in the interrupt and read in the loop
// we could use nThrottleIn = 0 in loop instead of a separate variable, but using bNewThrottleSignal to indicate we have a new signal
// is clearer for this first example
};

#endif
