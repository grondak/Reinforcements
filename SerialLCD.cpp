
#include "SerialLCD.h"

// SerialLCD knows how to print things that are relevant to Reinforcements
// It has one line for general messages
/*
from Reinforcements.h:
 enum speed_t { stopped=90, slow=75, fast=72};
 enum turning_direction_t {turn_straight = 90, turn_left = 0, turn_right = 180};
 enum range_direction_t {range_straight = 1, range_left = 0, range_right = 2};
 enum navigation_decision_t {free_roam = 1};
 typedef int duration_t;
 
 */

SerialLCD:: SerialLCD()
{

}

void SerialLCD::initialize()
{
  Serial1.begin(9600);
  Serial1.write(ESC); 
  Serial1.write(0x41); 
  Serial1.write(ESC); 
  Serial1.write(0x51); // Set Contrast 
  Serial1.write(ESC); 
  Serial1.write(0x52); 
  Serial1.write(40); // Set Backlight
  Serial1.write(ESC); 
  Serial1.write(0x53); 
  Serial1.write(8);
  for( int x; x< numLines; x++) // zero out our string holder
  {
    memset(lineData[x],0, 1);
  }
}

// a human interpretation of the data in the Decision system
void SerialLCD::printDirectionDecision(turning_direction_t inDirection)
{
  int zerobaseLine = line_direction - 1;
  strcpy(lineData[zerobaseLine],"Dir: ");
  switch(inDirection)
  {
  case turn_left:
    strcat(lineData[zerobaseLine], "Left");
    break;
  case turn_straight:
    strcat(lineData[zerobaseLine], "Straight");
    break;
  case turn_right:
    strcat(lineData[zerobaseLine], "Right");
    break;
  default:
    strcat(lineData[zerobaseLine], "Undef dir");
  }
  printline(line_direction, lineData[zerobaseLine]);
}

void SerialLCD::printSpeedDecision(speed_t inSpeed, duration_t inDuration)
{
  
  int zerobaseLine = line_speed - 1;
  char frontOfLine[numCols];
  strcpy(frontOfLine,"Speed: ");
  switch(inSpeed)
  {
  case stopped:
    strcat(frontOfLine, "Stopped:");
    break;
  case slow:
    strcat(frontOfLine, "Slow:");
    break;
  case fast:
    strcat(frontOfLine, "Fast:");
    break;
   default:
    strcat(frontOfLine, "Undef speed");
    break;
  }
  snprintf(lineData[zerobaseLine], numCols, "%s (%i)ms", frontOfLine, inDuration);
  printline(line_speed, lineData[zerobaseLine]); 
}

void SerialLCD::printNavigationDecision(navigation_decision_t inChoice)
{
  int zerobaseLine = line_navigation - 1;
  char courseType[numCols];
  switch(inChoice)
  {
    case free_roam:
      strcpy(courseType, "Free Roam");
      break;
    default:
      strcpy(courseType, "Undefined");
      break;
  }
  snprintf(lineData[zerobaseLine], numCols, "Course Type: %s", courseType);
  printline(line_navigation, lineData[zerobaseLine]);

}


void SerialLCD::printRanges(int ranges[3])// left, middle, right
{
  snprintf(lineData[line_ranges], numCols, "L: %i|C: %i|R: %i", ranges[0], ranges[1], ranges[2]);
}

void SerialLCD::printline(int lineNumber, char *inputData)
{
  Serial1.write(ESC);  // set up the ESC Char
  Serial1.write(0x45); // send the address-cursor line cmd
  char switchToLineChar = 0;
  // based on the line number, we select a cursor position code
  switch(lineNumber) // use from the Longtech LCD manual p.8
  {
  case 1:
    switchToLineChar = 0;
    break;
  case 2:
    switchToLineChar = 0x40;
    break;
  case 3:
    switchToLineChar = 0x14;
    break;
  case 4:
    switchToLineChar = 0x54;
    break;
  default:
    switchToLineChar = 0;
  }
  Serial1.write(switchToLineChar); // send the code
  Serial1.print(inputData); // now print the data
}

