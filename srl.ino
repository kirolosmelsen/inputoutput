#include <IRremote.h>
#define REC 12
#define MORE 64
#define LESS 25
#define BEFORE 7
#define AFTER 9
#define RUN 21
void setup(){
Serial.begin(9600);
IrReceiver.begin(REC);}
void loop(){
if(IrReceiver.decode()){
IrReceiver.resume();
int command=IrReceiver.decodedIRData.command;
switch(command){
case MORE:{
Serial.println("MORE");
break;}
case LESS:{
Serial.println("LESS");
break;}
case BEFORE:{
Serial.println("BEFORE");
break;}
case AFTER:{
Serial.println("AFTER");
break;}
case RUN:{
Serial.println("RUN");
break;}
default:{
Serial.println("NOT FOUND");}}}}