unsigned long keypad(int orientation) 
{
int i,j,x,sx,y,sy,n;
int ex,ey,bsize,space;

  switch(orientation)
  {
    case 0:     // PORTRAIT
      x=50;
      y=dispy-130;
      break;

    case 1:    // LANDSCAPE
      x=215;
      y=215;
      break;
  }
  sx=x;
  sy=y;
  bsize=60;
  space=5;
  ex=sx+bsize;
  ey=sy+bsize;
  n=1;
  for(i=0;i<2;i++)
  {
    sx=x;
    ex=sx+bsize;
    for (j=0; j<4; j++,n++)
    {
      GLCD7.setFont(bodb26);
      GLCD7.setBackColor(button_color);
      GLCD7.setColor(button_color);
      GLCD7.fillRoundRect(sx,sy,ex,ey);
      GLCD7.setColor(button_text_color);
      GLCD7.drawRoundRect(sx,sy,ex,ey);
      sprintf(buf,"%d",n);
      if(n<10)
        GLCD7.print(buf,sx+23,ey-45);
      else
        GLCD7.print(buf,sx+16,ey-45);
      GLCD7.setFont(bell9);
      GLCD7.print(menu[n-1],sx+3+(2*(8-strlen(menu[n-1]))),ey-15);
      sx+=(bsize+space);
      ex=(sx+bsize);
    }
    sy+=(bsize+space);
    ey=(sy+bsize);
  }
}




