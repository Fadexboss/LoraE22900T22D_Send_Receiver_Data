#include "LoRa_E22.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 8);
LoRa_E22 e22ttl(&mySerial);


#define M0 7
#define M1 6


struct Message{
  byte sicaklik[10];
  byte hiz[10];

};


void setup() {
  Serial.begin(9600);
  pinMode(M0,OUTPUT);
  pinMode(M1,OUTPUT);
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
  e22ttl.begin();

}
void loop() {
  //while döngüsünün içindeki şart lora antenini gördüğünde çalıştırmasını sağlıyor
  while (e22ttl.available()>1) {
  ResponseStructContainer rsc = e22ttl.receiveMessage(sizeof(Message));
  struct Message message =* (Message*) rsc.data;
  rsc.close();
  Serial.print("yazıyor");
  //veriler byte olarak gönderiliyor float sayısına dönüştürüyoruz çünkü 5.1 şeklinde noktalı veriler gelebilir
  Serial.print(*(float*)(message.sicaklik));
  Serial.println();
  Serial.print(*(float*)(message.hiz));  

  
  }
}
