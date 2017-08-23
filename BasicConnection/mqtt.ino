
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
    //Numbers in char code.. So 0 is 48 
    case 48:  
            client.publish("fromarduino", "0"); 
            
            callcase48();
            break; 
    case 49:  
            client.publish("fromarduino", "1"); 
            callcase49();
            break; 
    case 50:  
            client.publish("fromarduino", "2"); 
            callcase50();
            break; 
    case 51:  
            client.publish("fromarduino", "3"); 
            callcase51();
            break;   
    case 52:  
            client.publish("fromarduino", "4");  
            callcase52();; 
            break; 
    case 53:  
            client.publish("fromarduino", "5"); 
            callcase53();
            break;   
    case 54:  
            client.publish("fromarduino", "6"); 
            callcase54();
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
  
}


