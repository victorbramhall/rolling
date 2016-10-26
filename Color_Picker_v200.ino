/**********************************************************************
                    48 Bit RBG Color Decoder
                 for 800x480 Touch Screen TFTs
                          10 Oct 2016
                             v2.00
**********************************************************************/
#define TITLE "48 Bit RBG Color Decoder v2.00"
#define Ver 2.00

#include <UTFT.h>
#include <UTFT_DLB.h>
#include <URTouch.h>
#include <VLB_Colors.h>

UTFT_DLB myGLCD(CTE70, 25, 26, 27, 28);         // Arduino Due LCD shield
URTouch  myTouch( 6, 5, 32, 3, 2);

#define TOUCH_ORIENTATION  LANDSCAPE        //PORTRAIT

extern uint8_t mod2016[];
extern uint8_t tnr22[];
extern uint8_t BigFont[];
extern uint8_t Symbols[];

void setup(void);
void loop(void);
unsigned long keypad(void); 

uint32_t Color = 0x00FFFFFF;
int dispx, dispy;
char buf[200];

void setup(void)
{
  myGLCD.InitLCD(TOUCH_ORIENTATION);
  myGLCD.clrScr();
  myTouch.InitTouch(TOUCH_ORIENTATION);
  myTouch.setPrecision(PREC_LOW);
  dispx = myGLCD.getDisplayXSize();
  dispy = myGLCD.getDisplayYSize();

  myGLCD.setColor(VLB_ORANGE);
  myGLCD.fillRect(0, 0, dispx - 1, 16);
  myGLCD.setColor(VLB_YELLOW);
  myGLCD.setBackColor(VLB_ORANGE);
  myGLCD.drawLine(0, 17, dispx - 1, 17);
  myGLCD.setFont(mod2016);
  myGLCD.print(TITLE, CENTER, 1);

  keypad();
}

void loop(void)
{
  myGLCD.setFont(tnr22);
  myGLCD.setBackColor(VLB_BLACK);
  myGLCD.setColor(VLB_WHITE);
  sprintf(buf, "0x%08X   ",Color);
  myGLCD.print(buf,355,75);
  myGLCD.setColor(Color);
  myGLCD.setBackColor(Color);
  myGLCD.fillRoundRect(245,125,600,275);
  myGLCD.setColor(VLB_WHITE);
  myGLCD.drawRoundRect(245,125,600,275);

  while (!myTouch.dataAvailable());

  delay(90);
  myTouch.read();
  myTouch.getX();
  myTouch.getY();
/*
  myGLCD.setBackColor(VLB_BLACK);
  myGLCD.setColor(VLB_WHITE);
  sprintf(buf,"TP_X= %d     TP_Y= %d        ",myTouch.TP_X,myTouch.TP_Y);
  myGLCD.print(buf,1,90);
  while (myTouch.dataAvailable());
*/  
  if(myTouch.TP_Y>2770&&myTouch.TP_Y<3100)
  {
    if(myTouch.TP_X>1370&&myTouch.TP_X<1620)      // Button 1
    {
      Color+=0x00100000;
    }
    if(myTouch.TP_X>1670&&myTouch.TP_X<1870)      // Button 2
    {
      Color+=0x00010000;
    }
    if(myTouch.TP_X>1930&&myTouch.TP_X<2100)      // Button 3
    {
      Color+=0x00001000;
    }
    if(myTouch.TP_X>2170&&myTouch.TP_X<2330)      // Button 4
    {
      Color+=0x00000100;
    }
    if(myTouch.TP_X>2400&&myTouch.TP_X<2600)      // Button 5
    {
      Color+=0x00000010;
    }
    if(myTouch.TP_X>2700&&myTouch.TP_X<2900)      // Button 6
    {
      Color+=0x00000001;
    }
  }
  if(myTouch.TP_Y>3160&&myTouch.TP_Y<3500)
  {
    if(myTouch.TP_X>1370&&myTouch.TP_X<1620)      // Button 7
    {
      Color-=0x00100000;
    }
    if(myTouch.TP_X>1670&&myTouch.TP_X<1870)      // Button 8
    {
      Color-=0x00010000;
    }
    if(myTouch.TP_X>1930&&myTouch.TP_X<2100)      // Button 9
    {
      Color-=0x00001000;
    }
    if(myTouch.TP_X>2170&&myTouch.TP_X<2330)      // Button 10
    {
      Color-=0x00000100;
    }
    if(myTouch.TP_X>2400&&myTouch.TP_X<2600)      // Button 11
    {
      Color-=0x00000010;
    }
    if(myTouch.TP_X>2700&&myTouch.TP_X<2900)      // Button 12
    {
      Color-=0x00000001;
    }
  }
}


