#include <WiFi.h>

#include "include/BMP280.c"
#include "include/webserver.c"

const char *ssid = "Cafe's Airport TC";
const char *password = "25102001";

void setup(void) 
{
  Serial.begin(9600);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  BMP280Setup();
  webServerSetup();
}

void loop(void) {
  server.handleClient();
}
