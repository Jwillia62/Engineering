#include <Servo.h>

#include <NewPing.h> 

 
int trigPin = 8;
int echoPin = 7; 
int maxDist = 200; 
 
long duration;
int cm;
 
Servo myServo;
int servoPin = 9;
 
NewPing myHCSR04(trigPin, echoPin, maxDist);
 
 
void setup(){
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT); 
	Serial.begin(9600);
	myServo.attach(servoPin);
}
 
 
 
void loop(){
	cm = myHCSR04.ping_cm();
	if (cm != 0 && cm <150){ 
		if(cm < 10){
			moveServo(); 
		}
		else{
		stopServo();
		}
	Serial.println(cm);
	}
	delay(10);
} 
 
 
void moveServo(){
	myServo.write(180); 
}

 
 
void stopServo(){
	myServo.write(95); 
}