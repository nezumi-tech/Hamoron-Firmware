#define Error_IN 0
#define Switch_OUT 1
#define LED_OUT 2

void setup() {
  pinMode(Error_IN, INPUT);
  pinMode(Switch_OUT, OUTPUT);
  pinMode(LED_OUT, OUTPUT);
  digitalWrite(Switch_OUT, HIGH);
  digitalWrite(LED_OUT, LOW);
  flash_LED_10sec();
}

void flash_LED_10sec() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_OUT, HIGH);
    delay(500);
    digitalWrite(LED_OUT, LOW);
    delay(500);
  }
}

void flash_LED_1sec() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_OUT, HIGH);
    delay(100);
    digitalWrite(LED_OUT, LOW);
    delay(100);
  }
}

void loop() {
  if (digitalRead(Error_IN) == LOW) {
    digitalWrite(Switch_OUT, LOW);
    digitalWrite(LED_OUT, HIGH);
    flash_LED_1sec();
    digitalWrite(Switch_OUT, HIGH);
    digitalWrite(LED_OUT, LOW);
    flash_LED_10sec();
  }
  delay(1);
}

/*動作シーケンス
   1.最初に電源が投入されると、マイコンの電源ON、setup()でSwitch_OUTがHIGHになる
   2.MDの電源がONになる。エラー信号が一瞬出力されるが、そのときはdelayで10秒間反応しない。
   3.MDからエラー信号が出力されると、Switch_OUTがLOWになり、1秒間MDの電源が切れる。
   4.MDが再起動する。エラー信号が一瞬出力されるが、そのときはdelayで10秒間反応しない。
*/
