/*
 BISMILLAH BISA
 
 dicoba sebagai PENERIMA(MASTER)
 konfigurasi
 CLIENT ==> ROUTER ==> MASTER
 
 */


#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

// Set up nRF24L01 radio on SPI bus plus pins 7 & 8 
RF24 radio(7,8);

const uint64_t pipes[2] = { 0xF0F0F0F0D2LL };
typedef enum { jawab } role_e;
const char* role_friendly_name[] = { "invalid", "MODE Jawab"};
role_e role = jawab;

void setup(void)
{
  Serial.begin(9600);
  printf_begin();
  printf("\n\r\t\t\t* * * BISMILLAH LULUS 2017 * * *\t\t\t\n\n\r");
  printf("\nROLE Awal: %s\n\r",role_friendly_name[role]);
  printf("\n\\t\t\t * * * HANYA BISA MENERIMA * * *\n\r");
  radio.begin();
  radio.setRetries(15,15);
  
  radio.openReadingPipe(1,pipes[1]);
  radio.startListening();
  radio.printDetails();
  printf("\n\n\t\t\t <=== Langsung MENERIMA <===\n\n\r");
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
      while (!done)
      {
        // Ambil muatan, dan lihat apakah ini yang terakhir.
        done = radio.read( &got_time, sizeof(unsigned long) );

        // Spew it
        printf("Dapat nilai Payload %lu...",got_time);

  // Delay just a little bit to let the other unit
  // make the transition to receiver (penerima)
  delay(20);
      }
      // Send the final one back.
      radio.write( &got_time, sizeof(unsigned long) );
      printf("DATA SUDAH DI TERIMA\n\r");

      // Now, resume listening so we catch the next packets.
      radio.startListening();
    }
    else{
      printf("TIDAK ADA DATA DI TERIMA\n\r");
      delay(1000);
    }
  }

  role = jawab;
  radio.openReadingPipe(1,pipes[0]);
}
