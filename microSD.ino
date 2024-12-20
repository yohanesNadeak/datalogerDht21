void intMicroSD() {
  while (!Serial) {
    ;  //Tunggu hingga koneksi Serial Monitor
  }
  Serial.print("Initializing SD card...");     //Mencetak pesan ke Serial Monitor
  if (!SD.begin(5)) {                          //Mencoba menginisialisasi kartu SD pada pin 5
    Serial.println("initialization failed!");  //Jika inisialisasi gagal, cetak pesan kesalahan
    while (1)
      ;  //Masuk ke loop tak terhingga untuk menghentikan eksekusi program
  }
  Serial.println("initialization done.");  //Jika inisialisasi berhasil, cetak pesan bahwa inisialisasi selesai
}
void simpanDatawaktu() {
  //nama dari microSD
  myFile = SD.open("/waktu.txt", FILE_APPEND);  //(tidak akan menimpa file yang sudah ada)
  if (myFile) {
    float humi = dht21.readHumidity();  // read humidity
    float tempC = dht21.readTemperature();
    DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);
    sprintf(tanggal, "%02d/%02d/%04d %02d:%02d:%02d",
            now.day(), now.month(), now.year(),
            now.hour(), now.minute(), now.second());
    myFile.print(tanggal);  //tampilkan tanggal yang sudah di set
    myFile.print(", Suhu: ");
    myFile.print(tempC);
    myFile.print(" C, Kelembapan: ");
    myFile.println(humi);
    myFile.close();  // close the file:
  } else {
    // if the file didn't open, print an error:
    Serial.println("gagal membuka waktu.txt");
  }
}

