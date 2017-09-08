

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

void callcase65(){
  irsend.sendNEC(0x2FD48B7, 32);
  Serial.println("TV Toggle NEC");
  delay(200);
}
void callcase66(){
  irsend.sendNEC(0x2FD28D7, 32);
  Serial.println("TV Source NEC");
  delay(200);
}
void callcase67(){
  irsend.sendNEC(0x2FDD827, 32);
  Serial.println("TV ProgrammUp NEC");
  delay(200);
}
void callcase68(){
  irsend.sendNEC(0x2FDF807, 32);
  Serial.println("TV ProgrammUp NEC");
  delay(200);
}
void callcase69(){}
void callcase70(){}
