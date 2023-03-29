#include <UnoWiFiDevEd.h>



#include <ESP8266WiFi.h>
/*#include <WiFiClientSecure.h>*/
#include <WiFiClient.h>
#include <Pushsafer.h>


// Initialize Wifi connection to the router
char ssid[] = "Con's iPhone";     // your network SSID (name)
char password[] = "doyler123"; // your network key

//Pushing Box
const char WEBSITE[] = "api.pushingbox.com"; //pushingbox API server
const String devid = "vA5B9442F60C85A1"; //device ID from Pushingbox 

// Pushsafer private or alias key
#define PushsaferKey "aR0r0uGnTKP2p5XE1UzQ"

/*WiFiClientSecure client;*/
WiFiClient client;
Pushsafer pushsafer(PushsaferKey, client);

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pushsafer.debug = true;
//End of pushsafer code in setup//


 // Inputs and Outputs
 const byte IR1 = 2;
 const byte IR2 = 3;
 const byte ButtonPress = 4;
 const byte ExtLED = 8;
  // put your setup code here, to run once:
    pinMode(IR1,INPUT);
    pinMode(IR2,INPUT);
    pinMode(ButtonPress,INPUT);
    pinMode(ExtLED,OUTPUT);


 // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.clear();
}

void loop() {
int counter1 = 0;
int counter2 = 0;
float total = 0;


int on = 1;
int off = 0;
int onOffState = 0;

if (buttonPress == Low)
{
  if onOffState = 0;
  {onOffState = 1;}
  if onOffState = 1;
  {onOffState = 0;}
}
while (onOffState = 1)
{
delay(100);
        if(digitalRead(IR1)==LOW)  {
            Serial.println("€1 detected.");
            counter1 ++;
        }
        if(digitalRead(IR2)==LOW)  {
            Serial.println("€2 detected.");
            counter2 ++;
        }
            
 lcd.setCursor(0,0);

             // Print a message to the LCD.
            lcd.print("Total:");

            lcd.setCursor(2,1);
            total = (counter1 * 1) + (counter2 * 2);
            lcd.print(total);
            
}
while {onOffState = 0}
{
  //Send code to API for pushingBox and pushSafer

  //Pushing Box
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

  //Push Safer
  // Take a look at the Pushsafer.com API at
  // https://www.pushsafer.com/en/pushapi
  
  struct PushSaferInput input;
  input.message = "This is a test message";
  input.title = "Hello!";
  input.sound = "8";
  input.vibration = "1";
  input.icon = "1";
  input.iconcolor = "#FFCCCC";
  input.priority = "1";
  input.device = "a";
  input.url = "https://www.pushsafer.com";
  input.urlTitle = "Open Pushsafer.com";
  input.picture = "";
  input.picture2 = "";
  input.picture3 = "";
  input.time2live = "";
  input.retry = "";
  input.expire = "";
  input.confirm = "";
  input.answer = "";
  input.answeroptions = "";
  input.answerforce = "";

  Serial.println(pushsafer.sendEvent(input));
  Serial.println("Sent");
  
  // client.stop();
}
}
