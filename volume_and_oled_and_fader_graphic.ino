/*  این کد میاد و ولوم را بصورت فیدر نمایش میدهد
*/

#include <Wire.h>                     // requried to run I2C SH1106
#include <SPI.h>                      // requried to run I2C SH1106
#include <Adafruit_GFX.h>             // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SH1106.h>          // https://github.com/wonho-maker/Adafruit_SH1106

#define OLED_RESET 4                  // reset required for SH1106

Adafruit_SH1106 display(OLED_RESET);  // reset required for SH1106

int analogInput = A0;                 // analog input for outside audio source
int hMeter = 65;                      // horizontal center for needle animation
int vMeter = 85;                      // vertical center for needle animation (outside of dislay limits)
int rMeter = 80;
long randNumber;
const int analogInPin = A2;  // Analog input pin that the potentiometer is attached to

const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;


void setup() {

  pinMode(analogInput, INPUT);                             // analog input for outside audio source
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);                // needed for SH1106 display
  display.clearDisplay();
  Serial.begin(9600);

}

void loop() {


  // shifts needle to zero position



  // read the analog in value:

  sensorValue = analogRead(analogInPin);

  // map it to the range of the analog out:

  outputValue = map(sensorValue, 0, 1023, 2, 35);
  randNumber = random(0, outputValue);
  Serial.println(randNumber);

  // change the analog out value:

  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:



  Serial.print("\t output = ");

  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital

  // converter to settle after the last reading:

  delay(200);

  display.clearDisplay();                                  // refresh display for next step
  display.drawLine(10, 10, 10, 40, WHITE);
  

  //splay.drawLine(0,8,15,8,WHITE);
  display.fillRect(6, outputValue, 10, 5, WHITE);
  //display.fillRect(5, outputValue, 8, 10, WHITE);

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(4, 45);
  display.println("Wow");
  display.drawRect(0, 0, 127, 64, WHITE);
 // display.drawRect(2, 2, 125, 62, WHITE);
  //display.drawLine(30, -5, 30, 40, WHITE);


  delay(20);

  // draws needle
  display.display();



}
