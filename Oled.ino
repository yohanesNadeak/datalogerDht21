void intOled() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();
  delay(1000);
}

void tampilWaktu() {
  DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);  // Ambil waktu saat ini dari RTC
  // Bersihkan buffer tampilan
  display.fillRect(0, 0, 128, 10, BLACK);

  // Atur ukuran teks dan warna
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  sprintf(tanggal, "%02d/%02d/%04d %02d:%02d:%02d",
          now.day(), now.month(), now.year(),
          now.hour(), now.minute(), now.second());
  display.setCursor(0, 0);  // Atur posisi kursor
  display.println(tanggal);

  // Tampilkan semua di layar
  display.display();
}

void tampilkanSuhu() {
  float humi = dht21.readHumidity();  // Read humidity
  float tempC = dht21.readTemperature();
  display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.setTextSize(1, 2);
  display.setTextColor(WHITE);

  // Display Temperature
  String tempText = "Suhu: " + String(tempC) + " C";
  int tempX = (SCREEN_WIDTH - (tempText.length() * 6)) / 2;  // Approximate width per character
  display.setCursor(tempX, 20);
  display.println(tempText);  // menampilkan nilai temperature

  // Display Humidity
  String humiText = "Kelembaban: " + String(humi) + " %";
  int humiX = (SCREEN_WIDTH - (humiText.length() * 6)) / 2;  // Approximate width per character
  display.setCursor(humiX, 40);
  display.println(humiText);  // menampilkan nilai humidity
  display.display();          // Update the display
}

void logo() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.drawBitmap((128 - 62) / 2, 0, myBitmap, 62, 64, 1);
  display.display();
  delay(3000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("OLED Initialized"));
  display.display();
  delay(3000);
}