#include <Servo.h>  
#define trigPin 3  
#define echoPin 2  
Servo servo;  
// int sound = 250; 
int pos = 0;  
int led = 5;
void setup() {  
Serial.begin (9600);  
pinMode(led, OUTPUT);
pinMode(trigPin, OUTPUT);  
pinMode(echoPin, INPUT);  
servo.attach(4);  
}  
void loop() {  
long duration, distance; 
 
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPin, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPin, LOW);  
duration = pulseIn(echoPin, HIGH);  
distance = (duration/2) / 29.1;  
if (distance < 10) {  
Serial.println("the distance is less than 10");  
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);  
    digitalWrite(led, HIGH);// tell servo to go to position in variable 'pos'
    delay(5
    );                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos); 
    digitalWrite(led, LOW);// tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  } 
}  
else {  
servo.write(0);  
}  
if (distance > 60 || distance <= 0){  
Serial.println("The distance is more than 60");  
}  
else {  
Serial.print(distance);  
Serial.println(" cm");  
}  
delay(500);  
}     
