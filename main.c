#include <mega16a.h>
#include <alcd.h>
#include <stdio.h>
#include <string.h>

#include "lib/dht-lib.h"

void main(void)
{
      //Variables
      float temperature;
      float humidity;

      //LCD Buffer
      char Buffer[32];

      // Alphanumeric LCD initialization
      // Connections are specified in the
      // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
      // Characters/line: 16
      lcd_init(16);
      lcd_puts("Starting...");

      //Setup
      DHT_Setup();

      //Loop
      while (1)
      {
            //Read from sensor
            DHT_Read(&temperature,&humidity);

            //Check status
            switch (DHT_GetStatus())
            {
                  case (DHT_Ok):
                        //Print temperature
                        //print(temperature[0]);

                        //Print humidity
                        //print(humidity[0]);

                        sprintf(Buffer,"Temp=%.2f H=%02.0f%%",temperature,humidity); 
                        lcd_clear();
                        lcd_puts(Buffer);

                        break;
                  case (DHT_Error_Checksum):
                        //Do something
                        break;
                  case (DHT_Error_Timeout):
                        //Do something else
                        break;
            }

            //Sensor needs 1-2s to stabilize its readings
            delay_ms(1000);
      }
}
