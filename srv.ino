#include <Servo.h>
#define potenziometro A0
#define pinservo0 3
#define pinservo1 5
#define pinservo2 6
Servo myservo0;
Servo myservo1;
Servo myservo2;
int pos;
void setup(){
myservo0.attach(pinservo0);
myservo1.attach(pinservo1);
myservo2.attach(pinservo2);}
void loop(){
pos=map(analogRead(potenziometro),0,1023,0,180);
myservo0.write(pos);
myservo1.write(pos);
myservo2.write(pos);
delay(500);}
//lib <Servo.h> will disable PIN9 and PIN10 pmw function
//read() will read servo angular position will return latest value written with write()
//writeMicroseconds() will set servo rotation speed 1000 to 2000 standard servo
//for(pos=0,pos<=180,pos+=1){myservo.write(pos);delay(15);}