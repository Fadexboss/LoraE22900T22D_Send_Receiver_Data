
#include <LoRa_E22.h>
#include <SoftwareSerial.h>
//lora antenlerini rx tx bağlantıları
SoftwareSerial mySerial(9, 8); 
LoRa_E22 e22ttl(&mySerial);

//arduino unoda loradaki m0 ile m1 in nereler bağlanacağını gösteriyoruz
#define M0 7
#define M1 6

//Denemelik Message structı oluşturup dizi byte uzunluğunu içine yazıyoruz 10 yeterli bizim için alttaki küçük harfdeki message kelimesiyle dizileri ulaşabiliriz
struct Message{
  byte sicaklik[10];
  byte hiz[10];

}message;



void setup()
{
  Serial.begin(9600);
  pinMode(M0,OUTPUT);
  pinMode(M1,OUTPUT);
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
//lorayı başlatma
  e22ttl.begin();
  
}

void loop()
{
  //denemelik değer girelim
  *(float*)(message.sicaklik)=1;
  *(float*)(message.hiz)=2;

  
  mySerial.listen();
  //bu fonksiyonla e22 lora antenini diğer lora ile eşleştirelim 2. parametre adresi 3.parametre ise rf settingsten oluşturduğumuz kanal sayımızdır
  ResponseStatus rs = e22ttl.sendFixedMessage(0 , 56 , 22 , &message , sizeof(message));
}







