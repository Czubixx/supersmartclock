unsigned int d_PosX = 0;      
unsigned int z_PosX = 0;
int speed = 30;
bool display_temperature = false;
String stringMessage;
bool scrolingText = false;
bool conwert_data = true;
char result[4];
char weatherTemp[5];



void displayAlarm(String alarmName, String alarmHour, String alarmMinute, int iconID){
    if(alarmHour.toInt() < 10){
        alarmHour = "0" + alarmHour;
    }
    if(alarmMinute.toInt() < 10){
        alarmMinute = "0" + alarmMinute;
    }
    unsigned int bufSize = alarmName.length() + 1;
    bool alarmActive = true;
    char text[bufSize + 1];
    alarmName.toCharArray(text, bufSize);
    
    String alarmTime = alarmHour + ":" + alarmMinute;
    Serial.println(alarmTime);
    clear_Display();

    unsigned long alarm1000delay = 0;
    unsigned long alarm400delay = 0;
    unsigned long alarmTimerStop = millis();
    bool reflershDisply = true;

    while (alarmActive)
    {
        yield();
        if(digitalRead(D1) == HIGH){
            Serial.println("ALARM STOP");
            alarmActive = false;
            delay(500);
        }

        if((unsigned long)(millis() - alarm1000delay) >= 1000 && !reflershDisply){
            clear_Display();
            refresh_display();
            alarm1000delay = millis();
            alarm400delay = millis();
            reflershDisply = true;
        }

        if((unsigned long)(millis() - alarm400delay) >= 500  && reflershDisply){
            char2Arr(alarmTime[4], 5, 0);
            char2Arr(alarmTime[3], 10, 0);
            char2Arr(alarmTime[2], 12, 0);
            char2Arr(alarmTime[1], 18, 0);
            char2Arr(alarmTime[0], 23, 0);
            charEmojiArr(0, 30, 0);
            refresh_display();
            reflershDisply = false;
        }
        if((unsigned long)(millis() - alarmTimerStop) >= 60000){
            alarmActive = false;
        }
    }
    

}


void displayNotification(String message, int iconID){

    unsigned int bufSize = message.length() + 1;
    bool alarmActive = true;
    char text[bufSize + 1];
    message.toCharArray(text, bufSize);
    
    Serial.println(message);
    clear_Display();

    int whileStop = 0;

    while (3 > whileStop)
    {
        yield();
        
        for (size_t j = 0; j < (bufSize*6)+32; j++)
        {
            clear_Display();
            for (size_t i = 0; i < bufSize; i++)
            {
                char2textArr(text[i], j - (i*6) , 0);
            }
            charEmojiArr(0, 30, 0);
            refresh_display();
            delay(40);
        }
        whileStop++;
    }
    

}


void ScrollText(String stringText, int loopNumber){
    unsigned int x = 0;
    unsigned int bufSize = stringText.length() + 1;

    char text[bufSize + 1];
    stringText.toCharArray(text, bufSize);

    while (x < loopNumber)
    {
        for (size_t j = 0; j < (bufSize*6)+32; j++)
        {
            clear_Display();
            for (size_t i = 0; i < bufSize; i++)
            {
                char2textArr(text[i], j - (i*6) , 0);
            }
            refresh_display();
            delay(40);
        }
        x++;
    }
    


}
unsigned int bufSize;
char text[128];

void ScrollTextAnimation(){

    if(conwert_data){
        String stringText = " ";
        stringText += stringMessage;
        bufSize = stringText.length() + 1;
    
        stringText.toCharArray(text, bufSize);
        conwert_data = false;
    }

    d_PosX++;
    z_PosX++;
    
    

    if (d_PosX == (bufSize * 6))
        z_PosX = 0;
    if (z_PosX == maxPosX) {
        scrolingText = false;
        conwert_data = true;
        d_PosX = -4;
    }
    
    for (size_t i = 1; i < bufSize; i++)
    {
        char2textArr(text[i], d_PosX - (i*6), 0);
    }

    refresh_display();

    delay(50);
}


void displayTemperature(){
  
    d_PosX++;
    z_PosX++;
      
    if (d_PosX == 55)
        z_PosX = 0;
    if(d_PosX == 40)
        delay(3000);
    if (z_PosX == maxPosX) {
        display_temperature = false;
        d_PosX = -4;
    }


    char2Arr(result[0], d_PosX - 7, 0);
    char22Arr(result[3], d_PosX - 17, 0);
    char2Arr(result[1], d_PosX - 13, 0);
    

    if(weatherTemp[1] == ' '){
        char2Arr('E', d_PosX - 28, 0);
        char2Arr('R', d_PosX - 34, 0);
    }else{
        if(weatherTemp[0] == ' '){
            char2Arr(weatherTemp[1], d_PosX - 27, 0);
            if(weatherTempFahrenheit){
                char2Arr('F', d_PosX - 34, 0);
            }else{
                char2Arr('C', d_PosX - 34, 0);
            }
        }else{
            char2Arr(weatherTemp[0], d_PosX - 28, 0);
            char2Arr(weatherTemp[1], d_PosX - 34, 0);
            if(weatherTempFahrenheit){
                char2Arr('F', d_PosX - 42, 0);
            }else{
                char2Arr('C', d_PosX - 42, 0);
            }
        }


    }

    refresh_display();
    delay(50);
}

bool displayDate_convert = true;
char monthDay[3];
char years[5];

void displayDate(){
  
    if(displayDate_convert){
        String yarsDaystr;
        yarsDaystr=String(year());
        yarsDaystr.toCharArray(years,5);

        String monthDaystr;
        monthDaystr=String(day());
        monthDaystr.toCharArray(monthDay,3);

        Serial.println(day());
        displayDate_convert = false;

        Serial.println(monthDay[0]);
        Serial.println(monthDay[1]);
        Serial.println(years[3]);
    }


    d_PosX++;
    z_PosX++;
      
    if (d_PosX == 75)
        z_PosX = 0;
    if (z_PosX == maxPosX) {
        display_temperature = false;
        displayDate_convert = true;
        d_PosX = -4;
    }


    char2Arr(monthDay[0], d_PosX - 7, 0);
    char2Arr(monthDay[1], d_PosX - 13, 0);
    char2Arr(mffonth[month() - 1][0], d_PosX - 23, 0);
    char2Arr(mffonth[month() - 1][1], d_PosX - 29, 0);
    char2Arr(mffonth[month() - 1][2], d_PosX - 35, 0);
    char2Arr(years[0], d_PosX - 43, 0);
    char2Arr(years[1], d_PosX - 49, 0);
    char2Arr(years[2], d_PosX - 55, 0);
    char2Arr(years[3], d_PosX - 61, 0);
    
    refresh_display();
    delay(50);
}
