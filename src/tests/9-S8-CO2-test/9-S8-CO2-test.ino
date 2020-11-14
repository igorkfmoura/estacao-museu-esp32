/*
 Reports values from a K-series sensor back to the computer
 written by Jason Berger
 Co2Meter.com
*/
#include "kSeries.h" //include kSeries Library

kSeries K_30(13, 4); //RX TX

void setup()
{
 Serial.begin(115200); //start a serial port to communicate with the computer
}
void loop()
{
 Serial.print("Co2 ppm = ");
 Serial.println(K_30.getCO2('p'));
 
 delay(2000);
}
