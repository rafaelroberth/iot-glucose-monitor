// open source glucose meter code, version 1

int strip_detect = 2;
int current = 0;
// measurement starts if transimpedance amp output voltage > threshold
float threshold = 2.8; 

#include <Wire.h>
#include "RTClib.h"
RTC_Millis RTC;

void setup() {
  Serial.begin(9600);
  // set the RTC to the date & time this sketch was compiled
  RTC.begin(DateTime(__DATE__, __TIME__));
  pinMode(strip_detect, INPUT);
}

void loop() {
  while(1) {
    if(digitalRead(strip_detect) == 1) break;
  }
  Serial.println("APPLY BLOOD");
  float current_voltage;
  float adjustment = 0.065;
  while(1) {
    current_voltage = (analogRead(0) * adjustment) * (5.0 / 1023.0);
    Serial.println(current_voltage);
    if(current_voltage > threshold) break;
  }
  // count down timer
  for(int i = 5; i > 0; i--) {
    delay(1000);
    Serial.print(i);
    if(i > 1) Serial.print(", ");
    else Serial.println("");
  }
  // compute concentration
  current_voltage = (analogRead(0) * adjustment)  * (5.0 / 1023.0);
  float concentration = 495.6 * current_voltage - 1275.5;
  Serial.print(concentration);
  Serial.println(" mg/dL");
  display_time();
  while(1) {
    if(digitalRead(strip_detect) == 0) break;
  }
  delay(1000); //debounce
}

void display_time() {
  DateTime now = RTC.now();
  Serial.print(now.year(), DEC);
  Serial.print('-');
  Serial.print(now.month(), DEC);
  Serial.print('-');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}
