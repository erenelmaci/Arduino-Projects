#include  <LiquidCrystal.h>                            
int trigPin = 7;                                       
int echoPin = 6;                                       
int sure;                                               
int uzaklik;                                           
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   
 LiquidCrystal lcd(rs, en, d4, d5, d6, d7);              
 void setup() {
   pinMode(trigPin, OUTPUT);                             
   pinMode(echoPin,INPUT);                               
   lcd.begin(16, 2);                                                                 
 }
 void loop() {
   digitalWrite(trigPin, LOW);                          
   delayMicroseconds(5);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   sure = pulseIn(echoPin, HIGH, 11600);                 
   uzaklik= sure*0.0345/2;                               
   lcd.clear();                                          
   lcd.setCursor(0, 0);                                       
   lcd.print("UZAKLIK:");                                
   lcd.setCursor(0, 1);                                  
   lcd.print(uzaklik);                                  
   lcd.print("cm");
 } 
