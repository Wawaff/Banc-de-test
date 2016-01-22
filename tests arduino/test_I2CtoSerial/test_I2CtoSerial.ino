#include <Wire.h>


const int chip_select_pin = 10;
char incoming_char;
uint8_t incoming_byte;
// byte address = 8;

void setup()
// put your setup code here, to run once:
{
  Serial.begin(9600);
  Wire.begin();
  pinMode(13, OUTPUT);
  Serial.println("Le programme commence");
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
    
    Wire.beginTransmission(8);
    Wire.write(incoming_char);
    Wire.write(incoming_byte);
    Wire.endTransmission();
    Serial.println(Wire.endTransmission());
    
    Serial.print("J'envoie le caractere ");
    Serial.print(incoming_char);
    Serial.print(" a l'adresse ");
    Serial.println(8);
  }
}
