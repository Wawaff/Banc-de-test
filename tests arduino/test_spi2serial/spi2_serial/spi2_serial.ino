// Written by Nick Gammon
// April 2011

#include "SPI.h"

// what to do with incoming data

volatile byte message = 0;
volatile char character;
bool newMessage = false;

void setup (void)
{

  // turn on SPI in slave mode
  //SPI.begin();
  SPCR |= _BV(SPE);
  //pinMode(13, OUTPUT);
  // turn on interrupts
  SPCR |= _BV(SPIE);

  
  Serial.begin(250000);
  Serial.println("Begin");
}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
  message = SPDR;
  character = message;
  newMessage = true;
}  // end of interrupt service routine (ISR) SPI_STC_vect

void loop (void)
{
  if (newMessage)
  {
    // Si un message est reçu, la LED 13 allume et le message
    // s'affiche dans le port série
    //digitalWrite(13, !digitalRead(13));
    Serial.print(character);
    Serial.print(" (");
    Serial.print(message);
    Serial.println(")");
    newMessage = false;
  }
  
  
}  // end of loop
