🏠 Smart Home Automation & Security System (ESP32)
📌 Project Overview

This project is an Integrated Smart Home Automation & Security System built using an ESP32.
It simulates real-world IoT-based home automation features such as:

🌡️ Temperature-based climate control
💡 Automatic lighting system
🚨 Motion detection security
🚪 Automated door access system
⚙️ Hardware Components
ESP32 DevKit
DHT22 Temperature Sensor
LDR (Light Sensor)
PIR Motion Sensor
Servo Motor (SG90)
Buzzer
LED + Resistor
🧠 System Features
🌡️ Temperature Monitoring
Detects room temperature
If Temperature > 30°C →
Buzzer ON
LED ON
💡 Smart Lighting
Uses LDR sensor
If LDR < 1000 (Dark) →
LED ON
If bright → LED OFF
🚨 Motion Detection
PIR sensor detects movement
On motion:
Buzzer ON
Servo rotates (door opens)
🚪 Door Automation
Servo motor simulates door
Opens on motion detection
Closes automatically after delay
🔌 Pin Configuration
Component	ESP32 Pin
DHT22	GPIO 4
LDR (AO)	GPIO 34
PIR	GPIO 27
Buzzer	GPIO 26
LED	GPIO 25
Servo	GPIO 18
💻 Software Used
Arduino IDE / PlatformIO
Wokwi
🚀 How to Run
Clone the repository:
git clone [https://github.com/your-username/home-Automation.git](https://github.com/Sharan21-cmd/home-Automation/new/main?filename=README.md)
Open in VS Code / PlatformIO
Install required libraries:
DHT sensor library
Adafruit Unified Sensor
ESP32Servo
Upload code to ESP32 or run in Wokwi
📊 Project Output
Real-time monitoring via Serial Monitor
Automated responses based on sensor inputs
Simulated smart home environment
🎯 Learning Outcomes
Embedded C/C++ programming
Sensor interfacing
Actuator control (Servo, Buzzer)
IoT system design principles
📎 Project Structure
├── src/
├── include/
├── lib/
├── diagram.json
├── wokwi.toml
├── platformio.ini
└── README.md
📸 Future Improvements
Add WiFi + cloud integration (ThingSpeak / MQTT)
Mobile app control
Security mode switching
Replace delay() with millis()
👨‍💻 Author

Sharan K U

⭐ Acknowledgment

This project is part of a Smart Home Automation simulation system for learning embedded systems and IoT.
