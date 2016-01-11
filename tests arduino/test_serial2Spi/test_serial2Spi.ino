#include "SPI.h"

const int chip_select_pin = 10;
char incoming_char;
uint8_t incoming_byte;


void setup()
// put your setup code here, to run once:
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(chip_select_pin, OUTPUT);
  digitalWrite(chip_select_pin, HIGH);
  SPI.begin();
}

void loop() 
// put your main code here, to run repeatedly:
{
  if (Serial.available() > 0)
  {
    incoming_byte = Serial.read();
    incoming_char = incoming_byte;
    
    Serial.print("\nCaractere envoye par port serie: ");
    Serial.print(incoming_char);
    Serial.print(" (");
    Serial.print(incoming_byte);
    Serial.println(")");

   
    digitalWrite(chip_select_pin, LOW);
    
    incoming_byte = SPI.transfer(incoming_byte);
    incoming_char = incoming_byte;
    
    Serial.print("Caractere recu par SPI: ");
    Serial.print(incoming_char);
    Serial.print(" (");
    Serial.print(incoming_byte);
    Serial.println(")");
    
    digitalWrite(chip_select_pin, HIGH);
  }
}
