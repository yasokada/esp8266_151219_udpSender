#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

#include "wifiConfig.h"
/*
 * Define your SSID and WiFi password at [wifiConfig.h] using [TemplateWifiConfig.h]
 * 
 */

/*
 * v0.1 2015 Dec. 19
 *   - add loop()
 *   - add setup()
 *   - add Serial_setup()
 *   - add WiFi_setup()
 *   - add wifiConfig.h
 */

static WiFiUDP wifiUdp; 
static const char *kRemoteIpadr = "192.168.10.4";
static const int kRmoteUdpPort = 9000;

static void WiFi_setup()
{
  static const int kLocalPort = 7000;

  WiFi.begin(kWifiSsid, kWifiPass);
  while( WiFi.status() != WL_CONNECTED) {
    delay(500);  
  }  
  wifiUdp.begin(kLocalPort);
}

static void Serial_setup()
{
  Serial.begin(115200);
  Serial.println(""); // to separate line  
}

void setup() {
  Serial_setup();
  WiFi_setup();
}

void loop() 
{
  wifiUdp.beginPacket(kRemoteIpadr, kRmoteUdpPort);
  wifiUdp.write("from ESP8266\r\n");
  wifiUdp.endPacket();  

  delay(3000);
}
