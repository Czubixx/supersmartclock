int alarmNum = 0;
String alarmArray[10][5] = {
  {"1", "name", "18", "59", "1111101"},
  {"", "", "", "", ""},
  {"", "", "", "", ""},
  {"", "", "", "", ""},
  {"", "", "", "", ""},
  {"", "", "", "", ""},
  {"", "", "", "", ""},
  {"", "", "", "", ""},
  {"", "", "", "", ""},
};


void readAlarmFormFile() {
  File file = SPIFFS.open("/alarm.json", "r");

  if(!file){
    Serial.println("SPIFFS was not loaded");
    return;
  }

  DynamicJsonDocument doc(2048);
  deserializeJson(doc, file);

  alarmNum = doc["alarmNum"];

  Serial.println(alarmNum);
  
  for (size_t i = 1; i < alarmNum; i++)
  {
    String alarmtopic = "alarm";

    String status = doc[alarmtopic][i - 1]["status"];
    String name = doc[alarmtopic][i - 1]["name"];
    String hour = doc[alarmtopic][i - 1]["hour"];
    String minute = doc[alarmtopic][i - 1]["min"];
    String day = doc[alarmtopic][i - 1]["day"];


    alarmArray[i - 1][4] = day;
    alarmArray[i - 1][3] = minute;
    alarmArray[i - 1][2] = hour;
    alarmArray[i - 1][1] = name;
    alarmArray[i - 1][0] = status;
    Serial.println(name);
    Serial.println(status);
    Serial.println(hour);
    Serial.println(minute);
    Serial.println(day);
  }

  file.close();
}


String readAlarmFormFileToString() {
  File file = SPIFFS.open("/alarm.json", "r");

  if(!file){
    Serial.println("SPIFFS was not loaded");
  }

  DynamicJsonDocument doc(2048);
  deserializeJson(doc, file);

  alarmNum = doc["alarmNum"];
  for (size_t i = 1; i < alarmNum; i++)
  {
    String alarmtopic = "alarm";


    String status = doc[alarmtopic][i-1]["status"];
    String name = doc[alarmtopic][i-1]["name"];
    String hour = doc[alarmtopic][i-1]["hour"];
    String minute = doc[alarmtopic][i-1]["min"];
    String day = doc[alarmtopic][i-1]["day"];


    alarmArray[i - 1][4] = day;
    alarmArray[i - 1][3] = minute;
    alarmArray[i - 1][2] = hour;
    alarmArray[i - 1][1] = name;
    alarmArray[i - 1][0] = status;
    Serial.println(name);
    Serial.println(status);
    Serial.println(hour);
    Serial.println(minute);
    Serial.println(day);
  }

  file.close();
  serializeJson(doc, Serial);
  String outdsfsdf;
  serializeJson(doc, outdsfsdf);
  Serial.println(outdsfsdf);
  return outdsfsdf;
     
}



void writeFileFromArray(){

  DynamicJsonDocument doc(2000);
  doc["alarmNum"] = alarmNum;
  for (size_t i = 0; i < (alarmNum - 1); i++)
  {
    JsonObject alarm = doc["alarm"].createNestedObject();
    alarm["status"] = alarmArray[i][0];
    alarm["name"] = alarmArray[i][1];
    alarm["hour"] = alarmArray[i][2];
    alarm["min"] = alarmArray[i][3];
    alarm["day"] = alarmArray[i][4];
  }

  File File = SPIFFS.open("/alarm.json", "w");
  serializeJson(doc, Serial);
  serializeJson(doc, File);
  File.close();
  Serial.println(alarmNum);

}

String changeAlarmStatus(int index){
  
  if(alarmArray[index][0] == "1")
    alarmArray[index][0] = "0";
  else if (alarmArray[index][0] == "0")
    alarmArray[index][0] = "1";
  Serial.println("CHANGE");
  writeFileFromArray();
  
  String json1 = "{\"state\":\"";
  json1 += alarmArray[index][0] + "\"}";
  Serial.println(json1);
  return json1;
}

void writeAlarmToFile(String name, String status, String hour, String min, String day){

  File configFile = SPIFFS.open("/alarm.json", "r");
  if (!configFile) {
    Serial.println("- failed to open config file for writing");
    return;
  }

  DynamicJsonDocument doc(2048);
  deserializeJson(doc, configFile);
  int alarmNum = doc["alarmNum"];
  configFile.close();

  String alarmArrayName = "alarm" + String(alarmNum + 1);
  Serial.println(alarmArrayName);
  doc["alarmNum"] = alarmNum+1;

  JsonObject alarm = doc["alarm"].createNestedObject();
  alarm["status"] = status;
  alarm["name"] = name;
  alarm["hour"] = hour;
  alarm["min"] = min;
  alarm["day"] = day;

  configFile = SPIFFS.open("/alarm.json", "w");
  serializeJson(doc, configFile);
  serializeJson(doc, Serial);
  configFile.close();

}

void turnAlarm(int index){

  Serial.println(alarmArray[index][1]);
  displayAlarm(alarmArray[index][1], alarmArray[index][2], alarmArray[index][3], 0);

}

int  weekaday = weekday();

unsigned long alarmDelay = 0;
void alarmWaiting() {
  
  if(second() == 0 &&(unsigned long)(millis() - alarmDelay) >= 1000){
    for (size_t i = 1; i < alarmNum; i++)
    {
      Serial.println("PETLA W SPRAWDZANIU ALARMU");
      if(alarmArray[i - 1][0].toInt() == 1 && alarmArray[i - 1][2].toInt() == hour() && alarmArray[i - 1][3].toInt() == minute()){
        Serial.println("TEST");
        Serial.println((weekday() - 1));
         Serial.println(weekday());
        Serial.println(alarmArray[i - 1][4].substring((weekday() - 1), weekday()).toInt());
        if((alarmArray[i - 1][4].substring((weekday() - 1), weekday()).toInt()) == 1){
          turnAlarm(i - 1);
        }
      }
    }
    alarmDelay = millis();
  }
}

String removeAlarm(int index) {
  File configFile = SPIFFS.open("/alarm.json", "r");
  if (!configFile) {
    Serial.println("- failed to open config file for writing");
  }

  DynamicJsonDocument doc(2048);
  deserializeJson(doc, configFile);
  configFile.close();

  int alarmNum = doc["alarmNum"];
  doc["alarmNum"] = alarmNum - 1;
  
  doc["alarm"].remove(index);


  configFile = SPIFFS.open("/alarm.json", "w");
  serializeJsonPretty(doc, configFile);
  serializeJsonPretty(doc, Serial);
  configFile.close();

  String test = "{\"status\":\"200\"}";
  return  test;
}

