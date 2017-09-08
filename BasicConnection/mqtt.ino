
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
    case 55:  
            client.publish("fromarduino", "7"); 
            callcase54();
            break;                               
    case 56:  
            client.publish("fromarduino", "8"); 
            callcase56();
            break;     
    case 57:  
            client.publish("fromarduino", "9"); 
            callcase57();
            break;      
    case 65:
            client.publish("fromArduino", "A");
            callcase65();
            break;      
    case 66:
            client.publish("fromArduino", "B");
            callcase66();
            break;
    case 67:
            client.publish("fromArduino", "C");
            callcase67();
            break;              
    case 68:
            client.publish("fromArduino", "D");
            callcase68();
            break;              
    case 69:
            client.publish("fromArduino", "E");
            callcase69();
            break;
    case 70:
            client.publish("fromArduino", "F");
            callcase70();
            break;
    case 71:
            client.publish("fromArduino", "G");
            callcase71();
            break;
    case 72:
            client.publish("fromArduino", "H");
            callcase72();
            break;
    case 73:
            client.publish("fromArduino", "I");
            callcase73();
            break;
    case 74:
            client.publish("fromArduino", "J");
            callcase74();
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


    
