#ifndef BOT_H
#define BOT_H
#include "botInterface.h"

bool isFwd = true; // need to find a better way to do this

void setForwards()
{
  isFwd = true;
  digitalWrite(RT_FWD, HIGH);
  digitalWrite(RT_BWD, LOW);
  digitalWrite(LF_FWD, HIGH);
  digitalWrite(LF_BWD, LOW);
}

void setBackwards()
{
  isFwd = false;
  digitalWrite(RT_FWD, LOW);
  digitalWrite(RT_BWD, HIGH);
  digitalWrite(LF_FWD, LOW);
  digitalWrite(LF_BWD, HIGH);
}

void turnLeft()
{
  if (isFwd == false)
  {
    turnRight();
  }
  else{
    digitalWrite(RT_FWD, HIGH);
    digitalWrite(RT_BWD, LOW);
    digitalWrite(LF_FWD, LOW);
    digitalWrite(LF_BWD, HIGH);
  }
}

void turnRight()
{
  if (isFwd == false)
  {
    turnLeft();
  }

  else{
    digitalWrite(RT_FWD, LOW);
    digitalWrite(RT_BWD, HIGH);
    digitalWrite(LF_FWD, HIGH);
    digitalWrite(LF_BWD, LOW);
  }
}

/*
  returns the distance in cm, of how far something is
 */
double getDistance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  double time = pulseIn(echo, HIGH);

  return (time * 0.034) / 2;

}

// May not be need since we may initiialise the speed
// to the highest possible speed from the get go
void setSpeed()
{
  // TODO
}

#endif 




