#include "include/config.c"
#include "include/database.c"


void setup() 
{

  Serial.begin(115200);
  
  if (config("/config/config.cfg")) 
  {
    config_set_default();
  }

  delay(2000);
  database_setup();
}

void loop() 
{
  database_save_data();

  delay(5000);
}
