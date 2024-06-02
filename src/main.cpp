#include <Arduino.h>

// 17 = R, 14 = G, B = 11
//  RGB LED pins
int redPin = 17;   // Assuming red is connected to GPIO9
int greenPin = 14; // Assuming green is connected to GPIO10
int bluePin = 3;  // Assuming blue is connected to GPIO11

void setup()
{
    Serial.begin(115200);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
  // Cycle through the color wheel
  for (int i = 0; i < 768; i++) {
    int red, green, blue;
    // Calculate RGB values based on the current position in the color wheel
    if (i < 256) {
      red = 255 - i;
      green = i;
      blue = 0;
    } else if (i < 512) {
      red = 0;
      green = 255 - (i - 256);
      blue = i - 256;
    } else {
      red = i - 512;
      green = 0;
      blue = 255 - (i - 512);
    }

    // Write the calculated RGB values to the LED pins
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);

    delay(10);  // Adjust the delay to control the speed of the animation
  }
  Serial.println("yesssssss");
}