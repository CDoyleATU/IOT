#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

 // Inputs and Outputs
 const byte IR1 = 6;
 const byte IR2 = 3;
 const byte ButtonPress = 4;
 const byte ExtLED = 8;


#define IR1 6
#define IR2 3
#define ButtonPress 4
#define ExtLED 8


void setup()  {
    Serial.begin(9600);

 
  // put your setup code here, to run once:
    pinMode(IR1,INPUT);
    pinMode(IR2,INPUT);
    pinMode(ButtonPress,INPUT);
    pinMode(ExtLED,OUTPUT);


 // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.clear();
}
// void loop()  {
//     // Turn off the blinking cursor:
//     // lcd.noBlink();
//     // // delay(3000);
//     // // Turn on the blinking cursor:
//     // lcd.blink();
//     //delay(3000);

//  int counter = 0;
//     while(1)  {
//         delay(100);
//         if(digitalRead(2)==LOW)  {
//             Serial.println("Something detected.");

//              // Print a message to the LCD.


//             lcd.setCursor(0,0);

//             lcd.print("Total:");

//             lcd.setCursor(2,1);

//             lcd.print(counter);


//             counter ++;
            

            
//         }
//         else  {
//             Serial.println("Nobody.");
//             digitalWrite(2, LOW);

//         }
//         Serial.println(counter);
//     }
// }

void loop() 
{
int counter1 = 0;
int counter2 = 0;
int total = 0;


// int on = 1;
// int off = 0;
// int onOffState = 0;

// if (digitalRead(buttonPress) == Low)
// {
//   if onOffState = 0;
//   {onOffState = 1;}
//   if onOffState = 1;
//   {onOffState = 0;}
// }
// while (onOffState = 1)
while(1)
{
delay(100);
if(digitalRead(IR1)==LOW)  {
    Serial.println("€1 detected.");
    counter1 ++;

 lcd.setCursor(0,0);
          // Print a message to the LCD.
        lcd.print("Total:");

        lcd.setCursor(2,1);
        total += (counter1 * 1) + (counter2 * 2);
        lcd.print(total);
    }

if(digitalRead(IR2)==LOW)  {
    Serial.println("€2 detected.");
    counter2 ++;

     lcd.setCursor(0,0);
          // Print a message to the LCD.
        lcd.print("Total:");

        lcd.setCursor(2,1);
        total += (counter1 * 1) + (counter2 * 2);
        lcd.print(total);
    }
        
       
        
}
}
