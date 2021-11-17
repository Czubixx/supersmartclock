WiFiUDP Udp;


unsigned int localPort = 8888; 


void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);

time_t prevDisplay = 0;


void printDigits(int digits)
{
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

/*-------- NTP code ----------*/
const int NTP_PACKET_SIZE = 48; 
byte packetBuffer[NTP_PACKET_SIZE];

time_t getNtpTime()
{

    IPAddress ntpServerIP;

    Serial.println("TIME GET NTP");

    while (Udp.parsePacket() > 0) ;
    Serial.println("Transmit NTP Request");
    WiFi.hostByName(ntpServerName, ntpServerIP);
    Serial.print(ntpServerName);
    Serial.print(": ");
    Serial.println(ntpServerIP);
    sendNTPpacket(ntpServerIP);
    uint32_t beginWait = millis();
    while (millis() - beginWait < 1500) {
      int size = Udp.parsePacket();
      if (size >= NTP_PACKET_SIZE) {
        Udp.read(packetBuffer, NTP_PACKET_SIZE);
        unsigned long secsSince1900;

        secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
        secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
        secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
        secsSince1900 |= (unsigned long)packetBuffer[43];

        return secsSince1900 - 2208988800UL + (timeZone) * SECS_PER_HOUR;
      }
    }

  return 0;
}

void sendNTPpacket(IPAddress &address)
{  
  Serial.println("SEND PACKET");
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  packetBuffer[0] = 0b11100011; 
  packetBuffer[1] = 0;
  packetBuffer[2] = 6;    
  packetBuffer[3] = 0xEC;  
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  Udp.beginPacket(address, 123);
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
  Serial.println(NTP_PACKET_SIZE);
}

void getTimeSetup()
{
  Udp.begin(localPort);
  readNTPtimeZone();
  setSyncProvider(getNtpTime);

  if(getNtpTime() == 0){
    String sjdfjmvb = "time.google.com ";
    sjdfjmvb.toCharArray(ntpServerName, sjdfjmvb.length());
    setSyncProvider(getNtpTime);
    ScrollText("NTP server ERORR !!!", 1);
  }
  setSyncInterval(300);
}