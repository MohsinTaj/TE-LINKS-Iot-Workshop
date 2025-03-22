#include <WiFi.h>
const char* ssid = "Your_WiFi";
const char* password = "Your_Password";
WiFiServer server(80);
void setup() {
  WiFi.begin(ssid, password);
  server.begin();
}
void loop() {
  WiFiClient client = server.available();
  if (client) {
    client.println("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>ESP Web Server</h1>");
    delay(10);
    client.stop();
  }
}