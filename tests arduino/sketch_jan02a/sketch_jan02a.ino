void setup()
{
  pinMode(8,OUTPUT); // la pin 13 doit envoyer du courant
}

void loop()
{
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);
}

