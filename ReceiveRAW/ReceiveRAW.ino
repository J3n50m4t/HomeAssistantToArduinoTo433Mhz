#define sprint Serial.print 
#define sprintln Serial.println
#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>


uint16_t RECV_PIN = 4;


IRrecv ir_receiver(RECV_PIN);
decode_results results;

void setup() {
    Serial.begin(115200);
    ir_receiver.enableIRIn(); // Start the receiver
}

void loop() {
   if (ir_receiver.decode(&results)) {
    dump(&results);
    ir_receiver.resume(); // Receive the next value
   }
}


void dump(decode_results *results) {
   int count = results->rawlen;   
   sprint("uint16_t raw[");
   sprint(count, DEC);
   sprint("] = {");
   for (int i = 1; i < count; i++) {
       sprint("0x");
       sprint((unsigned int)results->rawbuf[i], HEX);
       sprint(",");
    }
    sprint("};");
    sprintln("");
    sprint("irsend.sendRaw(raw,");
    sprint(count, DEC);
    sprint(",38);");
}
