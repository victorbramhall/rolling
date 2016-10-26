void displayText(char string[],int x,int y,int tsize,uint16_t color) 
{

  GLCD7.setColor(color);
  switch (tsize)
  {
    case 1:
      GLCD7.setFont(bell14);
      break;
    case 2:
    case 3:
      GLCD7.setFont(cambria26);
      break;
  }
  GLCD7.print(string,x,y);
}

void displayNum(uint16_t number,int x,int y,int tsize,uint16_t color,int num) 
{
  GLCD7.setColor(color);
  switch (tsize)
  {
    case 1:
      GLCD7.setFont(bell14);
      break;
    case 2:
    case 3:
      GLCD7.setFont(cambria26);
      break;
  }
  if(num)
  {
    sprintf(buf,"0x%04X",number);
    GLCD7.print(buf,x,y);
  }
  else
  {
    sprintf(buf,"%d",number);
    GLCD7.print(buf,x,y);
  }
}

void displayFloat(float number,int x,int y,int tsize,uint16_t color) 
{
  GLCD7.setColor(color);
  switch (tsize)
  {
    case 1:
      GLCD7.setFont(bell14);
      break;
    case 2:
    case 3:
      GLCD7.setFont(cambria26);
      break;
  }
  sprintf(buf,"%2f",number);
  GLCD7.print(buf,x,y);
}

void erase_text(uint8_t x,uint8_t y)
{
  GLCD7.setColor(GLCD7.getBackColor());
  GLCD7.fillRect(x,y,dispx-1,y+15);
  GLCD7.setColor(text_color);
}

void showNumI(char *msg, uint32_t val, int x, int y)
{
    sprintf(buf," %d",val);
    strcpy(msg,buf);
    GLCD7.print(msg,x,y);
}

void Hex2Ascii(uint32_t num)
{
    sprintf(buf,"0x%08XUL   ",num);
}

void DisplayKeyboardText(void)
{
int i;

  KeyboardColors();
  for(i=0;i<tbc;i++)
  {
    if(TextBox[i]==0x0D)
    {
      i+=2;
      tloc=0;
      tlocx=60;
      tlocy+=18;
    }
    if(TextBox[i]!=0x00)
    {
      GLCD7.printProportionalChar(TextBox[i],tlocx,tlocy);
      tlocx+=13;
      tloc++;
    }
    else
      i=tbc+1;
  }
}

