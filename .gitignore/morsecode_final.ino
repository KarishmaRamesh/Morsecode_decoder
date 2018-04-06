unsigned long time1,time2,first,low,high,temp;
char* code[30]={".-","-...","-.-.","-..",".","..-.","--.","....","..",
".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
"...","-","..-","...-",".--","-..-","-.--","--.."};
const int buttonPin = 2;
const int buzzer = 9;     
const int ledPin =  13;    
int buttonState = 0;
void funct(char *);
int i,t=1;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  label2:
  temp=millis();
  if((temp-time2)>3000)
  {
    if(t==0)
      Serial.print(" ");
    t=1;
    }
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
        tone(buzzer, 5000);
        while(buttonState==HIGH)
        buttonState = digitalRead(buttonPin);
        noTone(buzzer);
        time1 = millis();
        high=time1-first;
        delay(50);// wait a second so as not to send massive amounts of data
        if(high>=300)
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
            funct(b);
            goto label2;
          }
          buttonState = digitalRead(buttonPin);
        }
        first=time2;
      }
    }
  }
}

void funct(char *p)
{
  int j=0;
  char a1[10]="\0";
  char final;
  while(*p!='\0')
  {
  a1[j]=*p;
  p++;j++;
  }
  a1[j]='\0';
  for (int k=0;k<26;k++)
  { 
    if(strcmp(code[k],a1)==0)
    { 
      final=k+65;
      Serial.print(final);
    }
  }
  t=0;
}
