void Setup(void)
{
int i,j,n,x,y,tx,ty,gx,gy,yoffset,waiting;
int y1,y2,y3,y4,y5,y6,y7,y8;
int cbn,sbn,tbn,ty1,ty2,ty3,ty4,ty5;

int ttext_array[][2]=
  {
    2940,3360,
    2240,2320,
    2100,2190,
    1990,2080,
    1890,1960,
    1750,1850,
    1650,1720
  };

int tsize_array[][2]=
  {
    2250,2330,      //**row 1**
    490,880,
    940,1360,
    1420,1830,
    1900,2300,
    2120,2190,      //**row 2**
    490,880,
    940,1360,
    1420,1830,
    1900,2300
  };

int box_array[][2]=
  {
    3600,3700,
    640,1350,
    1540,2740,
    2800,3340
  };

int box[][4]=
  {
    45,42,145,75,
    165,42,333,75,
    349,42,420,75,
    9,212,306,272
  };

int color_array[][2]=
  {
    3460,3500,
    3400,3440,
    3300,3340,
    3220,3260,
    3150,3190,
    3060,3100,
    2970,3010,
    480,1100,
    1175,2035,
    2110,2760,
    2850,3590
  };

word colors[]=
  {
    VLB_NAVY, VLB_BLUE,     VLB_NAVY,  VLB_TEAL,
    VLB_GREEN, VLB_TURQUOISE,VLB_LIME,  VLB_CYAN,
    VLB_OLIVE, VLB_VIOLET,   VLB_PURPLE,VLB_MAROON,
    VLB_GRAY,  VLB_BROWN,    VLB_TAN,   VLB_CRIMSON,
    VLB_SILVER,VLB_SALMON,   VLB_RED,   VLB_MAGENTA,
    VLB_PINK,  VLB_ORANGE,   VLB_GOLD,  VLB_CORAL,
    VLB_YELLOW,VLB_IVORY,    VLB_WHITE
  };
int color_place[]=
  {
    85,40,136,262,356,
    102,40,136,262,356,
    119,40,136,262,356,
    136,40,136,262,356,
    153,40,136,262,356,
    170,40,136,262,356,
    187,40,136,262,356
  };
char color_text[][15]=
  {  
  "BLACK", "BLUE",     "NAVY",  "TEAL",
  "GREEN", "TURQUOISE","LIME",  "CYAN",
  "OLIVE", "VIOLET",   "PURPLE","MAROON",
  "GRAY",  "BROWN",    "TAN",   "CRIMSON",
  "SILVER","SALMON",   "RED",   "MAGENTA",
  "PINK",  "ORANGE",   "GOLD",  "CORAL",
  "YELLOW","IVORY",    "WHITE"
  };
  
  x=25;
  yoffset=17;
  y1=50;
  y2=y1+35;
  y3=y2+yoffset;
  y4=y3+yoffset;
  y5=y4+yoffset;
  y6=y5+yoffset;
  y7=y6+yoffset;
  y8=y7+yoffset;
  cbn=0;
  sbn=0;
  tbn=0;
  button_color=default_button_color;
  button_text_color=default_button_text_color;
  text_color=default_text_color;
  text_size=default_text_size;
  text_type=default_text_type;
  GLCD7.InitLCD(PORTRAIT);
  GLCD7.clrScr();
  myTouch.InitTouch(PORTRAIT);
  myTouch.setPrecision(PREC_LOW);
  GLCD7.setFont(cambria26);
  GLCD7.setColor(VLB_GREEN);
  GLCD7.print("SETUP",CENTER,7);
  GLCD7.setFont(cambria22);
  GLCD7.setBackColor(VLB_BLACK);
  GLCD7.setColor(button_color);
  GLCD7.print("BUTTON",50,y1);
  GLCD7.setColor(button_text_color);
  GLCD7.print("BUTTON TEXT",170,y1);
  GLCD7.setColor(text_color);
  GLCD7.print("TEXT",355,y1);
  GLCD7.setBackColor(VLB_BLACK);
  GLCD7.setColor(VLB_WHITE);
  GLCD7.setFont(bell14);
  j=0;
  for(i=0;i<31;i+=5)
  {
    for(n=1;n<5;n++)
    {
      if(j<27)
      {
        GLCD7.setColor(colors[j]);
        GLCD7.print(color_text[j++],color_place[i+n],color_place[i],0);
      }
    }
  }
  GLCD7.setBackColor(VLB_BLACK);
  GLCD7.setColor(VLB_WHITE);
  GLCD7.drawRect(box[0][0],box[0][1],box[0][2],box[0][3]);
  GLCD7.setFont(bell14);
  GLCD7.print("`~!@#$%^&*()_+{}|[]\";':,.\\/<>?",20,210,0);
  GLCD7.print("0123456789",20,225,0);
  GLCD7.print("abcdefghijklmnopqrstuvwxyz",20,240,0);
  GLCD7.print("ABCDEFGHIJKLM",20,255,0);
  GLCD7.print("NOPQRSTUVWXYZ",20,270,0);
  GLCD7.setFont(bell12);
  x=25;
  y=340;
  n=1;
  for(j=0;j<2;j++)
  {
    for(i=0;((i<4)&&(n<8));i++)
    {
      if((j==0)&&(i==0))
        GLCD7.setColor(VLB_RED);
      else
        GLCD7.setColor(VLB_WHITE);
      GLCD7.drawRoundRect(x,y,x+60,y+20);
      GLCD7.setColor(text_color);
      sprintf(buf,"Size %d",n++);
      GLCD7.print(buf,x+15,y+6);
      x+=65;
    }
    x=25;
    y+=25;
  }
  x=360;
  y=340;
  for(i=0;i<6;i++)
  {
    if(tbn==i)
      GLCD7.setColor(VLB_RED);
    else
      GLCD7.setColor(VLB_WHITE);
    GLCD7.drawRoundRect(x,y,x+60,y+20);
    GLCD7.setColor(text_color);
    sprintf(buf,"Text %d",i+1);
    GLCD7.print(buf,x+15,y+6);
    y+=25;
  }
  GLCD7.setColor(VLB_RED);
  GLCD7.fillRect(333,720,430,762);
  GLCD7.setBackColor(VLB_RED);
  GLCD7.setColor(VLB_YELLOW);
  GLCD7.setFont(cambria22);
  GLCD7.print("EXIT",357,733);
  GLCD7.setBackColor(VLB_BLUE);
  GLCD7.setColor(VLB_BLUE);
  GLCD7.fillRect(320,590,450,630);
  GLCD7.setColor(VLB_YELLOW);
  GLCD7.setFont(cambria22);
  GLCD7.print("DEBUG",348,595);
  GLCD7.setFont(bell14);
  switch(DEBUG)
  {
    case 0:
      GLCD7.print("OFF",371,617);
      break;
    case 1:
      GLCD7.print(" ON   ",371,617);
      break;
  }

  waiting=1;
  while(waiting)
  {
    while(!myTouch.dataAvailable());
    delay(175);
    myTouch.read();
    gx=myTouch.getX();
    gy=myTouch.getY();
    if(DEBUG)
    {
      GLCD7.setBackColor(VLB_BLACK);
      GLCD7.setColor(VLB_YELLOW);
      while(myTouch.dataAvailable())
      { 
        GLCD7.setFont(britanic18);
        sprintf(buf,"X = %d      Y = %d      ",gx,gy);
        GLCD7.print(buf,60,660);
        GLCD7.setFont(cambria26);
        sprintf(buf,"TP_X = %d      TP_Y = %d           ",myTouch.TP_X,myTouch.TP_Y);
        GLCD7.print(buf,60,680);
        myTouch.read();
        gx=myTouch.getX();
        gy=myTouch.getY();
        delay(250);
      }
    }
    if(myTouch.TP_Y>930&&myTouch.TP_Y<1130)
    {
      if(myTouch.TP_X>2680&&myTouch.TP_X<3570)
      {
        GLCD7.setBackColor(VLB_BLUE);
        GLCD7.setColor(VLB_YELLOW);
        switch(DEBUG)
        {
          case 0:
            DEBUG=1;
            GLCD7.setFont(bell14);
            GLCD7.print(" ON   ",368,617);
            break;
          case 1:
            DEBUG=0;
            GLCD7.setFont(bell14);
            GLCD7.print("OFF",368,617);
            GLCD7.setBackColor(VLB_BLACK);
            GLCD7.setColor(VLB_BLACK);
            GLCD7.fillRect(50,640,450,710);
            break;
        }
      }
    }
    if(myTouch.TP_X>ttext_array[0][0]&&myTouch.TP_X<ttext_array[0][1])  //***tbn****
    {
      GLCD7.setBackColor(VLB_BLACK);
      if(myTouch.TP_Y>ttext_array[1][0]&&myTouch.TP_Y<ttext_array[1][1])//****0*****
      {
        text_type=tbn=0;
        tx=360;
        ty=340;
        GLCD7.setFont(bell12);
        for(i=0;i<6;i++)
        {
          if(tbn==i)
            GLCD7.setColor(VLB_RED);
          else
            GLCD7.setColor(VLB_WHITE);
          GLCD7.drawRoundRect(tx,ty,tx+60,ty+20);
          GLCD7.setColor(text_color);
          sprintf(buf,"Text %d",i+1);
          GLCD7.print(buf,tx+15,ty+6);
          ty+=25;
        }
        switch(sbn)
        {
          case 0:
            GLCD7.setFont(bell9);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 1:
            GLCD7.setFont(bell12);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 2:
            GLCD7.setFont(bell14);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 3:
            GLCD7.setFont(bell16);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=263;
            ty5=278;
            break;
          case 4:
            GLCD7.setFont(bell18);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=266;
            ty5=286;
            break;
          case 5:
            GLCD7.setFont(bell22);
            ty1=210;
            ty2=231;
            ty3=251;
            ty4=275;
            ty5=296;
            break;
          case 6:
            GLCD7.setFont(bell26);
            ty1=210;
            ty2=236;
            ty3=258;
            ty4=286;
            ty5=308;
           break;
        }
        GLCD7.setColor(VLB_BLACK);
        GLCD7.fillRect(0,205,dispx-1,338);
        GLCD7.setColor(text_color);
        GLCD7.print("`~!@#$%^&*()_+{}|[]\";':,.\\/<>?",20,ty1,0);
        GLCD7.print("0123456789",20,ty2,0);
        GLCD7.print("abcdefghijklmnopqrstuvwxyz",20,ty3,0);
        GLCD7.print("ABCDEFGHIJKLM",20,ty4,0);
        GLCD7.print("NOPQRSTUVWXYZ",20,ty5,0);
      }
      if(myTouch.TP_Y>ttext_array[2][0]&&myTouch.TP_Y<ttext_array[2][1])//****1*****
      {
        text_type=tbn=1;
        tx=360;
        ty=340;
        GLCD7.setFont(bell12);
        for(i=0;i<6;i++)
        {
          if(tbn==i)
            GLCD7.setColor(VLB_RED);
          else
            GLCD7.setColor(VLB_WHITE);
          GLCD7.drawRoundRect(tx,ty,tx+60,ty+20);
          GLCD7.setColor(text_color);
          sprintf(buf,"Text %d",i+1);
          GLCD7.print(buf,tx+15,ty+6);
          ty+=25;
        }
        switch(sbn)
        {
          case 0:
            GLCD7.setFont(bodb9);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 1:
            GLCD7.setFont(bodb12);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 2:
            GLCD7.setFont(bodb14);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 3:
            GLCD7.setFont(bodb16);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=263;
            ty5=278;
            break;
          case 4:
            GLCD7.setFont(bodb18);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=266;
            ty5=286;
            break;
          case 5:
            GLCD7.setFont(bodb22);
            ty1=210;
            ty2=234;
            ty3=254;
            ty4=278;
            ty5=299;
            break;
          case 6:
            GLCD7.setFont(bodb26);
            ty1=210;
            ty2=236;
            ty3=258;
            ty4=286;
            ty5=308;
            break;
        }
        GLCD7.setColor(VLB_BLACK);
        GLCD7.fillRect(0,210,dispx-1,338);
        GLCD7.setColor(text_color);
        GLCD7.print("`~!@#$%^&*()_+{}|[]\";':,.\\/<>?",20,ty1,0);
        GLCD7.print("0123456789",20,ty2,0);
        GLCD7.print("abcdefghijklmnopqrstuvwxyz",20,ty3,0);
        GLCD7.print("ABCDEFGHIJKLM",20,ty4,0);
        GLCD7.print("NOPQRSTUVWXYZ",20,ty5,0);
      }
      if(myTouch.TP_Y>ttext_array[3][0]&&myTouch.TP_Y<ttext_array[3][1])//****2*****
      {
        text_type=tbn=2;
        tx=360;
        ty=340;
        GLCD7.setFont(bell12);
        for(i=0;i<6;i++)
        {
          if(tbn==i)
            GLCD7.setColor(VLB_RED);
          else
            GLCD7.setColor(VLB_WHITE);
          GLCD7.drawRoundRect(tx,ty,tx+60,ty+20);
          GLCD7.setColor(text_color);
          sprintf(buf,"Text %d",i+1);
          GLCD7.print(buf,tx+15,ty+6);
          ty+=25;
        }
        switch(sbn)
        {
          case 0:
            GLCD7.setFont(britanic9);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 1:
            GLCD7.setFont(britanic12);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 2:
            GLCD7.setFont(britanic14);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 3:
            GLCD7.setFont(britanic16);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=263;
            ty5=278;
            break;
          case 4:
            GLCD7.setFont(britanic18);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=266;
            ty5=286;
            break;
          case 5:
            GLCD7.setFont(britanic22);
            ty1=210;
            ty2=231;
            ty3=251;
            ty4=275;
            ty5=296;
            break;
          case 6:
            GLCD7.setFont(britanic26);
            ty1=210;
            ty2=236;
            ty3=259;
            ty4=288;
            ty5=309;
            break;
        }
        GLCD7.setColor(VLB_BLACK);
        GLCD7.fillRect(0,205,dispx-1,338);
        GLCD7.setColor(text_color);
        GLCD7.print("`~!@#$%^&*()_+{}|[]\";':,.\\/<>?",20,ty1,0);
        GLCD7.print("0123456789",20,ty2,0);
        GLCD7.print("abcdefghijklmnopqrstuvwxyz",20,ty3,0);
        GLCD7.print("ABCDEFGHIJKLM",20,ty4,0);
        GLCD7.print("NOPQRSTUVWXYZ",20,ty5,0);
      }
      if(myTouch.TP_Y>ttext_array[4][0]&&myTouch.TP_Y<ttext_array[4][1])//****3*****
      {
        text_type=tbn=3;
        tx=360;
        ty=340;
        GLCD7.setFont(bell12);
        for(i=0;i<6;i++)
        {
          if(tbn==i)
            GLCD7.setColor(VLB_RED);
          else
            GLCD7.setColor(VLB_WHITE);
          GLCD7.drawRoundRect(tx,ty,tx+60,ty+20);
          GLCD7.setColor(text_color);
          sprintf(buf,"Text %d",i+1);
          GLCD7.print(buf,tx+15,ty+6);
          ty+=25;
        }
        switch(sbn)
        {
          case 0:
            GLCD7.setFont(georgia9);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 1:
            GLCD7.setFont(georgia12);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 2:
            GLCD7.setFont(georgia14);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 3:
            GLCD7.setFont(georgia16);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=263;
            ty5=278;
            break;
          case 4:
            GLCD7.setFont(georgia18);
            ty1=210;
            ty2=228;
            ty3=249;
            ty4=270;
            ty5=290;
            break;
          case 5:
            GLCD7.setFont(georgia22);
            ty1=210;
            ty2=231;
            ty3=256;
            ty4=280;
            ty5=305;
            break;
          case 6:
            GLCD7.setFont(georgia26);
            ty1=205;
            ty2=229;
            ty3=259;
            ty4=287;
            ty5=310;
            break;
        }
        GLCD7.setColor(VLB_BLACK);
        GLCD7.fillRect(0,205,dispx-1,338);
        GLCD7.setColor(text_color);
        GLCD7.print("`~!@#$%^&*()_+{}|[]\";':,.\\/<>?",20,ty1,0);
        GLCD7.print("0123456789",20,ty2,0);
        GLCD7.print("abcdefghijklmnopqrstuvwxyz",20,ty3,0);
        GLCD7.print("ABCDEFGHIJKLM",20,ty4,0);
        GLCD7.print("NOPQRSTUVWXYZ",20,ty5,0);
      }
      if(myTouch.TP_Y>ttext_array[5][0]&&myTouch.TP_Y<ttext_array[5][1])//****4*****
      {
        text_type=tbn=4;
        tx=360;
        ty=340;
        GLCD7.setFont(bell12);
        for(i=0;i<6;i++)
        {
          if(tbn==i)
            GLCD7.setColor(VLB_RED);
          else
            GLCD7.setColor(VLB_WHITE);
          GLCD7.drawRoundRect(tx,ty,tx+60,ty+20);
          GLCD7.setColor(text_color);
          sprintf(buf,"Text %d",i+1);
          GLCD7.print(buf,tx+15,ty+6);
          ty+=25;
        }
        switch(sbn)
        {
          case 0:
            GLCD7.setFont(schlbkb9);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 1:
            GLCD7.setFont(schlbkb12);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 2:
            GLCD7.setFont(schlbkb14);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 3:
            GLCD7.setFont(schlbkb16);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=263;
            ty5=281;
            break;
          case 4:
            GLCD7.setFont(schlbkb18);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=266;
            ty5=286;
            break;
          case 5:
            GLCD7.setFont(schlbkb22);
            ty1=210;
            ty2=231;
            ty3=251;
            ty4=275;
            ty5=296;
            break;
          case 6:
            GLCD7.setFont(schlbkb26);
            ty1=210;
            ty2=236;
            ty3=259;
            ty4=286;
            ty5=311;
            break;
        }
        GLCD7.setColor(VLB_BLACK);
        GLCD7.fillRect(0,205,dispx-1,338);
        GLCD7.setColor(text_color);
        GLCD7.print("`~!@#$%^&*()_+{}|[]\";':,.\\/<>?",20,ty1,0);
        GLCD7.print("0123456789",20,ty2,0);
        GLCD7.print("abcdefghijklmnopqrstuvwxyz",20,ty3,0);
        GLCD7.print("ABCDEFGHIJKLM",20,ty4,0);
        GLCD7.print("NOPQRSTUVWXYZ",20,ty5,0);
      }
      if(myTouch.TP_Y>ttext_array[6][0]&&myTouch.TP_Y<ttext_array[6][1])//****5*****
      {
        text_type=tbn=5;
        tx=360;
        ty=340;
        GLCD7.setFont(bell12);
        for(i=0;i<6;i++)
        {
          if(tbn==i)
            GLCD7.setColor(VLB_RED);
          else
            GLCD7.setColor(VLB_WHITE);
          GLCD7.drawRoundRect(tx,ty,tx+60,ty+20);
          GLCD7.setColor(text_color);
          sprintf(buf,"Text %d",i+1);
          GLCD7.print(buf,tx+15,ty+6);
          ty+=25;
        }
        switch(sbn)
        {
          case 0:
            GLCD7.setFont(oldengl9);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 1:
            GLCD7.setFont(oldengl12);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 2:
            GLCD7.setFont(oldengl14);
            ty1=210;
            ty2=225;
            ty3=240;
            ty4=255;
            ty5=270;
            break;
          case 3:
            GLCD7.setFont(oldengl16);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=263;
            ty5=280;
            break;
          case 4:
            GLCD7.setFont(oldengl18);
            ty1=210;
            ty2=228;
            ty3=245;
            ty4=266;
            ty5=286;
            break;
          case 5:
            GLCD7.setFont(oldengl22);
            ty1=210;
            ty2=231;
            ty3=251;
            ty4=275;
            ty5=299;
            break;
          case 6:
            GLCD7.setFont(oldengl26);
            ty1=210;
            ty2=236;
            ty3=259;
            ty4=286;
            ty5=311;
            break;
        }
        GLCD7.setColor(VLB_BLACK);
        GLCD7.fillRect(0,205,dispx-1,338);
        GLCD7.setColor(text_color);
        GLCD7.print("`~!@#$%^&*()_+{}|[]\";':,.\\/<>?",20,ty1,0);
        GLCD7.print("0123456789",20,ty2,0);
        GLCD7.print("abcdefghijklmnopqrstuvwxyz",20,ty3,0);
        GLCD7.print("ABCDEFGHIJKLM",20,ty4,0);
        GLCD7.print("NOPQRSTUVWXYZ",20,ty5,0);
      }
    }
    if(myTouch.TP_Y>tsize_array[0][0]&&myTouch.TP_Y<tsize_array[0][1])  //***sbn1***
    {
      GLCD7.setBackColor(VLB_BLACK);
      if(myTouch.TP_X>tsize_array[1][0]&&myTouch.TP_X<tsize_array[1][1])//****0*****
      {
        sbn=0;
        x=25;
        y=340;
        n=1;
        GLCD7.setFont(bell12);
        for(j=0;j<2;j++)
        {
          for(i=0;((i<4)&&(n<8));i++)
          {
            if(sbn==n-1)
              GLCD7.setColor(VLB_RED);
            else
              GLCD7.setColor(VLB_WHITE);
            GLCD7.drawRoundRect(x,y,x+60,y+20);
            GLCD7.setColor(text_color);
            sprintf(buf,"Size %d",n++);
            GLCD7.print(buf,x+15,y+6);
            x+=65;
          }
          x=25;
          y+=25;
        }
      }
      if(myTouch.TP_X>tsize_array[2][0]&&myTouch.TP_X<tsize_array[2][1])//****1*****
      {
        sbn=1;
        x=25;
        y=340;
        GLCD7.setFont(bell12);
        n=1;
        for(j=0;j<2;j++)
        {
          for(i=0;((i<4)&&(n<8));i++)
          {
            if(sbn==n-1)
              GLCD7.setColor(VLB_RED);
            else
              GLCD7.setColor(VLB_WHITE);
            GLCD7.drawRoundRect(x,y,x+60,y+20);
            GLCD7.setColor(text_color);
            sprintf(buf,"Size %d",n++);
            GLCD7.print(buf,x+15,y+6);
            x+=65;
          }
          x=25;
          y+=25;
        }
      }
      if(myTouch.TP_X>tsize_array[3][0]&&myTouch.TP_X<tsize_array[3][1])//****2*****
      {
        sbn=2;
        x=25;
        y=340;
        GLCD7.setFont(bell12);
        n=1;
        for(j=0;j<2;j++)
        {
          for(i=0;((i<4)&&(n<8));i++)
          {
            if(sbn==n-1)
              GLCD7.setColor(VLB_RED);
            else
              GLCD7.setColor(VLB_WHITE);
            GLCD7.drawRoundRect(x,y,x+60,y+20);
            GLCD7.setColor(text_color);
            sprintf(buf,"Size %d",n++);
            GLCD7.print(buf,x+15,y+6);
            x+=65;
          }
          x=25;
          y+=25;
        }
      }
      if(myTouch.TP_X>tsize_array[4][0]&&myTouch.TP_X<tsize_array[4][1])//****3*****
      {
        sbn=3;
        x=25;
        y=340;
        GLCD7.setFont(bell12);
        n=1;
        for(j=0;j<2;j++)
        {
          for(i=0;((i<4)&&(n<8));i++)
          {
            if(sbn==n-1)
              GLCD7.setColor(VLB_RED);
            else
              GLCD7.setColor(VLB_WHITE);
            GLCD7.drawRoundRect(x,y,x+60,y+20);
            GLCD7.setColor(text_color);
            sprintf(buf,"Size %d",n++);
            GLCD7.print(buf,x+15,y+6);
            x+=65;
          }
          x=25;
          y+=25;
        }
      }
    }
    if(myTouch.TP_Y>tsize_array[5][0]&&myTouch.TP_Y<tsize_array[5][1])  //***sbn2***
    {
      GLCD7.setBackColor(VLB_BLACK);
      if(myTouch.TP_X>tsize_array[6][0]&&myTouch.TP_X<tsize_array[6][1])//****4*****
      {
        sbn=4;
        x=25;
        y=340;
        GLCD7.setFont(bell12);
        n=1;
        for(j=0;j<2;j++)
        {
          for(i=0;((i<4)&&(n<8));i++)
          {
            if(sbn==n-1)
              GLCD7.setColor(VLB_RED);
            else
              GLCD7.setColor(VLB_WHITE);
            GLCD7.drawRoundRect(x,y,x+60,y+20);
            GLCD7.setColor(text_color);
            sprintf(buf,"Size %d",n++);
            GLCD7.print(buf,x+15,y+6);
            x+=65;
          }
          x=25;
          y+=25;
        }
      }
      if(myTouch.TP_X>tsize_array[7][0]&&myTouch.TP_X<tsize_array[7][1])//****5*****
      {
        sbn=5;
        x=25;
        y=340;
        GLCD7.setFont(bell12);
        n=1;
        for(j=0;j<2;j++)
        {
          for(i=0;((i<4)&&(n<8));i++)
          {
            if(sbn==n-1)
              GLCD7.setColor(VLB_RED);
            else
              GLCD7.setColor(VLB_WHITE);
            GLCD7.drawRoundRect(x,y,x+60,y+20);
            GLCD7.setColor(text_color);
            sprintf(buf,"Size %d",n++);
            GLCD7.print(buf,x+15,y+6);
            x+=65;
          }
          x=25;
          y+=25;
        }
      }
      if(myTouch.TP_X>tsize_array[8][0]&&myTouch.TP_X<tsize_array[8][1])//****6*****
      {
        sbn=6;
        x=25;
        y=340;
        GLCD7.setFont(bell12);
        n=1;
        for(j=0;j<2;j++)
        {
          for(i=0;((i<4)&&(n<8));i++)
          {
            if(sbn==n-1)
              GLCD7.setColor(VLB_RED);
            else
              GLCD7.setColor(VLB_WHITE);
            GLCD7.drawRoundRect(x,y,x+60,y+20);
            GLCD7.setColor(text_color);
            sprintf(buf,"Size %d",n++);
            GLCD7.print(buf,x+15,y+6);
            x+=65;
          }
          x=25;
          y+=25;
        }
      }
    }
    if(myTouch.TP_Y>box_array[0][0]&&myTouch.TP_Y<box_array[0][1])      //**********
    {
      if(myTouch.TP_X>box_array[1][0]&&myTouch.TP_X<box_array[1][1])
      {
        cbn=0;
        GLCD7.setColor(VLB_BLACK);
        GLCD7.drawRect(box[1][0],box[1][1],box[1][2],box[1][3]);       // Box 2
        GLCD7.drawRect(box[2][0],box[2][1],box[2][2],box[2][3]);       // Box 3
        GLCD7.setColor(VLB_WHITE);
        GLCD7.drawRect(box[0][0],box[0][1],box[0][2],box[0][3]);       // Box 1
      }
      if(myTouch.TP_X>box_array[2][0]&&myTouch.TP_X<box_array[2][1])
      {
        cbn=1;
        GLCD7.setColor(VLB_BLACK);
        GLCD7.drawRect(box[0][0],box[0][1],box[0][2],box[0][3]);        // Box 1
        GLCD7.drawRect(box[2][0],box[2][1],box[2][2],box[2][3]);        // Box 3
        GLCD7.setColor(VLB_WHITE);
        GLCD7.drawRect(box[1][0],box[1][1],box[1][2],box[1][3]);        // Box 2
      }
      if(myTouch.TP_X>box_array[3][0]&&myTouch.TP_X<box_array[3][1])
      {
        cbn=2;
        GLCD7.setColor(VLB_BLACK);
        GLCD7.drawRect(box[0][0],box[0][1],box[0][2],box[0][3]);        // Box 1
        GLCD7.drawRect(box[1][0],box[1][1],box[1][2],box[1][3]);        // Box 2
        GLCD7.setColor(VLB_WHITE);
        GLCD7.drawRect(box[2][0],box[2][1],box[2][2],box[2][3]);        // Box 3
      }
    }
    GLCD7.setFont(cambria22);
    GLCD7.setBackColor(VLB_BLACK);
    if(myTouch.TP_Y>color_array[0][0]&&myTouch.TP_Y<color_array[0][1])      //**1********
    {
      if(myTouch.TP_X>color_array[7][0]&&myTouch.TP_X<color_array[7][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[0];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[0];
            break;
          case 2:
            default_text_color=text_color=colors[0];
            break;
        }
      }
      if(myTouch.TP_X>color_array[8][0]&&myTouch.TP_X<color_array[8][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[1];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[1];
            break;
          case 2:
            default_text_color=text_color=colors[1];
            break;
        }
      }
      if(myTouch.TP_X>color_array[9][0]&&myTouch.TP_X<color_array[9][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[2];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[2];
            break;
          case 2:
            default_text_color=text_color=colors[2];
            break;
        }
      }
      if(myTouch.TP_X>color_array[10][0]&&myTouch.TP_X<color_array[10][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[3];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[3];
            break;
          case 2:
            default_text_color=text_color=colors[3];
            break;
        }
      }
    }
    if(myTouch.TP_Y>color_array[1][0]&&myTouch.TP_Y<color_array[1][1])      //**2********
    {
      if(myTouch.TP_X>color_array[7][0]&&myTouch.TP_X<color_array[7][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[4];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[4];
            break;
          case 2:
            default_text_color=text_color=colors[4];
            break;
        }
      }
      if(myTouch.TP_X>color_array[8][0]&&myTouch.TP_X<color_array[8][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[5];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[5];
            break;
          case 2:
            default_text_color=text_color=colors[5];
            break;
        }
      }
      if(myTouch.TP_X>color_array[9][0]&&myTouch.TP_X<color_array[9][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[6];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[6];
            break;
          case 2:
            default_text_color=text_color=colors[6];
            break;
        }
      }
      if(myTouch.TP_X>color_array[10][0]&&myTouch.TP_X<color_array[10][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[7];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[7];
            break;
          case 2:
            default_text_color=text_color=colors[7];
            break;
        }
      }
    }
    if(myTouch.TP_Y>color_array[2][0]&&myTouch.TP_Y<color_array[2][1])      //**3********
    {
      if(myTouch.TP_X>color_array[7][0]&&myTouch.TP_X<color_array[7][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[8];
           break;
          case 1:
            default_button_text_color=button_text_color=colors[8];
            break;
          case 2:
            default_text_color=text_color=colors[8];
            break;
        }
      }
      if(myTouch.TP_X>color_array[8][0]&&myTouch.TP_X<color_array[8][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[9];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[9];
            break;
          case 2:
            default_text_color=text_color=colors[9];
            break;
        }
      }
      if(myTouch.TP_X>color_array[9][0]&&myTouch.TP_X<color_array[9][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[10];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[10];
            break;
          case 2:
            default_text_color=text_color=colors[10];
            break;
        }
      }
      if(myTouch.TP_X>color_array[10][0]&&myTouch.TP_X<color_array[10][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[11];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[11];
           break;
          case 2:
            default_text_color=text_color=colors[11];
            break;
        }
      }
    }
    if(myTouch.TP_Y>color_array[3][0]&&myTouch.TP_Y<color_array[3][1])      //**4********
    {
      if(myTouch.TP_X>color_array[7][0]&&myTouch.TP_X<color_array[7][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[12];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[12];
            break;
          case 2:
            default_text_color=text_color=colors[12];
            break;
        }
      }
      if(myTouch.TP_X>color_array[8][0]&&myTouch.TP_X<color_array[8][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[13];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[13];
            break;
           case 2:
            default_text_color=text_color=colors[13];
            break;
        }
      }
      if(myTouch.TP_X>color_array[9][0]&&myTouch.TP_X<color_array[9][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[14];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[14];
            break;
          case 2:
            default_text_color=text_color=colors[14];
            break;
        }
      }
      if(myTouch.TP_X>color_array[10][0]&&myTouch.TP_X<color_array[10][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[15];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[15];
            break;
          case 2:
            default_text_color=text_color=colors[15];
            break;
        }
      }
    }
    if(myTouch.TP_Y>color_array[4][0]&&myTouch.TP_Y<color_array[4][1])      //**5********
    {
      if(myTouch.TP_X>color_array[7][0]&&myTouch.TP_X<color_array[7][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[16];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[16];
            break;
          case 2:
            default_text_color=text_color=colors[16];
            break;
        }
      }
      if(myTouch.TP_X>color_array[8][0]&&myTouch.TP_X<color_array[8][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[17];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[17];
            break;
          case 2:
            default_text_color=text_color=colors[17];
            break;
        }
      }
      if(myTouch.TP_X>color_array[9][0]&&myTouch.TP_X<color_array[9][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[18];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[18];
            break;
          case 2:
            default_text_color=text_color=colors[18];
            break;
        }
      }
      if(myTouch.TP_X>color_array[10][0]&&myTouch.TP_X<color_array[10][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[19];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[19];
            break;
          case 2:
            default_text_color=text_color=colors[19];
            break;
        }
      }
    }
    if(myTouch.TP_Y>color_array[5][0]&&myTouch.TP_Y<color_array[5][1])      //**6********
    {
      if(myTouch.TP_X>color_array[7][0]&&myTouch.TP_X<color_array[7][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[20];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[20];
            break;
          case 2:
            default_text_color=text_color=colors[20];
            break;
        }
      }
      if(myTouch.TP_X>color_array[8][0]&&myTouch.TP_X<color_array[8][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[21];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[21];
            break;
          case 2:
            default_text_color=text_color=colors[21];
            break;
        }
      }
      if(myTouch.TP_X>color_array[9][0]&&myTouch.TP_X<color_array[9][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[22];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[22];
            break;
          case 2:
            default_text_color=text_color=colors[22];
            break;
        }
      }
      if(myTouch.TP_X>color_array[10][0]&&myTouch.TP_X<color_array[10][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[23];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[23];
            break;
          case 2:
            default_text_color=text_color=colors[23];
            break;
        }
      }
    }
    if(myTouch.TP_Y>color_array[6][0]&&myTouch.TP_Y<color_array[6][1])      //**7********
    {
      if(myTouch.TP_X>color_array[7][0]&&myTouch.TP_X<color_array[7][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[24];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[24];
            break;
          case 2:
            default_text_color=text_color=colors[24];
            break;
        }
      }
      if(myTouch.TP_X>color_array[8][0]&&myTouch.TP_X<color_array[8][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[25];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[25];
            break;
          case 2:
            default_text_color=text_color=colors[25];
            break;
        }
      }
      if(myTouch.TP_X>color_array[9][0]&&myTouch.TP_X<color_array[9][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[26];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[26];
            break;
          case 2:
            default_text_color=text_color=colors[26];
            break;
        }
      }
      if(myTouch.TP_X>color_array[10][0]&&myTouch.TP_X<color_array[10][1])
      {
        switch(cbn)
        {
          case 0:
            default_button_color=button_color=colors[27];
            break;
          case 1:
            default_button_text_color=button_text_color=colors[27];
            break;
          case 2:
            default_text_color=text_color=colors[27];
            break;
        }
      }
    }
    GLCD7.setColor(button_color);
    GLCD7.print("BUTTON",50,y1);
    GLCD7.setColor(button_text_color);
    GLCD7.print("BUTTON TEXT",170,y1);
    GLCD7.setColor(text_color);
    GLCD7.print("TEXT",355,y1);
    if(myTouch.TP_Y>300&&myTouch.TP_Y<480)
      if(myTouch.TP_X>2700&&myTouch.TP_X<3400)
        waiting=0;
    delay(175);
  }
  while(myTouch.dataAvailable());
  delay(325);
  myTouch.read();
  gx=myTouch.getX();
  gy=myTouch.getY();
} 

