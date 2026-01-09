# Water-Quality-Monitoring-System  
**Ensuring Pure Water Through Intelligent Monitoring**

## Overview

The **Water-Quality-Monitoring-System** is an open-source hardware and software solution designed to monitor and assess water quality in real time. The system integrates multiple sensors to measure critical water parameters such as **pH**, **Total Dissolved Solids (TDS)**, **turbidity**, and **temperature**, providing actionable insights into water safety and purity.

This project is suitable for applications in domestic water monitoring, environmental studies, agriculture, and educational or research environments.

---

## Features

- **Multi-Parameter Sensing**  
  Measures pH, TDS, turbidity, and temperature for a comprehensive water quality profile.

- **Real-Time Monitoring**  
  Displays live sensor readings on an LCD for immediate visibility.

- **Temperature Compensation**  
  Improves TDS accuracy by adjusting readings based on water temperature.

- **Modular and Extensible Design**  
  Sensor modules can be replaced, upgraded, or expanded as required.

- **Water Safety Indicators**  
  LEDs or visual indicators signal whether measured values fall within safe thresholds.

---

## Built With

- Microcontroller platform (e.g., Arduino-compatible board)
- Water quality sensors (pH, TDS, turbidity, temperature)
- LCD display module
- Embedded firmware (language dependent on microcontroller)

> **Note:** Specific hardware models and libraries may vary based on implementation.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Built With](#built-with)
- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

---

## Getting Started

Follow the instructions below to set up the project locally and deploy it on compatible hardware.

---

## Prerequisites

- Git
- Compatible microcontroller (e.g., Arduino Uno / Nano)
- Arduino IDE or equivalent development environment
- Required sensor modules:
  - pH sensor
  - TDS sensor
  - Turbidity sensor
  - Temperature sensor (e.g., DS18B20)
- LCD display (I2C or parallel)

---

## Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/Rajarshi-adesara-2909/Water-Quality-Monitaring-System.git
   
2. **Navigate to the project directory**
   ```bash
   cd Water-Quality-Monitaring-System

   
3. ## Open the project in Arduino IDE:
- Launch Arduino IDE
- Open the main .ino file from the project folder

4. ##Install required libraries:

- Open Arduino IDE → Library Manager
- Install libraries for:
  - LCD (I2C or standard)
  - Temperature sensor
  - Any sensor-specific dependencies

##Usage

- Connect all sensors and the LCD according to the circuit diagram.
- Ensure correct power supply connections.
- Upload the code to the microcontroller.
- Power on the system.
- Observe real-time water quality readings on the LCD display.
- Monitor LED indicators to determine water safety status.
