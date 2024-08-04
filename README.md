# IKEA-VINDRIKTNING-for-Homekit
Integrating the IKEA VINDRIKTNING in Homekit using an ESP32 and Homespan

This code uses the [Homespan library](https://github.com/HomeSpan/HomeSpan). Install Homepsan according to [their manual](https://github.com/HomeSpan/HomeSpan/blob/master/docs/GettingStarted.md).

Download the full folder available in this repository, and open VINDRIKTNING-Homespan.ino in Arduino IDE.
com.ino file manages communication and tests with the sensor part, and DEV_Sensors.h manages the Homespan part.

On Hardware side, I followed [this documentation](https://github.com/Hypfer/esp8266-vindriktning-particle-sensor/tree/master?tab=readme-ov-file) for soldering the pins.
On Air Quality Sensor, solder wires on 5+V, GND and REST. Connect to the ESP32 these wires to +5, GND and PIN16 respectively (Pin 16 or anyother pin you selected in the code).

Needs probably some debuging and cleanup. More coming soon!

# TO-DO
Add a historic of data using homespan weblog service
