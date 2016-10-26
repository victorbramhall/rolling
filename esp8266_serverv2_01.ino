/**********************************************************************
*             ESP8266 Server using the Arduino Due
*                for 7" 800x480 Touch Screen TFTs
*                         23 Oct 2016
*                            v2.01
**********************************************************************/
#define TITLE "ESP8266 Server using the Arduino Due v2.01"
#define Ver 2.01

#include <UTFT.h>
#include <URTouch.h>
#include <DS3234.h>
#include <UTFT_DLB.h>
#include <VLB_Colors.h>

extern uint8_t bell9[];
extern uint8_t bell12[];
extern uint8_t bell14[];
extern uint8_t bell16[];
extern uint8_t bell18[];
extern uint8_t bell22[];
extern uint8_t bell26[];
extern uint8_t bodb9[];
extern uint8_t bodb12[];
extern uint8_t bodb14[];
extern uint8_t bodb16[];
extern uint8_t bodb18[];
extern uint8_t bodb22[];
extern uint8_t bodb26[];
extern uint8_t cambria9[];
extern uint8_t britanic9[];
extern uint8_t britanic12[];
extern uint8_t britanic14[];
extern uint8_t britanic16[];
extern uint8_t britanic18[];
extern uint8_t britanic22[];
extern uint8_t britanic26[];
extern uint8_t cambria22[];
extern uint8_t cambria26[];
extern uint8_t georgia9[];
extern uint8_t georgia12[];
extern uint8_t georgia14[];
extern uint8_t georgia16[];
extern uint8_t georgia18[];
extern uint8_t georgia22[];
extern uint8_t georgia26[];
extern uint8_t oldengl9[];
extern uint8_t oldengl12[];
extern uint8_t oldengl14[];
extern uint8_t oldengl16[];
extern uint8_t oldengl18[];
extern uint8_t oldengl22[];
extern uint8_t oldengl26[];
extern uint8_t schlbkb9[];
extern uint8_t schlbkb12[];
extern uint8_t schlbkb14[];
extern uint8_t schlbkb16[];
extern uint8_t schlbkb18[];
extern uint8_t schlbkb22[];
extern uint8_t schlbkb26[];

UTFT_DLB GLCD7(CTE70,25,26,27,28);    // Arduino Due LCD shield
URTouch  myTouch( 6, 5, 32, 3, 2);
DS3234 rtc(8);
Time t;

#define ESP8266 Serial1

int TOUCH_ORIENTATION=PORTRAIT;     // 0
//int TOUCH_ORIENTATION=LANDSCAPE;    // 1

void setup(void);
void loop(void);
void Setup(void);
void displayText(char string[],int x,int y,int tsize,uint16_t color); 
void displayNum(uint16_t number,int x,int y,int tsize,uint16_t color,int num); 
void displayFloat(float number,int x,int y,int tsize,uint16_t color); 
void erase_text(uint8_t x,uint8_t y);
void showNumI(char *msg, uint32_t val, int x, int y);
void Hex2Ascii(uint32_t num);
unsigned long keypad(int orientation);
unsigned long KeyBoard(int shift); 
void erasebutton(void);
void BigButton(String* text,int x,uint16_t y,int x1,int y1,int tloc,word bcolor,word tcolor,int shift);
void kbd_Input(void);
void KeyboardColors(void);
void SetUpScreen(int select);
void Select_Orientation(int select);
void clrscr(void);
void DisplayKeyboardText(void);
int reset_ESP8266(void);
int check_ESP8266(void);
int check_ok(void);
int check_ready(void);
int check_error(void);
int check_connect(void);
int set_server(void);
int close_server(void);
int close_AP(void);
int get_ip_address(void);
int set_CIPMUX(void);
int set_CWMODE(void);
int set_CWJAP(void);
int AP_list(void);
int ESP8266_Status(void);
int joined_AP(void);
int ESP8266_Info(void);
int check_AT(void);
int diaplay_response(word color,uint32_t timeout_val);
void erase_response(void);

int DEBUG=0;

word default_button_color=VLB_BLUE;
word default_button_text_color=VLB_YELLOW;
word default_text_color=VLB_WHITE;
word button_color=default_button_color;
word button_text_color=default_button_text_color;
word text_color=default_text_color;
int default_text_size=0;
int default_text_type=0;
int text_size=default_text_size;
int text_type=default_text_type;
int color=0;
int info_line=60;
uint32_t bPL;
float px=0, py=30;
int dispx,dispy,x,y;
int cx,cy,tbc=0;
int bn,skip,toffset;
int nx,ny,sx,sy,bsize,offset;
int text_window_bottom,capson=0;
unsigned long tloc,tlocx,tlocy;
const char CWMODE = '1';    //CWMODE 1=STATION, 2=APMODE, 3=BOTH
const char CIPMUX = '1';    //CWMODE 0=Single Connection, 1=Multiple Connections

char keys[]=
{
  '`','1','2','3','4','5','6','7','8','9','0','-','=',' ',
  ' ','q','w','e','r','t','y','u','i','o','p','[',']','\\',
  ' ','a','s','d','f','g','h','j','k','l',';','\'',' ',' ',
  ' ',' ','z','x','c','v','b','n','m',',','.','/',' ',' '  
};
char btext[8][6]={"BKSP","   ","CAPS","ENTER","SHIFT","SHIFT","SPACE","EXIT"};
char caps[]=
{
  '~','!','@','#','$','%','^','&','*','(',')','_','+',' ',
  ' ','Q','W','E','R','T','Y','U','I','O','P','{','}','|',
  ' ','A','S','D','F','G','H','J','K','L',':',';','\'',' ',' ',
  ' ',' ','Z','X','C','V','B','N','M','<','>','?',' ',' '  
};
char TextBox[255];
const char SSID_ESP[]="ARRIS-8CA2";
const char SSID_KEY[]="2143263388";
char data_in[1024];
char data[1024];
char url[150];
int data_size=1024;
char ip_address[16];
char buf[150];
char menu[][10]=
{
  "SERVER","CLOSESVR","","",
  "","CLRSCR","SETUP",""
};

uint16_t btns[][2]=
{
  1050,790,     // Row 1-|--------
  720,470,      // Row 2-|- Y     |
  1300,1660,    // Colum 1-|      |- PORTRAIT
  1750,2140,    // Colum 2-|- X   |
  2200,2600,    // Colum 3-|      |
  2670,3050,    // Colum 4-|------
//********************************************
  2300,1890,    // Row 1-|--------
  2790,2390,    // Row 2-|- Y     |
  1180,1450,    // Colum 1-|      |- LANDSCAPE
  1500,1750,    // Colum 2-|- X   |
  1800,2070,    // Colum 3-|      |
  2130,2370,    // Colum 4-|------
};

void setup(void)
{
  ESP8266.begin(115200);

  Select_Orientation(0);
  sx=5;
  sy=30;
  cx=sx;
  cy=sy;
  ny=18;
  text_window_bottom=dispx-170;
}

void loop(void)
{
int16_t i,n;
  while(!myTouch.dataAvailable())
  {
    i=0;
    if((i=ESP8266.readBytesUntil('\n',data_in,1024))>0)
    {
      data_in[i]=0x00;
      if(strncmp(data_in, "+IPD,", 5)==0)
      {
        displayText(data_in,cx,cy+=ny,1,text_color);
        switch(TOUCH_ORIENTATION)
        {
          case 0:
            if(cy>dispy-text_window_bottom)
            {
              cy=sy;
              clrscr();
            }
            break;
          case 1:
            if(cy>dispy-145)
            {
              cy=sy;
              clrscr();
            }
            break;
        }
      }
    }
  }
  
  delay(125);
  myTouch.read();
  x=myTouch.getX();
  y=myTouch.getY();
  if(DEBUG)
  {
    while(myTouch.dataAvailable())
    {
      switch(TOUCH_ORIENTATION)
      {
        case 0:
          GLCD7.setFont(britanic18);
          sprintf(buf,"X = %d    Y = %d    ",x,y);
          GLCD7.print(buf,80,461);
          GLCD7.setFont(cambria26);
          sprintf(buf,"TP_X = %d    TP_Y = %d            ",myTouch.TP_X,myTouch.TP_Y);
          GLCD7.print(buf,80,480);
          break;
        case 1:
          GLCD7.setFont(britanic18);
          sprintf(buf,"X = %d    Y = %d    ",x,y);
          GLCD7.print(buf,230,166);
          GLCD7.setFont(cambria26);
          sprintf(buf,"TP_X = %d    TP_Y = %d            ",myTouch.TP_X,myTouch.TP_Y);
          GLCD7.print(buf,230,186);
          break;
      }
      delay(250);
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
    }
  }
  if(myTouch.TP_Y>btns[bPL][1]&&myTouch.TP_Y<btns[bPL][0])            //**1******
  {
    if(myTouch.TP_X>btns[bPL+2][0]&&myTouch.TP_X<btns[bPL+2][1])      // Button 1
    {
      clrscr();
      reset_ESP8266();
      ESP8266_Info();
      set_CWMODE();
      set_CIPMUX();
      set_CWJAP();
      get_ip_address();
      set_server();
      displayText("--- Server Started ---",cx,cy+=ny,1,text_color);
      switch(TOUCH_ORIENTATION)
      {
        case 0:
          if(cy>dispy-text_window_bottom)
          {
            cy=sy;
            clrscr();
          }
          break;
        case 1:
          if(cy>dispy-145)
          {
            cy=sy;
            clrscr();
          }
          break;
      }
      ESP8266.setTimeout(2000);
    }
    if(myTouch.TP_X>btns[bPL+3][0]&&myTouch.TP_X<btns[bPL+3][1])      // Button 2
    {
      close_server();
      close_AP();
      displayText("--- Server Closed ---",cx,cy+=ny,1,text_color);
      switch(TOUCH_ORIENTATION)
      {
        case 0:
          if(cy>dispy-text_window_bottom)
          {
            cy=sy;
            clrscr();
          }
          break;
        case 1:
          if(cy>dispy-145)
          {
            cy=sy;
            clrscr();
          }
          break;
      }
    }
    if(myTouch.TP_X>btns[bPL+4][0]&&myTouch.TP_X<btns[bPL+4][1])      // Button 3
    {
    }
    if(myTouch.TP_X>btns[bPL+5][0]&&myTouch.TP_X<btns[bPL+5][1])      // Button 4
    {
    }
  }
  if(myTouch.TP_Y>btns[bPL+1][1]&&myTouch.TP_Y<btns[bPL+1][0])        //**2******
  {
    if(myTouch.TP_X>btns[bPL+2][0]&&myTouch.TP_X<btns[bPL+2][1])      // Button 5
    {
    }
    if(myTouch.TP_X>btns[bPL+3][0]&&myTouch.TP_X<btns[bPL+3][1])      // Button 6
    {
      clrscr();
    }
    if(myTouch.TP_X>btns[bPL+4][0]&&myTouch.TP_X<btns[bPL+4][1])      // Button 7
    {
      Setup();
      Select_Orientation(0);
    }
    if(myTouch.TP_X>btns[bPL+5][0]&&myTouch.TP_X<btns[bPL+5][1])      // Button 8
    {
    }
  }
}


