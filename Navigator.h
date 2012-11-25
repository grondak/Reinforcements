#ifndef Navigator_h
#define Navigator_h
#include "Reinforcements.h"
#include "Map.h"

class Navigator // the navigator will use the map to determine where we want to go.
// since there is no map, there is no real decision-- if you chose not to decide, you still have made a choice. I will chose free roa
{
public:
  Navigator();
  navigation_decision_t course(); // here's the heavy lifting for now
private:
  navigation_decision_t _decision;
  Map *_pMap;
};


#endif
