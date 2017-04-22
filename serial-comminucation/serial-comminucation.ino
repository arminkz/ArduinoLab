//Serial Comminucation Example
//Created By : Armin Kazemi

void setup() {
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);

  Serial.begin(57600);
  while(!Serial){
    ;
  }
  Serial.write("HELLO ! IM HERE");
}

int n =0;
int arr[6] = {6,7,8,10,11,12};
int arr2[6] = {12,6,7,8,10,11};

void loop() {
  delay(80);
  turnoff();
  digitalWrite(arr[n],HIGH);
  digitalWrite(arr2[n],HIGH);
  n = (n+1) % 6;
  //Serial.write(arr[n]);
}

void turnoff(){
  for(int i=5;i<13;i++){
    digitalWrite(i,LOW);
  }
}

void printNum(int n){
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

