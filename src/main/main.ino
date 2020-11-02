#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <sqlite3.h>
#include <SPI.h>
#include <FS.h>
#include "SD.h"

#include "include/BMP280.c"
#include "include/webserver.c"
#include "include/Database.c"

const char *ssid = "DNAModas";
const char *password = "mengao81";

sqlite3 *db1;
int timer = 0;

void setup() {

 
  int rc;
  sqlite3_stmt *res;
  int rec_count = 0;
  const char *tail;

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

  SPI.begin();
  SD.begin();
  sqlite3_initialize();

  // Open database
  if (openDb("/sd/data/museu.db", &db1))
    return;


  BMP280Setup();
  webServerSetup(db1);
  
  //readDB(db1);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  if (millis() - timer > 2000){
    saveData();
    timer = millis();
  }
}

void saveData(){
  float temperature = BMP280ReadTemperature();
  float pressure = BMP280ReadPressure();
  float altitude = BMP280ReadAltitude();
  float datalist[3] = {temperature,pressure,altitude};
  writeOnDB(datalist,db1);
}
