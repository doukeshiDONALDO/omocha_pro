#include <FlexiTimer2.h>

const int buttonPin0 = 10;     // スイッチピン
const int buttonPin1 = 11;     // スイッチピン
const int buttonPin2 = 12;     // スイッチピン

const int buttonPin3 = 13;     // スイッチピン
const int buttonPin4 = 14;     // スイッチピン
const int buttonPin5 = 15;     // スイッチピン

const int ledPincom_r =  7;      // LEDカソードコモンのR
const int ledPincom_g =  8;      // LEDカソードコモンのG
const int ledPincom_b =  9;      // LEDカソードコモンのB

const int ledPin_0 =  0;      // 三色LED0
const int ledPin_1 =  1;      // 三色LED1
const int ledPin_2 =  2;      // 三色LED2
const int ledPin_3 =  3;      // 三色LED3
const int ledPin_4 =  4;      // 三色LED4
const int ledPin_5 =  5;      // 三色LED5

const int d_time = 400;     // delay time ms

//点灯パターン
int pattern[6][3] = {
  {0, 0, 1}, //一つのLEDの各R, G, BのON or OFF
  {0, 1, 0}, //一つのLEDの各R, G, BのON or OFF
  {1, 0, 0}, //一つのLEDの各R, G, BのON or OFF

  {0, 0, 1}, //一つのLEDの各R, G, BのON or OFF
  {0, 1, 0}, //一つのLEDの各R, G, BのON or OFF
  {1, 0, 0} //一つのLEDの各R, G, BのON or OFF

};

unsigned int cnt = 0;

int buttonState0 = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

unsigned int tmp_s;

void swap(int a, int b){
  tmp_s = pattern[a][0];
  pattern[a][0] = pattern[b][0];
  pattern[b][0] = tmp_s;

  tmp_s = pattern[a][1];
  pattern[a][1] = pattern[b][1];
  pattern[b][1] = tmp_s;

  tmp_s = pattern[a][2];
  pattern[a][2] = pattern[b][2];
  pattern[b][2] = tmp_s;  
}

void flash() {
  digitalWrite(cnt, HIGH);

  if (++cnt >= 6)
    cnt = 0;

  digitalWrite(cnt, LOW);
  digitalWrite(ledPincom_r, pattern[cnt][0]);
  digitalWrite(ledPincom_g, pattern[cnt][1]);
  digitalWrite(ledPincom_b, pattern[cnt][2]);
}

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin_0, OUTPUT);
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  pinMode(ledPin_4, OUTPUT);
  pinMode(ledPin_5, OUTPUT);


  pinMode(ledPincom_r, OUTPUT);
  pinMode(ledPincom_g, OUTPUT);
  pinMode(ledPincom_b, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);

  for (int i = 0; i < 6; i++)
    digitalWrite(i, HIGH);

  FlexiTimer2::set(2, flash); // MsTimer2 style is also supported
  FlexiTimer2::start();

}

void loop() {
  // read the state of the pushbutton value:
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);

  if (buttonState0 == HIGH && buttonState1 == HIGH && buttonState2 == HIGH) {
    delay(d_time);
  } else if (buttonState0 == HIGH && buttonState1 == HIGH && buttonState2 == LOW) {
    swap(0,1);
    delay(d_time);
  }
  else if (buttonState0 == LOW && buttonState1 == HIGH && buttonState2 == HIGH) {
    swap(1,2);
    delay(d_time);
  }
  else if (buttonState0 == HIGH && buttonState1 == LOW && buttonState2 == HIGH) {
    swap(0,2);
    delay(d_time);
  }

  if (buttonState3 == HIGH && buttonState4 == HIGH && buttonState5 == HIGH) {
    delay(d_time);
  } else if (buttonState3 == HIGH && buttonState4 == HIGH && buttonState5 == LOW) {
    swap(3,4);
    delay(d_time);
  }
  else if (buttonState3 == LOW && buttonState4 == HIGH && buttonState5 == HIGH) {
    swap(4,5);
    delay(d_time);
  }
  else if (buttonState3 == HIGH && buttonState4 == LOW && buttonState5 == HIGH) {
    swap(3,5);
    delay(d_time);
  }

}
