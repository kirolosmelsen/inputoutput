#include <Servo.h>
#define pinservo0 12
Servo myservo0;
int xAxisPin=0;
int yAxisPin=1;
int zAxisPin=8;
int xVal,yVal,zVal;
int pos;
void setup(){
myservo0.attach(pinservo0);
pinMode(zAxisPin,INPUT_PULLUP);
//Serial.begin(9600);}
void loop(){
xVal=analogRead(xAxisPin);
yVal=analogRead(yAxisPin);
zVal=digitalRead(zAxisPin);
pos=map(xVal,0,1023,0,180);
myservo0.write(pos);
delay(500);
//Serial.print("X : ");
//Serial.print(xVal);
//Serial.print("\t Y : ");
//Serial.print(yVal);
//Serial.print("\t Z : ");
//Serial.println(zVal);
//delay(200);}