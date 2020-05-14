#include <virtuabotixRTC.h> //|

#include "TM1637.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports       
#define DIO 3
TM1637 tm1637(2,3);
TM1637 tm1637alarm(8,9);
int8_t getal[] = {0x00,0x00,0x00,0x00};
int cijfers;
int uren;
int minuten;

 
// Creation of the Real Time Clock Object
//SCLK -> 6, I/O -> 7, CE -> 8
virtuabotixRTC myRTC(4, 5, 6);   //display op 2 en 
 
void setup() { 
pinMode(13,OUTPUT);
Serial.begin(9600);
cijfers=1234;
  tm1637.init();
  tm1637.set(4   );//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  
   tm1637alarm.init();
   tm1637alarm.set(4   );//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
 
// Set the current date, and time in the following format:
// seconds, minutes, hours, day of the week, day of the month, month, year
//myRTC.setDS1302Time(16, 25, 16, 6, 13, 6, 2014);

//Serial.println("jelle");
}
 
 
void loop() { 
// This allows for the update of variables for time or accessing the individual elements. 
myRTC.updateTime(); 
 

 
  getal[0]=myRTC.hours/10;
  getal[1]=myRTC.hours%10;
  getal[2]=myRTC.minutes/10;
  getal[3]=myRTC.minutes%10;
  
  //if (digitalRead(5)==HIGH){
  //  uren=map(analogRead(A1),0,1023,0,23);
  //  minuten=map(analogRead(A0),0,1023,0,59);
    
  //  myRTC.setDS1302Time(0, minuten, uren, 6, 13, 6, 2014);
       
    
 // }
    tm1637.display(getal);
    tm1637alarm.display(getal);
    
    
  if ((myRTC.hours==15) && (myRTC.minutes==41)){
      digitalWrite(13,HIGH);
  } 
  
  
  Serial.println(myRTC.seconds);
  //Serial.print("jelle");
}

