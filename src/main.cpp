//Recieves keyboard input via serial monitor and outputs to lcd display

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <string.h>

LiquidCrystal lcd(12,11,5,4,3,2);
String input = " "; 
int stringLength = 0; 


void countDown(int max){
  for(int i = max; i > 0 ;i--){
    Serial.print(i);
    Serial.print(", ");
    delay(1000);
  }
  Serial.print("Go...\n"); 
}

void countDownLCD(){
  lcd.print("                3, 2, 1, Go...");
  for( int i = 0; i < 32 ; i++){
    lcd.scrollDisplayLeft();
    delay(400);
  }
  lcd.clear();

}

void setup() {
  //setup code here
  Serial.begin(9600);
  lcd.begin(16,2);
  countDown(3); 
  countDownLCD();
}
//code that runs repeatedly 
void loop() {
  
  lcd.setCursor(0,1); 
  lcd.print(" ");
  if(Serial.available() > 0){
    input = Serial.readString(); 
    Serial.print("input: ");
    Serial.println(input);
  }
  lcd.print(input);
  stringLength = input.length(); 
  
  //lcd.scrollDisplayLeft();
  //delay(400);

  for(int i = 0; i < stringLength; i++){
    lcd.scrollDisplayLeft();
    delay(400);  
  }
  
}

