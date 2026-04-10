void setup() {
  Serial.begin(115200);
}

void loop() {
  char t = 0b01110100;
  char u = 0b01110101;
  char n = 0b01101110;
  char g = 0b01100111;

  Serial.print(t);
  Serial.print(u);
  Serial.print(n);
  Serial.println(g);

  delay(1000);
}
