

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

// Stereo lauter
void callcase56(){
  irsend.sendSony(0x481, 12);
  delay(200);
  irsend.sendSony(0x481, 12);
  delay(200);
  irsend.sendSony(0x481, 12);
  delay(200);
  Serial.println("SonyAnlage lauter"); 
}
// Stereo leiser 
void callcase57(){
  irsend.sendSony(0xC81, 12);
  delay(200);
  irsend.sendSony(0xC81, 12);
  delay(200);
  irsend.sendSony(0xC81, 12);
  delay(200);
  Serial.println("SonyAnlage leiser"); 
}
// TV Toggle
void callcase65(){
  irsend.sendNEC(0x2FD48B7, 32);
  Serial.println("TV Toggle NEC");
  delay(200);
}
// TV Source
void callcase66(){
  irsend.sendNEC(0x2FD28D7, 32);
  Serial.println("TV Source NEC");
  delay(200);
}
// TV Program UP
void callcase67(){
  irsend.sendNEC(0x2FDD827, 32);
  Serial.println("TV ProgrammUp NEC");
  delay(200);
}
// TV Program Down
void callcase68(){
  irsend.sendNEC(0x2FDF807, 32);
  Serial.println("TV Programm Down NEC");
  delay(200);
}
// Menu settings
void callcase69(){
  irsend.sendNEC(0x2FDDA25, 32);
  Serial.println("TV Menu NEC");
  delay(200);
}
// Controls
// UP
void callcase70(){
  irsend.sendNEC(0x2FD9867, 32);
  Serial.println("TV UP NEC");
  delay(200);
}
// right
void callcase71(){
  irsend.sendNEC(0x2FD02FD, 32);
  Serial.println("TV Right NEC");
  delay(200);
}
// down
void callcase72(){
  irsend.sendNEC(0x2FDB847, 32);
  Serial.println("TV Down NEC");
  delay(200);
}
// left
void callcase73(){
  irsend.sendNEC(0x2FD42BD, 32);
  Serial.println("TV Left NEC");
  delay(200);
}
// OK
void callcase74(){
  irsend.sendNEC(0x2FD847B, 32);
  Serial.println("TV OK NEC");
  delay(200);
}