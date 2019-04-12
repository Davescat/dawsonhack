//Tawfiq Jawhar
//Dawson Hackathon 2019
//Blinking LEDs State Machine


#define LEDPIN_BLUE 10
#define LEDPIN_RED 11

#define STATE_RED 1
#define STATE_BLUE 2


int state = STATE_RED;

unsigned long T_last_switch;
int period = 1000;

void setup()
{
  
  pinMode(LEDPIN_BLUE, OUTPUT);
  pinMode(LEDPIN_RED, OUTPUT);
  
  //digitalWrite(LEDPIN_BLUE, HIGH);
  //digitalWrite(LEDPIN_RED, HIGH);
  
  T_last_switch = millis();
}


void TransitionToBlueState()
{
  digitalWrite(LEDPIN_BLUE, HIGH);
  digitalWrite(LEDPIN_RED, LOW);
  
  state = STATE_BLUE;
  T_last_switch = millis();

}

void TransitionToRedState()
{
  digitalWrite(LEDPIN_RED, HIGH);
  digitalWrite(LEDPIN_BLUE, LOW);
  
  state = STATE_RED;
  T_last_switch = millis();

}


void loop()
{
  
  switch(state)
  {
    case STATE_RED:
    	if(millis() >= T_last_switch + period)
   			TransitionToBlueState();
    	break;
    
    case STATE_BLUE:
    
    	if(millis() >= T_last_switch + period)
          	TransitionToRedState();
    
    	break;
      
  }
  
  
}





