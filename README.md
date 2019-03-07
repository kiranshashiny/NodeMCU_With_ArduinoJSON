### Node MCU integrated with the Arduino JSON library

This sample code is to be run on the Arduino IDE and a NodeMCU connected to it.

The code is to demonstrate how we can use the JSON response from external web sites
and parse them internally in the ARDUINO IDE.

Here, I connect to Arduinojson.org with port 80 in the code and retrieve some sample response.

The connection schematic is as shown in the diagram below.

Flow chart starts from NodeMCU which connects to my internal Home Router over WiFi.
The router is connected to my Internet Service Provider. The code communicates to 
the http://arduinojson.org:80 and requests a Sample JSON response.

The Code ( or the Arduino Sketch ) waits for a response after sending the request,
gets the response, parses it and prints it.

The response is printed on the Serial Monitor of the Arduino IDE and a snapshot is attached below.


