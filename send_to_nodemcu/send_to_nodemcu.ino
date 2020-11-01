#include <SoftwareSerial.h>

SoftwareSerial espSerial(9, 10);
int current = 0;
int integral = 1;
float threshold = 2.8;
String str;
int cont = 0;

void setup() {
  Serial.begin(115200);
  espSerial.begin(115200);
  pinMode(6, OUTPUT);
}

void loop() {

    Serial.print("Measured value: ");
    Serial.println(analogRead(0));    
    int current_voltage = analogRead(0) * 494.45 * (5.0 / 1023.0);

  if(current_voltage > 96) {

    str = String(current_voltage);
    Serial.println("Sending value to Node...");    
    
    for (int i = 0; i <= 15; i++) {
        espSerial.println(str);
        Serial.print("Sending measured value: ");
        Serial.println(str);
        delay(1000);
    }
    
  }
}

