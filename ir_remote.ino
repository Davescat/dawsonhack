//Tawfiq Jawhar
//Dawson Hackathon 2019
//IR Remote Sample Code

#include <IRremote.h>

#define LEDPIN	10
#define IRPIN	9

#define BUTTON1 0xFD08F7
#define BUTTON2	0xFD8877

IRrecv irrecv(IRPIN);
decode_results results;


void setup()
{
  pinMode(LEDPIN, OUTPUT);
  
  Serial.begin(9600);
  
  irrecv.enableIRIn();
  
}

void loop()
{
  if(irrecv.decode(&results))
  {
    
    Serial.println(results.value, HEX);

	irrecv.resume();

	if(results.value == BUTTON1)
    {
      digitalWrite(LEDPIN,HIGH);
    }
    
    else if(results.value == BUTTON2)
    {
      digitalWrite(LEDPIN,LOW);
    }
    
  }
  


  
  
}