void sensorDHT() {
  dht21.begin();                          // initialize the DHT22 sensor
  float humi = dht21.readHumidity();      // read humidity
  float tempC = dht21.readTemperature();  // read temperature as Celsius
  //check if any reads failed
  if (isnan(humi) || isnan(tempC)) {
    Serial.println("Failed to read from DHT21 sensor!");
  } else {
    Serial.print("DHT21# Humidity: ");
    Serial.print(humi);
    Serial.print("%");
    Serial.print("  |  ");
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C");
  }
}