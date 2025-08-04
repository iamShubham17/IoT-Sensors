#define trigPin 13
#define echoPin 3
#define ledPin 8   // External LED connected to pin 8

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);  // LED output
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  float distance = duration * 0.034 / 2;

  if (duration == 0) {
    Serial.println("No Echo – check sensor & wires");
    digitalWrite(ledPin, LOW);
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 10) {  // Object is close
      // Blink the LED 3 times
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
      }
    } else {
      digitalWrite(ledPin, LOW);  // Keep LED off
    }
  }

  delay(500);
}
