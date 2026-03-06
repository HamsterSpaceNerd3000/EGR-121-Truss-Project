// For now this is only for one member.
#include <Adafruit_NeoPixel.h>

// Variable Init
const int sensorPin = A0;
int sensorVal = 0;
float Vin = 5;
float Vout = 0;
// Reference resistor measurement
float Rref = 990;
float R = 0;

// LED pin setup
const int ledPin = 3;
const int pixelCount = 16;

// Led setup
Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixelCount, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Vout = (Vin*sensorVal)/1023;
  R - Rref * (1/ ((Vin - Vout) -1));
  Serial.println(R);

  // If / Then statement to handle LED display
  // Control
  int controlMin = 320;
  int controlMax = 340;
  if (controlMin <= R <= controlMax) {
    for (int i = 0; i < pixelCount; i++) {
      strip.setPixelColor(i, strip.Color(0, 255, 0));
    }
  } else if (R > controlMax) {
    for (int i = 0; i < pixelCount; i++) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));
    }
  } else if (R < controlMin) {
    for (int i = 0; i < pixelCount; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, 255));
    }
  } else {
    for (int i = 0; i < pixelCount; i++) {
      strip.setPixelColor(i, strip.Color(255, 255, 255));
    }
  }
  
}
