// === Include Required Libraries ===
#include <DHT.h>

// === Define Sensor Pins ===
#define DHTPIN 2          // DHT11 connected to digital pin 2
#define DHTTYPE DHT11     // DHT 11 sensor type
#define TRIG_PIN 3        // Ultrasonic sensor TRIG pin
#define ECHO_PIN 4        // Ultrasonic sensor ECHO pin
#define SOIL_PIN A0       // Soil moisture sensor connected to A0
#define LDR_PIN A1        // LDR sensor connected to A1
#define LED_PIN 5         // LED output pin

// === Initialize Sensor Instances ===
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Multi-Sensor Monitoring Started...");
}

void loop() {
  // === Read DHT11 Sensor ===
  float tempC = dht.readTemperature();
  float hum = dht.readHumidity();

  // === Read Ultrasonic Sensor ===
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  // === Read Soil Moisture ===
  int soilValue = analogRead(SOIL_PIN);
  String soilStatus = (soilValue > 800) ? "DRY" : "WET";

  // === Read LDR ===
  int ldrValue = analogRead(LDR_PIN);
  String lightStatus = (ldrValue < 200) ? "Dark" : "Bright";

  // === LED Control based on LDR ===
  if (ldrValue < 200) {
    digitalWrite(LED_PIN, HIGH);  // Turn on LED in darkness
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn off LED in light
  }

  // === Print All Readings ===
  Serial.println("============================");
  Serial.print("Temperature: "); Serial.print(tempC); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(hum); Serial.println(" %");
  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");
  Serial.print("Soil Moisture: "); Serial.print(soilValue); Serial.print(" -> "); Serial.println(soilStatus);
  Serial.print("LDR Value: "); Serial.print(ldrValue); Serial.print(" -> "); Serial.println(lightStatus);
  Serial.println("============================\n");

  delay(2000);  // Delay between readings
}
