void SetUpScreen(int select)
{
  switch(select)
  {
    case 0:
      TOUCH_ORIENTATION=PORTRAIT;
      bPL=0;
    break;

    case 1:
      TOUCH_ORIENTATION=LANDSCAPE;
      bPL=7;
    break;
  }
  GLCD7.InitLCD(TOUCH_ORIENTATION);
  GLCD7.clrScr();
  myTouch.InitTouch(TOUCH_ORIENTATION);
  myTouch.setPrecision(PREC_LOW);
  keypad(TOUCH_ORIENTATION);
  title_bar();
}

void Select_Orientation(int select)
{
  switch(select)
  {
    case 0:
      TOUCH_ORIENTATION=PORTRAIT;
      bPL=0;
    break;

    case 1:
      TOUCH_ORIENTATION=LANDSCAPE;
      bPL=7;
    break;
  }
  GLCD7.InitLCD(TOUCH_ORIENTATION);
  GLCD7.clrScr();
  myTouch.InitTouch(TOUCH_ORIENTATION);
  myTouch.setPrecision(PREC_LOW);
  keypad(TOUCH_ORIENTATION);
  title_bar();
}

void title_bar(void)
{
  dispx = GLCD7.getDisplayXSize();
  dispy = GLCD7.getDisplayYSize();
  GLCD7.setFont(bell12);
  GLCD7.setColor(VLB_RED);
  GLCD7.fillRect(0, 0, dispx - 1, 16);
  GLCD7.setBackColor(VLB_RED);
  GLCD7.setColor(VLB_YELLOW);
  GLCD7.drawLine(0, 17, dispx - 1, 17);
  GLCD7.print(TITLE, CENTER, 3);
  GLCD7.drawLine(0,dispy-260,dispx-1,dispy-260);
  GLCD7.drawLine(0,dispy-259,dispx-1,dispy-259);
  GLCD7.setBackColor(VLB_BLACK);
}

void clrscr(void)
{
  delay(2000);
  GLCD7.setBackColor(VLB_BLACK);
  GLCD7.setColor(VLB_BLACK);
  GLCD7.fillRect(0,25,dispx-1,dispy-261);
}

