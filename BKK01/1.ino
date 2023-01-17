
void ReadADC () //อ่านค่าเซ็นเซอร์เช็คเส้น
{
  L2 = analog (1);
  L1 = analog (2);
  R1 = analog (3);
  R2 = analog (4);
}

void ReadCan () //อ่านค่าเซ็นเซอร์เช็คเส้น
{
  Can = analog (7);
}

void ShowCan () //อ่านค่าเซ็นเซอร์เช็คเส้น
{
  ReadCan ();
  set_oled_clear(); 
  set_oled(0,0,"Can: ");  //แสดงผลคำว่า "analogA0 = " ขึ้นที่หน้าจอ คอลัมที่ 0  บรรทัด ที่ 0
  set_oled(30,0,Can); 
}


void ConvertADC()
{
  ReadADC();
  if (L1 < RefL1)L1 = 0;  // ดำ = 0 , ขาว = 1
  else L1 = 1;
  if (L2 < RefL2)L2 = 0;
  else L2 = 1;
  if (R1 < RefR1)R1 = 0;
  else R1 = 1;
  if (R2 < RefR2)R2 = 0;
  else R2 = 1;
}

void ShowADC ()
{
  ReadADC (); //เรียกใช้ฟังก์ชันอ่านค่าสี
  set_oled_clear(); 
  set_oled(0,0,"L2: ");  //แสดงผลคำว่า "analogA0 = " ขึ้นที่หน้าจอ คอลัมที่ 0  บรรทัด ที่ 0
  set_oled(30,0,analog(A1)); 
  set_oled(70,0,"L1: ");  //แสดงผลคำว่า "analogA0 = " ขึ้นที่หน้าจอ คอลัมที่ 0  บรรทัด ที่ 0
  set_oled(100,0,analog(A2)); 
  
  set_oled(0,25,"R1: ");  //แสดงผลคำว่า "analogA0 = " ขึ้นที่หน้าจอ คอลัมที่ 0  บรรทัด ที่ 0
  set_oled(30,25,analog(A3));
  set_oled(70,25,"R2: ");  //แสดงผลคำว่า "analogA0 = " ขึ้นที่หน้าจอ คอลัมที่ 0  บรรทัด ที่ 0
  set_oled(100,25,analog(A4));
}
