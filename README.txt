💊 Smart Medicine Dispenser System

<p align="center">
  <img src="thumbnail.jpg" alt="Floating Point ALU Project Thumbnail" width="800">
</p>

A Smart Medicine Alarm & Dispenser System designed to help patients take medicines on time through automation, IoT, and cloud connectivity. The system combines hardware control and a mobile app interface to ensure accurate and timely medicine dispensing.

🚀 Overview

This project automates the medicine management process by integrating hardware dispensing, alarm notifications, and cloud connectivity.
The system ensures patients never miss a dose and caregivers can remotely monitor schedules and alerts.

⚙️ Features

📱 Android Application for medicine scheduling and alarm management

⏰ Automatic Medicine Dispensing based on scheduled times

🔔 Local Alarms triggered via ESP32 and ESP8266 microcontrollers

☁️ Cloud Connectivity to send real-time alerts and notifications to external users

💡 User-friendly Interface for setting medicine times and dosage

🔋 Low Power Operation with efficient standby management

🧩 Hardware Components

ESP32 – Controls medicine dispensing mechanism and manages connectivity

ESP8266 – Handles local alerts and Wi-Fi communication

Servo Motors – Operate dispensing trays

Buzzer & LED – Provide local alarm indication

Power Supply Module – For stable power delivery

🖥️ Software Components

Android App - MIT App Iventor

Cloud - Blink IoT

Arduino IDE / ESP-IDF – For firmware programming

C/C++ – For embedded programming on ESP boards

🧠 Working Principle

The user schedules medicine timings using the Android application.

The app syncs data with the cloud server.

The ESP32 retrieves schedule data and activates the dispenser mechanism at the right time.

A buzzer and LED alert the patient locally.


Notifications are sent to caregivers or family members via the cloud.
