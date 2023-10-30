#include "Server.h"
#include "SPIFFS.h"

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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void DownloadFile(String filename){
  if (1) { 
    File download = SPIFFS.open("/"+filename,  "r");
    if (download) {
      server.sendHeader("Content-Type", "text/text");
      server.sendHeader("Content-Disposition", "attachment; filename="+filename);
      server.sendHeader("Connection", "close");
      server.streamFile(download, "application/octet-stream");
      download.close();
    } else Serial.println("Fail"); 
  } else Serial.println("Fail");
}

void File_Download(){ // This gets called twice, the first pass selects the input, the second pass then processes the command line arguments
  if (server.args() > 0 ) { // Arguments were received
    if (server.hasArg("download")) DownloadFile(server.arg(0));
  }
  else Serial.println("Fail");
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
  htmlCode += "<form method=\"post\" enctype=\"multipart/form-data\">\n";
  htmlCode += "<label for=\"file\">Upload</label>\n";
  htmlCode += "<input id=\"file\" name=\"file\" type=\"file\"/>\n";
  htmlCode += "<a href=\"/download\"> <button> Send</button> </a>\n";
  htmlCode += "</form>\n";
  htmlCode += "</body>\n";
  htmlCode += "</html>\n";

  return htmlCode;
} 

void handle_Main(void)
{
  server.send(200, "text/html", getHTML());
}

void Server_Begin(void)
{
  Serial.begin(BAUD_RATE);

  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);

  server.on("/",handle_Main);
  server.on("/download",File_Download);
  server.begin();
}

int Server_NewUpdate(void)
{
  server.handleClient();
  return 0;
}

String Server_Download(void)
{
  String output = "";

  return output;
}