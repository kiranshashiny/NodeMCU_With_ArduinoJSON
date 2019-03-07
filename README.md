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

NodeMCU ESP8266
https://www.nodemcu.com/index_en.html

Arduino JSON
https://arduinojson.org/v5/example/

Architecture used in this demo example:

![screen shot 2019-03-07 at 11 46 01 am](https://user-images.githubusercontent.com/14288989/53936492-eb346c00-40cf-11e9-9797-86bcf6e8098f.png)

Here, I am connecting to Arduinojson.org with port 80 in the code and retrieve some sample response.

The connection schematic is as shown in the diagram below.

Flow chart starts from NodeMCU which connects to my internal Home Router over WiFi.
The router is connected to my Internet Service Provider. The code communicates to 
the http://arduinojson.org:80 and requests a Sample JSON response.

The Code ( or the Arduino Sketch ) waits for a response after sending the request,
gets the response, parses it and prints it.

The response is printed on the Serial Monitor of the Arduino IDE and a snapshot is attached below.


