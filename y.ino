#include <SD.h>                //Library Micro SD
#include <FS.h>                //Library Micro SD
#include <Wire.h>              //Library komunikasi I2C
#include "RTClib.h"            //library RTC
#include "variabel.h"          // variabel data tanggal
#include <Adafruit_GFX.h>      //Library mengelolah tampilan Oled
#include <Adafruit_SSD1306.h>  //Library mengelolah tampilan Oled
#include "DHT.h"               //Library sensor Dht 22

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define DHT21_PIN 33
#define SCREEN_ADDRESS 0x3C
#define LOGO_HEIGHT 128
#define LOGO_WIDTH 64
RTC_DS3231 rtc;  //Objek RTC
File myFile;     //Objek MICRO SD
DHT dht21(DHT21_PIN, DHT21);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  intOled();
  logo();
  intRtc();
  intMicroSD();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  ambilWaktu();
  tampilWaktu();
  display.setCursor(0, 20);
  display.println(F("Suhu"));
  display.setCursor(30, 20);
  display.println(F("="));
  display.setCursor(90, 20);
  display.println(F("°C"));

//display.setCursor(60, 20);
  //display.print(F(humi));

  display.setCursor(0, 40);
  display.println(F("Humid"));
  display.setCursor(35, 40);
  display.println(F("="));
  display.setCursor(90, 40);
  display.println(F("%"));
  display.display();
}

void loop() {
  // ambilWaktu();
  // simpanDatawaktu();
  // ambilDatawaktu();
  sensorDHT();
  tampilWaktu();
  // tampilkanSuhu();
  delay(200);
}