# Onboard led blink

```cpp
#include "DHT.h"
#include <WiFi.h>
#include <HTTPClient.h>

// onboard led
#define ONBOARD_LED 2

void setup()
{
  Serial.begin(9600);
  pinMode(ONBOARD_LED, OUTPUT);
}

void loop()
{
  delay(1000);
  digitalWrite(ONBOARD_LED, HIGH);
  delay(100);
  digitalWrite(ONBOARD_LED, LOW);
}
```
