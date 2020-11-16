

#include "SPIFFS.h"
#include <string.h>
#include <WiFi.h>
#include <Arduino_JSON.h>

#include <SPI.h>
#include "SD.h"

JSONVar _cfg;



int config_execute(JSONVar *cfg);
int config_wifi(JSONVar *cfg);
int config_save(JSONVar *cfg);
int config(const char *path);
int config_set_default();
int config_set_wifi_default();

int config_save(JSONVar *cfg)
{
  const char *path = (const char *) (*cfg)["path"];
  if (!path)
  {
    Serial.println("[CFG] Failed config save");
  }
  
  File file = SPIFFS.open(path, FILE_WRITE);if(!file){
    Serial.println("- failed to open file for writing");
    return 1;
  }
  
  if(file.print(JSON.stringify(*cfg)))
  {
    Serial.println("[CFG] Config saved");
  } 
  else 
  {
    Serial.println("[CFG] Failed config save");
    return 1;
  }
  
  return 0;
}

int config_execute(JSONVar *cfg)
{
  config_wifi(cfg);
}

int config_wifi(JSONVar *cfg)
{
  const char* ssid = (const char*) (*cfg)["wifi"]["ssid"];
  const char* pass = (const char*) (*cfg)["wifi"]["pass"];
  
  String mode = (const char*) (*cfg)["wifi"]["mode"];
  if (mode == "WIFI_STA")
  {
    WiFi.begin(ssid, pass);
    
    Serial.printf("[CFG] Connecting to '%s'..", ssid);
    
    int i = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(1000);
      if (i++ >= 10)
      {
        Serial.println(" failed");
        return config_set_wifi_default();
      }
    }
    
    Serial.println(" connected!");
  }
  else if (mode == "SOFT_AP")
  {
    Serial.printf("[CFG] Creating Soft AP '%s'\n", ssid);
    WiFi.softAP(ssid, pass);
    
    delay(1000);
    Serial.print("[CFG] IP address: ");
    Serial.println(WiFi.softAPIP());
    
    return 0;
  }
  
  Serial.print("[CFG] IP address: ");
  Serial.println(WiFi.localIP());
}

int config_set_wifi_default()
{
  uint64_t chipid = ESP.getEfuseMac();
  char str[32] = "";
  snprintf(str, sizeof(str), "ESTACAO_CEFET_%04X", (uint16_t)(chipid>>32));
  
  _cfg["wifi"]["mode"] = "SOFT_AP";
  _cfg["wifi"]["ssid"] = str;
  _cfg["wifi"]["pass"] = "";
  
  //config_save(&cfg);
  config_execute(&_cfg);
}

int config_set_default()
{
  _cfg["path"] = "/config/config.cfg";
  
  config_set_wifi_default();
  
  config_save(&_cfg);
  config_execute(&_cfg);
}

int config(const char *path)
{
  _cfg["path"] = path;
  
  if(!SPIFFS.begin()){
    Serial.printf("[CFG] SPIFFS Mount Failed\n");
    return 1;
  }
  
  File file = SPIFFS.open(path);
  if(!file || file.isDirectory()) {
    Serial.printf("[CFG] Failed to open '%s'\n", path);
    return 1;
  }
  
  //char buf[512] = "";
  //size_t s = sizeof(buf);
  int i = 0;
  
  String buf;
  while (file.available())
  {
    //if ((i + 1) >= s)
    //{
      //Serial.printf("[CFG] Error: '%s' is too big to parse!\n", path);
      //return 1;
    //}
    
    buf += (char) file.read();
    //buf[i++] = file.read();
  }
  
  //buf[i] = '\0';
  JSONVar tmp = JSON.parse(buf);
  Serial.print("cfg: ");
  Serial.println(tmp);
  
  if (JSON.typeof(tmp) != "string")
  {
    Serial.printf("[CFG] Error parsing '%s'\n", path);
    //Serial.println(buf);
    return 1;
  }
  
  _cfg = tmp;
  
  if (config_execute(&_cfg))
  {
    Serial.printf("[CFG] Failed config_execute\n");
  }
  
  return 0;
  //Serial.println(cfg);
}
