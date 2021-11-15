
//Variables

int i = 0;
int statusCode;
String esid;
String epass;

String st;
String content;

bool DHCPauto = false;

String getway1;
String getway2;
String getway3;
String getway4;
String ip1;
String ip2;
String ip3;
String ip4;

//Function Declaration
bool testWifi(void);
void launchWeb(void);
 
//--------Establishing Local server at port 80 whenever required
ESP8266WebServer server(80);

//Functions used for saving WiFi credentials and to connect to it which you do not need to change 
bool testWifi(void)
{
  int c = 0;
  Serial.println("Waiting for WiFi to connect");
  while ( c < 20 ) {
    if (WiFi.status() == WL_CONNECTED)
    {
      return true;
    }
    delay(500);
    Serial.print("*");
    c++;
  }
  Serial.println("");
  Serial.println("Connection timed out, opening AP or Hotspot");
  return false;
}
 
void createWebServer()
{
    server.on("/", HTTP_GET, []() {
      server.send(200, "text/html", Starting_page);
    });

    server.on("/setNetworkConfig", HTTP_POST, [](){
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
      ESP.restart();
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/plain", "OK");
      ESP.restart();
      
    });
}
void launchWeb()
{
  ScrollText("Turning HotSopt: SuperSmartClock", 1);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.softAP("SuperSmartClock", "");
  Serial.println("");
  if (WiFi.status() == WL_CONNECTED)
    Serial.println("WiFi connected");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  createWebServer();
  server.begin();
  Serial.println("Server started");
}


String ipToString(IPAddress ip){
  String s="";
  s += "http://";
  for (int i=0; i<4; i++){
    s += i  ? "." + String(ip[i]) : String(ip[i]);
  }
  s += "/";
  return s;
}


void staticIPaddres(){
  if(wifi__enable__ip == "true"){
    IPAddress gateway(wifi_ip[1][0].toInt(), wifi_ip[1][1].toInt(), wifi_ip[1][2].toInt(), wifi_ip[1][3].toInt());
    IPAddress local_IP(wifi_ip[0][0].toInt(), wifi_ip[0][1].toInt(), wifi_ip[0][2].toInt(), wifi_ip[0][3].toInt());
    IPAddress subnet(wifi_ip[2][0].toInt(), wifi_ip[2][1].toInt(), wifi_ip[2][2].toInt(), wifi_ip[2][3].toInt());
    IPAddress primaryDNS(8, 8, 8, 8);
    IPAddress secondaryDNS(8, 8, 4, 4);
    if(!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)){
      ScrollText("Static IP ERROR !!!", 1);
    }
  }
}

void WifiConnectSetup()
{
  Serial.println("Disconnecting previously connected WiFi");
  WiFi.disconnect();
  delay(10);
  Serial.println();
  Serial.println();
  Serial.println("Startup");
  ScrollText("Trying to connect...", 1);
  staticIPaddres();


  WiFi.begin(wifi__ssid.c_str(), wifi__pass.c_str());
  if (testWifi())
  {
    Serial.println("Succesfully Connected!!!");
    ScrollText(ipToString(WiFi.localIP()), 1);
    return;
  }
  else
  {
    Serial.println("COONET");
    launchWeb();
  }
 
  Serial.println();
  Serial.println("Waiting.");
  
  while ((WiFi.status() != WL_CONNECTED))
  {
    server.handleClient();
    delay(100);
  }
 
}