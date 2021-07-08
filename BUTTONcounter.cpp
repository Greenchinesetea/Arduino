int number = 0;
int sped = 110;
void setup() {
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT); //ENB
  pinMode(8, INPUT_PULLUP); //btn
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void count(){
  int x = digitalRead(8);
  if(x==0){
    number++;
    Serial.println(number);
    delay(300);
  }
}
