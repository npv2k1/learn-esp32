// #include "DHT.h"
// #include <WiFi.h>
// #include <HTTPClient.h>

// const char *ssid = "NWiFi";
// const char *password = "10092001";

// // Your Domain name with URL path or IP address with path
// String serverName = "https://api.thingspeak.com/update?api_key=O8O22PQ0OS2EJUJG";

// #define LEDPIN 25
// const int DHTPIN = 5;
// const int DHTTYPE = DHT11;
// #define LED 25

// DHT dht(DHTPIN, DHTTYPE);
// void setup()
// {
//   Serial.begin(9600);
//   WiFi.begin(ssid, password);
//   Serial.println("Connecting");
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.print("Connected to WiFi network with IP Address: ");
//   Serial.println(WiFi.localIP());
//   pinMode(LED, OUTPUT);
//   dht.begin();
// }

// void loop()
// {
//   float h = dht.readHumidity();
//   float t = dht.readTemperature();

//   Serial.print("Nhiet do: ");
//   Serial.println(t);
//   Serial.print("Do am: ");
//   Serial.println(h);
//   digitalWrite(LED, HIGH); // Turn the LED on

//   if (WiFi.status() == WL_CONNECTED)
//   {
//     HTTPClient http;

//     String serverPath = serverName + "&field1=" + String(t, 3) + "&field2=" + String(h, 3);

//     // Your Domain name with URL path or IP address with path
//     http.begin(serverPath.c_str());

//     // Send HTTP GET request
//     int httpResponseCode = http.GET();

//     if (httpResponseCode > 0)
//     {
//       Serial.print("HTTP Response code: ");
//       Serial.println(httpResponseCode);
//       String payload = http.getString();
//       Serial.println(payload);
//     }
//     else
//     {
//       Serial.print("Error code: ");
//       Serial.println(httpResponseCode);
//     }
//     // Free resources
//     http.end();
//   }
//   else
//   {
//     Serial.println("WiFi Disconnected");
//   }

//   Serial.println("........................");
//   delay(1000);
// }