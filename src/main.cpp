#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Replace with your network credentials
const char *ssid = "NWiFi";
const char *password = "10092001";

// Replace with your MQTT broker settings
const char *mqtt_server = "192.168.129.102";
const int mqtt_port = 1883;
const char *mqtt_username = "myuser";
const char *mqtt_password = "1";
const char *mqtt_topic = "your_mqtt_topic";

// Replace with your DHT sensor settings
const int dht_pin = 5;
const int dht_type = DHT11;

// Initialize the DHT sensor
DHT dht(dht_pin, dht_type);

// Initialize the WiFi client and MQTT client
WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

void setup()
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to MQTT broker
  mqtt_client.setServer(mqtt_server, mqtt_port);
  // mqtt_client.setCallback(callback);
  while (!mqtt_client.connected())
  {
    Serial.println("Connecting to MQTT broker...");
    if (mqtt_client.connect("ESP32Client", mqtt_username, mqtt_password))
    {
      Serial.println("Connected to MQTT broker");
    }
    else
    {
      Serial.print("Failed with state ");
      Serial.print(mqtt_client.state());
      delay(2000);
    }
  }

  // Initialize the DHT sensor
  dht.begin();
}

void loop()
{
  // Read the temperature and humidity from the DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if the readings are valid
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  // Publish the temperature and humidity to MQTT
  char message[50];
  snprintf(message, 50, "%.2f,%.2f", temperature, humidity);
  mqtt_client.publish(mqtt_topic, message);

  // Print the temperature and humidity to the serial console
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Wait for 5 seconds before publishing again
  delay(1000);
}

// void callback(char *topic, byte *payload, unsigned int length)
// {
//   // Handle incoming MQTT messages here
// }
