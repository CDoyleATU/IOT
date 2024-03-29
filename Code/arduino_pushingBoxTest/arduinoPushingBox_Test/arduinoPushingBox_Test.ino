//-----------------------------------------------
//This sketch is combined from Adafruit DHT sensor and tdicola
//for dht.h library
//Along with some  esp8266 NodeMCU specifics from teos009    
// https://learn.adafruit.com/dht/overview
// https://gist.github.com/teos0009/acad7d1e54b97f4b2a88
//other Authors Arduino and associated Google Script:
//Aditya Riska Putra
//Ahmed Reza Rafsanzani
//Ryan Eko Saputro
//See Also
//http://jarkomdityaz.appspot.com/
//
//ELINS UGM
//
//Modified for Hackster.io project to the ESP8266 from
//a Ethernet Sheild project
//by Stephen Borsay
//Since Arduino can't handle https, we need to use Pushingbox API
//(uses http)to run 
//the Google Script (uses https).


#include "ESP8266WiFi.h"
#include "DHT.h"


const char WEBSITE[] = "api.pushingbox.com"; //pushingbox API server
const String devid = "vA5B9442F60C85A1"; //device ID from Pushingbox 

const char* MY_SSID = "Con's iPhone";
const char* MY_PWD =  "doyler123";


void setup()
{
  Serial.begin(115200);
  dht.begin();
  Serial.print("Connecting to "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  Serial.println("going into wl connect");

  while (WiFi.status() != WL_CONNECTED) //not connected,..waiting to connect
    {
      delay(1000);
      Serial.print(".");
    }
  Serial.println("wl connected");
  Serial.println("");
  Serial.println("Credentials accepted! Connected to wifi\n ");
  Serial.println("");
}


void loop()
{
  
  //Wait between measurements longer then normal to slow donwn
  //google sheet populate, as We dont want to exceed free service quota
  delay(10000); //10 seconds, (sampling rate vs. service call quota)

int counter = 9876;
int celData = 1345;
int fehrData = 2343;
int hicData = 329;
int hifData = 2344;
char description[] = "using_Arduino";
  
  
  //Print to Serial monitor or Terminal of your chocice at 115200 Baud
  Serial.print("Counter: ");
  Serial.print(counter);
  Serial.print(" %\t");
  Serial.print("Temperature in Cel: ");
  Serial.print(celData);
  Serial.print(" *C ");
  Serial.print("Temperature in Fehr: ");
  Serial.print(fehrData);
  Serial.print(" *F\t");
  Serial.print("Heat index in Cel: ");
  Serial.print(hicData);
  Serial.print(" *C ");
  Serial.print("Heat index in Fehr: ");
  Serial.print(hifData);
  Serial.print(" *F\n");
  Serial.print("Description:");
  Serial.print(description);
    
  WiFiClient client;  //Instantiate WiFi object
  
  

    //Start or API service using our WiFi Client through PushingBox
    if (client.connect(WEBSITE, 80))
      { 
         client.print("GET /pushingbox?devid=" + devid
       + "&counter=" + (String) counter
       + "&celData="      + (String) celData
       + "&fehrData="     + (String) fehrData
       + "&hicData="      + (String) hicData
       + "&hifData="      + (String) hifData
       + "&description="      + (String) description
         );

      client.println(" HTTP/1.1"); 
      client.print("Host: ");
      client.println(WEBSITE);
      client.println("User-Agent: ESP8266/1.0");
      client.println("Connection: close");
      client.println();
      }
}
