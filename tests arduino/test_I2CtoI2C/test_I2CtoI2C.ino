#include "Wire.h"

const int chip_select_pin = 10;
char incoming_char;
uint8_t incoming_byte;
int address = 8;


void setup()
// put your setup code here, to run once:
{
  Serial.begin(9600);
  Wire.begin(8);
  pinMode(13, OUTPUT);
  Serial.println("Begin");
  digitalWrite(13, HIGH);
  
  Wire.onReceive(test);
}

void loop() 
// put your main code here, to run repeatedly:
{
  while(Wire.available())
  {
    digitalWrite(13, LOW);
    incoming_byte = Wire.read();
    incoming_char = incoming_byte;
    
    Serial.print("\nCaractere recu par I2C: ");
    Serial.print(incoming_char);
    Serial.print(" (");
    Serial.print(incoming_byte);
    Serial.println(")");
       
//    Wire.beginTransmission(address);
//   
//    Wire.write(incoming_char + 1);
//    Wire.endTransmission();
    
    Serial.print("Caractere envoye sur I2C: ");
    Serial.print(incoming_char);
    Serial.print(" (");
    Serial.print(incoming_byte);
    Serial.println(")");
   }
}

void test(int x)
{
  digitalWrite(13, LOW);
}
