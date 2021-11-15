int timeZone = 0; 
int set_temperature = 0;
char ntpServerName[33];
int trialsNtp_reqest = 0;
int brightness_value = -1;


String weatherApi;
String watherCity;
String serverName;

String mqtt_enable;
String mqtt_server;
String mqtt_user;
String mqtt_password;
String mqtt_topic;
String mqtt_topic_mes;
String mqtt_topic_temp;
String mqtt_topic_brightness;
String mqtt_topic_alarm;

String wifi__ssid;
String wifi__pass;
String wifi__enable__ip;
String wifi_ip[3][4] = {
    {"0","0","0","0"}, //static ip
    {"0","0","0","0"},  //gateway
    {"0","0","0","0"},  //subnet mask
};

bool nightModeEnable;
int nightModeFormHour;
int nightModeFormMin;
int nightModeToHour;
int nightModeToMin;



void setBrightness(int value){
    if(value == -1){
        Serial.println("AUTO");
        brightness_value = -1;
    }else{
        brightness_value = value;
        Serial.println(value);
        max7219_set_brightness(value);
    }
}
void readNTPtimeZone(){
    File files = SPIFFS.open("/config.json", "r");
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, files);
    files.close();

    String ntpServerIP = doc["timezone"]["ntp"];
    String timeZoneString = doc["timezone"]["zone"];

    ntpServerIP.toCharArray(ntpServerName, (ntpServerIP.length() + 1));

    Serial.println(timeZoneString);
    timeZone = timeZoneString.toInt();
}

int setTemperature(){
    File files = SPIFFS.open("/config.json", "r");
    DynamicJsonDocument doc(3000);
    deserializeJson(doc, files);
    files.close();

    int conftemp = doc["temp"]["conf"];

    return conftemp;
}
bool tempInfahrenheit(){
    File files = SPIFFS.open("/config.json", "r");
    DynamicJsonDocument doc(3000);
    deserializeJson(doc, files);
    files.close();

    bool conftemp = doc["temp"]["fahrenheit"];

    return conftemp;
}



bool weatherTempInfahrenheit(){
    File files = SPIFFS.open("/config.json", "r");
    DynamicJsonDocument doc(3000);
    deserializeJson(doc, files);
    files.close();

    bool conftemp = doc["weather"]["fahrenheit"];

    return conftemp;
}


void setWeather(){
    File files = SPIFFS.open("/config.json", "r");
    DynamicJsonDocument doc(512);
    deserializeJson(doc, files);
    files.close();

    String wetherApiFormFile = doc["weather"]["api"];
    String wetherCityFormFile = doc["weather"]["city"];

    serializeJson(doc, Serial);
    
    watherCity = wetherCityFormFile;
    weatherApi = wetherApiFormFile;

    String serverName1 = "http://api.openweathermap.org/data/2.5/forecast?q=";
    String serverName2 = "&APPID=";

    String serverName3 = "&mode=json&units=metric&cnt=2";

    serverName = serverName1 + watherCity.c_str() + serverName2 + weatherApi.c_str() + serverName3;
    Serial.println(serverName);

}

void getMqtt(){
    
    File files = SPIFFS.open("/config.json", "r");
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, files);
    files.close();

    String mqtt_enablefile = doc["mqtt"]["enable"];
    String mqtt_serverfile = doc["mqtt"]["brokerIP"];
    String mqtt_userfile = doc["mqtt"]["name"];
    String mqtt_passwordfile = doc["mqtt"]["pass"];
    String mqtt_topicfile = doc["mqtt"]["topic"];


    serializeJson(doc, Serial);
    
    mqtt_enable = mqtt_enablefile; 
    mqtt_server = mqtt_serverfile;
    mqtt_user = mqtt_userfile;
    mqtt_password = mqtt_passwordfile;
    mqtt_topic = mqtt_topicfile;

    mqtt_topic_mes = mqtt_topic.c_str() + String("/m");
    mqtt_topic_temp = mqtt_topic.c_str() + String("/temp");
    mqtt_topic_brightness = mqtt_topic.c_str() + String("/b");
    mqtt_topic_alarm = mqtt_topic.c_str() + String("/a");
}

String getFirmwareVersion(){
    File files = SPIFFS.open("/config.json", "r");
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, files);
    files.close();
    
    String version = doc["version"];
    return version;
}

void getNightMode(){
  File files = SPIFFS.open("/config.json", "r");
  DynamicJsonDocument doc(3000);
  deserializeJson(doc, files);
  files.close();

  bool nightMode = doc["nightmode"]["enable"];
  String fromHour = doc["nightmode"]["from"][0];
  String fromMin = doc["nightmode"]["from"][1];
  int toHour = doc["nightmode"]["to"][0];
  int toMin = doc["nightmode"]["to"][1];
  
  nightModeEnable = nightMode;
  nightModeFormHour = fromHour.toInt();
  nightModeFormMin = fromMin.toInt();
  nightModeToHour = toHour;
  nightModeToMin = toMin;
  Serial.println(nightMode);
  Serial.println(fromHour);
  Serial.println(fromMin);
}


void getNetworkConfig(){
  File files = SPIFFS.open("/config.json", "r");
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, files);
  files.close();

  String ssid = doc["wifi"]["ssid"];
  String pass = doc["wifi"]["pass"];
  String enableStaticIp = doc["wifi"]["staticIpEnable"];

    for (size_t i = 0; i < 4; i++)
    {
        String ipAddres = doc["wifi"]["ipAddres"][i];
        wifi_ip[0][i] = ipAddres;
        
        String gateway = doc["wifi"]["gateway"][i];
        wifi_ip[1][i] = gateway;

        String subnet = doc["wifi"]["subnet"][i];
        wifi_ip[2][i] = subnet;

    }

  wifi__ssid = ssid.c_str(); 
  wifi__pass = pass.c_str();
  wifi__enable__ip = enableStaticIp.c_str(); 

}


void createFile () {
    File files = SPIFFS.open("/alarm.json", "r");
    if(!files){
        Serial.println("SPIFFS alarm Create File");
        files.close();
        File filez = SPIFFS.open("/alarm.json", "w");
        if (!filez) {
            Serial.println("file creation failed");
        }
        filez.println("{\"alarmNum\": 1,\"alarm\": []}");
        filez.close();
    }
    File configR = SPIFFS.open("/config.json", "r");
    if(!configR){
        Serial.println("SPIFFS alarm Create File");
        configR.close();
        File configW = SPIFFS.open("/config.json", "w");
        if (!configW) {
            Serial.println("file creation failed");
        }
        configW.println("{\"wifi\":{\"ssid\":\"\",\"pass\":\"\",\"staticIpEnable\":false,\"ipAddres\":[0,0,0,0],\"gateway\":[0,0,0,0],\"subnet\":[0,0,0,0]},\"weather\":{\"api\":\"\",\"city\":\"\"},\"temp\":\"0\",\"timezone\":{\"ntp\":\"\",\"zone\":\"0\"},\"mqtt\":{\"enable\":\"0\",\"name\":\"\",\"pass\":\"\",\"brokerIP\":\"\",\"topic\":\"\"}}");
        configW.close();
    }

}