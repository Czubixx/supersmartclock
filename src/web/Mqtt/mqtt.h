
PubSubClient client(mqttClient);


char temperature[10];
bool sendMqtt = true;
bool mqtt_reconnect = true;

void callback(char * topic, byte * payload, unsigned int length) {
  String topicStr = topic;
  String message;

  for (int i = 0; i < length; i++) {
    message = message + (char) payload[i];
  }

  if (topicStr == mqtt_topic_mes) {
    if(message != ""){
      stringMessage = message;
      scrolingText = true;
    }
  }
  else if (topicStr == mqtt_topic_brightness.c_str()){
      if(message == "auto"){
        setBrightness(0, true);
      }else{
        setBrightness(message.toInt(), false);
      }
  }
  else if (topicStr == mqtt_topic_alarm.c_str()){
    displayAlarm(message, String(hour()), String(minute()), 0);
  }
  else if (topicStr == mqtt_topic_notification.c_str()){
    displayNotification(message, 0);
  }
}
unsigned long mqtt_reconet_delay = 0;
void reconnect() {
  if(!client.connected() &&(unsigned long)(millis() - mqtt_reconet_delay) >= 10000) {
    Serial.println("Attempting MQTT connection...");
    Serial.println(mqtt_user);
    Serial.println(mqtt_password);
    if(client.connect(mqtt_topic.c_str(), mqtt_user.c_str(), mqtt_password.c_str(), mqtt_topic_availability.c_str(), 1, true, "offline")){
      client.subscribe(mqtt_topic_temp.c_str());
      client.subscribe(mqtt_topic_mes.c_str());
      client.subscribe(mqtt_topic_brightness.c_str());
      client.subscribe(mqtt_topic_alarm.c_str());
      client.subscribe(mqtt_topic_notification.c_str());
      client.publish(mqtt_topic_availability.c_str(), "online");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println("try again in 60 seconds");
      ScrollText("Mqtt error", 1);
      mqtt_reconet_delay = millis();
    }
  }
}


void mqqtSetup(){
  getMqtt();
  if(mqtt_enable == "1"){
    client.setServer(mqtt_server.c_str(), 1883);
    client.setCallback(callback);
  }
}

unsigned long mqtt_send_delay = 0;

void mqttLoop(){
  if(mqtt_enable == "1"){
    if (!client.connected()) {
      reconnect();
    }
    client.loop();
    if(sendMqtt == true){
      if(WiFi.status()== WL_CONNECTED){
        sensors.requestTemperatures();
        printTemperature(insideThermometer);
        dtostrf(temp, 3, 1, temperature); 
        client.publish(mqtt_topic_temp.c_str(), temperature);
        Serial.println("Mqtt send Temp");
        sendMqtt = false;
      }
    }else if((minute()%10) == 0 && (unsigned long)(millis() - mqtt_send_delay) >= 60000 ){
      sendMqtt = true;
      mqtt_send_delay = millis();
    }
  }

}