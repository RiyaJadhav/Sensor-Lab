// Servo library supports servos on only two pins 9 and 10


#include <Servo.h>
Servo myservo;

int Echo = 0;
int Trig = 1;

#define ENA 11
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5

#define carSpeed 200
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void forward(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW); 
 digitalWrite(IN3, LOW); 
 digitalWrite(IN4, HIGH); 
 Serial.println("Forward");  
}

void back(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH); 
 digitalWrite(IN3, HIGH); 
 digitalWrite(IN4, LOW); 
 Serial.println("Back");  
}

void left(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH); 
 digitalWrite(IN3, LOW); 
 digitalWrite(IN4, HIGH); 
 Serial.println("Left");  
}

void right(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW ); 
 digitalWrite(IN3, HIGH ); 
 digitalWrite(IN4, LOW); 
 Serial.println("Right");  
}

void stop(){
 analogWrite(ENA, LOW);
 analogWrite(ENB, LOW);
  
 Serial.println("Stop");  
}

int Distance_test(){
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance /58;
  return (int)Fdistance;
}

void setup(){
  myservo.attach(10);  //attach servo on pin 10 to servo object
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop(); 
}
void loop(){
  myservo.write(90);
  delay(500);
  middleDistance = Distance_test();

  if(middleDistance <= 20) {
    stop();
    delay(500);
    myservo.write(10);
    delay(1000);
    rightDistance = Distance_test();

    delay(500);
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    leftDistance = Distance_test();

    delay(500);
    myservo.write(90);
    delay(1000);
    if(rightDistance > leftDistance) {
      right();
      delay(360);
    }
    else if(rightDistance < leftDistance) {
      left();
      delay(360);
    }
    else if((rightDistance <= 20) || (leftDistance <= 20)){
      back();
      delay(180);
    }
    else {
      forward();
    }
  }
  else{
    forward();
  }
}
