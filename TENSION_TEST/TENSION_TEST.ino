
int current = 0;
int integral = 1;
float threshold = 2.8;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  Serial.println("TESTE");
}

void loop() {
  float current_voltage = analogRead(0) * (5.0 / 1023.0);
  float integral_voltage = analogRead(1) * (5.0 / 1023.0);
  Serial.print("ANALOG0: ");
  Serial.print(analogRead(0));
  Serial.print(" current_voltage: ");
  Serial.print(current_voltage);
  
  Serial.print(" ANALOG1: ");
  Serial.print(analogRead(1));
  Serial.print(" integral ");
  Serial.println(analogRead(1));
  
  if(current_voltage > threshold) {
    // reset integrator
    digitalWrite(6, HIGH); 
    delay(100);
    digitalWrite(6, LOW);
    //delay 5 seconds like the ONE TOUCH ULTRA 2
    delay(5000);
    current_voltage = analogRead(0) * (5.0 / 1023.0);
    integral_voltage = analogRead(1) * (5.0 / 1023.0);
    Serial.print("Current to voltage: ");
    Serial.println(current_voltage,5);
    Serial.print("Integral to voltage: ");
    Serial.println(integral_voltage,5);
    while(1);
  }
}
