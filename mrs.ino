#define Led 12
void setup(){
pinMode(Led,OUTPUT);}
void loop(){
punto();
punto();
punto();
linea();
linea();
linea();
punto();
punto();
punto();
delay(1000);}
void punto(){
digitalWrite(Led,HIGH);
delay(200);
digitalWrite(Led,LOW):
delay(200);}
void linea(){
digitalWrite(Led,HIGH);
delay(500);
digitalWrite(Led,LOW):
delay(500);}