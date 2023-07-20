/*
 * BANLINHKIEN.COM
 * Ngoại vi: LED WS2812 RING
 * Link tham khảo: http://arduino.vn/bai-viet/1006-fiat-lux-hay-co-anh-sang-phan-2-viet-code-blink-thanh-cho-neopixel-ws2812
*/

/*
 * Đấu nối: 
 *  WS2812   |   Arduino
 *  VCC      |   5V
 *  GND      |   GND
 *  DATA     |   6
*/
#include <Adafruit_NeoPixel.h>
const int ledPin = 6;     // the number of the neopixel strip
const int numLeds = 12;

//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, ledPin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.setBrightness(80); // 1/3 brightness
}
void loop() { 
  rainbow(30);
  delay(10);
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i*1+j) & 255));
    }
  //  strip.show();
    delay(wait);
  }
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
