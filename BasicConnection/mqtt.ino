
void callback(char* topic, byte* payload, unsigned int length) { 
  Serial.print("Message arrived ["); 
  Serial.print(topic); 
  Serial.println("] "); 
  Serial.println( payload[0]); 
  Serial.println( (char)payload[0]); 
  for (int i = 0; i < length; i++) { 
    Serial.print((char)payload[i]); 
  } 
  Serial.println(); 
 
  switch(payload[0]){ 
    case 48:  
            client.publish("fromarduino", "0"); 
            Serial.println("Antwort gesendet 0"); 
            mySwitch.switchOn('a', 1, 1); 
            break; 
    case 49:  
            client.publish("fromarduino", "1"); 
            Serial.println("Antwort gesendet 1"); 
            mySwitch.switchOff('a', 1, 1); 
            break; 
    case 50:  
            client.publish("fromarduino", "2"); 
            Serial.println("Antwort gesendet 2"); 
            mySwitch.switchOn('a', 1, 2); 
            break; 
    case 51:  
            client.publish("fromarduino", "3"); 
            Serial.println("Antwort gesendet 3"); 
            mySwitch.switchOff('a', 1, 2); 
            break;   
    case 52:  
            client.publish("fromarduino", "4"); 
            Serial.println("Antwort gesendet 4"); 
            mySwitch.switchOn('a', 1, 3); 
            break; 
    case 53:  
            client.publish("fromarduino", "5"); 
            Serial.println("Antwort gesendet 5"); 
            mySwitch.switchOff('a', 1, 3); 
            break;                                
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqttuser, mqttpassword)) {
      Serial.println("connected");
      client.publish("fromarduino", "hello");
      client.subscribe("toarduino");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setupmqtt(){
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  mySwitch.enableTransmit(mqtt_connected_pin);
}


