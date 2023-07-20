#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
const char* ssid = "nguyen.pham";
const char* password = "10092001";
#define MQTT_SERVER "broker.mqttdashboard.com"
#define MQTT_PORT 8000
#define MQTT_USER "nguyen.pham"
#define MQTT_PASSWORD "10092001"
#define MQTT_TEMPERATURE_TOPIC "ESP32/DHT1l/Temperature"
#define MQTT_HUMIDITY_TOPIC "ESP32/DHT11/Humidity”
#define MQTT_LED_TOPIC "ESP32/Led"

#define LEDPIN 25
#define DHTPIN 14
#define DHTTYPE DHT11

unsigned long previousMillis = 0;
const long interval = 5000;
int current_ledState = LOW;
int last ledState = LOW;

WiFiClient wifiClient;
PubSubClient client(wifiClient);
DHT dht(DHTPIN, DHTTYPE);

void setup_wifi() {
  Serial.printf("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay (500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void connect_to_broker() {
  while (!client.connected()){ I
    Serial .print("Attempting MQTT connection...");
    String clientId = "ESP32";
    clientId += String(ramdom(0xffff).HEX);
    it (client.connect(clientId.c_str()).MQTT_USER.MQTT_PASSWORD)) { 
      Serial.println("connected");
      client.subscribe(MQTT_LED_TOPIC):
    }else {
    Serial.print("failed, rc=");
    Serial.print(client.state()):
    Serial.println(" try again in 2 seconds");
    delay(2000);
    }
  }
}

void callback(char* topic, byte *payload, unsigned int length) {
  Serial.println("-------new message from broker---------");
  Serial.print("topic: ");
  Serial.println(topic);
  Serial.print("message: ");
  Serial.write(payload, length);
  Serial.println();
  if(*payload == '1') current_ledState = HIGH;
  if(*payload == '0') current_ledState = LOW;
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(500);
  Serial.println(F("ESP32-U get data from DHT11 & send to HiveMQ!"));
  setup_wifi();
  client.setServer(MQTT_SERVER,MQTT_PORT);
  client.setCallback(callback);
  connect_to_broker();
  dht.begin();
  pinMode(LEDPIN,OUTPUT);
  digitalWrite(LEDPIN,current_ledState);
}

void loop() {
  client.loop();
  if(! client.connected()) {
    connect_to_broker();
  }
  if(last_ledState != current_ledState){ 
    last_ledState = current_ledState; 
    digitalWrite(LEDPIN, current_ledState); 
    Serial.print("LED state is "); 
    Serial.println(current_ledState); 
  }
  unsigned long currentMillis = millis(); 
  if (currentMillis - previousMillis >= interval){ 
    float h= dht.readHumidity(); 
    float t= dht.readTemperature();
    //Check if any reads failed and exit early (to try again). 
    if (isnan(h) || isnan(t)) { 
      Serial.println(F("Failed to read from DHT sensor!")); 
      return;
    } else {
      client.publish(MQTT_TEMPERATURE_TOPIC, String(t).c_str()); 
      client.publish(MQTT_HUMIDITY_TOPIC, String(h).c_str()); 
      previousMillis = currentMillis;

    Serial.print(F("Humidity: ")); 
    Serial.print(h); 
    Serial.println("%"); 
    Serial.print(F("Temperature: ")); 
    Serial.print(t); Serial.println("C"); //ALT+167 
    }
  }
}
