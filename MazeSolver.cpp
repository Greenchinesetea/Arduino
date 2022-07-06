
int distance1;
int distance2;
int distance3;
void setup() {
  pinMode(0, OUTPUT); //sensor1trig
  pinMode(1, OUTPUT); //sensor2trig
  pinMode(2, OUTPUT); //sensor3trig
  pinMode(3, INPUT); //sensor1echo
  pinMode(4, INPUT); //sensor2echo
  pinMode(5, INPUT); //sensor3echo
  //motors:
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}
//sensor1 vasate,sensor2 raste,sensor3 chap
void loop() {
  sensor1();
  sensor2();
  sensor3();
  if (distance1 > 5 and distance2 <= 5 and distance3 > 5) {
    right();
    delay(200);
  }
  else if (distance1 <= 5 and distance2 <= 5 and distance3 > 5) {
    right();
    delay(200);
  }
  else if (distance1 > 5 and distance2 > 5 and distance3 <= 5) {
    left();
    delay(200);
  }
  else if (distance1 <= 5 and distance2 > 5 and distance3 <= 5) {
    left();
    delay(200);
  }
  else if (distance1 <= 5 and distance2 > distance3 ) {
    backrotateleft();
    delay(200); 
  }
  else if (distance1 <= 5 and distance3 > distance2 ) {
    backrotateright();
    delay(200); 
  }
  else {
    forward();
    delay(200);
  }
}
void sensor1() {
  digitalWrite(0, LOW);
  delayMicroseconds(2);
  digitalWrite(0, HIGH);  
  delayMicroseconds(10);
  digitalWrite(0, LOW);
  long duration = pulseIn(3, HIGH);
  distance1 = duration * 0.017;
}
void sensor2() {
  digitalWrite(1, LOW);
  delayMicroseconds(2);
  digitalWrite(1, HIGH);
  delayMicroseconds(10);
  digitalWrite(1, LOW);
  long duration = pulseIn(4, HIGH);
  distance2 = duration * 0.017;
}
void sensor3() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  long duration = pulseIn(5, HIGH);
  distance3 = duration * 0.017;
}
void forward() {
  analogWrite(6, 225);
  analogWrite(9, 0);
  analogWrite(10, 225);
  analogWrite(11, 0);

}
void right() {
  analogWrite(6, 225);
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 180);
  delay(600);
}
void left() {
  analogWrite(6, 0);
  analogWrite(9, 180);
  analogWrite(10, 225);
  analogWrite(11, 0);
  delay(600);
}
void backrotateleft() {
  analogWrite(6, 0);
  analogWrite(9, 225);
  analogWrite(10, 0);
  analogWrite(11, 225);
  delay(800);
  left();
  delay(600);
}
void backrotateright() {
  analogWrite(6, 0);
  analogWrite(9, 225);
  analogWrite(10, 0);
  analogWrite(11, 225);
  delay(800);
  right();
  delay(600);
}
