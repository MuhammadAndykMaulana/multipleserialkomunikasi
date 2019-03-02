/*
 BISMILLAH BISA
 
 dicoba sebagai PENERIMA(MASTER)
 konfigurasi
 CLIENT ==> ROUTER ==> MASTER
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
typedef enum { jawab } role_e;
const char* role_friendly_name[] = { "invalid", "MODE Jawab"};
role_e role = jawab;
int LED4 = 2;
int LED3 = 3;
int LED2 = 4;
int LED1 = 5;
int BUZZ = 12; //buzzer 
int D = 24;//input BCD
int C = 26;//Input BCD
int B = 28;//input BCD
int A = 22;//input BCD
int DD = 32;//input BCD
int CC = 34;//Input BCD
int BB = 36;//input BCD
int AA = 30;//input BCD

void setup(void)
{
  Serial.begin(9600);
  printf_begin();
  printf("\n\r\t\t\t* * * BISMILLAH LULUS 2017 * * *\t\t\t\n\n\r");
  printf("\nROLE Awal: %s\n\r",role_friendly_name[role]);
  printf("\n\\t\t\t * * * HANYA BISA MENERIMA * * *\n\r");
  radio.begin();
  radio.setRetries(15,15);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  //pinMode(BUZZ, OUTPUT);
  pinMode(DD, OUTPUT);
  pinMode(CC, OUTPUT);
  pinMode(BB, OUTPUT);
  pinMode(AA, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  radio.printDetails();
  printf("\n\n\t\t\t <=== Langsung MENERIMA <===\n\n\r");
  radio.openReadingPipe(1,pipes[1]);
  radio.startListening();
}

void loop(void)
{
  delay(10);
  if ( role == jawab )
  {
    if ( radio.available() )
    {
      // Buang muatan sampai kita mendapatkan semuanya
      unsigned long got_time;
      bool done = false;
      while (!done){
        done = radio.read(code, 1);       
        Serial.println(code[0]);
        done = radio.read( &got_time, sizeof(unsigned long) );
        printf("Dapat nilai Payload %lu...",got_time);
        if (code[0] == 1){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, HIGH);                       
          digitalWrite(BB, LOW);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED1, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED1, LOW);
            //digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
        else if (code[0] == 2){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, HIGH);                       
          digitalWrite(BB, LOW);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED2, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED2, LOW);
            //digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
        else if (code[0] == 3){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, HIGH);                       
          digitalWrite(BB, LOW);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED3, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED3, LOW);
            //digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
        else if (code[0] == 4){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, HIGH);                       
          digitalWrite(BB, LOW);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED4, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED4, LOW);
            //digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
        else if (code[0] == 5){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, LOW);                       
          digitalWrite(BB, HIGH);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED1, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED1, LOW);
            //digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
        else if (code[0] == 6){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, LOW);                       
          digitalWrite(BB, HIGH);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED2, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED2, LOW);
            //digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
        else if (code[0] == 7){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, LOW);                       
          digitalWrite(BB, HIGH);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED3, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED3, LOW);
            //digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
        else if (code[0] == 8){
          digitalWrite(A, LOW);                        
          digitalWrite(B, LOW);                         
          digitalWrite(C, LOW);                       
          digitalWrite(D, LOW);                      
          digitalWrite(AA, LOW);                       
          digitalWrite(BB, HIGH);                       
          digitalWrite(CC, LOW);                       
          digitalWrite(DD, LOW);
          for (int i=0; i<=10; i++){
            digitalWrite(LED4, HIGH);
            //digitalWrite(BUZZ, HIGH);
            delay(200);    
            digitalWrite(LED4, LOW);
            digitalWrite(BUZZ, LOW);
            delay(200);
          }
        }
      }
      digitalWrite(AA, LOW);                       
      digitalWrite(BB, LOW);                       
      digitalWrite(CC, LOW);                       
      digitalWrite(DD, LOW);
//      digitalWrite(A, LOW);                        
//      digitalWrite(B, LOW);                         
//      digitalWrite(C, LOW);                       
//      digitalWrite(D, LOW);                      
      // Send the final one back.
      //radio.write( &got_time, sizeof(unsigned long) );
      printf("DATA SUDAH DI TERIMA\n\r");
    }
  }
  role = jawab;
  radio.openReadingPipe(1,pipes[0]);
//  printf("TIDAK ADA DATA DI TERIMA\n\r");
//  delay(1000);
}
