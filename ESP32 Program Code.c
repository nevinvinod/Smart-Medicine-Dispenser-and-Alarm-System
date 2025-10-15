#include <Wire.h>
#include <RTClib.h>
#include <BluetoothSerial.h>
#include <ESP32Servo.h>

RTC_DS3231 rtc;
BluetoothSerial ESP_BT;
String input;
const int enablepinT = 15;  // pin for esp8266
const int buzzer = 5;       // Pin for buzzer
const int always = 2;       // Pin for always-on functionality

Servo servoMotor1; // Motor 1 (Servo 1) Control Pin 26
Servo servoMotor2; // Motor 2 (Servo 2) Control Pin 25

void setup() {
  pinMode(enablepinT, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(always, OUTPUT); // Define the pin mode for always pin
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control");

  servoMotor1.attach(26); // Attaching servo motor 1 to pin 26
  servoMotor2.attach(25); // Attaching servo motor 2 to pin 25

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  digitalWrite(always, HIGH); // Set always pin to high

  // RTC time update
  DateTime now = rtc.now();
  Serial.print("Current time: ");
  print2digits(now.hour());
  Serial.print(":");
  print2digits(now.minute());
  Serial.print(":");
  print2digits(now.second());
  Serial.println();
  delay(1000);

  // Bluetooth control
  if (ESP_BT.available()) {
    input = ESP_BT.readString();
    Serial.println(input);
    
    int alarm1, alarm2, alarm3, hour1, minute1, hour2, minute2, hour3, minute3, med1_1, med1_2, med2_1, med2_2, med3_1, med3_2, tp1, tp2, tp3;
    
    if (sscanf(input.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &hour1, &minute1, &med1_1, &med1_2, &hour2, &minute2, &med2_1, &med2_2, &hour3, &minute3, &med3_1, &med3_2,&tp1,&tp2,&tp3) == 15) {
      Serial.println("Alarm 1 set time: " + String(hour1) + ":" + String(minute1));
      Serial.println("Alarm 2 set time: " + String(hour2) + ":" + String(minute2));
      Serial.println("Alarm 3 set time: " + String(hour3) + ":" + String(minute3));
      Serial.println(String(tp1)+","+String(tp2)+","+String(tp3));
      
      while (true) {
        now = rtc.now(); // Update current time
        Serial.print("ALARM TIME: ");
        Serial.print(hour1);
        Serial.print(":");
        Serial.print(minute1);
        Serial.print(",");
        Serial.print(hour2);
        Serial.print(":");
        Serial.print(minute2);
        Serial.print(",");
        Serial.print(hour3);
        Serial.print(":");
        Serial.print(minute3);        
        Serial.print(" CURRENT TIME: ");
        Serial.print(now.hour());
        Serial.print(":");
        Serial.print(now.minute());
        Serial.print(":");
        print2digits(now.second());
        Serial.println();
        delay(1000);
      
        if (tp1 == 1 && now.hour() == hour1 && now.minute() == minute1) {
            Serial.println("Alarm 1 activated!");
            digitalWrite(buzzer,HIGH);
            for (int i = 0; i < med1_1; i++) {
              servoMotor1.write(0); // Rotate servo motor 1 to start position (0 degrees)
              delay(2000);          // Wait for servo to reach start position
              for (int pos = 0; pos <= 180; pos += 1) { // Slowly increase position from 0 to 180
                servoMotor1.write(pos); // Set servo position
                delay(15); // Delay for smoother movement
              }
              delay(2000);           // Wait for servo to stabilize
            }
            for (int i = 0; i < med1_2; i++) {
              servoMotor2.write(0); // Rotate servo motor 2 to start position (0 degrees)
              delay(2000);          // Wait for servo to reach start position
              for (int pos = 0; pos <= 180; pos += 1) { // Slowly increase position from 0 to 180
                servoMotor2.write(pos); // Set servo position
                delay(15); // Delay for smoother movement
              }
              delay(2000);           // Wait for servo to stabilize
            }
            digitalWrite(buzzer,LOW);
            tp1= 0; // Reset tp3 after rotation
            digitalWrite(enablepinT,HIGH);
            delay(1000);
            digitalWrite(enablepinT,LOW);
        }
        if (tp2 == 1 && now.hour() == hour2 && now.minute() == minute2) {
          Serial.println("Alarm 2 activated!");
          digitalWrite(buzzer,HIGH);
          for (int i = 0; i < med2_1; i++) {
            servoMotor1.write(0); // Rotate servo motor 1 to start position (0 degrees)
            delay(2000);          // Wait for servo to reach start position
            for (int pos = 0; pos <= 180; pos += 1) { // Slowly increase position from 0 to 180
              servoMotor1.write(pos); // Set servo position
              delay(15); // Delay for smoother movement
            }
            delay(2000);           // Wait for servo to stabilize
          }
          for (int i = 0; i < med2_2; i++) {
            servoMotor2.write(0); // Rotate servo motor 2 to start position (0 degrees)
            delay(2000);          // Wait for servo to reach start position
            for (int pos = 0; pos <= 180; pos += 1) { // Slowly increase position from 0 to 180
              servoMotor2.write(pos); // Set servo position
              delay(15); // Delay for smoother movement
            }
            delay(2000);           // Wait for servo to stabilize
          }
          digitalWrite(buzzer,LOW);
          tp2= 0; // Reset tp3 after rotation
          digitalWrite(enablepinT,HIGH);
          delay(1000);
          digitalWrite(enablepinT,LOW);
        }
        if (tp3 == 1 && now.hour() == hour3 && now.minute() == minute3) {
          Serial.println("Alarm 3 activated!");
          digitalWrite(buzzer,HIGH);
          for (int i = 0; i < med3_1; i++) {
            servoMotor1.write(0); // Rotate servo motor 1 to start position (0 degrees)
            delay(2000);          // Wait for servo to reach start position
            for (int pos = 0; pos <= 180; pos += 1) { // Slowly increase position from 0 to 180
              servoMotor1.write(pos); // Set servo position
              delay(15); // Delay for smoother movement
            }
            delay(2000);           // Wait for servo to stabilize
          }
          for (int i = 0; i < med3_2; i++) {
            servoMotor2.write(0); // Rotate servo motor 2 to start position (0 degrees)
            delay(2000);          // Wait for servo to reach start position
            for (int pos = 0; pos <= 180; pos += 1) { // Slowly increase position from 0 to 180
              servoMotor2.write(pos); // Set servo position
              delay(15); // Delay for smoother movement
            }
            delay(2000);           // Wait for servo to stabilize
          }
          digitalWrite(buzzer,LOW);
          tp3= 0; // Reset tp3 after rotation
          digitalWrite(enablepinT,HIGH);
          delay(1000);
          digitalWrite(enablepinT,LOW);
        }
        if(tp1 == 0 && tp2 == 0 && tp3 == 0) {
          break; // Exit the loop after all alarms are activated
        }
        // Check for new input from Bluetooth
        if (ESP_BT.available()) {
          input = ESP_BT.readString();
          Serial.println(input);
          if (sscanf(input.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &hour1, &minute1, &med1_1, &med1_2, &hour2, &minute2, &med2_1, &med2_2, &hour3, &minute3, &med3_1, &med3_2,&tp1,&tp2,&tp3) == 15) {
            Serial.println("Alarm times updated.");
            break; // Exit the loop to update alarm times
          }
        }
        
        // Add delay to prevent flooding and to check time at regular intervals
        delay(1000);
      }
    } else {
      Serial.println("Invalid input");
    }
  }
}

void print2digits(int number) {
  if (number < 10) {
    Serial.print("0"); // Add leading zero for single digit numbers
  }
  Serial.print(number);
}