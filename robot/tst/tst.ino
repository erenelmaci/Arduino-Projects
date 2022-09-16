#define role 8 
const int x_ekseni = A0;

int x_durum;

void setup()
{  
  Serial.begin(9600);
  pinMode(role,OUTPUT);
  

}

void loop() {
  x_durum = analogRead(x_ekseni);

  Serial.print("x durumu =");
  Serial.println(x_durum);
  Serial.println("******************");
  delay(1000);
  if (x_durum = 1023)
  {
      digitalWrite(role,HIGH);
    }
  else
  {
   digitalWrite(role,LOW);
    }

}
