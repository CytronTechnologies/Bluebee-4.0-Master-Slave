
const char ledPin = 13;   //red
#include <Servo.h>

Servo myservo;

byte packet[4];
byte rcvState=0; 


void setup()
{
 Serial.begin(115200); //initialize serial communication with baudrate = 9600bps (UART is used for this case)
 Serial.flush();  //flush out the contents in the receive buffer
 pinMode(ledPin,OUTPUT); //set the led2 (or digital pin 13) as output
 pinMode(11,OUTPUT);
 myservo.attach(9,800 ,2200);
  rcvState=0;
}

void loop()
{


    while(Serial.available()<4); //wait for 4 bytes

    for(int i=0;i<4; i++)  //read 4 bytes
    {
      packet[i]=Serial.read(); 
    }
    

    if(packet[0]==0xFF && packet[1]==0xFF) //header verified correct
    {
      if(packet[2]=='S')  //servo packet
      {
        myservo.write(packet[3]);        
      }

      else if(packet[2]=='L')
      {

        digitalWrite(ledPin, packet[3]);
      } 
      else if(packet[2]=='B')
      {
        analogWrite(11,packet[3]);
      }
    
    }

}      

