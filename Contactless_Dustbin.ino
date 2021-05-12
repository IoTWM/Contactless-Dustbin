/**********************************************************************************
 *  TITLE: Blinking a LED using Blink App and ESP8266
 *  Click on the following links to learn more. 
 *  YouTube Video: https://www.youtube.com/channel/UCscQZ6FyFrx3dKgsPSPOVGQ
 *  by IoT withme
 *  Github link :
 *  https://github.com/IoTWM
 **********************************************************************************/

#include <Servo.h>    //library for Servo Motor

const int trigP = 6;  
const int echoP = 5;  

long duration;
int distance;

int servoPin =  3;     
Servo Servo1; 

void setup() 
{ 
   Servo1.attach(servoPin); 
   pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
   pinMode(echoP, INPUT);   // Sets the echoPin as an Input
   Serial.begin(9600);      // Open serial channel at 9600 baud rate
}

void loop()
{ 

digitalWrite(trigP, LOW);   // Makes trigPin low
delayMicroseconds(2);       // 2 micro second delay 

digitalWrite(trigP, HIGH);  // tigPin high
delayMicroseconds(10);      // trigPin high for 10 micro seconds
digitalWrite(trigP, LOW);   // trigPin low

duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
distance= duration*0.034/2;        //Calculating actual/real distance

if(distance<10)
 {
  Serial.print("Distance = ");        //Output distance on arduino ide serial monitor 
  Serial.println(distance);
  Servo1.write(180); 
  delay(5000);
 }

else
 {
 Serial.print("Distance = ");        //Output distance on arduino ide serial monitor 
 Serial.println(distance);
 delay(1000);
 Servo1.write(0); 
 delay(1000);
 }

}
