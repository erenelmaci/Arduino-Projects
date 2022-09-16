#include <IRremote.h>  //https://github.com/z3t0/Arduino-IRremote
int RECV_PIN = 2;    // IR alıcısı giriş portu
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  // 2.3.4.5. pinler Ledler için çıkış olarak ayarlandı
  pinMode(8,OUTPUT);   // kırmızı led - led bacağına 330R-1K arası direnç bağlayın
  Serial.begin(9600);  // seri port ekranbağlantı hızı
  irrecv.enableIRIn(); // Alış başlıyor
     Serial.println("KODLAR:");
}

void loop() {
  if (irrecv.decode(&results)) {

    //Serial.print komutu seriport ekranda satırı yazar yan yana devam eder
    //Serial.println komutu seri port ekranda satırı yazar alt satıra geçer
     Serial.print("HEX> "); 
     Serial.println(results.value, HEX); // Gelen veri hexadecimal (16'lık) tabanda yazılır
    
       if(results.value == 0xFF30CF)          // CH... ise 1. Led yansın - bu satırdaki hex kodu elimdeki kumandaya göre yazdım, siz kendinize göre değiştirin  
             digitalWrite(8,HIGH);      
               Serial.println(results.value);
    irrecv.resume(); // yeni bir değer almak için yola devam ediyoruz

  }
  delay(1000); // sinyaller karışmasın azıcık bekleyelim
}
