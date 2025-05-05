# 🤖 Web-Controlled Arduino Robotic Arm

Control a robotic arm using **voice commands** or **web interaction** via USB — directly from your browser!

## 📦 Project Structure
```
.
├── ArduinoControl.ino      # Arduino sketch to move 5 servo motors
├── scrips.js               # JS script to send serial commands from browser

## 💡 Features

- 🎮 Control robotic arm using browser commands
- 🔌 Real-time USB serial communication
- 🗣️ Accepts English or Arabic commands (like "Right", "يسار")
- 🦾 Supports 5 servo joints: base, shoulder, elbow, wrist, and gripper

## 🛠 Hardware Needed

- Arduino Uno/Nano
- 5x Servo Motors
- USB cable for Arduino
- Optional: Voice-to-text input for commands

## ⚙️ Setup

### 🔌 Arduino Side
1. Open `ArduinoControl.ino` in the Arduino IDE.
2. Upload it to your board.
3. Connect the servos to pins:
   | Servo     | Pin |
   |-----------|-----|
   | Base      | 8   |
   | Shoulder  | 9   |
   | Elbow     | 10  |
   | Wrist     | 11  |
   | Gripper   | 12  |

### 🌐 Browser Side
1. Open an HTML file with `scrips.js` linked (you can make a simple button UI).
2. Click “Connect USB” → your browser will prompt to connect the Arduino.
3. Speak or type a command like `Right` or `يسار`.

> Make sure to use **Google Chrome** or **Edge** with Web Serial API enabled.

## 🧪 Sample Commands

| English | Arabic | Action             |
|---------|--------|--------------------|
| Right   | يمين   | Rotate base right  |
| Left    | يسار   | Rotate base left   |
| Top     | اعلى   | Shoulder up        |
| Bottom  | اسفل   | Shoulder down      |

