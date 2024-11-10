# Smart Scape: Arduino Home Automation System

## Introduction & Objective

Smart Scape is a smart home robotics model built using Arduino and other components to provide both user accessibility and autonomous safety measures. The primary objective is to design and implement a home automation system to enhance convenience and safety. Automatic features include door opening upon a person’s arrival and room lighting based on darkness levels, while safety features include fire detection and flammable gas detection.
![DALL·E 2024-11-10 12 10 41 - A smart home automation system built with Arduino components in a home setting  Display an Arduino Uno board connected to various sensors and actuator](https://github.com/user-attachments/assets/b6d676e6-8d8e-47d3-b033-0553e3b7cd6f)

## Real-world Need

This autonomous smart home solution can be used in homes, offices, hotels, or any public space to enhance safety and convenience. Features such as automatic door opening and lighting can improve accessibility and energy efficiency, while safety measures like gas and fire detection are crucial for preventing accidents and saving lives.


## Demonstration Video

[![Smart Scape Demo](https://img.youtube.com/vi/rzl3d3x_Jic/0.jpg)](https://www.youtube.com/watch?v=rzl3d3x_Jic)


## Project Report

[project report.pdf](https://github.com/shihabmuhtasim/Smart-Scape/files/15421342/project.report.pdf)

## GitHub Link
[GitHub Repository](https://github.com/shihabmuhtasim/Smart-Scape)

## Components

- Arduino Uno
- Breadboard
- Ultrasonic Sensor
- Mini Servo Motor SG-90
- LDR Sensor
- LEDs
- Thermistor
- MQ2 Gas Sensor
- Buzzer
- Resistors
- Jumper Wires

## Diagram
![circuitdiagram](https://github.com/shihabmuhtasim/Smart-Scape/assets/92597456/7f9cb92f-8f43-4a41-8ae7-b413789ba059)


## Functionality

### Automatic Door

An ultrasonic sensor is used to detect someone in front of the door, activating a servo motor to open it. The sensor measures distance by sending and receiving sound waves.

### Automatic Light

Lighting turns on automatically when it becomes dark, utilizing an LDR sensor to detect surrounding light intensity.

### Smoke or Flammable Gas Detector

A MQ2 gas sensor in the kitchen detects smoke or flammable gases, triggering a buzzer alarm when concentrations surpass a threshold.

### Fire Detection

A thermistor detects fires, with the Arduino activating a buzzer alarm and opening the door for immediate evacuation. Connected appliances are also disabled for added safety.

## Code Explanation

### Initialization of Variables

The code initializes variables and pins, including those for sensors, actuators, and constants used in equations.

### Setup Function

The `setup()` function initializes servo motors, pins, and serial communication.

### Loop Function

The `loop()` function contains tasks for door control, LDR and LED control, buzzer control, and temperature decision.

### Ultrasonic Sensor Function

The `ultra_sonic()` function reads distance from the ultrasonic sensor using sound wave reflection.

### Temperature Sensor Function

The `temp()` function reads temperature from the thermistor using analog signals and calculates temperature based on resistance values.

## Image
![Snapchat-282876004~2](https://github.com/shihabmuhtasim/Smart-Scape/assets/92597456/c4df123c-d28e-458b-a87d-3f329c1f16bf)



