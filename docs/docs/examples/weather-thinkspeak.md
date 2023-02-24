---
sidebar_position: 2
---

# Sử dụng esp32 với module dht11

## Gửi dữ liệu lên thingspeak

```cpp

#include "DHT.h"
#include <WiFi.h>
#include <HTTPClient.h>


const char *ssid = "";
const char *password = "";
const char *api_key = "";

// Your Domain name with URL path or IP address with path
String serverName = "https://api.thingspeak.com/update?api_key="+ api_key;

// Định nghĩa loại DHT và chân kết nối
const int DHTPIN = 6;
const int DHTTYPE = DHT11;


DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Nhiet do: ");
  Serial.println(t);
  Serial.print("Do am: ");
  Serial.println(h);

  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    String serverPath = serverName + "&field1=" + String(t, 3) + "&field2=" + String(h, 3);

    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0)
    {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    }
    else
    {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else
  {
    Serial.println("WiFi Disconnected");
  }

  Serial.println("........................");
  delay(1000);
}
```
