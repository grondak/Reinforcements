#include "Player.h"

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

Player::Player()
  {

  }

void Player::initialize(int speakerPin, char inNames[], int inTones[], int inLength)
  {
    _mySpeaker = speakerPin;
    memcpy(_names, inNames, inLength * sizeof(_names[0]));
    memcpy(_tones, inTones, inLength * sizeof(_tones[0]));
    _beepTempo = 300; // a speed for the duration of the beep note
    pinMode(pin_speaker, OUTPUT);
  }

void Player::playTone(int tone, int duration)
  {
    for (long i = 0; i < duration * 1000L; i += tone * 2)
    {
      digitalWrite(_mySpeaker, HIGH);
      delayMicroseconds(tone);
      digitalWrite(_mySpeaker, LOW);
      delayMicroseconds(tone);
    }
  }

void Player::playNote(char note, int duration)
  {
    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++)
    {
      if (_names[i] == note)
      {
        playTone(_tones[i], duration);
      }
    }
  }

void Player::playSong(Song inSong)
  {

    for (int i = 0; i < inSong.length; i++)
    {
      if (inSong.notes[i] == ' ') {
        delay(inSong.beats[i] * inSong.tempo); // rest
      }
      else {
        playNote(inSong.notes[i], inSong.beats[i] * inSong.tempo);
      }

      // pause between notes
      delay(inSong.tempo / 2);
    }
  }

void Player::beep(int count)
  {
    for (int i = 0; i < count; i++)
    {
      playTone(440, _beepTempo/2);
      delay(_beepTempo/2);
    }
  }
void Player::otherBeep(int count)
  {
    for (int i = 0; i < count; i++)
    {
      playTone(880, _beepTempo/2);
      delay(_beepTempo/2);
    }
  }


