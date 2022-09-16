#include <LiquidCrystal.h>
#include <virtuabotixRTC.h>
#include <IRremote.h>


int pirPin = 13;

int hareket;

int CLK_PIN = 7;
int DAT_PIN = 6;
int RST_PIN = A1;
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);

int rs = 5, en = 4, d4 = 3, d5 = 2, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

int kirmiziPin = 10;
int yesilPin = 11;
int maviPin = 12;

int RECV_PIN = A0;
IRrecv irrecv (RECV_PIN);
decode_results results;

#define CH1 0xFFA25D
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BU0TON200 0xFFB04F
#define BUTON1 0xFFA25D
#define BUTON2 0xFF629D
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD


int role1 = 8;
int role2 = 9;
int durum = 1;

void setup() {

  //myRTC.setDS1302Time(52, 04, 21, 6, 23, 01, 2021);

  lcd.begin(16,2);
  
  pinMode(pirPin, INPUT);
  pinMode(role1, OUTPUT);
  pinMode(role2, OUTPUT);

  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  Serial.begin(9600);
  irrecv.enableIRIn();

  Serial.begin(9600);
}

void loop() {

  Serial.print(hareket);

  myRTC.updateTime();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  lcd.setCursor(0, 1);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
  
   
  hareket = digitalRead(pirPin);
  if(hareket == 1){
    digitalWrite(role1, LOW);
    digitalWrite(role2, LOW);
    digitalWrite(kirmiziPin, HIGH);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, LOW);
    lcd.print("HAREKET ALGILANDI!!!");   
    delay(1000);
    }
    else
    {
      digitalWrite(role1, HIGH);
      digitalWrite(kirmiziPin, LOW);
      digitalWrite(yesilPin, HIGH);
      digitalWrite(maviPin, LOW);
      lcd.print("Devam Ediliyor");
      }

  
  if (irrecv.decode(&results)){  
    if (results.value == BUTON1){     
      digitalWrite(role1, 1);
      digitalWrite(role2, 0);
      }
     else
    { 
      digitalWrite(role1, 0);
    }
        
        if (results.value == BUTON2){     
      digitalWrite(role2, 1);
      digitalWrite(role1, 0);
      }
      else
    { digitalWrite(role2, 0);}
    }
  //Serial.println(results.value);
  
    irrecv.resume();
    delay(786);
    }
   
 
