#ifndef SERVER_H_
#define SERVER_H_

#include <Arduino.h>

//Define the WiFi credentials

#define WIFI_SSID                       "OTA_WIFI"
#define WIFI_PASSWORD                   "123456789"

#define UPDATE_NOTIFICATION             'u'
#define START_SEND                      's'

#define BAUD_RATE                       115200


//Function to establish server
void Server_Begin(void);

//Function to check for new update
int Server_NewUpdate(void);

//Function to download file from server
String Server_Download(void);


#endif
