#include <TM1637Display.h>

const int clk = 2, dio = 3, trig = 4, echo = A0;
TM1637Display ds = TM1637Display(clk, dio);

void setup() {
  // put your setup code here, to run once:
  ds.clear();
  ds.setBrightness(7);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  long long x = pulseIn(echo, HIGH);
  if(x >= 10000) digitalWrite(LED_BUILTIN, HIGH);
  else digitalWrite(LED_BUILTIN, LOW);
  ds.showNumberDec(x);
}
