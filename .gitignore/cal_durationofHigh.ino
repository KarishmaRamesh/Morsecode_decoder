unsigned long time1,time2,first,low,high;
char* code[30]={".-","-...","-.-.","-..",".","..-.","--.","....","..",
".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
"...","-","..-","...-",".--","-..-","-.--","--.."};
const int buttonPin = 2;     
const int ledPin =  13;    
int buttonState = 0;
void funct(char *);
int i;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop()
{
  label2:
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    first=millis();
    i=0;
    char b[10]="\0";
    while(1)
    {
      buttonState = digitalRead(buttonPin);
      if (buttonState == HIGH) 
      {
        digitalWrite(ledPin, HIGH);
        while(buttonState==HIGH)
        buttonState = digitalRead(buttonPin);
        Serial.print("how long HIGH : ");
        time1 = millis();
        high=time1-first;
        Serial.println(high);
        delay(50);// wait a second so as not to send massive amounts of data
        if(high>500)
          b[i]='-';
        else
          b[i]='.';
        i++;
      } 
      else
      {
        digitalWrite(ledPin, LOW);
        while(buttonState==LOW)
        {
          time2 = millis();
          low=time2-time1;
          if(low>1100)
          {
            b[i]='\0';
            Serial.print("how long space : ");
            Serial.println(low);
            //funct(b);
            //Serial.print("\t");
            goto label2;
          }
          buttonState = digitalRead(buttonPin);
        }
        first=time2;
      }
    }
  }
}

