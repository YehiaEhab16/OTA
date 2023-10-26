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

  server.on("/",handle_Main);
  server.begin();
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

String getHTML(void)
{
  String htmlCode = "<!DOCTYPE html> <html>\n";
  htmlCode += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  htmlCode += "<title>OTA Project</title>\n";

  htmlCode += "</head>\n";
  htmlCode += "<body>\n";
  htmlCode += "<h1>ESP32 Web Server</h1>\n";
  htmlCode += "<h3>Select file to upload</h3>\n";
  htmlCode += "<p id="test"> Helloooooo</p>\n"
  htmlCode += "<button>onclick="doSomething()" Upload</button>\n"
  htmlCode += "<script>function doSomething(){document.getElementById("test").innerHTML = "Nooooooo";}<\script>";
  htmlCode += "</body>\n";
  htmlCode += "</html>\n";

  return htmlCode;
} 

void handle_Main(void)
{
  server.send(200, "text/html", getHTML());
}