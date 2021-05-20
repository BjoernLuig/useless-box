#include <Servo.h>



int pinDeckel = 9;
int pinPfote = 6;
//Pin 5 doesnt work
int pinLever = 3;
Servo servoDeckel;
Servo servoPfote;
int numberActions = 10;
int n = 0; // default action index
int minDeckel = 25;
int maxDeckel = 70;
int minPfote = 0;
int maxPfote = 155;



void setup() {
  Serial.begin(9600);
  Serial.println("Setup ");
  pinMode(pinLever,INPUT_PULLUP);
}



void loop() {
  if(digitalRead(pinLever) == LOW) {
    Serial.println("Do something");
    action();
  }
  else Serial.println("Do nothing");
  delay(1000);
}



void openDeckel() {
  servoDeckel.attach(pinDeckel);
  servoDeckel.write(maxDeckel);
  delay(200);
}
void closeDeckel() {
  servoDeckel.write(minDeckel);
  delay(300);
  servoDeckel.detach();
}
void openDeckelSlow() {
  servoDeckel.attach(pinDeckel);
  for(int i = minDeckel; i <= maxDeckel; i++) {
    servoDeckel.write(i);
    delay(30);
  }
}
void closeDeckelSlow() {
  for(int i = maxDeckel; i >= minDeckel; i--) {
    servoDeckel.write(i);
    delay(30);
  }
  servoDeckel.detach();
}
void fakeDeckel() {
  servoDeckel.attach(pinDeckel);
  servoDeckel.write((maxDeckel+minDeckel)/2);
  delay(500);
  servoDeckel.write(minDeckel);
  delay(100);
  servoDeckel.detach();
}



void openPfote() {
  servoPfote.attach(pinPfote);
  servoPfote.write(maxPfote);
  delay(300);
}
void closePfote() {
  servoPfote.write(minPfote);
  delay(300);
  servoPfote.detach();
}
void fakePfote() {
  servoPfote.attach(pinPfote);
  servoPfote.write((maxPfote+minPfote)/2);
  delay(500);
  servoPfote.write(minPfote);
  delay(300);
  servoPfote.detach();
  }



void action() {
  n = random(numberActions);  // random n
  Serial.print("Do action number ");
  Serial.println(n);
  delay(400);
  switch(n) {
    case 0:
      openDeckel();
      openPfote();
      closePfote();
      closeDeckel();
      break;
    case 1:
      openDeckelSlow();
      delay(500);
      openPfote();
      closePfote();
      delay(500);
      closeDeckelSlow();
      break;
    case 2:
      openDeckelSlow();
      delay(1000);
      closeDeckel();
      delay(1000);
      openDeckelSlow();
      delay(500);
      openPfote();
      delay(500);
      closePfote();
      closeDeckel();
      break;
    case 3:
      openDeckel();
      delay(3000);
      closeDeckelSlow();
      delay(3000);
      openDeckel();
      openPfote();
      closePfote();
      closeDeckel();
      break;
    case 4:
      delay(5000);
      openDeckel();
      openPfote();
      closePfote();
      closeDeckel();
      break;
    case 5:
      delay(500);
      fakeDeckel();
      delay(500);
      openDeckel();
      openPfote();
      closePfote();
      closeDeckel();
      break;
    case 6:
      openDeckel();
      delay(1000);
      fakePfote();
      delay(1000);
      openPfote();
      closePfote();
      closeDeckel();
      break;
    case 7:
      delay(1000);
      openDeckelSlow();
      delay(500);
      openPfote();
      delay(500);
      closePfote();
      delay(500);
      closeDeckel();
      delay(500);
      openDeckel();
      closeDeckel();
      break;
    case 8:
      openDeckel();
      fakePfote();
      delay(500);
      closeDeckel();
      delay(1000);
      openDeckel();
      openPfote();
      closePfote();
      closeDeckel();
      break;
    case 9:
      fakeDeckel();
      delay(1000);
      fakeDeckel();
      delay(1000);
      openDeckel();
      openPfote();
      closePfote();
      delay(1000);
      closeDeckel();
      break;
    default:
      break;
  }
}
