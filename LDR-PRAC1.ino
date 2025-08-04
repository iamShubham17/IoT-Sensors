const int ledPin = 13;
const int ldrPin = A0;
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue <= 20) {
    Serial.println("It's dark → LED ON");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("It's bright → LED OFF");
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
