//Don't forgett MQTT Username and Password in line 83 or remove it 
#include <ESP8266WiFi.h> 
#include <PubSubClient.h> 
#include <RCSwitch.h> 
RCSwitch mySwitch = RCSwitch(); 
const char* ssid = "SSID"; 
const char* password = "Password"; 
const char* mqtt_server = "MQTT Server IP"; 
WiFiClient espClient; 
PubSubClient client(espClient); 
 
void setup_wifi() { 
  delay(10); 
  // We start by connecting to a WiFi network 
  Serial.println(); 
  Serial.print("Connecting to "); 
  Serial.println(ssid); 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  } 
  randomSeed(micros()); 
  Serial.println(""); 
  Serial.println("WiFi connected"); 
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP()); 
} 
 
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