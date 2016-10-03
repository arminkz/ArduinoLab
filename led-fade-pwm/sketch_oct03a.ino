//Fade LED (Manual PWM)
//Created By : Armin Kazemi

int brightness = 0;
int delta = 1;
int counter = 1;

void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
  if(counter > 10){
    counter = 0;
    brightness += delta;
    if(brightness == 0 || brightness == 10){
      delta *= -1;
    }
  }else{
    digitalWrite(13,HIGH);
    delay(brightness);
    digitalWrite(13,LOW);
    delay(10-brightness);
    counter++;
  }
}
