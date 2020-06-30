#include <Servo.h>
Servo myservo;
int pos = 20;
const int trigPin = 5;
const int echoPin = 6;
const int led = 13;
long duration, time;
float distance;  // distanta de la care act serverul cred
void setup()
{
  myservo.attach(11);   //servomotorul e atasat pe pinul 11
  pinMode(trigPin, OUTPUT);  // trigpin ia iesirea (face actiune)
  pinMode(echoPin, INPUT);   // echopin ia intrarea
  pinMode(led, OUTPUT);    // ledul e tot pe iesire (face actiune)
  myservo.write(pos);   // e pe poztia 20 la inceput?
}
void loop()
{
  //Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * (duration / 2);
  //Serial.println(distance);

  if (distance < 27)
  {
    time = millis(); //daca pui mana dupa 10 secunde se misca
    while (millis() < time+10000)
    {
      digitalWrite(1,HIGH);
    }

    digitalWrite(led, HIGH);
    myservo.write(pos + 160);
    delay(1000);
  }
  else
  {
    digitalWrite(led, LOW);
    myservo.write(pos);
  }
  delay(300);  // inainte de fiecare loop intarzie putin procesul
}
