//Don't forgett MQTT Username and Password in line 80 or remove it 
#include "userconfig.h"
#include <ESP8266WiFi.h> 
#include <PubSubClient.h> 
#include <RCSwitch.h> 
#include <IRremoteESP8266.h>
#include <IRsend.h>
IRsend irsend(IR_connected_pin); 

RCSwitch mySwitch = RCSwitch(); 
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
 
void setup() {
  Serial.begin(115200);
  setup_wifi();
  #ifdef mqtt
    setupmqtt();
  #endif
  #ifdef RC433mhz
    setupRC();
  #endif
  #ifdef IR
    setupIR();
  #endif
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();  
}

