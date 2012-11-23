#include "Song.h"


Song::Song(int inLength, char inNotes[], int inBeats[], int inTempo)
  {
    length = inLength;
    memcpy(notes, inNotes, inLength*sizeof(notes[0]));
    memcpy(beats, inBeats, inLength*sizeof(beats[0]));
    tempo = inTempo;
  }
