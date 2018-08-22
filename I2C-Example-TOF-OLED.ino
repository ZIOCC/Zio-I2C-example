
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SparkFun_RFD77402_Arduino_Library.h> //Use Library Manager or download here: https://github.com/sparkfun/SparkFun_RFD77402_Arduino_Library

RFD77402 myDistance; //Hook object to the library
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
unsigned int distance = 0;

void setup() {
   Serial.begin(9600);
   while (!Serial);
   Serial.println("Distance display example");
 
  if (myDistance.begin() == false)
  {
    Serial.println("Sensor failed to initialize. Check wiring.");
    while (1); //Freeze!
  }
  Serial.println("Sensor online!");
}
void loop() 
{ 
  delay(10);
  myDistance.takeMeasurement(); //Tell sensor to take measurement
  distance = myDistance.getDistance();
  //return distance;
   if (myDistance.begin() == true)
  {
    printTitle();
    printDistance();
    printMm();
  }
  display.display();
}

void printTitle() 
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.println("Distance: ");
}

void printDistance()
{
  //myDistance.takeMeasurement();
  //unsigned int distance = myDistance.getDistance();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,15);
  display.println(distance);
}

void printMm()
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(70,15);
  display.println("mm");
}


