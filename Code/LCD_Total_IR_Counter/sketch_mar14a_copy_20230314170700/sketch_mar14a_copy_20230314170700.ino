#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;


void setup()  {
    Serial.begin(9600);
    pinMode(2,INPUT);
    // pinMode(2,OUTPUT);

 // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    // Print a message to the LCD.
    // lcd.print("hello, i'm gonna count your coins!");
    lcd.clear();

  
}
void loop()  {
    // Turn off the blinking cursor:
    // lcd.noBlink();
    // // delay(3000);
    // // Turn on the blinking cursor:
    // lcd.blink();
    //delay(3000);

 int counter = 0;
    while(1)  {
        delay(100);
        if(digitalRead(2)==LOW)  {
            Serial.println("Something detected.");

             // Print a message to the LCD.


            lcd.setCursor(0,0);

            lcd.print("Total:");

            lcd.setCursor(2,1);

            lcd.print(counter);


            counter ++;
            

            
        }
        else  {
            Serial.println("Nobody.");
            digitalWrite(2, LOW);

        }
        Serial.println(counter);
    }
}
