#include <IRremote.h>
#include <Servo.h>
#define REC 12
#define ON 69
#define MENU 71
#define TEST 68
#define MORE 64
#define BACK 67
#define BEFORE 7
#define RUN 21
#define AFTER 9
#define LESS 25
#define C 13
#define LED 2
#define BLUE A0
#define PURPLE A1
#define YELLOW A2
#define BUZZER 13
#define SERVO0 3
#define SERVO1 5
#define SERVO2 6
#define SERVO3 11
#define SERVO4 11
Servo myservo0;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int STEPPER[]={10, 9, 8, 7};
int menu=0;
int pos;
int speed=1000;
int stepper=300;
int RGB=1;
void setup(){
IrReceiver.begin(REC);
pinMode(LED,OUTPUT);
pinMode(BLUE,OUTPUT);
pinMode(PURPLE,OUTPUT);
pinMode(YELLOW,OUTPUT);
pinMode(BUZZER,OUTPUT);
myservo0.attach(SERVO0);
myservo1.attach(SERVO1);
myservo2.attach(SERVO2);
myservo3.attach(SERVO3);
myservo4.attach(SERVO4);
for (int i=0;i<4;i++){
pinMode(STEPPER[i],OUTPUT);}}
void loop(){
if(IrReceiver.decode()){
digitalWrite(BUZZER,HIGH);
delay(75);
digitalWrite(BUZZER,LOW);
IrReceiver.resume();
int command=IrReceiver.decodedIRData.command;
switch(command){
//case ON:{
//blink();
//break;
//}
case MENU:{
blink();
menu<5?menu++:menu=0;
break;
}
//case TEST:{
//blink();
//break;
//}
case MORE:{
blink();
speed=2000;
stepper=100;
break;}
case BACK:{
blink();
menu>0?menu--:menu=5;
break;}
case BEFORE:{
blink();
if(RGB=1){
purple();}
switch(menu){
case 0:{
for(int i=0;i<32;i++){
step(false);
delay(3);}
delay(stepper);
break;}
case 1:{
pos=myservo0.read();
if(pos>=5){
myservo0.writeMicroseconds(speed);
pos=pos-5;
myservo0.write(pos);}
break;}
case 2:{
pos=myservo1.read();
if(pos>=5){
myservo1.writeMicroseconds(speed);
pos=pos-5;
myservo1.write(pos);}
break;}
case 3:{
pos=myservo2.read();
if(pos>=5){
myservo2.writeMicroseconds(speed);
pos=pos-5;
myservo2.write(pos);}
break;}
case 4:{
pos=myservo3.read();
if(pos>=5){
myservo3.writeMicroseconds(speed);
pos=pos-5;
myservo3.write(pos);}
break;}
case 5:{
pos=myservo4.read();
if(pos>=5){
myservo4.writeMicroseconds(speed);
pos=pos-5;
myservo4.write(pos);}
break;}}
yellow();
break;}
case RUN:{
digitalWrite(LED,HIGH);
digitalWrite(BUZZER,HIGH);
delay(150);
digitalWrite(BUZZER,LOW);
digitalWrite(LED,LOW);
break;}
case AFTER:{
blink();
if(RGB=1){
purple();}
switch(menu){
case 0:{
for(int i=0;i<32;i++){
step(true);
delay(3);}
delay(stepper);
break;}
case 1:{
pos=myservo0.read();
if(pos<=175){
myservo0.writeMicroseconds(speed);
pos=pos+5;
myservo0.write(pos);}
break;}
case 2:{
pos=myservo1.read();
if(pos<=175){
myservo1.writeMicroseconds(speed);
pos=pos+5;
myservo1.write(pos);}
break;}
case 3:{
pos=myservo2.read();
if(pos<=175){
myservo2.writeMicroseconds(speed);
pos=pos+5;
myservo2.write(pos);}
break;}
case 4:{
pos=myservo3.read();
if(pos<=175){
myservo3.writeMicroseconds(speed);
pos=pos+5;
myservo3.write(pos);}
break;}
case 5:{
pos=myservo4.read();
if(pos<=175){
myservo4.writeMicroseconds(speed);
pos=pos+5;
myservo4.write(pos);}
break;}}
yellow();
break;}
case LESS:{
blink();
speed=1000;
stepper=300;
break;}
case C:{
blink();
switch(RGB){
case 0:{
analogWrite(BLUE,0);
analogWrite(PURPLE,0);
analogWrite(YELLOW,0);
break;}
case 1:{
yellow();
break;}}
if(RGB=0){
RGB=1;}
else{
RGB=0;}
break;}
default:{}}}}
void blink(){
digitalWrite(LED,HIGH);
delay(25);
digitalWrite(LED,LOW);
delay(25);
digitalWrite(LED,HIGH);
delay(25);
digitalWrite(LED,LOW);}
void step(bool dir){
static byte out=0x01;
if(dir){
out!=0x08?out=out<<1:out=0x01;}
else{
out!=0x01?out=out>>1:out=0x08;}
for(int i=0;i<4;i++){
digitalWrite(STEPPER[i],(out & (0x01 << i))?HIGH:LOW);}}
void blue(){
analogWrite(BLUE,255);
analogWrite(PURPLE,0);
analogWrite(YELLOW,0);}
void purple(){
analogWrite(BLUE,0);
analogWrite(PURPLE,255);
analogWrite(YELLOW,0);}
void yellow(){
analogWrite(BLUE,0);
analogWrite(PURPLE,0);
analogWrite(YELLOW,255);}