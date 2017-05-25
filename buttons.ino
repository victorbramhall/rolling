void buttons(int sel)
{
int x,y,sx,ex,sy,radius1,radius2;

  sx=377;
  ex=425;
  sy=235;
  radius1=15;
  radius2=5;
  switch(sel)
  {
    case 0:
      x=sx;
      y=sy;
      myGLCD.fillCircle(x,y,radius1,VLB_IVORY);
      myGLCD.fillCircle(x,y,radius2,VLB_MediumBlue);
      x=ex;
      myGLCD.fillCircle(x,y,radius1,VLB_IVORY);
      break;
    case 1:
      x=sx;
      y=sy;
      myGLCD.fillCircle(x,y,radius1,VLB_IVORY);
      x=ex;
      myGLCD.fillCircle(x,y,radius1,VLB_IVORY);
      myGLCD.fillCircle(x,y,radius2,VLB_MediumBlue);
      break;
  }
}

