#include <Arduino.h>
#include <SPI.h>
#include <Ticker.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <FS.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266httpUpdate.h>
#include <TimeLib.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <WiFiUdp.h>
#include <EEPROM.h>
#include <Wire.h>

#include "web/PAGES.h"
#include "Font_Data.h"

WiFiClient espClient;


#include "matrix/max7219.h"
#include "matrix/diplayText.h"
#include "bootTask.h"
#include "web/connect.h"
#include "web/update.h"
#include "weather.h"
#include "temp.h"
#include "ntp.h"
#include "web/Mqtt/mqtt.h"
#include "alarm.h"
#include "web/page.h"

           
              
                      
bool f_tckr1s = false;
bool f_tckr50ms = false;

Ticker tckr;

void timer50ms() {
    static unsigned int cnt50ms = 0;
    f_tckr50ms = true;
    cnt50ms++;
    if (cnt50ms == 20) {
        f_tckr1s = true; // 1 sec
        cnt50ms = 0;
    }
}
//**************************************************************************************************


//***************************************************************************

void setup() {

    pinMode(D2, OUTPUT);
    pinMode(CS, OUTPUT);
    pinMode(D1, INPUT);
    digitalWrite(CS, HIGH);
    Serial.begin(115200);
    SPI.begin();
   
    helpArr_init();
    max7219_init();  
    if(!SPIFFS.begin()){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }


    createFile();
     getNetworkConfig();
    WifiConnectSetup();
    setWeather();

    tempSetup();
    mqqtSetup();
    
    getTimeSetup();
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.subnetMask());
    Serial.println(WiFi.gatewayIP());
    tckr.attach(0.05, timer50ms);
    renderPageSetup();
    setBrightness(-1);
    readAlarmFormFile();
    getNightMode();
}
//**************************************************************************************************
// The loop function is called in an endless loop

int hour1(){
  int hours = hour();
  hours = hours /= 10;
  return hours;
}

int hours2(){
  int hourse2 = hour();
  hourse2 = hourse2 % 10;
  return hourse2;
}

int minuts1(){
  int hourse2 = minute();
  hourse2 = hourse2 /= 10;
  return hourse2;
  
}
int minuts2(){
  int hourse2 = minute();
  hourse2 = hourse2 % 10;
  return hourse2;
}
int secude1(){
  int hourse3 = second();
  hourse3 = hourse3 /= 10;
  return hourse3;
}
int secunde2(){
  int hourse3 = second();
  hourse3 = hourse3 % 10;
  return hourse3;
}

int lastTime =0;
bool nightMode = false;

void loop() {
    unsigned int sek1 = secunde2(), sek2 = secude1();
    unsigned int min1 = minuts2(), min2 = minuts1();
    unsigned int std1 = hours2(), std2 = hour1();
    unsigned int sek11 = 0, sek12 = 0, sek21 = 0, sek22 = 0;
    unsigned int min11 = 0, min12 = 0, min21 = 0, min22 = 0;
    unsigned int std11 = 0, std12 = 0, std21 = 0, std22 = 0;
    signed int x = 0; //x1,x2;
    signed int y = 0, y1 = 0, y2 = 0, y3=0;
    bool updown = false;
    unsigned int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0, sc5 = 0, sc6 = 0;
    bool f_scrollend_y = false;

    bool sc3_scroll = false;
    bool sc4_scroll = false;
    bool sc5_scroll = false;
    bool sc6_scroll = false;

    bool displayTime = true;


    z_PosX = maxPosX;
    d_PosX = -4;
    //  x=0; x1=0; x2=0;
    Serial.println(weekday());
    Serial.println(day());
    refresh_display();
    updown = true;
    if (updown == false) {
        y2 = -9;
        y1 = 13;
    }
    if (updown == true) { //scroll  up to down
        y2 = 8;
        y1 = -8;
    }

    // do 06:30 od 23:15 
    Serial.println(nightModeFormHour);
    Serial.println(nightModeFormMin);
    while (true) {
        yield();
        if(WiFi.status()== WL_CONNECTED){
            server.handleClient();

            if(!nightModeEnable){
                nightMode = false;
                displayTime = true;
            }
            
            if(nightModeFormHour == hour() && nightModeFormMin == minute() && nightModeEnable){
                nightMode = true;
            }
            if(nightModeToHour == hour() && nightModeToMin == minute()){
                nightMode = false;
                displayTime = true;
            }


            if (f_tckr1s == true)        // flag 1sek
            {
                y = y2;                 //scroll updown
                sc1 = 1;
                sek1 = secunde2();
                sek2 = secude1();
                min1 = minuts2(); 
                min2 = minuts1();
                if (sek1 == 0) {
                    sek1 = secunde2();
                    sc2 = 1;
                }

                if (sek2 == 0 && sc3_scroll != true) {
                    min1 = minuts2();
                    min2 = minuts1();
                    sek2 = secude1();
                    sek1 = secunde2();
                    sc3 = 1;
                    sc3_scroll = true;
                }
                if (sek2 != 0 && sc3_scroll != false){
                    sc3_scroll = false;
                }


                
                if (min1 == 0 && sc4_scroll != true) {
                    min2 = minuts1();
                    min1 = minuts2();
                    sek2 = secude1();
                    sek1 = secunde2();
                    std1 = hours2();
                    std2 = hour1();
                    sc4 = 1;
                    sc4_scroll = true;
                }
                if (min1 != 0 && sc4_scroll != false){
                    sc4_scroll = false;
                }

                

                if (min2 == 0 && sc5_scroll != true) {
                    min2 = minuts1();
                    min1 = minuts2();
                    sek2 = secude1();
                    sek1 = secunde2();
                    std1 = hours2();
                    std2 = hour1();
                    sc5 = 1;
                    sc5_scroll = true;
                }
                if(min2 != 0 &&  sc5_scroll != false){
                    sc5_scroll = false;
                }



                if (std1 == 0 && sc6_scroll != true) {
                    min2 = minuts1();
                    min1 = minuts2();
                    sek2 = secude1();
                    sek1 = secunde2();
                    std1 = hours2();
                    std2 = hour1();
                    sc6 = 1;
                    sc6_scroll = true;
                }
                if(std1 != 0 && sc6_scroll != false){
                    sc6_scroll = false;
                }

                sek11 = sek12;
                sek12 = sek1;
                sek21 = sek22;
                sek22 = sek2;
                min11 = min12;
                min12 = min1;
                min21 = min22;
                min22 = min2;
                std11 = std12;
                std12 = std1;
                std21 = std22;
                std22 = std2;
                f_tckr1s = false;
            }
                // if (digitalRead(D1) == HIGH){
                //     printTemperature(insideThermometer);
                //     display_temperature = true;
                // }
            if (digitalRead(D1) == HIGH){
                if(!nightMode){
                    printTemperature(insideThermometer);
                    display_temperature = true;
                }
                Serial.println("TEST");
                if(nightMode)
                    displayTime = true;
                    // sc6 = 0;
                    // sc5 = 0;
                    // sc4 = 0;
                    // sc3 = 0;
                    // sc2 = 0;
                    // sc1 = 0;
                    // sc3_scroll = false;
                    // sc4_scroll = false;
                    // sc5_scroll = false;
                    // sc6_scroll = false;
            }else{
                if(nightMode){
                    displayTime = false;
                    clear_Display();
                }
            }

            if(displayTime){
                if (f_tckr50ms == true) {
                    f_tckr50ms = false;
                    if (sc1 == 1) {
                        if (updown == 1){
                            y--;
                        }
                        else{
                            y++;
                        }
                        y3 = y;
                        if (y3 > 0) {
                        y3 = 0;
                        }     
                        char22Arr(48 + sek12, z_PosX - 27, (y+ 4) + (y1+ 4));
                        char22Arr(48 + sek11, z_PosX - 27, y + y1);
                        if (y == 0) {
                            sc1 = 0;
                            f_scrollend_y = true;
                        }
                    }
                    else
                        char22Arr(48 + sek1, z_PosX - 27, 0);

                    if (sc2 == 1) {
                        char22Arr(48 + sek22, z_PosX - 23, (y+ 4) + (y1+ 4));
                        char22Arr(48 + sek21, z_PosX - 23, y + y1);
                        if (y == 0)
                            sc2 = 0;
                    }
                    else
                        char22Arr(48 + sek2, z_PosX - 23, 0);

                    if (sc3 == 1) {
                        char2Arr(48 + min12, z_PosX - 19, (y+ 4) + (y1+ 4));
                        char2Arr(48 + min11, z_PosX - 19, y + y1);
                        if (y == 0)
                            sc3 = 0;
                    }
                    else
                        char2Arr(48 + min1, z_PosX - 19, 0);

                    if (sc4 == 1) {
                        char2Arr(48 + min22, z_PosX - 14, (y+ 4) + (y1+ 4));
                        char2Arr(48 + min21, z_PosX - 14, y + y1);
                        if (y == 0)
                            sc4 = 0;
                    }
                    else
                        char2Arr(48 + min2, z_PosX - 14, 0);

                        char2Arr(':', z_PosX - 11 + x, 0);

                    if (sc5 == 1) {
                        char2Arr(48 + std12, z_PosX - 4, (y+ 4) + (y1+ 4));
                        char2Arr(48 + std11, z_PosX - 4, y + y1);
                        if (y == 0)
                            sc5 = 0;
                    }
                    else
                        char2Arr(48 + std1, z_PosX - 4, 0);

                    if (sc6 == 1) {
                        char2Arr(48 + std22, z_PosX + 1, (y+ 4) + (y1+ 4));
                        char2Arr(48 + std21, z_PosX + 1, y + y1);
                        if (y == 0)
                            sc6 = 0;
                    }
                    else{
                        tempLoop();
                        char2Arr(48 + std2, z_PosX + 1, 0);

                    //   char2Arr(result[0], d_PosX - 3, 0);
                    //   char22Arr(result[3], d_PosX - 13, 0);
                    //   char2Arr(result[1], d_PosX - 9, 0);


                    //   char2Arr(weatherTemp[1], d_PosX - 29, 0);
                    //   char2Arr(weatherTemp[0], d_PosX - 23, 0);




                        refresh_display(); //alle 50ms
                        if (f_scrollend_y == true) {
                            f_scrollend_y = false;
                        }
                    }

                } //end 50ms
                if (y == 0) {
                    // do something else
                }
            }
        alarmWaiting();
        getWeather();
        mqttLoop();
        

       // renderPageLoop();
        
        if(scrolingText == true){
            ScrollTextAnimation();    
        }
        if(display_temperature){
            displayTemperature();
        }
        }
    }  //end while(true)
    
}
