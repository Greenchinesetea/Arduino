#include <Event.h>
#include <Timer.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
SoftwareSerial chuppy(4, 8); //rx arduino tx bl  / tx ard  rx bl
Timer t;
int compdata;
int bluedata;
int cl;
int cr;
long last_time = 0;
int left = 0;
int right = 0;
long period = 1000;
int one = 0;
void setup() {
  Serial.begin(9600);
  chuppy.begin(9600);
  pinMode(5, INPUT);//left sensor
  pinMode(7, INPUT);//right sensor
  pinMode(2, INPUT);//left COUNTER
  pinMode(3, INPUT);//RIGHT COUNTER
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  attachInterrupt(0, leftcount, FALLING);
  attachInterrupt(1, rightcount, FALLING);
  t.every(period, counterresult);

}

void loop() {
  t.update();
  int s1 = digitalRead(5);
  int s2 = digitalRead(7);
  if (chuppy.available()) {
    int reads = chuppy.read();
    Serial.println(reads);
    if (reads = 49) {
      one = 1;
    }
    Serial.println(one);
  }
  if (one == 1) {
    if (s1 == 1 && s2 == 1)
    {
      nomove();
        chuppy.print("sum: ");
        chuppy.println(left + right);
        Serial.end();
        chuppy.end();
    }
    else if (s1 == 0 && s2 == 1)
    {
      leftmove();
    }
    else if (s1 == 1 && s2 == 0)
    {
      rightmove();
    }
    else
    {
      forward();
    }
  }

}
void forward() {
  analogWrite(6, 225);
  analogWrite(9, 0);
  analogWrite(10, 225);
  analogWrite(11, 0);

}
void nomove() {
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
void rightmove() {
  analogWrite(6, 225);
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 180);
}
void leftmove() {
  analogWrite(6, 0);
  analogWrite(9, 180);
  analogWrite(10, 225);
  analogWrite(11, 0);
}
void leftcount()
{
  if (millis() - last_time >= 100) {
    last_time = millis();
    left++;
    EEPROM.write(0,left);
  }
  
}
void rightcount()
{
  if (millis() - last_time >= 100) {
    last_time = millis();
    right++;
    EEPROM.write(50,right);
  }
  
}
void counterresult()
{

  chuppy.print("L: ");
  chuppy.println(left);
  chuppy.print("R: ");
  chuppy.println(right);

}
