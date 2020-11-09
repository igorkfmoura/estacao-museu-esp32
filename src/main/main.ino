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
#include "include/rtc.c"

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
  if(openDb("/sd/data/museu.db", &db1)){
    return;
  }
  
  //dbClear(db); // Delete table museu
  dbSetup(db1);
  //rtcSetup();
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
  //String date_iso = rtcGetDate();
  String date_iso = "09/11/2020T12:58";
  float temperature = BMP280ReadTemperature();
  float humidity = BMP280ReadHumidity();
  float pressure = BMP280ReadPressure();
  float luminosity = analogRead(34);
  float co = 0.0;
  float dust = 0.0;
  float datalist[6] = {temperature, humidity, pressure, luminosity, co, dust};
  writeOnDB(date_iso.c_str(),datalist,db1);
}
