#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// RFID setup
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// Ultrasonic setup
#define TRIG_PIN 6
#define ECHO_PIN 5

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Attendance Sys");
  delay(2000);
  lcd.clear();
}

void loop() {
  // 🔹 RFID detection
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uid += String(rfid.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RFID Detected");
    lcd.setCursor(0, 1);
    lcd.print(uid);

    Serial.print("RFID:");
    Serial.println(uid); // send to python

    delay(2000);
  }

  // 🔹 Ultrasonic presence detection
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 50) { // presence within 50 cm
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Person Present");
    Serial.println("ULTRASONIC:PRESENT");
    delay(2000);
  }

  delay(500);
}
