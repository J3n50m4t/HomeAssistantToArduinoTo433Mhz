

void setupIR(){
  irsend.begin();
}

void callcase54(){
  irsend.sendSony(0xA81, 12);
  delay(200);
  irsend.sendSony(0xA81, 12);
  delay(200);
  irsend.sendSony(0xA81, 12);
  delay(200);
  Serial.println("SonyAnlage Angeschaltet 3x send A81"); 
}
