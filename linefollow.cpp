//line follower robot using 2 IR sensors.
int s1;
int s2;
void setup() {
  pinMode(5, INPUT);//left sensor
  pinMode(7, INPUT);//right sensor
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  s1 = digitalRead(5);
  s2 = digitalRead(7);
  if (s1 == 1 && s2 == 1)
  {
    nomove();
  }
  else if(s1==0 && s2 == 1)
  {
    left();
  }
  else if(s1==1 && s2 == 0)
  {
    right();
  }
  else
  {
    forward();
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
void right() {
  analogWrite(6, 225);
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 110);
}
void left() {
  analogWrite(6, 0);
  analogWrite(9, 110);
  analogWrite(10, 225);
  analogWrite(11, 0);
}
