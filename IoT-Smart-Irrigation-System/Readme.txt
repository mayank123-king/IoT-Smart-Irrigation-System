
==================================================
       IoT SMART IRRIGATION SYSTEM
==================================================

PROJECT TITLE:
Automated Plant Irrigation System Using NodeMCU ESP8266
and Self-Hosted Blynk Legacy Infrastructure.

TEAM MEMBERS:
1. Anuj Parihar - 20247015
2. Sudarshan Jha - 20247051
3. Aman Kharwar - 20247010
4. Mayank Gupta - 20247027


--------------------------------------------------
1. PROJECT DESCRIPTION
--------------------------------------------------

This project presents an IoT-based automated plant
irrigation system using NodeMCU ESP8266 and a soil
moisture sensor.

The system measures soil moisture and uses a
predefined threshold to determine whether watering
is required.

The ESP8266 controls a relay module, which is
intended to switch the external DC water pump.

The project also uses a self-hosted Blynk Legacy
server architecture for planned remote monitoring
and manual control.


--------------------------------------------------
2. SUBMITTED FILES
--------------------------------------------------

Firmware:
- PlantWatering_NodeMCU.ino

Hardware:
- Circuit diagram
- Hardware reference images
- Component connection details

Documentation:
- Final Project Report
- Final Research Paper

Screenshots:
- Local server administration console
- Mobile application dashboard
- Firmware screenshots

README.txt:
- Project description
- Execution instructions
- Software requirements


--------------------------------------------------
3. HARDWARE REQUIREMENTS
--------------------------------------------------

1. NodeMCU ESP8266
2. Soil Moisture Sensor
3. One-channel Relay Module
4. DC Submersible Water Pump
5. External DC Power Supply
6. Breadboard
7. Connecting Wires
8. USB Cable


--------------------------------------------------
4. PIN CONFIGURATION
--------------------------------------------------

Soil Moisture Sensor AO -> A0
Relay Input             -> D3
Pump                    -> Relay COM/NO
Pump Power              -> External DC Supply


--------------------------------------------------
5. SOFTWARE REQUIREMENTS
--------------------------------------------------

1. Arduino IDE
2. ESP8266 Arduino Board Package
3. ESP8266WiFi Library
4. Blynk Library (for planned integration)
5. Java Runtime (for local server)
6. Community-maintained Blynk Android Application


--------------------------------------------------
6. HOW TO RUN THE CODE
--------------------------------------------------

STEP 1:
Install Arduino IDE.

STEP 2:
Install the ESP8266 board package using Boards Manager.

STEP 3:
Connect NodeMCU ESP8266 to your computer using USB.

STEP 4:
Open PlantWatering_NodeMCU.ino in Arduino IDE.

STEP 5:
Select the appropriate NodeMCU board and COM port.

STEP 6:
Verify sensor and relay connections.

STEP 7:
Compile and upload the firmware.

STEP 8:
Open Serial Monitor to observe sensor readings.

STEP 9:
Test the moisture threshold and relay logic using
a properly connected and rated hardware setup.


--------------------------------------------------
7. WORKING PRINCIPLE
--------------------------------------------------

The soil moisture sensor provides an analog reading
through pin A0.

The controller compares the reading with a threshold
value of 400.

If ADC reading > 400:
- Soil is considered dry.
- D3 becomes LOW.
- Active-LOW relay turns ON.
- Pump is intended to turn ON.

If ADC reading <= 400:
- Soil is considered sufficiently moist.
- D3 becomes HIGH.
- Relay remains OFF.
- Pump remains OFF.

Actual calibration is required for different soil types.


--------------------------------------------------
8. BLYNK LEGACY INFRASTRUCTURE
--------------------------------------------------

The project uses a community-maintained Java server
fork for local Blynk Legacy infrastructure.

Server:
https://github.com/Peterkn2001/blynk-server

Android Application:
https://github.com/BlynkMobile/Blynk-Android-App

Port 9443: HTTPS administration.
Port 8080: Hardware TCP communication.

Local server and mobile dashboard setup have been
prepared. Final firmware integration is pending.


--------------------------------------------------
9. IMPLEMENTATION STATUS
--------------------------------------------------

COMPLETED:
- Local server deployment
- Admin console configuration
- User provisioning
- Mobile application setup
- Dashboard configuration
- Firmware control logic draft
- Technical documentation

PENDING:
- Local server IP integration in firmware
- Physical breadboard wiring
- Pump integration
- Soil moisture calibration
- Complete hardware testing
- Remote control validation


--------------------------------------------------
10. SAFETY AND SECURITY
--------------------------------------------------

- Use a suitable external DC supply for the pump.
- Check relay voltage and current ratings.
- Keep motor and controller power requirements separate.
- Never publish Wi-Fi passwords or authentication tokens.
- Disconnect power before changing circuit connections.
- Use appropriate electrical protection and isolation.


--------------------------------------------------
END 
--------------------------------------------------
