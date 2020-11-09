#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <sqlite3.h>

WebServer server(80);
sqlite3 *db;

void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void handleRoot()
{
  char temp[400];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  float temperature = BMP280ReadTemperature();
  float pressure = BMP280ReadPressure();
  float altitude = BMP280ReadAltitude();

  Serial.println(temperature);

  snprintf(temp, 400,
#include "html.h"
           , hr, min % 60, sec % 60,
           temperature, pressure, altitude);

  server.send(200, "text/html", temp);
}

void handleAPI()
{
  char msg[610] = "%.02f,%.02f,%.02f";
  Serial.println("API");
  snprintf(msg, sizeof(msg), msg, BMP280ReadTemperature(), BMP280ReadPressure(), BMP280ReadAltitude());
  Serial.println(msg);
  server.send(200, "text/plain", msg);
}

void handleDashboard()
{
  char *zErrMsg = 0;
  int rc;
  sqlite3_stmt *res;
  const char *tail;
  const char *data = "Callback function called";
  char *sql = "SELECT * FROM museu ORDER BY rowid DESC LIMIT 10 ";
  rc = sqlite3_prepare_v2(db, sql, strlen(sql), &res, &tail);
  if (rc != SQLITE_OK)
  {
    String resp = "Failed to fetch data: ";
    resp += sqlite3_errmsg(db);
    sqlite3_close(db);
    Serial.println(resp.c_str());
    return;
  }

  server.setContentLength(CONTENT_LENGTH_UNKNOWN);
  String resp = "<html><head><title>Estação Ambiental Museu</title>\
          <meta http-equiv='refresh' content='5' />\
          <meta charset='utf-8'/>\
          <style>\
          body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; font-size: large; Color: #000088; }\
          #table{width:300px,height:100px}\
          </style><head><body><h1>Estação Ambiental Museu</h1>";

  resp += "<br><table cellspacing='1' cellpadding='1' border='1' id='table'><tr><td>Data<td>Temperatura</td><td>Humidade</td><td>Pressão</td><td>Luminosidade</td><td>Co2</td><td>Poeira</td></tr>";
  server.send(200, "text/html", resp.c_str());
  while (sqlite3_step(res) == SQLITE_ROW)
  {
    resp = "<tr><td>";
    resp += (const char *)sqlite3_column_text(res, 0);
    resp += "</td><td>";
    resp += sqlite3_column_double(res, 1);
    resp += "</td><td>";
    resp += sqlite3_column_double(res, 2);
    resp += "</td><td>";
    resp += sqlite3_column_double(res, 3);
    resp += "</td><td>";
    resp += sqlite3_column_double(res, 4);
    resp += "</td><td>";
    resp += sqlite3_column_double(res, 5);
    resp += "</td><td>";
    resp += sqlite3_column_double(res, 6);
    resp += "</td></tr>";

    server.sendContent(resp);
  }
  sqlite3_finalize(res);
}

void webServerSetup(sqlite3 *db1)
{
  db = db1;
  if (MDNS.begin("esp32"))
  {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.on("/getdata", handleAPI);
  server.on("/dashboard", handleDashboard);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}
