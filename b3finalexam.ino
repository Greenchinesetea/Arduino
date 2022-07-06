int distance1;
void setup() {
  pinMode(0, OUTPUT); //sensor1trig
  pinMode(1, INPUT); //sensor2echo
  pinMode(7, INPUT); //BUTTON SPEED
  pinMode(8, INPUT); //BUTTON MODE
  pinMode(2, INPUT); //irs1
  pinMode(3, INPUT); //irs2
  pinMode(4, INPUT); //irs3
  pinMode(5, INPUT); //irs4
  //motors:
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

}
//sensor1 vasate,sensor2 raste,sensor3 chap
void loop() {
  sensor1();
  int bm = digitalRead(8);
  int m;
  int bs = digitalRead(7);
  int s;
  if (bm == 1 and m <= 3) {
    m++;
    delay(50);
  }
  else {
    m = 0;
  }
  if (bs == 1 and s <= 2) {
    s++;
    delay(150);
  }
  else {
    s = 0;
  }
  Serial.println(s);
  Serial.println(m);
  if (m == 1 and s == 1) {
    linefollowHS();

  }
  else if (m == 1 and s == 2) {
    linefollowLS();

  }
  else if (m == 2 and s == 1) {
    //maze
    if (distance1 <= 8) {
      backrotateright(0, 255, 0, 255);
    }
    else {
      forward(255, 0, 255, 0);
    }
  }
  else if (m == 2 and s == 2) {
    if (distance1 <= 8) {
      backrotateright(0, 110, 0, 110);
    }
    else {
      forward(110, 0, 110, 0);
    }
  }
  else if (m == 3) {
    nomove();
  }
  else {
    nomove();
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
void forward(int six, int nine, int ten, int eleven) {
  analogWrite(6, six);
  analogWrite(9, nine);
  analogWrite(10, ten);
  analogWrite(11, eleven);
  //255 0 255 0

}
void right(int six, int nine, int ten, int eleven) {
  analogWrite(6, six);
  analogWrite(9, nine);
  analogWrite(10, ten);
  analogWrite(11, eleven);
}
void left(int six, int nine, int ten, int eleven) {
  analogWrite(6, six);
  analogWrite(9, nine);
  analogWrite(10, ten);
  analogWrite(11, eleven);
}
void backrotateleft(int six, int nine, int ten, int eleven) {
  analogWrite(6, six);
  analogWrite(9, nine);
  analogWrite(10, ten);
  analogWrite(11, eleven);
  delay(800);
  left(0, 180, 225, 0);
  delay(600);
}
void backrotateright(int six, int nine, int ten, int eleven) {
  analogWrite(6, six);
  analogWrite(9, nine);
  analogWrite(10, ten);
  analogWrite(11, eleven);
  delay(800);
  right(255, 0, 0, 180);
  delay(600);
}
void nomove() {
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
void linefollowHS() {
  int s1;
  int s2;
  int s3;
  int s4;
  s1 = digitalRead(2);
  s2 = digitalRead(3);
  s3 = digitalRead(4);
  s4 = digitalRead(5);
  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1)) {
   nomove();
  }
  else if ((s1 == 0 ) && (s2 == 0) && (s3 == 1)&& (s4 == 0)) {
   right(255, 0, 0, 180);

    
  }
  else if ((s1 == 0 ) && (s2 == 0)&& (s3 == 0) && (s4 == 1)) {
    right(255, 0, 0, 180);

  
  }
  else if ((s1 == 0 ) && (s2 == 0)&& (s3 == 1) && (s4 == 1)) {
    right(255, 0, 0, 180);

    
  }
  else if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0)) {
    left(0, 180, 225, 0);
    
  }
  else if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0)) {
    left(0, 180, 225, 0);
    
  }
  else if ((s1 == 0) && (s2 == 1)&& (s3 == 0) && (s4 == 0)) {
    left(0, 180, 225, 0);
    
  }
  else {
    forward(255,0,255,0);
  }
}
void linefollowLS() {
  int s1;
  int s2;
  int s3;
  int s4;
  s1 = digitalRead(2);
  s2 = digitalRead(3);
  s3 = digitalRead(4);
  s4 = digitalRead(5);
  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1)) {
   nomove();
  }
  else if ((s1 == 0 ) && (s2 == 0) && (s3 == 1)&& (s4 == 0)) {
   right(255, 0, 0, 180);

    
  }
  else if ((s1 == 0 ) && (s2 == 0)&& (s3 == 0) && (s4 == 1)) {
    right(255, 0, 0, 180);

  
  }
  else if ((s1 == 0 ) && (s2 == 0)&& (s3 == 1) && (s4 == 1)) {
    right(255, 0, 0, 180);

    
  }
  else if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0)) {
    left(0, 180, 225, 0);
    
  }
  else if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0)) {
    left(0, 180, 225, 0);
    
  }
  else if ((s1 == 0) && (s2 == 1)&& (s3 == 0) && (s4 == 0)) {
    left(0, 180, 225, 0);
    
  }
  else {
    forward(110,0,110,0);
  }
}
