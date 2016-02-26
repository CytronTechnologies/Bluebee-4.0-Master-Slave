int potpin = A0;
int potpin1 = A2;
byte LEDState=0;

unsigned int val;
unsigned int val1;


void setup()
{
 Serial.begin(115200);
}

void loop()
{
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 225);

  val1 = analogRead(potpin1);
  val1 = map(val1, 0, 1023, 0, 225);


  writeServo(val);
  writeLED(val1);
  

  if(digitalRead(A1)==0)
  {
    while(digitalRead(A1)==0); //wait for release
    LEDState=!LEDState;
    writeLEDonoff(LEDState);
  }
 
  delay(40);
}

void writeServo(byte pos)
{
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write('S');
  Serial.write(pos);

}

void writeLED(byte Brightness)
{
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write('B');
  Serial.write(Brightness);
}

void writeLEDonoff(byte onoff)
{
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write('L');
  Serial.write(onoff);
}
  


