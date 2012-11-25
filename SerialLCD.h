#ifndef SerialLCD_h
#define SerialLCD_h
#include "Reinforcements.h"
#include "Arduino.h"


// makes use of the Mega's Serial1 port
class SerialLCD
{
  public:
    SerialLCD();
    void initialize();
    void printDirectionDecision(turning_direction_t inDirection);
    void printSpeedDecision(speed_t inSpeed, duration_t inDuration);
    void printNavigationDecision(navigation_decision_t inChoice);
    void printRanges(int ranges[3]); // left, middle, right
    void printDeadman();
    void printFreeRAM();
    void clear();
    

  private:
     void printline(int lineNumber, char *inputData);
     static const char ESC = 0xFE; 
     static const int numLines = 4; // how many lines in the serial display
     static const int numCols = 20 ; // how many columns in the serial display
     static const int LCDDelay = 20; // thanks Amazon.com guy
     char lineData[numLines][numCols]; // 4 lines of 20 characters each
     enum line_number_t {line_direction = 1, line_speed = 2, line_navigation = 3, line_ranges = 4, line_deadman = 3};
};

#endif
