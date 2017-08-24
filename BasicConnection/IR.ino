

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
  Serial.println("SonyAnlage umgeschaltet 3x send A81"); 
}

// void callcase55 == 54, because ON / OFF is a toggle on my receiver


void callcase56(){
  irsend.sendSony(0x481, 12);
  delay(200);
  irsend.sendSony(0x481, 12);
  delay(200);
  irsend.sendSony(0x481, 12);
  delay(200);
  Serial.println("SonyAnlage lauter"); 
}
void callcase57(){
  irsend.sendSony(0xC81, 12);
  delay(200);
  irsend.sendSony(0xC81, 12);
  delay(200);
  irsend.sendSony(0xC81, 12);
  delay(200);
  Serial.println("SonyAnlage leiser"); 
}

