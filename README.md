# 🌃 Ecolight Maestro

### Time & Light Intensity Based Street Light Automation using LPC2129 ARM7

`LPC2129` `ARM7` `Language: Embedded C` `Keil uVision` `Proteus Simulation`

---

## 📖 Project Overview

**Ecolight Maestro** is an intelligent street light automation system developed using the **LPC2129 ARM7 microcontroller**. The system automatically controls street lights based on **real-time clock scheduling** and **ambient light intensity** detected via an LDR sensor.

Traditional street lighting systems often remain ON unnecessarily, leading to excessive energy consumption. Ecolight Maestro addresses that issue by combining **time-based automation** with **light intensity monitoring**, ensuring that street lights operate only when required.

The system continuously monitors:

* Current Time and Date using RTC
* Ambient Light Intensity using LDR and ADC
* User-configurable RTC parameters through a Keypad Interface

This results in an energy-efficient and fully automated smart lighting solution.

---

## 🎯 Project Objectives

* ✅ Reduce power wastage in street lighting systems
* ✅ Automate street light operation based on environmental conditions
* ✅ Provide user-friendly RTC configuration
* ✅ Demonstrate ARM7 peripheral integration
* ✅ Implement interrupt-driven embedded system design

---

## ✨ Key Features

### 🕐 Real-Time Clock Management

* Displays current Time
* Displays Date
* Displays Day
* Supports RTC parameter modification

### 🌗 Intelligent Light Detection

* LDR-based ambient light sensing
* ADC conversion for light intensity measurement
* Automatic day/night detection

### 💡 Automatic Street Light Control

* Lights turn ON during low-light conditions
* Lights turn OFF during daylight conditions
* Dual-condition verification using RTC and LDR

### ⌨️ User Configuration Interface

* 4×4 Matrix Keypad
* RTC parameter editing
* Menu-driven operation

### ⚡ Interrupt-Driven Design

* EINT0 external interrupt support
* Instant access to RTC configuration menu
* Responsive user interaction

### 🖥️ LCD Monitoring

Displays:

* Time
* Date
* Day
* ADC Value
* Menu Options
* System Status

---

## 🧩 Hardware Components

| Component        | Purpose                     |
| ---------------- | --------------------------- |
| LPC2129 ARM7 MCU | Main Controller             |
| LCD 16×2         | User Interface              |
| LDR Sensor       | Light Detection             |
| ADC Channel      | Sensor Data Acquisition     |
| RTC Module       | Time Management             |
| 4×4 Keypad       | User Input                  |
| LEDs             | Street Light Simulation     |
| Push Button      | EINT0 Interrupt Trigger     |
| Resistors        | Current Limiting & Pull-ups |

## 💻 Software Tools

* Keil µVision
* Proteus (Circuit Simulation)
* Flash Magic
* Embedded C
* Git & GitHub

---

## 🏗️ System Architecture

```text
                          RTC
                           │
                           v
+----------+       +--------------------+
| Keypad   |------>|      LPC2129       |
+----------+       |                    |
                    |   Decision Logic   |
+----------+       |                    |
| LDR      |------>|   ADC Conversion   |
+----------+       +--------+-----------+
                             │
                             v
                    +----------------+
                    |      LEDs      |
                    |  Street Lights |
                    +----------------+
                             ^
                             │
                    +-------------+
                    |  LCD 16x2   |
                    +-------------+
```

---

## ⚙️ Working Principle

The system continuously performs the following operations:

**Step 1 — Initialize:**
LCD, RTC, ADC, GPIO, Interrupts

**Step 2 — Read current:**
Hour, Minute, Second, Date

**Step 3 —**
Read LDR value through ADC.

**Step 4 —**
Determine whether the environment is Daytime or Nighttime, based on RTC and light intensity.

**Step 5 —**
Control street lights automatically.

**Step 6 —**
Monitor external interrupt (EINT0). When an interrupt occurs: open the RTC configuration menu, allow parameter modification, and save the updated values.

---

## 💡 Street Light Decision Logic

**LED OFF Condition**

```text
Time < 18:00
OR
ADC Value > 300
```

*Example:* Time = 14:00:00 → **Result: LED OFF**

**LED ON Condition**

```text
Time >= 18:00
AND
ADC Value <= 300
```

*Example:* Time = 19:30:00, ADC Value = 180 → **Result: LED ON**

---

## 🔄 System Flow

```text
                    START
                      │
                      v
              Initialize LCD
                      │
                      v
              Initialize RTC
                      │
                      v
              Initialize ADC
                      │
                      v
                 Read Time
                      │
                      v
                  Read LDR
                      │
                      v
      Time >= 6 PM AND ADC < Threshold ?
                /            \
             YES              NO
              │                │
        Turn LEDs ON     Turn LEDs OFF
              │                │
              └───────┬────────┘
                       v
              Update LCD Display
                       │
                       v
            Check EINT0 Interrupt?
                /            \
             YES              NO
              │                │
   Open RTC Config Menu     Continue Loop
              │                │
              └───────┬────────┘
                       v
                 Repeat (Loop)
```

---

## 🖱️ RTC Configuration Menu

The RTC settings can be modified using the keypad whenever EINT0 is triggered.

**Interrupt Pin**

```text
EINT0 → P0.16
```

**Menu Options**

```text
1 → Update Hour
2 → Update Minute
3 → Update Second
4 → Update Day
5 → Update Date
6 → Update Month
7 → Update Year
8 → Exit Menu
```

---

## 📂 Project Structure

```text
📁 EcoLight-Maestro
│
├── 📄 README.md
│   └── Complete project overview
│
├── 📁 docs
│   ├── 📄 README.md
│   ├── 📄 Abstract.pdf
│   ├── 📄 Project_Report.pdf
│   ├── 📄 Presentation.pptx
│   └── 📄 User_Manual.pdf (Optional)
│
├── 📁 inc
│   ├── 📄 README.md
│   ├── ADC.h
│   ├── ADC_defines.h
│   ├── KPM.h
│   ├── RTC.h
│   ├── defines.h
│   ├── delaydef.h
│   ├── kpm_defines.h
│   ├── lcd.h
│   ├── lcd_defines.h
│   ├── pinconnectblock.h
│   ├── pindefine.h
│   └── types.h
│
├── 📁 src
│   ├── 📄 README.md   ← Add this
│   ├── ADC.c
│   ├── KPM.c
│   ├── Miniproject_Main.c
│   ├── RTC.c
│   ├── Startup.s
│   ├── delayms.c
│   ├── lcd.c
│   └── pin.c
│
├── 📁 media
│   ├── 📄 README.md
│   ├── Circuit connections.png
│   └── miniproject 2026-08-08 150540.mp4
│
├── 📁 simulation
│   ├── 📄 README.md
│   ├── 2026-08-08.png
│   ├── 2026-08-08 (1).png
│   ├── 2026-08-08 (2).png
│   └── 2026-08-08 (3).png
```

---

## 🚦 Applications

* Smart Street Lighting
* Smart Cities
* Campus Lighting
* Industrial Lighting

## 🚀 Future Enhancements

* Wireless Monitoring using IoT
* GSM-Based Fault Reporting
* Solar Powered Street Lights
* Motion Detection for Adaptive Brightness
* Cloud-Based Energy Analytics
* Mobile Application Integration

## 🎓 Learning Outcomes

Through this project, I gained practical experience in:

* ARM7 LPC2129 Programming
* Embedded C Development
* RTC Programming
* ADC Interfacing
* Sensor Integration
* Interrupt Handling

---

## 👨‍💻 Author

**Ajay Manda**

B.Tech, Electrical & Electronics Engineering — Godavari Institute of Engineering and Technology

Embedded Systems Learner | ARM7 (LPC2129/LPC2148), Embedded C, UART/SPI/I2C/CAN
