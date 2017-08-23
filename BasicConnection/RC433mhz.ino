void setupRC(){
    mySwitch.enableTransmit(mqtt_connected_pin);
}

void callcase48(){
mySwitch.switchOn('a', 1, 1); 
Serial.println("Antwort gesendet 0"); 
}
void callcase49(){
    mySwitch.switchOff('a', 1, 1); 
    Serial.println("Antwort gesendet 1"); 
}


void callcase50(){
    mySwitch.switchOn('a', 1, 2); 

    Serial.println("Antwort gesendet 2"); 
}
void callcase51(){
    mySwitch.switchOff('a', 1, 2); 

    Serial.println("Antwort gesendet 3"); 
}

void callcase52(){
    mySwitch.switchOn('a', 1, 3); 

    Serial.println("Antwort gesendet 4");
}
void callcase53(){
    mySwitch.switchOff('a', 1, 3); 

    Serial.println("Antwort gesendet 5"); 
}
