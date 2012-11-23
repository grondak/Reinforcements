#ifndef Map_h
#define Map_h
#include "Reinforcements.h"
#include "Arduino.h"

class Map
{
public:
  Map();
   boolean initialized();
 private:
  static const boolean _initialized = false;
};

#endif
