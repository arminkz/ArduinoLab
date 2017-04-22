//Bomb Countdown With Sound Effects
//Created By : Armin Kazemi

int n = 9;

void setup() {
  pinMode(12,OUTPUT); // 7 Segment 
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(4,OUTPUT); //Buzzer 
}

int mode = 1; // 1 loading 2 count down
int halt = 0;

void loop() {
  if(!halt){
    turnoff();
    
    printNum();
    n--;
    if (n==-1) halt = 1;
    if(n==-1)
    digitalWrite(4,HIGH);
    else if(n<=1){
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
    }else if(n <= 4){
    digitalWrite(4,HIGH);
    delay(250);
    digitalWrite(4,LOW);
    delay(250);
    digitalWrite(4,HIGH);
    delay(250);
    digitalWrite(4,LOW);
    delay(250);
    }else{
    digitalWrite(4,HIGH);
    delay(300);
    digitalWrite(4,LOW);
    delay(700);
    }

    
  }
}

void turnoff(){
  for(int i=5;i<13;i++){
    digitalWrite(i,LOW);
  }
}

void printNum(){
  switch(n){
    case 0:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 1:
      digitalWrite(12,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 2:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(7,HIGH);
      break;
    case 3:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 4:
      digitalWrite(12,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 5:
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 6:
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 7:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 8:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 9:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      break;
  }
}

