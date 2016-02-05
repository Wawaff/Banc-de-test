#include "SPI.h"

const int chip_select_pin = 10;


void setup() {
  // Code de setup du arduino:
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(chip_select_pin, INPUT);
  SPI.begin();
  Serial.println("Le programme commence");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    // read
  }
}
