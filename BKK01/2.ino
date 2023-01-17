void Track_FW()
{
  check1 = 0;
  while (check1 == 0)
  {
    ConvertADC();
    if ((L2 == 0)  && (R2 == 0)) //เจอดำซ้ายก่อน&& (L1 == 0) && (R1 == 0)
    {
      check1 = 1;
      Stopp();
    }
    else if ((L1 == 1) && (R1 == 1)) //เจอขาวทั้งคู่
    {
      goStraight();
    }
    else if ((L1 == 0) && (R1 == 1)) //เจอดำทางซ้าย
    {
      goLeft();
    }
    else if ((L1 == 1) && (R1 == 0)) //เจอดำทางซ้าย
    {
      goRight();
    }
    else
    {
      goStraight();
    }
    delay(1);
  }
  delay(1);
}

void Track_Delay()
{
  for (dulation == Timedulation ; dulation <= Timedulation ; dulation++)
  {
    ConvertADC();
    if ((L1 == 1) && (R1 == 1)) //เจอขาวทั้งคู่
    {
      goStraight();
    }
    if ((L1 == 1) && (R1 == 0)) //เจอดำทางซ้าย
    {
      goRight();
    }
    if ((L1 == 0) && (R1 == 1)) //เจอดำทางซ้าย
    {
      goLeft();
    }
    delayMicroseconds (1);
  }
  Stopp();
  dulation = 0;
  Timedulation = 0;
  delay (200);
}

void goStraight()
{
  motor(1, LSpeed+10);  motor(2, RSpeed-5);
}

void goStraight2()
{
  motor(1, LSpeed);  motor(2, RSpeed);  //-1  -12   -3
}

void goStraight22()
{
  motor(1, LSpeed);  motor(2, RSpeed);  //-1  -12   -3
}

void goStraight3()
{
  motor(1, LSpeed);  motor(2, RSpeed);  //-3
}

void goStraightClossLine()
{
  motor(1, LSpeed);  motor(2, RSpeed);
  delay (250);  //
  motor(1, 0);  motor(2, 0);
  delay(50);
}

void goRight()
{
  motor(1, LSpeed+10);  motor(2, 0);   //+10
  delayMicroseconds(1);
}

void turnRightOff()
{
  motor(1, LSpeed);  motor(2, -RSpeed);
}

void turnRight()
{
  motor(1, LSpeed);  motor(2, RSpeed);
  delay (300);
  ConvertADC();
  while (R2 == 1)
  {
    ConvertADC();
    motor(1, LSpeed);  motor(2, -RSpeed);
    delay(1);
  }

  motor(1, LSpeed);  motor(2, -RSpeed);
  delay(500);

  motor(1, 0);  motor(2, 0);
  delay(50);

  ConvertADC();
  while (R2 == 0)
  {
    ConvertADC();
    motor(1, LSpeed);  motor(2, -RSpeed);
    delay(1);
  }
  motor(1, 0);  motor(2, 0);
  delay(50);

}

void goLeft()
{
  motor(1, 0);  motor(2, RSpeed+10);   //+10
  delayMicroseconds(1);
}

void turnLeftOff()
{
  motor(1, -LSpeed);  motor(2, RSpeed);
}

void turnLeft()
{
  motor(1, LSpeed);  motor(2, RSpeed);
  delay (300);
  ConvertADC();
  while (L2 == 1)
  {
    ConvertADC();
    motor(1, -LSpeed);  motor(2, RSpeed);
    delay(1);
  }

  motor(1, -LSpeed);  motor(2, RSpeed);
  delay(500);

  motor(1, 0);  motor(2, 0);
  delay(50);

  ConvertADC();
  while (L2 == 0)
  {
    ConvertADC();
    motor(1, -LSpeed);  motor(2, RSpeed);
    delay(1);
  }
  motor(1, 0);  motor(2, 0);
  delay(50);
}

void Stopp()
{
  motor(1, 0);  motor(2, 0);
  delay(50);
}
