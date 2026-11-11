/* Smart Plant Watering System with Blynk (No LCD) */

#define BLYNK_TEMPLATE_ID "TMPL3QABczm15"
#define BLYNK_TEMPLATE_NAME "Smart Plant Watering System"
#define BLYNK_AUTH_TOKEN "ljvfVYdgS8pTB-l7UrG_hrdHMxfkMdyV"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "realme GT 6T";
char pass[] = "77654321";

BlynkTimer timer;

#define sensor A0
#define waterPump D4

// Calibration values: replace with stable measured readings.
const int DRY_VALUE = 1023;
const int WET_VALUE = 450;

bool Relay = false;

// Pump is OFF when the active-LOW relay input is HIGH.
void pumpOff() {
  digitalWrite(waterPump, HIGH);
  Relay = false;
  Serial.println("Motor is OFF");
}

void pumpOn() {
  digitalWrite(waterPump, LOW);
  Relay = true;
  Serial.println("Motor is ON");
}

BLYNK_CONNECTED() {
  // Start with the pump OFF after connecting to Blynk.
  pumpOff();
  Blynk.virtualWrite(V1, 0);
}

BLYNK_WRITE(V1) {
  int state = param.asInt();

  if (state == 1) {
    pumpOn();
  } else {
    pumpOff();
  }
}

void soilMoistureSensor() {
  int raw = analogRead(sensor);

  // Map dry soil to 0% and wet soil to 100%.
  int moisture = map(raw, DRY_VALUE, WET_VALUE, 0, 100);
  moisture = constrain(moisture, 0, 100);

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print("  Moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  if (Blynk.connected()) {
    Blynk.virtualWrite(V0, moisture);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(waterPump, OUTPUT);
  pumpOff();

  timer.setInterval(1000L, soilMoistureSensor);

  Serial.println("Starting Smart Plant Watering System...");

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
  timer.run();
}