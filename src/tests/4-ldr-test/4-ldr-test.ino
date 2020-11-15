void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(analogRead(4));
  delay(100);
}
