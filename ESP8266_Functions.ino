int reset_ESP8266(void)
{
  displayText("RESET ESP8266",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+RST");
  diaplay_response(text_color,7000);
  return (check_ready());
}

int set_CWMODE(void)
{
  displayText("SET ESP8266 MODE",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CWMODE=1");
  diaplay_response(text_color,2000);
  return (check_ok());
}

int set_CWJAP(void)
{
  displayText("JOIN ACCESS POINT",cx,cy+=ny,1,text_color);
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
  sprintf(buf,"AT+CWJAP=\"%s\",\"%s\"",SSID_ESP,SSID_KEY);
  ESP8266.println(buf);
  diaplay_response(text_color,4000);
  return (check_ok());
}

int get_ip_address(void)
{
  displayText("ESP8266 IP ADDRESS",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CIFSR");
  diaplay_response(text_color,3000);
  return (check_ok());
}

int set_CIPMUX(void)
{
  displayText("SET ESP8266 Multiplex",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CIPMUX=1");
  diaplay_response(text_color,2000);
  return (check_ok());
}

int set_server(void)
{
  displayText("SET AS ESP8266 Server",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CIPSERVER=1,80");
  diaplay_response(text_color,4000);
  return (check_ok());
}

int close_server(void)
{
  displayText("CLOSE ESP8266 Server",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CIPSERVER=0");
  diaplay_response(text_color,2000);
  return (check_ok());
}

int close_AP(void)
{
  displayText("QUIT ACCESS POINT",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CWQAP");
  diaplay_response(text_color,3500);
  return (check_ok());
}

int AP_list(void)
{
  displayText("ESP8266 ACCESS POINTS",cx,cy+=ny,1,VLB_ORANGE);
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
  ESP8266.println("AT+CWLAP");
  diaplay_response(text_color,4000);
  return (check_ok());
}

int ESP8266_Status(void)
{
  displayText("ESP8266 STATUS",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CIPSTATUS");
  diaplay_response(text_color,2000);
  return (check_ok());
}

int joined_AP(void)
{
  displayText("JOINED ACCESS POINT",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT+CWJAP?");
  diaplay_response(text_color,2000);
  return (check_ok());
}

int ESP8266_Info(void)
{
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
  ESP8266.println("AT+GMR");
  displayText("ESP8266 Info",cx,cy+=ny,1,text_color);
  diaplay_response(text_color,2000);
  return (check_ok());
}

int check_AT(void)
{
  displayText("CHECK AT RESPONSE",cx,cy+=ny,1,text_color);
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
  ESP8266.println("AT");
  diaplay_response(text_color,1000);
  return (check_ok());
}

int diaplay_response(word color,uint32_t timeout_val)
{
int i,wait;
uint32_t timeout_start_val;

  GLCD7.setColor(color);
  wait=1;
  timeout_start_val=millis();
  while(!ESP8266.available()&&wait);
  {
    if((millis()-timeout_start_val)>timeout_val)
      wait=0;
  }
  i=0;
//  wait=1;
  timeout_start_val=millis();
  while(((i=ESP8266.readBytesUntil('\n', data_in, 1024))>=0)&&wait)
  {
    data_in[i]=0x00;
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
    if((millis()-timeout_start_val)>timeout_val)
      wait=0;
  }
  return i;
}

int check_ready(void)
{
int i;

  for(i=0;i<1024;i++)
  {
    if(data_in[i]=='r')
    {
      if(data_in[i+1]=='e')
      {
        if(data_in[i+2]=='a')
        {
          if(data_in[i+3]=='d')
          {
            if(data_in[i+4]=='y')
            {
              return i;
            }
          }
        }
      }
    }
  }
  return 0;
}

int check_ok(void)
{
int i;

  for(i=0;i<1024;i++)
  {
    if(data_in[i]=='O')
    {
      if(data_in[i+1]=='K')
      {
        return i;
      }
    }
  }
  return 0;
}

void erase_response(void)
{
  clrscr();
}

