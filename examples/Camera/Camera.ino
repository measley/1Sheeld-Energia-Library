/*
Example illustrates Sensing the Light and if its beyond a certain
Limit take a Picture
*/

/*Include OneSheeld Library*/ 
#include <OneSheeld.h>


void setup ()
{
  /*Start UART communication on buadrate 57600*/
  OneSheeld.begin();
  /*Set the Flash of the Camera to be On while capturing*/
  Camera.setFlash(FLASH_ON);
}


void loop ()
{
  /*Always get the value of the Light Sensor*/
  if(LightSensor.getValue()<100&&LightSensor.getValue()>0)
  {
    /*Capture a picture*/
    Camera.rearCapture();
    /*Wait a second to handle the next capturing*/
    delay(1000);
  }
  
}
