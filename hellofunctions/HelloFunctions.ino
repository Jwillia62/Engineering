#include <Servo.h>
#include <NewPing.h>
const int trigPin = 8;
const int echoPin = 7;
Servo myservo;
int pos = 0;
void setup()
{
	Serial.begin(9600);
	myservo.attach(9);
}

void loop()
{
	long duration, inches, cm;
	pinMode(trigPin, OUTPUT);
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	pinMode(echoPin, INPUT);
	duration = pulseIn(echoPin, HIGH);
	inches = microsecondsToInches(duration);
	cm = microsecondsToCentimeters(duration);
	Serial.print(inches);
	Serial.print("in, ");
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();
	if (inches != 0)
	{
		if (inches <= 4)
		{
			sweep(3);
		}
		else
		{
			myservo.write(pos);
		}
		delay(100);
	}
}

long microsecondsToInches(long microseconds)
{
	return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
	return microseconds / 29 / 2;
}

void sweep(int NUM_OF_CYCLES)
{
	for (int j = 0; j < NUM_OF_CYCLES; j++)
		for (pos = 0; pos < 180; pos += 1)
		{
			myservo.write(pos);
			for (pos = 180; pos >= 1; pos -= 1)
			{
				myservo.write(pos);
				delay(2);
			}
		}
}
