/*

  Project:       1Sheeld Library 
  File:          ProximitySensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#include "OneSheeld.h"
#include "ProximitySensorShield.h"


//Class Constructor
ProximitySensorShield::ProximitySensorShield() : ShieldParent(PROXIMITY_ID)
{
	value=0x00;
	isCallBackAssigned=false;
}
//Proximity Getter 
byte ProximitySensorShield::getValue()
{
	return value;
}

//ProximitySensor Input Data Processing 
void ProximitySensorShield::processData()
{
	//Checking Function-ID
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==PROXIMITY_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		//Users Function Invoked
		if (isCallBackAssigned && !OneSheeld.isInACallback())
		{
			OneSheeld.enteringACallback();
			(*changeCallBack)(value);
			OneSheeld.exitingACallback();
		}
	}
}
//Users Function Setter
void ProximitySensorShield::setOnValueChange(void (*userFunction)(byte proximityValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

#ifdef PROXIMITY_SHIELD
//Instatntiating Object
ProximitySensorShield ProximitySensor;
#endif