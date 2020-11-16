#include "include/config.c"
#include "include/database.c"
#include "include/webserver.c"

void setup()
{

  Serial.begin(115200);

  delay(2000);

  if (config("/config/config.cfg"))
  {
    config_set_default();
  }


  delay(2000);
  database_setup();
  webserver_setup();

  analogSetSamples(4);
  analogSetClockDiv(8);

}

void loop()
{
  static uint64_t t = 0;

  
  if ((millis() - t) > 10000)
  {
    database_save_data();
    t = millis();
  }
}
