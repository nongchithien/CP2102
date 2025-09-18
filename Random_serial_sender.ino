#include <Arduino.h>

void setup() {
  Serial.begin(9600);  // tốc độ baud phải trùng với phía PC
}

void loop() {
  Serial.println("Hello ");
  delay(500);
}
