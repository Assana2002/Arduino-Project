#include <IRremote.h>
int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define IR_Go      0x00ff629d
#define IR_Back    0x00ffa857
#define IR_Left    0x00ff22dd
#define IR_Right   0x00ffc23d
#define IR_Stop    0x00ff02fd
#define IR_ESC     0x00ff52ad
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
    { digitalWrite(backwardLED2, HIGH);
      digitalWrite(forwardLED1, LOW);
      digitalWrite(rightLED3, LOW);
      digitalWrite(leftLED4, LOW);
     
     digitalWrite(pinRB,LOW);  
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
    {digitalWrite(forwardLED1, LOW);
     digitalWrite(backwardLED2, LOW);
     digitalWrite(rightLED3, LOW);
     digitalWrite(leftLED4, LOW);
    
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,HIGH);
     
    }
         
void IR_Control(void)
{
   unsigned long Key;
   if(irrecv.decode(&results))  
 {
     Key = results.value;
    switch(Key)
     {
       case IR_Go:go_forward(150);   
       break;
       case IR_Back:go_backward(150);   
       break;
       case IR_Left:rotate_left(100);      
       break;
       case IR_Right:rotate_right(100); 
       break;
       case IR_Stop:stopp();   
       break;
       default: 
       break;      
     } 
     irrecv.resume(); 
    } 
  
}
void setup() 
{ 
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
   
   irrecv.enableIRIn(); 
   Serial.begin(9600);   
   stopp();  
}
void loop() 
{  
   
   IR_Control();
    
}
