// LOW if reflecting 
//#include <Servo.h>
//Servo myservo;

#define LT_R digitalRead(4)  //10
#define LT_L digitalRead(2)   //2

#define ENA 11
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5

#define carSpeed 200

void forward(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW); 
 digitalWrite(IN3, LOW); 
 digitalWrite(IN4, HIGH); 
 Serial.println("go forward!");  
}   

void back(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH); 
 digitalWrite(IN3, HIGH); 
 digitalWrite(IN4, LOW); 
 Serial.println("go back");  
}

void left(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH); 
 digitalWrite(IN3, LOW); 
 digitalWrite(IN4, HIGH); 
 Serial.println("go left");  
}

void right(){
 analogWrite(ENA, carSpeed);
 analogWrite(ENB, carSpeed);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW ); 
 digitalWrite(IN3, HIGH ); 
 digitalWrite(IN4, LOW); 
 Serial.println("go right");  
}

void stop(){
 analogWrite(ENA, LOW);
 analogWrite(ENB, LOW);
  
 Serial.println("Stop");  
}

void setup(){
  Serial.begin(9600);
  pinMode(LT_R, INPUT);
  pinMode(LT_L, INPUT);
  }
void loop(){
   if((LT_R == 0) && (LT_L == 0)) {
      forward();
      }
   else if(LT_R == 1) {
      left();
      while(LT_R);
      }
   else if(LT_L == 1){
      right();
      while(LT_L);
      }
  }
  
