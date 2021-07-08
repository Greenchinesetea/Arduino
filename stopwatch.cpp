#include <Event.h>
#include <Timer.h>
unsigned long T = 5000;
unsigned long timecounted = 0;
unsigned long timenow = 0;

int c = 0;
Timer t;
void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
  

}

void loop() {
  timenow = millis();
  t.update();
  int btn1 = digitalRead(3);
  int btn2 = digitalRead(4);
  if(btn1==0)
  {
    timecounted = millis();Serial.println(timecounted-timenow);
  }
  
  

}
