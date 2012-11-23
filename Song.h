#ifndef Song_h
#define Song_h
#include "Arduino.h"
#include "Reinforcements.h"

#include "String.h"
class Song {
public:
  int length;
  char notes[];
  char beats[];
  int tempo;
  Song(int inLength, char inNotes[], int inBeats[], int inTempo);

};

#endif
