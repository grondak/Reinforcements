#include "Navigator.h"

Navigator::Navigator()
  {
    _decision = free_roam;
    static Map localMap;
    _pMap = &localMap;
  }

  decision_t Navigator::course() // here's the heavy lifting for now
  {
    if(!_pMap->initialized())
      return free_roam;
  }

