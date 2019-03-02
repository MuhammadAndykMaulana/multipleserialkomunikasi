/*
 BISMILLAH BISA
 
 dicoba sebagai PENGIRIM (CLIENT 02)
 konfigurasi NO ROUTER
 CLIENT ==> MASTER
 * * * and FIXED PIN * * *
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

// Set up nRF24L01 radio on SPI bus plus pins 7 & 8 
RF24 radio(7,8);

int code[1]; 
//const uint64_t pipes[2] = { 0xF0F0F0F0E1LL };
const uint64_t pipes[2] = { 0xF0F0F0F0D2LL };
typedef enum { panggil = 1} role_e;
const char* role_friendly_name[] = { "invalid", "MODE Panggil"};
role_e role = panggil;
int SW1 = 13;
int SW2 = 12;
int SW3 = 11;
int SW4 = 10;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;

void setup(void)
{
  Serial.begin(9600);
  printf_begin();
  printf("\n\r\t\t\t* * * BISMILLAH LULUS 2017 * * *\n\n\t\t\t\r");
  printf("\nROLE Awal: %s\n\r",role_friendly_name[role]);
  printf("\n\t\t\t * * * HANYA BISA KIRIM * * *\n\n\r");
  radio.begin();
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  radio.setRetries(15,15);
  radio.printDetails();
  printf("\n\n\t\t\t ===> Langsung MENGIRIM ke MASTER RECEIVER===>\n\n\r");
}

void loop(void)
{
  delay(10);
  radio.stopListening();
  if (role == panggil)
  {
    if (digitalRead(SW1) == LOW){
    code[0] = 5;
    Serial.println(code[0]);
    radio.write(code, 1);
    for (int i=0; i<=10; i++){
        digitalWrite(LED1, HIGH);
        delay(200);    
        digitalWrite(LED1, LOW);
        delay(200);}
    }
    if (digitalRead(SW2) == LOW){
    code[0] = 6;
    Serial.println(code[0]);
    radio.write(code,1);
    for (int i=0; i<=10; i++){
        digitalWrite(LED2, HIGH);
        delay(200);    
        digitalWrite(LED2, LOW);
        delay(200);}
    }
    if (digitalRead(SW3) == LOW){
    code[0] = 7;
    Serial.println(code[0]);
    radio.write(code,1);
    for (int i=0; i<=10; i++){
        digitalWrite(LED3, HIGH);
        delay(200);    
        digitalWrite(LED3, LOW);
        delay(200);}
    }
    if (digitalRead(SW4) == LOW){
    code[0] = 8;
    Serial.println(code[0]);
    radio.write(code,1);
    for (int i=0; i<=10; i++){
        digitalWrite(LED4, HIGH);
        delay(200);    
        digitalWrite(LED4, LOW);
        delay(200);}
    }
 
    else 
    {
        code[0] = 000;
        radio.write(code, 1);
    }
    unsigned long time = millis();
    printf("Sedang mengirim %lu...",time);
    bool ok = radio.write( &time, sizeof(unsigned long) );
    
    if (ok){
      printf("Okesip...");}
    else {
      printf("Gagal.\n\r");}
    
    radio.startListening();

    // tunggu disini sampai mendapatkan respon, atau timeout (250ms)
    unsigned long tunggu = millis();
    bool timeout = false;
    while ( ! radio.available() && ! timeout )
      if (millis() - tunggu > 200 )
        timeout = true;

    // Describe the results
    if ( timeout )
    {
      printf("Sip mantab ==> Langsung MASTER RECEIVER\n\r");
      //printf("Gagal, tidak ada respon.\n\r");
    }
    else
    {
      // Ambil respon, bandingkan, dan kirim ke debugging spew
      unsigned long got_time;
      radio.read( &got_time, sizeof(unsigned long) );

      // Spew it
      printf("Dapat Respon %lu \n\r",got_time);
      //printf("Dapat Respon %lu, round-trip delay: %lu\n\r",got_time,millis()-got_time);
    }
    delay(1000);
  }
  
  role = panggil;
  radio.openWritingPipe(pipes[0]);
}
