#define pin 4
int pinStateCurrent=LOW;  
int pinStatePrevious=LOW;
int blue=5;
int purple=6;
int yellow=7;
void setup() {
//Serial.begin(9600);
pinMode(pin,INPUT);
pinMode(blue,OUTPUT);
pinMode(purple,OUTPUT);
pinMode(yellow,OUTPUT);}
void loop() {
pinStatePrevious=pinStateCurrent;//store old state
pinStateCurrent=digitalRead(pin);//read new state
if(pinStatePrevious==LOW&&pinStateCurrent==HIGH){
//pin state change LOW->HIGH
//Serial.println("MOTION ON");
digitalWrite(blue,LOW);
digitalWrite(purple,HIGH);
digitalWrite(yellow,LOW);
delay(500);}
else
if(pinStatePrevious==HIGH&&pinStateCurrent==LOW){
//pin state change HIGH->LOW
//Serial.println("MOTION OFF");
digitalWrite(blue,LOW);
digitalWrite(purple,LOW);
digitalWrite(yellow,HIGH);
delay(500);}}