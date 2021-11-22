
bool getWeatherDelay = true;
unsigned long getWeatherDelay_Run = 0;
bool fahrenheit = true;

void getWeather(){
    if((unsigned long)(millis() - getWeatherDelay_Run) >= 60000 && minute() == 40){
        getWeatherDelay = true;
        getWeatherDelay_Run = millis();
    }

    if(getWeatherDelay == true){
        HTTPClient http;

        String serverPath = serverName;

        Serial.println(serverPath);

        http.begin(espClient, serverPath.c_str());
        

        int httpResponseCode = http.GET();
        
        if (httpResponseCode>0) {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            String payload = http.getString();
            DynamicJsonDocument weatherJSON(512);
            deserializeJson(weatherJSON, payload);
            Serial.println(payload);
            float cod = weatherJSON["list"][0]["main"]["temp"];
            weatherTempInfahrenheit();
            if(weatherTempFahrenheit){
                cod = (cod*1.8)+32;
                dtostrf(cod, 4, 1, weatherTemp);
                Serial.println(weatherTemp[0]);
                Serial.println(weatherTemp[1]);
            }else{
                dtostrf(cod, 4, 1, weatherTemp);
                Serial.println(weatherTemp[0]);
                Serial.println(weatherTemp[1]);
            }
            getWeatherDelay = false;
            
        }
        else {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
            getWeatherDelay = true;
        }

    } 
      // Free resources
}

