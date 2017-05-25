void keypad(void) 
{
int i,j,sx,sy,ex,ey,bsize,space,toffset;

  myGLCD.setTextSize(1);
  myGLCD.setTextColor(VLB_WHITE);
  myGLCD.setFont(&FreeMono9pt7b);
  bsize=60;
  space=5;
  sy=180;
  ex=ey=bsize;
  toffset=20;
  for(i=0;i<2;i++)
  {
    sx=150;
    for(j=0;j<3;j++)
    {
      switch(i)
      {
        case 0:
          switch(j)
          {
            case 0:
              myGLCD.fillRoundRect(sx,sy,ex,ey,3,VLB_RED);
              break;
            case 1:
              myGLCD.fillRoundRect(sx,sy,ex,ey,3,VLB_GREEN);
              break;
            case 2:
              myGLCD.fillRoundRect(sx,sy,ex,ey,3,VLB_BLUE);
              break;
          }
          myGLCD.setTextSize(2);
          myGLCD.setCursor(sx+toffset,sy+bsize-toffset);
          myGLCD.print("+");
          myGLCD.setTextSize(1);
          break;
        case 1:
          switch(j)
          {
            case 0:
              myGLCD.fillRoundRect(sx,sy,ex,ey,3,VLB_RED);
              break;
            case 1:
              myGLCD.fillRoundRect(sx,sy,ex,ey,3,VLB_GREEN);
              break;
            case 2:
              myGLCD.fillRoundRect(sx,sy,ex,ey,3,VLB_BLUE);
              break;
          }
          myGLCD.setTextSize(2);
          myGLCD.setCursor(sx+toffset,sy+bsize-toffset);
          myGLCD.print("-");
          myGLCD.setTextSize(1);
          break;
      }
      myGLCD.drawRoundRect(sx,sy,ex,ey,3,VLB_WHITE);
      sx+=(bsize+space);
    }
    sy+=(bsize+space);
  }
}

