
#include <Servo.h>
#include <Servo.h>
Servo myservo;
int Echo_Pin=A0;  
int Trig_Pin=A1;  
#define Lpwm_pin  5     
#define Rpwm_pin  6    
int pinLB=2;             
int pinLF=4;             
int pinRB=7;            
int pinRF=8;   
const int forwardLED1 = 10;
const int backwardLED2 = 11;
const int rightLED3 = 9;
const int leftLED4 = 3;
volatile int D_mix;
volatile int D_mid;
volatile int D_max;
volatile int Front_Distance;
volatile int Left_Distance;
volatile int Right_Distance;
volatile int Right_IR_Value;
volatile int Left_IR_Value;

float checkdistance() {
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);
  float distance = pulseIn(Echo_Pin, HIGH) / 58.00;
  delay(10);
  return distance;
}

void Detect_Left_and_Right__distance() {
  myservo.write(180);
  delay(400);
  Left_Distance = checkdistance();
  delay(600);
  Serial.print("Left_Distance:");
  Serial.println(Left_Distance);
  myservo.write(0);
  delay(400);
  Right_Distance = checkdistance();
  delay(600);
  Serial.print("Right_Distance:");
  Serial.println(Right_Distance);
  myservo.write(90);
}

void Ultrasonic_obstacle_avoidance()
{
  Front_Distance=checkdistance(); 
  if((Front_Distance < 20)&&(Front_Distance > 0))
{
    stopp();
    delay(100);
    myservo.write(180);
    delay(500);
    Left_Distance=checkdistance();
    delay(100);
    myservo.write(0);
    delay(500);
    Right_Distance=checkdistance();
    delay(100);
if(Left_Distance > Right_Distance)
    {
      rotate_left(150);
      myservo.write(90);
      delay(300); 
    }
    else 
    {
      rotate_right(150);
      myservo.write(90);
      delay(300); 
    }
  }
  else
  {
    go_forward(100);
  }
}






void Obstacle_Avoidance_Main() 
{
  Ultrasonic_obstacle_avoidance();
}



void setup(){
  myservo.attach(A2);
  Serial.begin(9600);
  D_mix = 10;
  D_mid = 20;
  D_max = 100;
  Front_Distance = 0;
  Left_Distance = 0;
  Right_Distance = 0;
  myservo.write(90);
  pinMode(Echo_Pin, INPUT);      
  pinMode(Trig_Pin, OUTPUT);    
  pinMode(pinLB,OUTPUT); 
  pinMode(pinLF,OUTPUT); 
  pinMode(pinRB,OUTPUT); 
  pinMode(pinRF,OUTPUT);  
  pinMode(Lpwm_pin,OUTPUT);   
  pinMode(Rpwm_pin,OUTPUT);  
  pinMode(forwardLED1, OUTPUT);
  pinMode(backwardLED2, OUTPUT);
  pinMode(rightLED3, OUTPUT); 
  pinMode(leftLED4, OUTPUT); 
    
}

void loop(){
  Obstacle_Avoidance_Main();

}



void go_forward(unsigned char speed_val)    
    {digitalWrite(forwardLED1, HIGH);
     digitalWrite(backwardLED2, LOW);
     digitalWrite(rightLED3, LOW);
     digitalWrite(leftLED4, LOW);
     
     digitalWrite(pinRB,HIGH); 
     digitalWrite(pinRF,LOW);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,LOW);
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
     
      
    }

void go_backward(unsigned char speed_val)    
    {digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,LOW);  
     digitalWrite(pinLF,HIGH);
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
    }
    
void rotate_left(unsigned char speed_val)        
    {digitalWrite(leftLED4, HIGH);
     digitalWrite(rightLED3, LOW);
     digitalWrite(forwardLED1, LOW);
     digitalWrite(backwardLED2, LOW);
      
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,LOW );  
     digitalWrite(pinLB,LOW); 
     digitalWrite(pinLF,HIGH);
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
      
     
    }
void rotate_right(unsigned char speed_val)   
    {digitalWrite(rightLED3, HIGH);
     digitalWrite(leftLED4, LOW);
     digitalWrite(forwardLED1, LOW);
     digitalWrite(backwardLED2, LOW);
     
     digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,LOW);  
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
     
    }    
void stopp()        
    {digitalWrite(backwardLED2, HIGH);
     digitalWrite(forwardLED1, LOW);
     digitalWrite(rightLED3, LOW);
     digitalWrite(leftLED4, LOW);
     
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,HIGH);
    }
