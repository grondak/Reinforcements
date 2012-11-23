#ifndef Reinforcements_h
#define Reinforcements_h
#include "Arduino.h"
void calcInput();
#ifdef __AVR_ATmega2560__ // running on the Mega, the target platform

#define CPU_TEST
// SONAR
const int pin_sonar = 4;
// SONAR Turret
const int pin_turret = 6;
// Speaker
const int pin_speaker = 7;
// Radio Receiver
const int pin_radio = 2; // INTERRUPT 0 = DIGITAL PIN 2 - use the PIN number in digitalRead
// Steering
const int pin_steering = 8;
// Electronic Speed Control
const int pin_esc = 9;
#endif

#ifdef __AVR_ATmega328P__  // running on the Uno, the prototyping platform
// SONAR
#define CPU_TEST
// SONAR
const int pin_sonar = 4;
// SONAR Turret
const int pin_turret = 6;
// Speaker
const int pin_speaker = 7;
// Radio Receiver
const int pin_radio = 2; // INTERRUPT 0 = DIGITAL PIN 2 - use the PIN number in digitalRead
// Steering
const int pin_steering = 8;
// Electronic Speed Control
const int pin_esc = 9;
#endif

#if not defined(CPU_TEST)
#error Hey you got the wrong CPU setup maaaaang
#endif


enum speed_t { stopped=90, slow=75, fast=72};
enum turning_direction_t {turn_straight = 90, turn_left = 0, turn_right = 180};
enum range_direction_t {range_straight = 1, range_left = 0, range_right = 2};
enum decision_t {free_roam = 1};

typedef struct HelmDecision
{
  turning_direction_t directionDecision;
  speed_t speedDecision;
};

const boolean run_mode = true; // FALSE: Ruckus servos are not actuated. TODO: Serial data enabled
const int throttle_signal_int = 0; // INTERRUPT 0 = DIGITAL PIN 2 - use the interrupt number in attachInterrupt
const int neutral_throttle = 1500; // this is the duration in microseconds of neutral throttle on an electric RC Car
const int deadman_threshhold = 1800; // any throttle signal greater than this will allow the truck to drive

const int min_movement_distance = 175; // if our measured distance is less than this, we will stop
const int min_straight_distance = 220; // if our measured distance is greater than this distance in cm, we will turn
#endif
