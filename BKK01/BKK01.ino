#include <NKP_ONE.h>   
int L2, L1, R1, R2, Can;
int RefL2 = 1400, RefL1 = 2050, RefR1 = 1800, RefR2 = 1800; //int RefL2 = 1150, RefL1 = 2450, RefR1 = 1800, RefR2 = 1900;   //int RefL2 = 1200, RefL1 = 2300, RefR1 = 1600, RefR2 = 1600; int RefL2 = 1900, RefL1 = 1200, RefR1 = 2500, RefR2 = 2500; 
int Speed, LSpeed, RSpeed;
int check1 = 0;
int chkCan = 0;
int dulation = 0;
int Timedulation = 0;
void setup()
{
  
  LSpeed = 85;    
  RSpeed = 80;    
  NKP_ONE();      
  beep();
  servo(4, 0);    
  servo(1, 10);   
  delay(500);
  servo(3, 0);    

  IO15();        

  beep();
  delay(100);

  //while(1);
}

void loop()
{
  ShowCan ();
  while (chkCan == 0)
  {
    ShowCan ();
    if (Can <= 500)
    {
      beep();
      delay(500);
      chkCan = 1;
    }
    else
    {
      delay(100);
    }
    delay(100);
  }
  beep();
  beep();
  beep();
  servo(3, 50); 
  delay (500);

  goStraight2();
  delay(800);
  Stopp();

  Track_FW();
  delay(300);
  goStraightClossLine();
  delay(300);

  turnLeft();

  Track_FW();
  delay(300);
  goStraightClossLine();
  delay(300);

  turnLeft();

  Track_FW();
  delay(300);
  goStraightClossLine();
  delay(300);
  turnRight();

  Track_FW();
  delay(300);

  goStraight22();
  delay(4700);  
  Stopp();
  delay(2000);

  Track_FW();
  delay(300);

  goStraight2();  
  delay(1800);    
  Stopp();
  delay(300);

  turnRightOff();
  delay(1600);   
  Stopp();
  delay(3000);

  goStraight2();
  delay(700);
  Stopp();
  delay(300);

  Track_FW();
  delay(300);
  goStraightClossLine();
  delay(300);

  turnRight();  

  ////////////////////////

  Timedulation = 600;   //800
  Track_Delay();
  delay(2000);

  goStraight2();
  delay(1700);         
  Stopp();
  delay(2000);

  //while (1);
  ///////////////////////

  Track_FW();
  delay(300);
  goStraightClossLine();
  delay(300);

  Track_FW();
  delay(300);
  goStraightClossLine();
  delay(300);

  goStraight3();
  delay(1200);  
  Stopp();
  delay(2000);

  servo(1, 180);    //arm
  delay(1000);
  servo(3, 0);   // grab  
  delay(1000);
  servo(1, 90);   //arm
  delay(1000);
  servo(4, 90);//flag    
  beep();
  beep();
  beep();
  beep();
  beep();
  while (1);


  //////
  //  Timedulation = 1000;
  //  Track_Delay();
  while (1);
  //////

}
