void intRtc() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("init RTC"));
  display.display();

  if (!rtc.begin()) {
    Serial.println("RTC tidak ditemukan");
    Serial.flush();
    display.setCursor(0, 20);
    display.println(F("RTC ERROR"));
    display.display();

    while (1) delay(10);
  }
}
void ambilWaktu() {
  DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);
  sprintf(tanggal, "%02d/%02d/%04d %02d:%02d:%02d",
          now.day(), now.month(), now.year(),
          now.hour(), now.minute(), now.second());
  Serial.println(tanggal);
}
