/**********************************************************************
 *                   24 Bit RBG Color Decoder                         *
 *                 for 480x320 Touch Screen TFTs                      *
 *                          25 May 2017                               *
 *                             v4.80                                  *
 **********************************************************************/
#define TITLE "24 Bit RBG Color Decoder v4.80"
#define Ver 4.80

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <VLB_Colors.h>

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerifBold12pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSerifBold9pt7b.h>
#include <Fonts/FreeSerifBold18pt7b.h>

MCUFRIEND_kbv myGLCD;

#define PORTRAIT 0
#define LANDSCAPE 1
#define PORTRAIT_ALT 2
#define LANDSCAPE_ALT 3

//#define TOUCH_ORIENTATION  PORTRAIT
#define TOUCH_ORIENTATION  LANDSCAPE
//#define TOUCH_ORIENTATION  PORTRAIT_ALT
//#define TOUCH_ORIENTATION  LANDSCAPE_ALT

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4

uint8_t YP = A2;  // must be an analog pin, use "An" notation!
uint8_t XM = A3;  // must be an analog pin, use "An" notation!
uint8_t YM = 8;   // can be a digital pin
uint8_t XP = 9;   // can be a digital pin
/*
uint8_t YP = A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 7;   // can be a digital pin
uint8_t XP = 6;   // can be a digital pin
*/
TouchScreen ts=TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;

#define MINPRESSURE 3
#define MAXPRESSURE 1000

void setup(void);
void loop(void);
void buttons(int sel);
void keypad(void); 

uint16_t Red=255,Green=255,Blue=255;
uint32_t color24=0xFFFFFF;
uint16_t color16=0xFFFF;

int dispx, dispy;
int T10=0;
char buf[200];
char tm[20];

void setup(void)
{
int identifier;

  myGLCD.reset();
  identifier = myGLCD.readID();
  myGLCD.begin(identifier);
  myGLCD.setRotation(TOUCH_ORIENTATION);
  dispx=myGLCD.width();
  dispy=myGLCD.height();
  myGLCD.fillScreen(VLB_BLACK);

  myGLCD.setTextSize(1);
  myGLCD.setTextColor(VLB_YELLOW);
  myGLCD.fillRect(0, 0, dispx, 16,VLB_DARKORANGE);
  myGLCD.drawLine(0, 17, dispx, 17,VLB_YELLOW);
  myGLCD.setCursor(155,5);
  myGLCD.print(TITLE);

  myGLCD.setFont(&FreeSans9pt7b);
  myGLCD.setTextSize(1);
  myGLCD.setTextColor(VLB_ORANGE);
  myGLCD.setCursor(370,210);
  strcpy(buf,"x1     x10");
  myGLCD.print(buf);
  buttons(T10);
  keypad();
}

void loop(void)
{
  color24=(uint32_t)Red<<16;
  color24|=(uint32_t)Green<<8;
  color24|=(uint32_t)Blue;
  color16=((Red&0xF8)<<8);
  color16|=((Green&0xFC)<<3);
  color16|=(Blue&0xF8)>>3;

  myGLCD.setTextSize(1);
  myGLCD.setFont(&FreeSerifBold12pt7b);
  myGLCD.setTextColor(VLB_WHITE);
  myGLCD.fillRect(360,50,105,25,VLB_BLACK);
  myGLCD.setCursor(370,70);
  sprintf(buf, "0x%04X   ",color16);
  myGLCD.print(buf);

  myGLCD.fillRoundRect(130,40,225,100,7,color16);
  myGLCD.drawRoundRect(130,40,225,100,7,VLB_WHITE);

  myGLCD.fillRect(38,44,75,18,VLB_BLACK);
  sprintf(buf, "R=%03d   ",Red);
  myGLCD.setCursor(40,60);
  myGLCD.setTextColor(VLB_RED);
  myGLCD.print(buf);
  myGLCD.fillRect(38,64,75,18,VLB_BLACK);
  sprintf(buf, "G=%03d   ",Green);
  myGLCD.setCursor(40,80);
  myGLCD.setTextColor(VLB_LIME);
  myGLCD.print(buf);
  myGLCD.fillRect(38,84,75,18,VLB_BLACK);
  sprintf(buf, "B=%03d   ",Blue);
  myGLCD.setCursor(40,100);
  myGLCD.setTextColor(VLB_BLUE);
  myGLCD.print(buf);

  myGLCD.setTextSize(1);
  myGLCD.setFont(&FreeSerifBold18pt7b);
  myGLCD.setTextColor(VLB_YELLOW);
  myGLCD.fillRect(150,140,190,40,VLB_BLACK);
  myGLCD.setCursor(160,170);
  sprintf(buf, "0x%06X   ",color24);
  myGLCD.print(buf);

  while (1)
{
    tp = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    pinMode(XP, OUTPUT);
    pinMode(YM, OUTPUT);
/*
    while (tp.z > MINPRESSURE && tp.z < MAXPRESSURE)
    {
      myGLCD.setFont(&FreeMono9pt7b);
      myGLCD.setTextColor(VLB_WHITE);
      myGLCD.setCursor(20,100);
      myGLCD.fillRect(10,85,280,23,VLB_BLACK);
      sprintf(buf,"TP.X= %d     TP.Y= %d        ",tp.x,tp.y);
      myGLCD.print(buf);
      tp = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      pinMode(XP, OUTPUT);
      pinMode(YM, OUTPUT);
      delay(150);
    }
*/
    if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE)
      delay(75);
    if (tp.z < MINPRESSURE || tp.z > MAXPRESSURE)
      continue;
    if(tp.y>605&&tp.y<685)
    {
      if(tp.x>380&&tp.x<455)      // Button 1
      {
        switch(T10)
        {
          case 0:
            if(Red<255)
              Red++;
            else
              Red=0;
            break;
          case 1:
            if(Red<250)
              Red+=10;
            else
              Red=0;
            break;
        }
        break;
      }
      if(tp.x>470&&tp.x<545)      // Button 2
      {
        switch(T10)
        {
          case 0:
            if(Green<255)
              Green++;
            else
              Green=0;
            break;
          case 1:
            if(Green<250)
              Green+=10;
            else
              Green=0;
            break;
        }
        break;
      }
      if(tp.x>570&&tp.x<640)      // Button 3
      {
        switch(T10)
        {
          case 0:
            if(Blue<255)
              Blue++;
            else
              Blue=0;
            break;
          case 1:
            if(Blue<250)
              Blue+=10;
            else
              Blue=0;
            break;
        }
        break;
      }
    }
    if(tp.y>705&&tp.y<785)
    {
      if(tp.x>380&&tp.x<455)      // Button 4
      {
        switch(T10)
        {
          case 0:
            if(Red>0)
              Red--;
            else
              Red=255;
            break;
          case 1:
            if(Red>10)
              Red-=10;
            else
              Red=255;
            break;
        }
        break;
      }
      if(tp.x>470&&tp.x<545)      // Button 5
      {
        switch(T10)
        {
          case 0:
            if(Green>0)
              Green--;
            else
              Green=255;
            break;
          case 1:
            if(Green>10)
              Green-=10;
            else
              Green=255;
            break;
        }
        break;
      }
      if(tp.x>570&&tp.x<640)      // Button 6
      {
        switch(T10)
        {
          case 0:
            if(Blue>0)
              Blue--;
            else
              Blue=255;
            break;
          case 1:
            if(Blue>10)
              Blue-=10;
            else
              Blue=255;
            break;
        }
        break;
      }
    }
    if(tp.y>670&&tp.y<710)
    {
      if(tp.x>685&&tp.x<725)      // x1
      {
        T10=0;
        buttons(T10);
        break;
      }
      if(tp.x>760&&tp.x<800)      // x10
      {
        T10=1;
        buttons(T10);
        break;
      }
    }
  }
}


