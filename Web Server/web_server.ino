#include <SoftwareSerial.h>

SoftwareSerial ESP8266(2,3);
// RX is pin 2, TX is pin 3.

void setup() {
  //init Hardware Serial
  Serial.begin(9600);
  while(!Serial);
  Serial.print("Arduino Serial OK \n");

  //init Software Serial to ESP Module
  ESP8266.begin(115200);
  while(!ESP8266);
  Serial.print("ESP Serial OK \n");

  //set up AP
  sendData("AT+RST\r\n",2000); // reset module
  sendData("AT+CWMODE=3\r\n",1000); // configure as access point
  sendData("AT+CIFSR\r\n",1000); // get ip address
  sendData("AT+CIPMUX=1\r\n",1000); // configure for multiple connections
  sendData("AT+CIPSERVER=1,8585\r\n",1000); // turn on server on port 80
  Serial.print("ESP Server OK \n");
}

String sendData(String command,const int timeout)
{
    String response = "";
    ESP8266.print(command); // send the character data to the esp8266
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(ESP8266.available())
      {
        char c = ESP8266.read(); // read response
        response+=c;
      }  
    }
    
    Serial.print(response);
    return response;
}

void loop()
{
  if(ESP8266.available()) // check if the esp is sending a message 
  {
    if(ESP8266.find("+IPD,"))
    {
     delay(200);
 
     int connectionId = ESP8266.read()-48; // subtract 48 because the read() function returns the ASCII decimal value
     
     String webpage = "<h1>Hello World !</h1>";
     
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend += webpage.length();
     cipSend += "\r\n";
     
     sendData(cipSend,1000);
     sendData(webpage,1000);
 
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand += connectionId; // append connection id
     closeCommand += "\r\n";
     
     sendData(closeCommand,2000);
    }
  }
}
