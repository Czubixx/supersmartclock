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

    if(conwert_data == true){
        String stringText = " ";
        stringText += stringMessage;
        bufSize = stringText.length() + 1;
    
        stringText.toCharArray(text, bufSize);
    }

    d_PosX++;
    z_PosX++;
    
    conwert_data = false;

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
    

    if(weatherTemp[0] != ' '){
        char2Arr('E', d_PosX - 28, 0);
        char2Arr('R', d_PosX - 34, 0);
    }else{
        char2Arr(weatherTemp[0], d_PosX - 28, 0);
        char2Arr(weatherTemp[1], d_PosX - 34, 0);
        if(weatherTempFahrenheit){
            char2Arr('F', d_PosX - 42, 0);
        }else{
            char2Arr('C', d_PosX - 42, 0);
        }
    }

    refresh_display();
    delay(50);
}
