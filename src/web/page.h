
void renderPageSetup(){

    server.on("/", HTTP_GET,[]() {
       // server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "text/html", home_page_HTML);
    });

    server.on("/style", HTTP_GET,[]() {
   // String s = home_page_CSS;
   // String content(home_page_CSS);
    server.send(200, "text/css", home_page_CSS);
        
    });
    server.on("/app", HTTP_GET,[]() {
   // String s = home_page_JS;
    server.send(200, "text/js", home_page_JS);
        
    });


    // -------------------------------- Set ----------------------------------------

    server.on("/set/nightmode", HTTP_POST, [] () {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(512);
        deserializeJson(doc, postBody);
        Serial.println(postBody);

        bool enable = doc["enable"];
        int fromHour = doc["fromHour"];
        int fromMin = doc["fromMin"];
        int toHour = doc["toHour"];
        int toMin = doc["toMin"];


        File fileRead = SPIFFS.open("/config.json", "r");
        DynamicJsonDocument configFile(3000);
        deserializeJson(configFile, fileRead);
        fileRead.close();
        

        JsonObject nightmode = configFile.createNestedObject("nightmode");
        nightmode["enable"] = enable;
        nightmode["from"][0] = fromHour;
        nightmode["from"][1] = fromMin;
        nightmode["to"][0] = toHour;
        nightmode["to"][1] = toMin;

        File fileWrite = SPIFFS.open("/config.json", "w");
        serializeJsonPretty(configFile, fileWrite);
        serializeJsonPretty(configFile, Serial);
        fileWrite.close();

        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "text/plain", "OK");
        getNightMode();
    });


    server.on("/set/network", HTTP_POST, [] () {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(2000);
        deserializeJson(doc, postBody);
        Serial.println(postBody);

        String name = doc["name"];
        String pass = doc["pass"];
        bool staticIpEnable = doc["staticIpEnable"];
        String address[4];
        String gateway[4];
        String mask[4];

        if(!staticIpEnable){
            Serial.println("STATIC IP ENABLE");
        }else{
            for (size_t i = 0; i < 4; i++)
            {
                String addressString = doc["address"][i];
                address[i] = addressString;
                String gatewayString = doc["gateway"][i];
                Serial.println(gatewayString);
                gateway[i] = gatewayString;
                String maaskString = doc["mask"][i];
                mask[i] = maaskString;
            }
        }

        Serial.println(address[3]);
        Serial.println(gateway[0]);
        Serial.println(gateway[1]);
        Serial.println(gateway[2]);
        Serial.println(gateway[3]);
        Serial.println(staticIpEnable);
        Serial.println(pass);

        File fileRead = SPIFFS.open("/config.json", "r");
        DynamicJsonDocument configFile(3000);
        deserializeJson(configFile, fileRead);
        fileRead.close();
        
        JsonObject wifi = configFile.createNestedObject("wifi");

        wifi["ssid"] = name;
        wifi["pass"] = pass;
        wifi["staticIpEnable"] = staticIpEnable;

        if(staticIpEnable){
            JsonArray addresArray = wifi.createNestedArray("ipAddres");
            addresArray.add(address[0]);
            addresArray.add(address[1]);
            addresArray.add(address[2]);
            addresArray.add(address[3]);

            JsonArray geteway = wifi.createNestedArray("gateway");
            geteway.add(gateway[0]);
            geteway.add(gateway[1]);
            geteway.add(gateway[2]);
            geteway.add(gateway[3]);

            JsonArray subnet = wifi.createNestedArray("subnet");
            subnet.add(mask[0]);
            subnet.add(mask[1]);
            subnet.add(mask[2]);
            subnet.add(mask[3]);
        }

        File fileWrite = SPIFFS.open("/config.json", "w");
        serializeJsonPretty(configFile, fileWrite);
        serializeJsonPretty(configFile, Serial);
        fileWrite.close();

        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "text/plain", "OK");
        ESP.restart();
        
    });
    
    server.on("/set/brightness", HTTP_POST, []() {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(64);
        deserializeJson(doc, postBody);

        int value = doc["value"];

        setBrightness(value); 

        server.sendHeader("Access-Control-Allow-Origin", "*");
        String sendBody = "{\"value\":\"" + String(value) + "\"}";
        server.send(200, "application/json", sendBody);
    });

    server.on("/set/timezone", HTTP_POST, []() {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(128);
        deserializeJson(doc, postBody);

        String server_ip = doc["server"];
        String UTC = doc["UTC"];
        
        File fileRead = SPIFFS.open("/config.json", "r");
        DynamicJsonDocument configFile(3000);
        deserializeJson(configFile, fileRead);
        fileRead.close();
        
        JsonObject timeZone = configFile.createNestedObject("timezone");

        timeZone["ntp"] = server_ip;
        timeZone["zone"] = UTC;

        File fileWrite = SPIFFS.open("/config.json", "w");
        serializeJsonPretty(configFile, fileWrite);
        serializeJsonPretty(configFile, Serial);
        fileWrite.close();

        ESP.restart();
        
    });

    server.on("/set/temperature", HTTP_POST, []() {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(64);
        deserializeJson(doc, postBody);

        int value = doc["value"];
        bool fahrenheit = doc["fahrenheit"];
        
        File fileRead = SPIFFS.open("/config.json", "r");
        DynamicJsonDocument configFile(3000);
        deserializeJson(configFile, fileRead);
        fileRead.close();

        configFile["temp"]["conf"] = value;
        configFile["temp"]["fahrenheit"] = fahrenheit;

        File fileWrite = SPIFFS.open("/config.json", "w");
        serializeJsonPretty(configFile, fileWrite);
        serializeJsonPretty(configFile, Serial);
        fileWrite.close();

        setTemperature();
    });

    server.on("/set/weather", HTTP_POST, []() {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(128);
        deserializeJson(doc, postBody);

        String api = doc["api"];
        String city = doc["city"];
        bool fahrenheit = doc["fahrenheit"];

        File fileRead = SPIFFS.open("/config.json", "r");
        DynamicJsonDocument configFile(3000);
        deserializeJson(configFile, fileRead);
        fileRead.close();
        JsonObject weatherConfig = configFile.createNestedObject("weather");

        weatherConfig["api"] = api;
        weatherConfig["city"] = city;
        weatherConfig["fahrenheit"] = fahrenheit;

        File fileWrite = SPIFFS.open("/config.json", "w");
        serializeJsonPretty(configFile, fileWrite);
        serializeJsonPretty(configFile, Serial);
        fileWrite.close();

        ESP.restart();
    });


    server.on("/set/mqtt", HTTP_POST, []() {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(256);
        deserializeJson(doc, postBody);

        String mqttIP = doc["mqttIP"];
        String mqttUser = doc["mqqttUser"];
        String mqttPass = doc["mqqttPass"];
        String mqttTopic = doc["mqttTopic"];
        String mqqttEnable = doc["mqqttEnable"];
        Serial.println(mqqttEnable);

        File fileRead = SPIFFS.open("/config.json", "r");
        DynamicJsonDocument configFile(2000);
        deserializeJson(configFile, fileRead);
        fileRead.close();
        JsonObject mqqttConfig = configFile.createNestedObject("mqtt");

        mqqttConfig["enable"] = mqqttEnable;
        mqqttConfig["name"] = mqttUser;
        mqqttConfig["pass"] = mqttPass;
        mqqttConfig["brokerIP"] = mqttIP;
        mqqttConfig["topic"] = mqttTopic;

        File fileWrite = SPIFFS.open("/config.json", "w");
        serializeJsonPretty(configFile, fileWrite);
        serializeJsonPretty(configFile, Serial);
        fileWrite.close();


        ESP.restart();
    });


    // -------------------------------- Alarm ----------------------------------------
    
    server.on("/alarm/add", HTTP_POST, [] () {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(258);
        deserializeJson(doc, postBody);
        Serial.println(postBody);

        String name = doc["name"];
        String status = doc["state"];
        String hour = doc["hour"];
        String min = doc["min"];
        String day = doc["day"];
        writeAlarmToFile(name, status, hour, min, day);
        readAlarmFormFile();

    });

    server.on("/alarm/remove", HTTP_POST, [] () {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(64);
        deserializeJson(doc, postBody);
        Serial.println(postBody);

        int index = doc["index"];
        Serial.println("Wywołanie");
        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "application/json", removeAlarm(index));
    });

    server.on("/alarm/update", HTTP_POST, [] () {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(64);
        deserializeJson(doc, postBody);
        Serial.println(postBody);

        int index = doc["index"];
        Serial.println("wywołanie");
        
        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "application/json", changeAlarmStatus(index));
    });

    server.on("/alarm/list", []() {
        DynamicJsonDocument doc(2000);

        doc["alarm"] = readAlarmFormFileToString();

        String JSON;
        serializeJson(doc, JSON);
        Serial.println(JSON);
        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "application/json", JSON);
    });


    // -------------------------------- Display ----------------------------------------
    
    server.on("/display/text", HTTP_POST, []() {
        String postBody = server.arg("plain");
        DynamicJsonDocument doc(64);
        deserializeJson(doc, postBody);

        String text = doc["text"];
        int repeat = doc["repeat"];
        Serial.println(text);
        Serial.println(repeat);
        scrolingText = true;
        stringMessage = text;
        speed = 50;
    });

    // server.on("/display/sign", HTTP_POST, []() {
    //     String postBody = server.arg("plain");
    //     DynamicJsonDocument doc(700);
    //     deserializeJson(doc, postBody);

    //     String zero = doc["0"];
    //     String jeden = doc["1"];
    //     String dwa = doc["2"];
    //     String trzy = doc["3"];

    //     for (size_t i = 0; i < 9; i++)
    //     {
    //         int a = doc["0"][i];
    //         sign0[0][i] = a;

    //         int b = doc["1"][i];
    //         sign0[1][i] = b;

    //         int c = doc["2"][i];
    //         sign0[2][i] = c;

    //         int d = doc["3"][i];
    //         sign0[3][i] = d;
    //     }

    //     clear_Display();
    //     refresh_display();
    //     fdgdfg("4", 8, 0);
    //     fdgdfg("3", 16, 0);
    //     fdgdfg("2", 24, 0);
    //     fdgdfg("1", 32, 0);
    //     refresh_display();
    //     delay(2000);

    // });
    

    // -------------------------------- other api ----------------------------------------

    server.on("/update", HTTP_POST, [] () {
        Serial.println("OTRYMANO");
        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
        ESP.restart();
    },[] () {updateOTA();});

    
    
    server.on("/data", []() {
        DynamicJsonDocument doc(1024);

        doc["brightness"] = brightness_value;
        doc["ntpIP"]   = ntpServerName;

        doc["nightMode"]["enable"] = nightModeEnable;
        doc["nightMode"]["from"][0] = nightModeFormHour;
        doc["nightMode"]["from"][1] = nightModeFormMin;

        doc["nightMode"]["to"][0] = nightModeToHour;
        doc["nightMode"]["to"][1] = nightModeToMin;

        doc["timeZone"] = timeZone;
        doc["temperature"]["value"] = set_temperature;
        doc["temperature"]["fahrenheit"] = tempInfahrenheit();
        doc["weather"]["city"] = watherCity;
        doc["weather"]["fahrenheit"] = weatherTempInfahrenheit();
        doc["mqtt"][0] = mqtt_server;
        doc["mqtt"][1] = mqtt_user;
        doc["mqtt"][2] = mqtt_topic;
        doc["mqtt"][3] = mqtt_enable;
        doc["firmware"] = getFirmwareVersion();
        JsonObject wifi = doc["wifi"].createNestedObject();
        wifi["ssid"] = wifi__ssid;
        wifi["enableStaticIp"] = wifi__enable__ip;
        wifi["enableStaticIp"] = wifi__enable__ip;
        
        if(wifi__enable__ip == "true"){
            for (size_t i = 0; i < 4; i++)
            {
                wifi["staticIP"][i] = wifi_ip[0][i];
                wifi["gateway"][i] = wifi_ip[1][i];
                wifi["subnet"][i] = wifi_ip[2][i];
            }
        }

        String JSON;
        serializeJson(doc, JSON);
        Serial.println(JSON);
        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "application/json", JSON);

    });
   

    server.begin();
}

void renderPageLoop(){
   server.handleClient();
}