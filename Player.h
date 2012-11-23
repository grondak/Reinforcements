#ifndef Player_h
#define Player_h
#include "Arduino.h"
#include "Song.h"
#include "String.h"
#include "Reinforcements.h"

class Player {

  /* Melody
   * (cleft) 2005 D. Cuartielles for K3
   *
   * This example uses a piezo speaker to play melodies.  It sends
   * a square wave of the appropriate frequency to the piezo, generating
   * the corresponding tone.
   *
   * The calculation of the tones is made following the mathematical
   * operation:
   *
   *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
   *
   * where the different tones are described as in the table:
   *
   * note  frequency  period  timeHigh
   * c          261 Hz          3830  1915
   * d          294 Hz          3400  1700
   * e          329 Hz          3038  1519
   * f          349 Hz          2864  1432
   * g          392 Hz          2550  1275
   * a          440 Hz          2272  1136
   * b          493 Hz          2028 1014
   * C         523 Hz         1912  956
   *
   * http://www.arduino.cc/en/Tutorial/Melody
   */
public:
  Player();
  void initialize(int speakerPin, char inNames[], int inTones[], int inLength);
  void playTone(int tone, int duration);
  void playNote(char note, int duration);
  void playSong(Song inSong);
  void beep(int count);
  void otherBeep(int count);
private:
  int _beepTempo;
  int _mySpeaker;
  char _names[];
  int _tones[];
};

#endif
