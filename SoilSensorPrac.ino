// Pin configuration
const int rainPin = A0;       // Soil moisture sensor analog output
const int greenLED = 6;       // Green LED: soil is wet, no water needed
const int redLED = 7;         // Red LED: soil is dry, water needed

const int thresholdValue = 800;  // Adjust as needed based on your soil

void setup() {
  pinMode(rainPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  Serial.begin(9600);
  Serial.println("Soil Moisture Monitoring System Started...");
  Serial.print("Moisture Threshold: ");
  Serial.println(thresholdValue);
}

void loop() {
  int sensorValue = analogRead(rainPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue < thresholdValue) {
    // Soil is wet
    Serial.println("Condition: Soil is WET");
    Serial.println("Action: Water is NOT needed ❌💧");
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    // Soil is dry
    Serial.println("Condition: Soil is DRY");
    Serial.println("Action: Water IS needed ✅💧");
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  Serial.println("-------------------------------");
  delay(2000);  // Wait 2 seconds before next read
}
