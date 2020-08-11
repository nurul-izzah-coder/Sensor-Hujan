#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //pin LCD

int rainPin = A0; 
int greenLED = 7; 
int yellowLED = 6; 
int thershold = 500;
 
void setup(){
  pinMode(rainPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT); 
  digitalWrite(greenLED, LOW); 
  digitalWrite(yellowLED, LOW);
  Serial.begin(9600);
  lcd.begin(16, 2);
}
 
void loop() { 
  // read the input on analog pin 0:
  int sensorValue =analogRead(rainPin);
  if(sensorValue < thershold){
    lcd.setCursor(0, 0); 
    lcd.print("Permukaan Basah");
    lcd.setCursor(6, 1);
    lcd.print("Hujan");
    Serial.println(" Permukaan Basah --- Hujan "); 
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH); 
    delay(1000); 
    lcd.clear();
  }
else {
    lcd.setCursor(0, 0); 
    lcd.print("Permukaan Kering"); 
    lcd.setCursor(4, 1); 
    lcd.print("Cuaca Cerah"); 
    Serial.println(" Permukaan Kering --- Cuaca Cerah");
     digitalWrite(greenLED, HIGH); 
    digitalWrite(yellowLED, LOW);
     delay(1000); 
    lcd.clear(); 
  }
  delay(500); 
}
