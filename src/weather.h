
unsigned long getWeatherDelay_Run = 0;
bool fahrenheit = true;

void getWeather(){
    if((unsigned long)(millis() - getWeatherDelay_Run) >= 30000 && minute() == 45){
        getWeatherDelay = true;
        getWeatherDelay_Run = millis();
    }


    if(getWeatherDelay && displayTemp){
        HTTPClient http;

        String serverPath = serverName;

        http.begin(httpClient, serverPath.c_str());
    
        int httpResponseCode = http.GET();
        
        if (httpResponseCode>0) {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            String payload = http.getString();
            StaticJsonDocument<200> filter;
            filter["list"][0]["main"]["temp"] = true;
            DynamicJsonDocument weatherJSON(512);
            deserializeJson(weatherJSON, payload, DeserializationOption::Filter(filter));

            float cod = weatherJSON["list"][0]["main"]["temp"];

            if(weatherTempFahrenheit){
                cod = (cod*1.8)+32;
                dtostrf(cod, 4, 1, weatherTemp);
            }else{
                dtostrf(cod, 4, 1, weatherTemp);
            }
            getWeatherDelay = false;
            
        }
        else {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
            getWeatherDelay = true;
        }
        http.end();
    } 
      // Free resources
}

