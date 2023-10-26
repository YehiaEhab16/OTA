#include "Server.h"

String file = "";

void setup(){

  //Establish server
  Server_Begin();
}


void loop(){

  if (Server_NewUpdate())
  {
    file = Server_Download();  

    Serial.write(UPDATE_NOTIFICATION);

    while(Serial.read() != START_SEND);     
         
    Serial.print(file); 
  }
  
}
