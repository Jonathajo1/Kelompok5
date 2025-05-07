#include <LiquidCrystal.h>

// Inisialisasi pin LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Inisialisasi pin LED
int ledMerah = 6;
int ledKuning = 7;
int ledHijau = 8;

void setup() {
  // Set pin LED sebagai output
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  // Inisialisasi LCD dengan jumlah kolom dan baris
  lcd.begin(16, 2);
  // Tampilkan pesan awal di LCD
  lcd.print("Simulasi Lampu");
  lcd.setCursor(0, 1);
  lcd.print("Lalu Lintas");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Merah menyala selama 3 detik
  digitalWrite(ledMerah, HIGH);
  digitalWrite(ledKuning, LOW);
  digitalWrite(ledHijau, LOW);
  hitungMundur(5); // Hitung mundur 5 detik

  // Kuning menyala selama 2 detik
  digitalWrite(ledMerah, LOW);
  digitalWrite(ledKuning, HIGH);
  digitalWrite(ledHijau, LOW);
  hitungMundur(2); // Hitung mundur 5 detik

  // Hijau menyala selama 3 detik
  digitalWrite(ledMerah, LOW);
  digitalWrite(ledKuning, LOW);
  digitalWrite(ledHijau, HIGH);
  hitungMundur(3); // Hitung mundur 5 detik
}

void hitungMundur(int detik) {
  for (int i = detik; i >= 0; i--) {
    lcd.setCursor(0, 0);
    lcd.print("Waktu: ");
    lcd.print(i);
    lcd.print(" detik");
    delay(2000); // Tunda 2 detik
  }
  lcd.clear();
} 