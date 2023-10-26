#include "Server.h"

#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <WebServer.h>

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

void Server_Begin(void)
{
  Serial.begin(BAUD_RATE);

  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);
}

int Server_NewUpdate(void)
{
  return 1;
}

String Server_Download(void)
{
  String output = "";

  return output;
}
