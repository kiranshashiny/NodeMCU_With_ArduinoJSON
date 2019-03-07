/* This program sends JSON request to arduinojson.org - port 80 and gets a sample 
 *  response.
 *  Prints it after parsing. Look for the response in Arduino IDE Serial Monitor.
 *  Author : Shashi Kiran
 *  Date : 7 Mar 2019
 *  
 *  Prerequisites : Install Arduino JSON library from https://arduinojson.org/
 *  NodeMCU Repo library has to be installed in the IDE.
 *  NodeMCU to be connected to the home WiFi router.
 *
 *   To Plug and Playthis code, replace the WiFi Credentials below.
 * 
 *  Output : Open the Serial Monitor and view the response (that was parsed in this code)
 *      Sample response that you will see in the Serial Monitor is shown below. NETGEAR is the name of my WiFi Router.           
 *
 *      Connecting to NETGEAR84
 *
 *	WiFi connected
 *	IP address: 
 *	192.168.1.15
 *	Connecting...
 *	Connected!
 *	Response:
 *	gps
 *	1351824120
 *	48.756081
 *	2.302038
 *	
 *
*/

#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <SPI.h>



#ifndef STASSID
#define STASSID "NETGEAR84"   /* Your WiFi Router credentials */
#define STAPSK  "XXXXXXX"     /* User Id and Password */
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

const char* host = "arduinojson.org";
const uint16_t port = 80;

void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);


  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println(F("Connecting..."));
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(5000);
    return;
  }
  
  // Connect to HTTP server
  client.setTimeout(10000);
  if (!client.connect("arduinojson.org", 80)) {
    Serial.println(F("Connection failed"));
    return;
  }

  Serial.println(F("Connected!"));

  // Send HTTP request
  client.println(F("GET /example.json HTTP/1.0"));
  client.println(F("Host: arduinojson.org"));
  client.println(F("Connection: close"));
  if (client.println() == 0) {
    Serial.println(F("Failed to send request"));
    return;
  }

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.1 200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));
    return;
  }

  // Allocate the JSON document
  // Use arduinojson.org/v6/assistant to compute the capacity.
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonDocument doc(capacity);

  // Parse JSON object
  DeserializationError error = deserializeJson(doc, client);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  // Extract values
  Serial.println(F("Response:"));
  Serial.println(doc["sensor"].as<char*>());
  Serial.println(doc["time"].as<long>());
  Serial.println(doc["data"][0].as<float>(), 6);
  Serial.println(doc["data"][1].as<float>(), 6);

  // Disconnect
  client.stop();
}

void loop() {

}
