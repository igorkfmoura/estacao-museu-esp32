#include <WiFiClient.h>

#include <sqlite3.h>
#include <Arduino_JSON.h>

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

#include "JSONHandler.h"

JSONHandler* json_handler;

AsyncWebServer server(80);

sqlite3 *db;

void handleNotFound(AsyncWebServerRequest * request)
{
  request->send(SPIFFS, "/index.html", "text/html");
}

void handleRoot(AsyncWebServerRequest * request)
{

}

void handleAPI(AsyncWebServerRequest * request)
{
  //char msg[610] = "%.02f,%.02f,%.02f";
  //Serial.println("API");
  //snprintf(msg, sizeof(msg), msg, BMP280ReadTemperature(), BMP280ReadPressure(), BMP280ReadAltitude());
  //Serial.println(msg);
  //request->send(200, "text/plain", msg);
}

void handleDashboard(AsyncWebServerRequest * request)
{
  char *zErrMsg = 0;
  int rc;
  sqlite3_stmt *res;
  const char *tail;
  const char data[] = "Callback function called";
  
  char sql[] = "SELECT * FROM museu ORDER BY rowid DESC LIMIT 10 ";
  rc = sqlite3_prepare_v2(db, sql, strlen(sql), &res, &tail);
  
  if (rc != SQLITE_OK)
  {
    String resp = "Failed to fetch data: ";
    resp += sqlite3_errmsg(db);
    sqlite3_close(db);
    Serial.println(resp);
    
    return;
  }

  JSONVar response;
  int i = 0;
  while (sqlite3_step(res) == SQLITE_ROW)
  {
    response[i]["Hora_UTC"]     = (const char *)sqlite3_column_text(res, 0);
    response[i]["Temperatura"]  = sqlite3_column_double(res, 1);
    response[i]["Humidade"]     = sqlite3_column_double(res, 2);
    response[i]["Pressão"]      = sqlite3_column_double(res, 3);
    response[i]["Luminosidade"] = sqlite3_column_double(res, 4);
    response[i]["Co2"]          = sqlite3_column_double(res, 5);
    response[i]["Poeira"]       = sqlite3_column_double(res, 6);
  }
  
  sqlite3_finalize(res);
  request->send(200, "application/json", JSON.stringify(response));
}

void webServerSetup(sqlite3 *db1)
{
  //if (MDNS.begin("esp32"))
  //{
    //Serial.println("MDNS responder started");
  //}

  server.serveStatic("/", SPIFFS, "/");
  
  //server.on("/getdata", handleAPI);
  server.on("/dashboard", handleDashboard);
  
  server.onNotFound(handleNotFound);
  server.begin();
  
  Serial.println("HTTP server started");
}
