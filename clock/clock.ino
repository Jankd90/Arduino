#include "TM1637.h"
#define CLK 5//pins definitions for TM1637 and can be changed to other ports       
#define DIO 6
TM1637 tm1637(CLK,DIO);
int t;

void setup() {
  Serial.begin(9600);
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  // put your setup code here, to run once:

}

int sec(int t){
  t = (t/1000);
  return t;
}


void loop() {
  tm1637.point(POINT_ON);
  Serial.println(t);
  tm1637.display(1,t);
  delay(50);
  // put your main code here, to run repeatedly:
}
