//include <WiFi.h>
//include < PubSubClicnt.h
//include "DHT.h"
1 const char* ssid - "Thcrainman";
। const char* password = "0123456789”;
//define MQI I SERVER "broker.mqttdashboard.com"
//define MQTI PORT 1883
I //define MQI 1 USER "Thcrainman"
//define MQTI PASSWORD "0123456789"
//define MQI I IEMPERATURF TOPIC "ESP32/DH11 l/Temperature
//define MQTT HUMIDITY TOPIC "ESP32/DHT11/Humidity”
/define MQTI LED TOPIC "ESP32/Led"
//define l.EDPIN 25
//define DHTP1N 14
//define DHTTYPE DHTI1
unsigned long previousMillis = 0;
1 const long interval - 5000;
int current IcdStatc - LOW;
ini last led State LOW;
WiFiClicnl wifiClicnt;
PubSubClienl clicnt(wifiClient);
DI IT dht(DHTPIN. DHTTYPE);
void setup wifi() {
Serial.printf'Connecting to ");
Serial.pi intln(ssid);
WiFi.bcgin(ssid, password);
while (WiFi.statusO != WL CONNECTED) {
delay (500);
Serial.print(".");
}
randomSeed(micros());
Serial.printlnC"’);
Serial.printing WiFi connected");
Serial.printlnf'IP address: ");
Scrial.priniln(WiFi.localIP());
}

void connect to brokerf) {
while ('client.connected!)) I
Serial .print! "Attempting MQTI connection...*);
String clienlld "l'SP32";
clienlld • StringfnmdomfOx 1111). III:.X);
it (client conncctfclicntld c strf). MQTI USER. MQI I PASSWORD)) { Serial prinllnf "connected");
client subscribe! MQI I III) TOPIC):
} else ;
Serial.print!"failed, re");
Serial printfclicnt.statef)):
Serial.prinllnf" try again in 2 seconds");
delav(2000);
}
void callbackfchar* topic, byte «payload. unsigned int length) | Serial.prinllnf"......new message from broker---------");
Serial.print!"topic: ");
Serial prinllnflopic);
Serial.printf "message:");
Serial.write!pa) load, length);
Serial printin!):
il (♦payload T) current IcdState1 HIGH;
if(*payload ’0‘) current IcdState “ LOW;
| \ oid setup!) !
I Serial.beginf 115200);
Scrial.scl Timcout(500);
Serial printin!I ("ESP32-U get data from DHTII & send to IlivcMQ!"));
| setup willf);
clicnl.setServcrfMQlT SERVER. MQTT PORT);
client. sclCallbackfcallback);
connect to brokerf):
dht.beginf):
pinModefLEDPIN. OUTPUT):
digital Writefl I DPIN. current IcdState);
I }
v oid loopf) !
client, loopf);
।t (J c I tent.conneclcdQ) [
  conned to broker!);
!
if! last IcdState != current IcdState)!
last IcdState current IcdState,
digital Write! I !■ DPIN. current IcdState);
Serial print! "I I D Mate is ");
Serial.println(current IcdState);
unsigned long currcntMillis inillisf);
it (currcntMillis - prcviousMillis >•• interval) !
float h dht.rcadllumidity();
float I dht.read IcinpcraturcO;
U Cheek if any reads failed and exit early (to try again).
if (isnan(h) I isnan(t)) {
Serial.println(F("Eailed to read from DHT sensor!"));
return;
} else {
client.publish(MQTT TF MPERATUR1 TOPIC, String(t).c str());
client.publish!MQTT HUMIDITY TOPIC. String!h).c str());
prcviousMillis - currcntMillis:
Serial.print!l;("l lumidity: "));
Serial.print(h);
Serial.println("%");
Serial.print(F("l emperature:"));
Serial.print(t);
Serial.printlnCX'"); //ALT-167