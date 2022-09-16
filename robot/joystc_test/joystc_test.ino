const int x_ekseni = A0;

int x_durum;

void setup()
{  
  Serial.begin(9600);

}

void loop() {
   x_durum = analogRead(x_ekseni);

  Serial.print("x durumu =");
  Serial.println(x_durum);
  Serial.println("******************");
  delay(1000);

}
