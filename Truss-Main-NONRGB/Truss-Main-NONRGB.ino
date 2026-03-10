// One member, nonRGB

// Variable Init
const int sensorPin = A0;
int sensorVal = 0;
float Vin = 5;
float Vout = 0;
const int zeroPin = 5;
int zeroState = 0;
// Reference resistor measurement
float Rref = 1000;
float R = 0;

// LED pin setup
const int ledPin = 3;

// Led setup

void setup() {
  Serial.begin(9600);
  pinMode(zeroPin, INPUT);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Vout = (Vin*sensorVal)/1023.0;
  R = Rref * (1/ ((Vin - Vout) -1));
  zeroState = digitalRead(zeroPin);
  Serial.println(R);

  
  // Zero handling
  if (zeroState == HIGH) {
    R = 0;
  }
}
