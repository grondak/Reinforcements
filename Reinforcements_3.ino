#include <Servo.h>
#include <NewPing.h>

#include "Reinforcements.h"
#include "Song.h"
#include "Player.h"
#include "DeadmanSwitch.h"
#include "DriveWheels.h"
#include "SteeringWheels.h"
#include "SerialLCD.h"
#include "Map.h"
#include "Environment.h"
#include "Navigator.h"
#include "Helmsman.h"
#include "ReferenceMaintainer.h"


// data for Twinkle, Twinkle, Little Star
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = {
  1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

// data for the key of high C
char initializedNames[] = { // notes required for the key of C
  'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
int initializedTones[] = {
  1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };  // and their corresponding timeHigh values
int numTones = 8; // (in the key of C)

/*
  calcInput is a straight-up C function that serves as an Interrupt Service Routine.  It will be inserted
  by the DeadmanSwitch class into interrupt 0's ISR position.  When the pin goes low to high,
  the Adruino CPU will call this function in the middle of whatever the Arduino was doing.  This code
  has two side-effects:
  * modifies the DeadmanSwitch::ulStartPeriod static variable
  * modified the DeadmanSwitch::bNewThrottleSignal static variable
  
  These variables can be used later, especially by the loop() function, to determine if the
  Deadman switch is "on".  Note that Reinforcements is wired with the RC Receiver's channel 2 input
  connected straight to the Arduino pin 2.
  
*/
void calcInput()  // the Interrupt Service Routine for the Radio (the only ISR in the whole system)
{
 
  // if the pin is high, its the start of an interrupt
  if(digitalRead(DeadmanSwitch::radioPin) == HIGH)
  {
    // get the time using micros - when our code gets really busy this will become inaccurate, but for the current application its
    // easy to understand and works very well
    DeadmanSwitch::ulStartPeriod = micros();
  }
  else  {
    // if the pin is low, its the falling edge of the pulse so now we can calculate the pulse duration by subtracting the
    // start time ulStartPeriod from the current time returned by micros()
    if(DeadmanSwitch::ulStartPeriod && (DeadmanSwitch::bNewThrottleSignal == false))
    {
      DeadmanSwitch::nThrottleIn = (int)(micros() - DeadmanSwitch::ulStartPeriod);
      DeadmanSwitch::ulStartPeriod = 0;

      // tell loop we have a new signal on the throttle channel
      // we will not update nThrottleIn until loop sets
      // bNewThrottleSignal back to false
      DeadmanSwitch::bNewThrottleSignal = true;
    }
  }
}

ReferenceMaintainer rm;  // this single global will own the construction and initialization
                        // of all classes in Reinforcements


void setup()
{
  rm.initialize(pin_speaker, initializedNames, initializedTones, sizeof(initializedTones)/sizeof(int));  
}


void loop() {
  HelmDecision *instructions;


    
  if(rm.Deadman.hasRadioSignal() || !run_mode)
  {
    if(rm.justDoneWithDeadman)
    {
       instructions = rm.Helm.getHelmDecision();
       instructions = rm.Helm.getHelmDecision();
       instructions = rm.Helm.getHelmDecision();
       rm.justDoneWithDeadman = false;
     }
    instructions = rm.Helm.getHelmDecision();
    rm.LCD.printDirectionDecision(instructions->directionDecision);
    rm.LCD.printSpeedDecision(instructions->speedDecision, instructions->durationDecision);
    rm.LCD.printNavigationDecision(instructions->courseDecision);
    rm.LCD.printRanges(instructions->ranges); // left, middle, right

    rm.FrontWheels.setDirection(instructions->directionDecision);  
    rm.RearWheels.setVelocity(instructions->speedDecision);
    rm.Deadman.discardCurrentSignal();  // we have to forget what we know about the deadman switch
    delay(instructions->durationDecision);
  } // hasRadioSignal & isActive

  else
  {
    rm.justDoneWithDeadman = true;
    rm.RearWheels.halt();
    rm.FrontWheels.goStraight();
    rm.MyPlayer.beep(1);
    delay(200);
  }

} // loop




