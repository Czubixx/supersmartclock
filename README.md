<p align="center">
    <img src="/img/logo.png">
</p>

# SuperSmartClock🕒

Super Smart Clock is a perfect useful decoration, the cost of the entire clock is $ 20 which makes it really profitable, it uses a max7219 led matrix. It communicates with the user via the web interface and the mqtt protocol.

# 💡 Features 
- Support for mqtt protocol, possibility of integration with HASS
- Displaying notifications from HASS (mqtt)
- Displaying castom text via the web interface
- Automatic or manual brightness adjustment of the matrix
- Possibility to set audible alarms (alarm clock)
- Night mode - matrix blanking at designated times
- Getting the time from NTP servers (RTC module is not required) and configuration of time zones
- Displaying the current temperature and publishing using mqtt
- Ability to display the weather forecast from openweathermap.org
- Remotely updating from a bin file (ArduinoOTA)

# 🦺 Construction

### Required components

- ESP8266 (recommended NodeMCU)
- LED matrix 32x8 MAX7219
- Touch button TTP223
- Temperature sensor DS18B20
- Resistor 4.7K Ohm 5% 1/4W
- Resistor 10K Ohm 5% 1/4W
- Photoresistor 50-100kΩ 100mW GM5539

### Schematic diagram

Connect all the elements according to the diagram, in case of problems contact me at hubert.kozlowski07@gmail.com

<p align="center">
    <img src="/img/schemat.png">
</p>

### Software

The bin file should be downloaded from <link> and upload to esp8266 using esphome-flasher or tasmotizer
