#define Error_IN 0
#define Switch_OUT 1
#define LED_OUT 2

void setup() {
  pinMode(Error_IN, INPUT);
  pinMode(Switch_OUT, OUTPUT);
  pinMode(LED_OUT, OUTPUT);
  digitalWrite(Switch_OUT, HIGH);
  digitalWrite(LED_OUT, LOW);
  delay(10000);
}

void loop() {
  if(digitalRead(Error_IN) == LOW){
    digitalWrite(Switch_OUT, LOW);
    digitalWrite(LED_OUT, HIGH);
    delay(1000);
    digitalWrite(Switch_OUT, HIGH);
    digitalWrite(LED_OUT, LOW);
    delay(10000);
  }
  delay(1);
}

/*動作シーケンス
 * 1.最初に電源が投入されると、マイコンの電源ON、setup()でSwitch_OUTがHIGHになる
 * 2.MDの電源がONになる。エラー信号が一瞬出力されるが、そのときはdelayで10秒間反応しない。
 * 3.MDからエラー信号が出力されると、Switch_OUTがLOWになり、1秒間MDの電源が切れる。
 * 4.MDが再起動する。エラー信号が一瞬出力されるが、そのときはdelayで10秒間反応しない。
 */
