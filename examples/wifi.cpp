// #include <Arduino.h>
// #include <WiFi.h>
// #include <esp_wifi.h>
// #include <ESPAsyncWebServer.h>

// AsyncWebServer server(80);
// AsyncWebSocket ws("/ws");
// const char *AP_SSID = "ESP32-Wifi-AP-Mode";
// const char *AP_PASSWORD = "12345678";

// String makeAccessPoint(const char *ssid, const char *password)
// {
//   Serial.print("Setting AP mode");
//   WiFi.softAP(ssid, password);
//   IPAddress IP = WiFi.softAPIP(); // mặc định là 192.168.4.1
//   Serial.print("AP IP address: ");
//   Serial.println(IP);
//   // WiFi.onEvent(WiFiEvent);
//   return IP.toString();
// }

// void blinkLedOnboard()
// {
//   uint8_t pin = 2;
//   uint32_t delayTime = 1000;
//   digitalWrite(pin, HIGH);
//   delay(delayTime);
//   digitalWrite(pin, LOW);
//   delay(delayTime);
// }

// // void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info)
// // {

// //   Serial.println("Station disconnected");

// //   for (int i = 0; i < 6; i++)
// //   {

// //     Serial.printf("%02X", info.sta_disconnected.mac[i]);
// //     if (i < 5)
// //       Serial.print(":");
// //   }

// //   Serial.println("\n------------");
// // }
// // void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info)
// // {
// //   if (event == SYSTEM_EVENT_AP_STACONNECTED)
// //   {
// //     Serial.println("Station connected");

// //     // for (int i = 0; i < 6; i++)
// //     // {

// //     //   Serial.printf("%02X", info.);
// //     //   if (i < 5)
// //     //     Serial.print(":");
// //     // }

// //     Serial.println("\n------------");
// //   }
// // }

// // void printClientInfo(){
// //   Serial.println("Client info:");
// //   Serial.print("IP address: ");
// //   Serial.println(WiFi.softAPIP());
// //   Serial.print("MAC address: ");
// //   Serial.println(WiFi.softAPmacAddress());
// //   Serial.print("SSID: ");
// //   Serial.println(WiFi.SSID());
// //   Serial.print("Password: ");
// //   Serial.println(WiFi.psk());
// //   Serial.print("Channel: ");
// //   Serial.println(WiFi.channel());
// //   Serial.print("Encryption type: ");
// //   Serial.println(WiFi.encryptionType());
// //   Serial.print("BSSID: ");
// //   Serial.println(WiFi.BSSIDstr());
// //   Serial.print("RSSI: ");
// //   Serial.println(WiFi.RSSI());
// //   Serial.print("Connected clients: ");
// //   Serial.println(WiFi.softAPgetStationNum());
// //   Serial.println("====================================");
// // }

// void listConnectedClients()
// {
//   wifi_sta_list_t wifi_sta_list;
//   tcpip_adapter_sta_list_t tcpip_adapter_sta_list;

//   memset(&wifi_sta_list, 0, sizeof(wifi_sta_list_t));
//   memset(&tcpip_adapter_sta_list, 0, sizeof(tcpip_adapter_sta_list_t));

//   ESP_ERROR_CHECK(esp_wifi_ap_get_sta_list(&wifi_sta_list));
//   ESP_ERROR_CHECK(tcpip_adapter_get_sta_list(&wifi_sta_list, &tcpip_adapter_sta_list));

//   // Print information about each connected client
//   for (int i = 0; i < tcpip_adapter_sta_list.num; i++)
//   {
//     esp_netif_sta_info_t station = tcpip_adapter_sta_list.sta[i];
//     Serial.print("Client ");
//     Serial.print(i + 1);
//     Serial.print(" - MAC address: ");
//     Serial.print(station.mac[0], HEX);
//     Serial.print(":");
//     Serial.print(station.mac[1], HEX);
//     Serial.print(":");
//     Serial.print(station.mac[2], HEX);
//     Serial.print(":");
//     Serial.print(station.mac[3], HEX);
//     Serial.print(":");
//     Serial.print(station.mac[4], HEX);
//     Serial.print(":");
//     Serial.print(station.mac[5], HEX);
//     Serial.print(" IP address: ");
//     Serial.println(IPAddress(station.ip.addr).toString());
//   }
// }

// void connectToWiFi(const char *ssid, const char *password)
// {
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi");
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println();
//   Serial.print("Connected to WiFi network with IP Address: ");
//   Serial.println(WiFi.localIP());
// }

// void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
// {
//   if (type == WS_EVT_CONNECT)
//   {
//     Serial.println("WebSocket client connected");
//   }
//   else if (type == WS_EVT_DISCONNECT)
//   {
//     Serial.println("WebSocket client disconnected");
//   }
//   else if (type == WS_EVT_DATA)
//   {
//     Serial.printf("WebSocket received data: %.*s\n", len, (char *)data);
//     blinkLedOnboard();
//     client->text(data, len);
//   }
// }

// void setup()
// {
//   Serial.begin(9600);
//   pinMode(2, OUTPUT);
//   // Serial.println("Starting Web Server: " + makeAccessPoint(AP_SSID, AP_PASSWORD));
//   connectToWiFi("NWiFi", "10092001");

//   // Define web server routes
//   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
//             { request->send(200, "text/html", "<html><body><h1>Hello, world!</h1></body></html>"); });

//   // Define WebSocket event handler
//   ws.onEvent(onWebSocketEvent);

//   // Add WebSocket server to web server
//   server.addHandler(&ws);
//   // Start web server
//   server.begin();
// }

// void loop()
// {
//   // listConnectedClients();
//   delay(1000);
// }
