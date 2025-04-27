# Glucose Meter Project

## Overview

This is an open-source project for building a low-cost glucose meter using Arduino and other components. The goal of this project is to provide an affordable and accessible solution for people with diabetes to monitor their blood sugar levels.

### Features

* Measures blood sugar levels using a glucose meter strip
* Sends data to a NodeMCU board for storage and display on an LCD module
* Includes features such as debounce and timing to ensure accurate measurements
* Supports multiple calibration modes for different glucose meter strips

## Components Used

* Arduino board (e.g., Arduino Uno or Mega)
	+ Compatible with other Arduino boards, but may require modifications to the code
* NodeMCU board
	+ ESP8266-based board for wireless communication and data storage
* Liquid Crystal Display (LCD) module
	+ I2C-compatible LCD module for displaying glucose level readings
* SoftwareSerial library
	+ Library for serial communication between Arduino and NodeMCU boards
* RTClib library
	+ Library for real-time clock functionality on the NodeMCU board
* Wire library
	+ Library for I2C communication between NodeMCU board and LCD module

## Hardware Setup

### Glucose Meter

1. Connect the glucose meter strip to the analog input pin (A0) on the Arduino board.
2. Ensure that the glucose meter strip is securely connected to prevent electrical noise or interference.

### NodeMCU Board

1. Connect the NodeMCU board to the Arduino board using serial communication pins (TX/RX).
	+ Set baud rate to 115200 for optimal communication
2. Connect the LCD module to the I2C pins on the NodeMCU board.
	+ SCL pin: D4
	+ SDA pin: D5

### LCD Module

1. Ensure that the LCD module is properly connected to the I2C pins on the NodeMCU board.
2. Calibrate the LCD module for optimal display of glucose level readings.

## Code Organization

The code is organized into two main files:

* `GLUCOSE_METER.ino`: This file contains the code for the glucose meter itself, including the measurement and calculation of blood sugar levels.
	+ Includes features such as debounce and timing to ensure accurate measurements
* `send_to_nodemcu.ino`: This file contains the code for sending data from the glucose meter to the NodeMCU board.

## Usage

### Initial Setup

1. Connect the glucose meter strip to the Arduino board.
2. Upload the `GLUCOSE_METER.ino` code to the Arduino board.
3. Connect the NodeMCU board to the Arduino board using serial communication pins (TX/RX).
4. Upload the `send_to_nodemcu.ino` code to the NodeMCU board.

### Operation

1. Apply a drop of blood to the glucose meter strip.
2. The glucose meter will measure and display the blood sugar level reading on the LCD module.
3. Data is sent to the NodeMCU board for storage and further processing.

## Troubleshooting

* Check that the glucose meter strip is properly connected to the analog input pin on the Arduino board.
* Ensure that the NodeMCU board and Arduino board are communicating correctly using serial communication.
* Verify that the LCD module is properly connected to the I2C pins on the NodeMCU board.

## Contributing

Contributions to this project are welcome! If you have any suggestions or improvements, please submit a pull request.

### Reporting Issues

If you encounter any issues with the code or hardware setup, please report them using the GitHub issue tracker.

## License

This project is licensed under the MIT License. Please see the LICENSE file for details.

## Credits

This project was inspired by various open-source projects and contributions from the community. We would like to extend our gratitude to all contributors who have helped make this project possible.