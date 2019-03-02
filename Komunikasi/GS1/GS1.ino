 /*
 BISMILLAH BISA
 
 dicoba sebagai PENGIRIM (CLIENT)
 konfigurasi
 CLIENT ==> ROUTER ==> MASTER
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

// Set up nRF24L01 radio on SPI bus plus pins 7 & 8 
RF24 radio(7,8);

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL };
typedef enum { panggil = 1} role_e;
const char* role_friendly_name[] = { "invalid", "MODE Panggil"};
role_e role = panggil;

void setup(void)
{
  Serial.begin(9600);
  printf_begin();
  printf("\n\r\t\t\t* * * BISMILLAH LULUS 2017 * * *\n\n\t\t\t\r");
  printf("\nROLE Awal: %s\n\r",role_friendly_name[role]);
  printf("\n\t\t\t * * * HANYA BISA KIRIM * * *\n\n\r");
  radio.begin();
  radio.setRetries(15,15);
  radio.printDetails();
  printf("\n\n\t\t\t ===> Langsung MENGIRIM ===>\n\n\r");
}

void loop(void)
{
  delay(10);
  if (role == panggil)
  {
    radio.stopListening();
    unsigned long time = millis();
    printf("Sedang mengirim %lu...",time);
    bool ok = radio.write( &time, sizeof(unsigned long) );
    
    if (ok)
      printf("Okesip...");
    else
      printf("Gagal.\n\r");
    
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
      printf("Sip mantab ==> ROUTER\n\r");
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
