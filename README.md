### Node MCU Microcontroller integrated with the Arduino JSON library

This Arduino IDE code is to demonstrate how we can use the JSON response from external web sites
and parse them internally in the ARDUINO IDE.

This is useful for retrieving data from external sites from microcontrollers like NodeMCU/ESP8266.
For example, external sites that hold weather, stocks, historical data etc and provide it in JSON
format or CSV format.

This sample code is to be run on the Arduino IDE with a NodeMCU connected to it.
Here I am reaching out to arduinojson.org which is the provider of the JSON library for Arduino
over port 80 and retrieving some sample JSON response and parsing it in the code.

Before I begin, some basics and understanding of the terms used here can be found at:

I'm assuming that the user is familiar with setting up the NodeMCU microcontroller, installing the necessary driver,
connecting to the Wireless router, and installing libraries. (as this won't be covered in this tutorial)

NodeMCU ESP8266
https://www.nodemcu.com/index_en.html

Arduino JSON
https://arduinojson.org/v5/example/

Installing libraries in Arduino IDE.
https://www.arduino.cc/en/guide/libraries


Architecture used in this demo example:

![screen shot 2019-03-07 at 11 46 01 am](https://user-images.githubusercontent.com/14288989/53936492-eb346c00-40cf-11e9-9797-86bcf6e8098f.png)




Snapshot showing the Arduino IDE File->Examples->Arduino JSON examples after the library is installed.
![screen shot 2019-03-07 at 12 00 57 pm](https://user-images.githubusercontent.com/14288989/53936695-c7255a80-40d0-11e9-9b85-1f7a1806a26b.png)

<br>
<br>
<br>
<br>


Snapshot of the Arduino JSON premade library examples that can be used by modifying to suit our needs.
![screen shot 2019-03-07 at 12 02 39 pm](https://user-images.githubusercontent.com/14288989/53936765-fdfb7080-40d0-11e9-8e4b-a80bd99672b6.png)

<br>
<br>
<br>
<br>

Here, I am connecting to Arduinojson.org with port 80 in the IDE code and retrieve some sample JSON response.

The connection schematic is as shown in the diagram below.

Flow chart starts from NodeMCU which connects to my internal Home Router over WiFi.
The home WiFi router is connected to my Internet Service Provider. The code communicates to 
the http://arduinojson.org:80 and requests a Sample JSON response, and waits for a 
response in JSON and parses it and prints it on the serial monitor.

The response is printed on the Serial Monitor of the Arduino IDE and a snapshot is attached below.

<br>
<br>
<br>
<br>

A sample snapshot is shown below:

![screen shot 2019-03-07 at 12 15 09 pm](https://user-images.githubusercontent.com/14288989/53937315-baa20180-40d2-11e9-8e7e-c8811632a5a9.png)

