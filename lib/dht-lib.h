#ifndef DHT_H_INCLUDED
#define DHT_H_INCLUDED
/*
||
||  Filename:	 		DHT.h
||  Title: 			    DHTxx Driver
||  Author: 			Efthymios Koktsidis
||	Email:				efthymios.ks@gmail.com
||  Compiler:		 	AVR-GCC
||	Description:
||	This library can drive DHT11 and DHT22 sensors.
||
||  Edit by Liyanboy74 for CodevisionAVR
||  https://github.com/liyanboy74
||
*/

//Includes
#include <mega16a.h>
#include <stdint.h>
#include <delay.h>

//----- Auxiliary data -------------------//
#define DHT11						 1
#define DHT22						 2
#define DHT_ReadInterval			1500

#define __DHT_Delay_Setup			2000


#define DHT_Type	DHT11          //DHT11 or DHT22

#define DHT_DDR 	DDRB.3
#define DHT_PORT	PORTB.3
#define DHT_PIN 	PINB.3

#define Low			0
#define High		1

#define Input		0
#define Output		1

enum DHT_Status_t
{
	DHT_Ok,
	DHT_Error_Humidity,
	DHT_Error_Temperature,
	DHT_Error_Checksum,
	DHT_Error_Timeout
};
//-----------------------------------------//

//----- Prototypes---------------------------//
void DHT_Setup();
enum DHT_Status_t DHT_GetStatus();
enum DHT_Status_t DHT_ReadRaw(uint8_t *Data);
enum DHT_Status_t DHT_GetTemperature(float *Temperature);
enum DHT_Status_t DHT_GetHumidity(float *Humidity);
enum DHT_Status_t DHT_Read(float *Temperature, float *Humidity);
float DHT_CelsiusToFahrenheit(float Temperature);
float DHT_CelsiusToKelvin(float Temperature);
//-------------------------------------------//
#endif
