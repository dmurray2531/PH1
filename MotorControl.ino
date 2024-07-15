#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int sensorPin = A5; //define pot pin
int sensorValue = 0;  // variable to store the value coming from the sensor
int RawSensorValue = 0;  // variable to store the value coming from the sensor

void setup() 
{
  Serial.begin(9600);
  
  myservo.attach(6);  // attaches the servo on pin 6 to the servo object
  myservo.write(95);
  delay(5000);
}

void loop()
{
  RawSensorValue = analogRead(sensorPin);
  Serial.print(RawSensorValue);
  Serial.print(" , ");
  sensorValue = map(RawSensorValue, 0, 1023, 95, 160);
  Serial.println(sensorValue);
  delay(50);
  myservo.write(sensorValue);
  //delay(50);
}

//slow rangge is 100 to 157
//stopped is 94 to 97
//backwoard is 91 to 47


/*void loop() {
  for (pos = 100; pos <= 254; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(500);                       // waits 20ms for the servo to reach the position
  }
  for (pos = 254; pos >= 0; pos -= 1) 
  { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(500);                       // waits 20ms for the servo to reach the position
  }
}*/

/*for (pos = 100; pos <= 254; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(500);                       // waits 20ms for the servo to reach the position
  }
  for (pos = 254; pos >= 0; pos -= 1) 
  { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(500);                       // waits 20ms for the servo to reach the position
  }*/