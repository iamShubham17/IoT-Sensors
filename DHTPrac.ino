#include "DHT.h"

#define DHTPIN 2      // Pin where the sensor is connected
#define DHTTYPE DHT11 // Sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Initialize the serial monitor
  dht.begin();        // Initialize the sensor
}

void loop() {
  float humidity = dht.readHumidity();           // Read humidity
  float temperatureC = dht.readTemperature();   // Temperature in Celsius
  float temperatureF = dht.readTemperature(true); // Temperature in Fahrenheit
  float temperatureK = temperatureC + 273.15;   // Temperature in Kelvin

  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Error reading data!");
    return;
  }

  // Output data to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("°C, ");
  Serial.print(temperatureF);
  Serial.print("°F, ");
  Serial.print(temperatureK);
  Serial.println("K");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000); // Delay between readings
}