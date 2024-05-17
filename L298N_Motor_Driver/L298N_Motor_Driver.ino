
#define Lpwm_pin  5     
#define Rpwm_pin  6    
int pinLB=2;             
int pinLF=4;             
int pinRB=7;            
int pinRF=8;         

void setup()
{
  pinMode(pinLB,OUTPUT); 
  pinMode(pinLF,OUTPUT); 
  pinMode(pinRB,OUTPUT); 
  pinMode(pinRF,OUTPUT);
  pinMode(Lpwm_pin,OUTPUT);  
  pinMode(Rpwm_pin,OUTPUT);   
}


void loop()
{go_forward(100);
 delay(2000);
 go_backward(100);
 delay(2000);
 rotate_left(150);
 delay(2000);
 rotate_right(150);
 delay(2000);
 stopp();
 delay(2000);
 }


void go_forward(unsigned char speed_val)    
    {digitalWrite(pinRB,HIGH); 
     digitalWrite(pinRF,LOW);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,LOW);
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
     
      
    }

void go_backward(unsigned char speed_val)    
    {
     digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,LOW);  
     digitalWrite(pinLF,HIGH);
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
    }
   
void rotate_left(unsigned char speed_val)        
    {digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,LOW );  
     digitalWrite(pinLB,LOW); 
     digitalWrite(pinLF,HIGH);
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
      
     
    }
void rotate_right(unsigned char speed_val)    
    {
      digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,LOW);  
     analogWrite(Lpwm_pin,speed_val);
     analogWrite(Rpwm_pin,speed_val);
     
    }    
void stopp()        
    {
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,HIGH);
    }
