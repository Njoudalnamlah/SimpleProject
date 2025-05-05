# 🤖 Web-Controlled Arduino Robotic Arm

Control a robotic arm using **voice commands** or **web interaction** via USB — directly from your browser!


## 💡 Features

- 🎮 Control robotic arm using browser commands  
- 🔌 Real-time USB serial communication  
- 🌐 Accepts English or Arabic commands (like `"Right"`, `"يسار"`)  
- 🦿 Supports 5 servo joints: base, shoulder, elbow, wrist, and gripper


## 🛠 Hardware Needed

- Arduino Uno or Nano  
- 5x Servo Motors  
- USB cable for Arduino  
- Power supply for the servos  
- (Optional) Microphone/voice input


## ⚙️ Setup Instructions

### 🔧 Arduino

1. Open `ArduinoControl.ino` in Arduino IDE.  
2. Upload the sketch to your board.  
3. Connect the servos to the following pins:

| Servo     | Pin |
|-----------|-----|
| Base      | 8   |
| Shoulder  | 9   |
| Elbow     | 10  |
| Wrist     | 11  |
| Gripper   | 12  |


### 🌐 Browser (JavaScript)

1. Create an HTML page that includes `scrips.js`.
2. In Google Chrome or Edge, click a button to **Connect USB**.
3. Speak or type a command, which will be sent to the Arduino via Web Serial.


## 🧪 Sample Commands

| English | Arabic | Action             |
|---------|--------|--------------------|
| Right   | يمين   | Rotate base right  |
| Left    | يسار   | Rotate base left   |
| Top     | اعلى   | Shoulder up        |
| Bottom  | اسفل   | Shoulder down      |



