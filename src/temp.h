
#define ONE_WIRE_BUS D3


OneWire oneWire(ONE_WIRE_BUS);


DallasTemperature sensors(&oneWire);


DeviceAddress insideThermometer;
float temp;



void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
void tempSetup(void)
{

  Serial.println("Dallas Temperature IC Control Library Demo");


  Serial.print("Locating devices...");
  sensors.begin();
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");


  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  

  if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address for Device 0"); 
  
  Serial.print("Device 0 Address: ");
  printAddress(insideThermometer);
  Serial.println();

  sensors.setResolution(insideThermometer, 10);
 
  Serial.print("Device 0 Resolution: ");
  Serial.print(sensors.getResolution(insideThermometer), DEC); 
  Serial.println();
  setTemperature();
}

unsigned long temp_delay = 0;
void printTemperature(DeviceAddress deviceAddress)
{

  if((unsigned long)(millis() - temp_delay) >= 5000){
    sensors.requestTemperatures();

    temp = sensors.getTempC(deviceAddress);
    
    if(tempInfahrenheit())
      temp = (temp*1.8)+32;

    if(temp == DEVICE_DISCONNECTED_C) 
    {
      Serial.println("Error: Could not read temperature data");
      return;
    }
    temp = temp + (setTemperature());
    Serial.print("Temp: ");
    Serial.print(temp);
    dtostrf(temp, 3, 1, result); // Leave room for too large numbers!
    Serial.print(result);

    temp_delay = millis();
  }

}
bool send_temp = true;
void tempLoop(void)
{ 
  if(minute() == 30 && send_temp == true){
    send_temp = false;
  }else if(minute() != 30 && send_temp == false){
    send_temp = true;
  }

}


