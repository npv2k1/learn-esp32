#include <Arduino.h>
int B_LED = 25;
int G_LED = 26;
int R_LED = 27;
int READ_PIN = 34;

void displayColor(int r, int g, int b)
{
  analogWrite(R_LED, r);
  analogWrite(G_LED, g);
  analogWrite(B_LED, b);
}

void setup()
{
  Serial.begin(115200);
  pinMode(B_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);
}

void loop()
{
  // for (int i = 0; i <= 255; i += 1)
  // {
  //   Serial.print("R: " + i);
  //   delay(1000);

  //   // // analogWrite(R_LED, i);
  //   // for (int j = 0; j <= 255; j += 1)
  //   // {
  //   //   for (int k = 0; k <= 255; k += 1)
  //   //   {
  //   //     displayColor(i, j, k);
  //   //     // displayColor(i, j, k);
  //   //     Serial.print("R: ");
  //   //     Serial.print(i);
  //   //     Serial.print(" G: ");
  //   //     Serial.print(j);
  //   //     Serial.print(" B: ");
  //   //     Serial.println(k);

  //   //     // analogWrite(R_LED, i);
  //   //     // analogWrite(G_LED, j);
  //   //     // analogWrite(B_LED, k);

  //   //     delay(1);
  //   //   }
  //   // }
  // }
  analogWrite(R_LED, 75);
  int voltage = analogRead(READ_PIN);
  Serial.println("voltage" + /* `voltage` is the variable that is storing the value of the analogRead. */
  voltage);
  delay(1000);
}