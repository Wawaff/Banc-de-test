char incomingByte;

void setup()
// put your setup code here, to run once:
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() 
// put your main code here, to run repeatedly:
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    Serial.print("Le byte est :"); //pour connaître la valeur du byte
    Serial.println(incomingByte);
  }

  if (incomingByte == 'a')
  {
    digitalWrite(8, HIGH);
  }
  if (incomingByte == 'b')
  {
    digitalWrite(8, LOW);
  }
}
