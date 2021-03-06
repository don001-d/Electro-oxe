#include <IRremote.h>

int RECV_PIN = 11; // output pin of sensor
int led1 = 2;
int led2 = 4;
int led3 = 7;
int led4 = 8;
int itsONled[] = {0,0,0,0};
#define button1 642546947  // for  button no. 1
#define button2 761297281  // for button no. 2
#define button3 2280302909 // for button no. 3
#define button4 2463769059 //for button no.4

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
Serial.begin(9600); 
irrecv.enableIRIn(); 
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
}

void loop() {
if (irrecv.decode(&results)) {
unsigned int value = results.value;
switch(value) {
case button1:
if(itsONled[1] == 1) { // if first led is on then
digitalWrite(led1, LOW); // turn it off when button is pressed
itsONled[1] = 0; // and set its state as off
} else { // else if first led is off
digitalWrite(led1, HIGH); // turn it on when the button is pressed
itsONled[1] = 1; // and set its state as on
}
break;
case button2:
if(itsONled[2] == 1) {
digitalWrite(led2, LOW);
itsONled[2] = 0;
} else {
digitalWrite(led2, HIGH);
itsONled[2] = 1;
}
break;
case button3:
if(itsONled[3] == 1) {
digitalWrite(led3, LOW);
itsONled[3] = 0;
} else {
digitalWrite(led3, HIGH);
itsONled[3] = 1;
}
break;
case button4:
if(itsONled[1] == 1) { 
digitalWrite(led4, LOW); 
itsONled[1] = 0; 
} else { 
digitalWrite(led4, HIGH); 
itsONled[1] = 1; 

}
break;
}

Serial.println(value); 
irrecv.resume(); // Receive the next value
}
}
