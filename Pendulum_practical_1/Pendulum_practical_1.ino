/* Include the library */
#include "HCMotor.h"

/* Pins used to drive the motors */
#define MOTOR_PINA 8 //For HCMODU0033 connect to A-IA, for HCARDU0013 connect to IN1
#define MOTOR_PINB 9 //For HCMODU0033 connect to A-IB, for HCARDU0013 connect to IN2
int incomingByte = 0;
int tik = 0;
int dif = 2000;
int d, on, speed = 0;
/* Create an instance of the library */
HCMotor HCMotor;
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  /* Initialise the library */
  HCMotor.Init();
  Serial.begin(115200);
  /* Attach motor 0 to digital pins 8 & 9. The first parameter specifies the 
     motor number, the second is the motor type, and the third and forth are the 
     digital pins that will control the motor */
  HCMotor.attach(0, DCMOTOR_H_BRIDGE, MOTOR_PINA, MOTOR_PINB);
  /* Set the duty cycle of the PWM signal in 100uS increments. 
     Here 100 x 100uS = 1mS duty cycle. */
  HCMotor.DutyCycle(0, 100);
}

void loop() 
{
if (Serial.available() > 0) {
    // read the incoming byte:
    int incomingByte = Serial.parseInt();
    Serial.println("byte");
    Serial.println(incomingByte);
    
    if(incomingByte > 0){
      if((incomingByte/10000)-1 == 0){
        d = REVERSE; 
        on = (incomingByte % 10000);
        speed = incomingByte %100;
        }
      else{
        d = FORWARD;
        on = (incomingByte % 20000);
        speed = incomingByte %100; 
      }
       HCMotor.Direction(0, d);
    HCMotor.OnTime(0,200);
    delay(on); 
    HCMotor.OnTime(0,0);
      }
     
    // say what you got:
    Serial.println("ON");
    Serial.println(on);
    Serial.println("Speed");
    Serial.println(speed);
    digitalWrite(LED_BUILTIN, HIGH);
    
    digitalWrite(LED_BUILTIN, LOW);
      
      }
    


}
