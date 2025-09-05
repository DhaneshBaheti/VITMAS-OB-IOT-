# Smart Attendance System

This project implements a **Smart Attendance System** using **Arduino UNO** and Python.  
It supports multiple attendance methods:

- **RFID Module** – for scanning cards/tags  
- **Ultrasonic Sensor** – for detecting physical presence  
- **16x2 I2C LCD** – for status display  
- **Python Scripts** – for logging attendance to **Excel** or **Google Sheets**  
- **Bonus** – Face Recognition Attendance using Python + OpenCV  

---

## 🚀 Features
- Detect user via **RFID** or **Ultrasonic Sensor**
- Display status on **16x2 I2C LCD**
- Log **Name/ID + Timestamp** into:
  - Excel (`attendance_rfid.xlsx`, `attendance_ultrasonic.xlsx`, `attendance_face.xlsx`)
  - OR Google Sheets (via Google Sheets API)
- Optional **Face Recognition** attendance using `face_recognition` + `OpenCV`

---

## 🛠️ Hardware Setup (Arduino UNO)
- **RFID RC522 Module**
  - SDA → D10
  - SCK → D13
  - MOSI → D11
  - MISO → D12
  - RST → D9
  - VCC → 3.3V
  - GND → GND

- **Ultrasonic Sensor (HC-SR04)**
  - VCC → 5V
  - GND → GND
  - TRIG → D7
  - ECHO → D6

- **I2C 16x2 LCD**
  - SDA → A4
  - SCL → A5
  - VCC → 5V
  - GND → GND

---

<img width="1170" height="856" alt="image" src="https://github.com/user-attachments/assets/444b3718-3e61-44d8-893b-cd69a8fa3cdb" />

<img width="2940" height="1596" alt="image" src="https://github.com/user-attachments/assets/9121289e-fd1d-4e72-ba81-e15032bcfe94" />

## 📦 Software Requirements

### Arduino IDE
- Install libraries:
  - `MFRC522` (for RFID)
  - `LiquidCrystal_I2C` (for I2C LCD)

### Python (3.12 recommended ✅)
Create a virtual environment:
```bash
python3.12 -m venv attendance_env
source attendance_env/bin/activate






