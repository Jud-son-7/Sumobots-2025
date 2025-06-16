bool isFwd = true;

void turnRight();

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

void setSensorData()
{
  dist_1 = getDistance(ULT_1_TRIG, ULT_1_ECHO);
  dist_2 = getDistance(ULT_2_TRIG, ULT_2_ECHO);
  dist_3 = getDistance(ULT_3_TRIG, ULT_3_ECHO);
  // TODO: set the accelerometer data
  // TODO: set weight/pressure sensor data
  // TODO: set the light sensor data
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





