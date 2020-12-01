#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

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
 
  lcd.begin (16,2); 
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("   AGUARDANDO");
  lcd.setCursor(0,1);
  lcd.print("    AMOSTRA.");
  
}

void bloodDetected(){   
  lcd.clear();    
  lcd.setCursor(0,0);
  lcd.print("    AMOSTRA");
  lcd.setCursor(0,1);
  lcd.print("   DETECTADA!");
  
  for (int i = 0; i <= 4; i++) {
    lcd.setBacklight(HIGH);
    delay(500);
    lcd.setBacklight(LOW);
    delay(500);
  }   
    lcd.setBacklight(HIGH);
}

String leStringSerial(){
  String conteudo = "";
  char caractere;
  
  // Enquanto receber algo pela serial
  while(Serial.available() > 0) {
    // Lê byte da serial
    caractere = Serial.read();
    // Ignora caractere de quebra de linha
    if (caractere != '\n'){
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }
    
  Serial.print("Recebi: ");
  Serial.println(conteudo);
    
  return conteudo;
}

void loop() {

  int current_voltage = 0;
  String recebido;

//Lê valor do Sangue
    Serial.print("Measured value: ");
    Serial.println(analogRead(0));    
    current_voltage = analogRead(0) * 494.45 * (5.0 / 1023.0);

//Lê valor Serial
//    if (Serial.available() > 0){
//      // Lê toda string recebida
//      recebido = leStringSerial();
//      current_voltage = recebido.toInt();
//    }

  if(current_voltage > 96) {
    bloodDetected();
    str = String(current_voltage);
    Serial.println("Sending value to Node...");    
      
      lcd.setCursor(0,0);
      lcd.print("VALOR MEDIDO:");
      lcd.setCursor(13,0);
      lcd.print(str);
      lcd.setCursor(0,1);
      lcd.print("   ENVIANDO...   ");
    
    for (int i = 0; i <= 10; i++) {
        espSerial.println(str);
        Serial.print("Sending measured value: ");
        Serial.println(str);
        delay(1000);
    }
      current_voltage = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("   AGUARDANDO");
      lcd.setCursor(0,1);
      lcd.print("  NOVA AMOSTRA");
      delay(2000);
      
  }
}
