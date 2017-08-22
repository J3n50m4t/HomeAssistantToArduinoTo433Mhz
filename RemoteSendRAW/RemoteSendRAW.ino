#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "rawcodes.h"
IRsend irsend(4);  // An IR LED is controlled by GPIO pin 4 (D2)
int counter = 0;

uint16_t rawData[67] = {+9024 -4512 +564 -564 +564 -564 +564 -564 +564 -564 +564 -564 +564 -564 +564 -1692 +564 -564 +564 -1692 +564 -1692 +564 -1692 +564 -1692 +564 -1692 +564 -1692 +564 -564 +564 -1692 +564 -564 +564 -564 +564 -564 +564 -564 +564 -1692 +564 -564 +564 -564 +564 -564 +564 -1692 +564 -1692 +564 -1692 +564 -1692 +564 -564 +564 -1692 +564 -1692 +564 -1692 +564 -39756};

void setup() {
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
}

void loop() {
  counter++;
  Serial.print("raw  #");
  Serial.print(counter);
  Serial.println("");
  irsend.sendRaw(raw, 68, 38);  // Send a raw data capture at 38kHz.
  delay(200);
}
