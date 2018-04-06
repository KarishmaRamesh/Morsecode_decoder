const int buzzer=9;
void setup(){
 pinMode(buzzer, OUTPUT);
}
void loop(){
  tone(buzzer, 200);
  delay(1000);
   tone(buzzer, 500);
  delay(1000);
  noTone(buzzer);  
  delay(1000); 
}
