/* NAME: VIJISARANI CHINNADURAI
   PROJECT TITLE: ARDUINO TO INTERFACE AN LM35 TEMPERATURE SENSOR AND CONTROL THE ONBOARD LED BASED ON TEMPERATURE READINGS.
   DATE: 24-11-2023
*/

#include <Arduino.h>              //include header file

const int temperature_Pin = A0;   //defining pin for LM35 temp.sensor
const int led_Pin = LED_BUILTIN;  //predefined constant that is defining the pin number of the onboard LED

const int lower_celsius = 30;     //initialise with 30
const int higher_celsius = 30;

const int time_low_blink = 250;   //time interval by which LED will blink based on the temperature readings
const int time_high_blink = 500;

void setup() 
{
    pinMode(led_Pin, OUTPUT);     //set LED pin as output
}

const int blink;
int i=0;
void loop() 
{
    temp = analogRead(temperature_pin);   //read the temperature from the temperature sensor by function called as analogRead
    float temperature = (temp / 1024.0) * 5000;  //to find the voltage in LM35 temp.sensor, where max voltage reference is 5 and 1024 represents maximum value the analog pin can read

  if (temperature <= lower_celsius)  //check that temperature is less than 30, if it is then blink LED in the interval of 250 millisecond
  {
    if (i++ < 50000)           //delay
    blink = time_low_blink;
  } 
  else if (temperature > higher_celsius)  //if temperature is greater than 30 then blink LED at the time interval of 500 milliseconds
  {
    if (i++ < 50000)  
    blink = time_high_blink;
  }
}
