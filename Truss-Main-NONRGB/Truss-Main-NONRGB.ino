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
  pinMode(zeroPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Vout = (Vin*sensorVal)/1023.0;
  R = Rref * (1/ ((Vin - Vout) -1));
  zeroState = digitalRead(zeroPin);
  Serial.println(R);

  float controlMin = 0.45;
  float controlMax = 0.55;

  if (controlMin <= R & controlMax >= R) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else if (R > controlMax) {
    digitalWrite(ledPin, HIGH);
  } else if (R < controlMin) {
    digitalWrite(ledPin, LOW);
  } else {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);

    }

    delay(750);

    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(800);
    }

    delay(750);

    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }
  }
  
  // Zero handling
  if (zeroState == HIGH) {
    R = 0;
  }
}
