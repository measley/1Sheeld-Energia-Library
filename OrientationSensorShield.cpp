#include "OneSheeld.h"
#include "OrientationSensorShield.h"

OrientationSensorShield::OrientationSensorShield()
{
	valueX=0;
	valueY=0;
	valueZ=0;
	isCallBackAssigned=false;
}


float OrientationSensorShield::getX()
{
	return valueX;
}

float OrientationSensorShield::getY()
{
	return valueY;
}

float OrientationSensorShield::getZ()
{
	return valueZ;
}

void OrientationSensorShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==ORIENTATION_VALUE)
	{
		valueX=0;
		valueY=0;
		valueZ=0;
		//getting the float of first 4bytes
		getfloat.data[0]=OneSheeld.getArgumentData(0)[0];
		getfloat.data[1]=OneSheeld.getArgumentData(0)[1];
		getfloat.data[2]=OneSheeld.getArgumentData(0)[2];
		getfloat.data[3]=OneSheeld.getArgumentData(0)[3];
		valueX=getfloat.num;
	    //getting the float of second 4bytes
	    getfloat.data[0]=OneSheeld.getArgumentData(1)[0];
		getfloat.data[1]=OneSheeld.getArgumentData(1)[1];
		getfloat.data[2]=OneSheeld.getArgumentData(1)[2];
		getfloat.data[3]=OneSheeld.getArgumentData(1)[3];
		valueY=getfloat.num;
	    //getting the float of third 4bytes
	    getfloat.data[0]=OneSheeld.getArgumentData(2)[0];
		getfloat.data[1]=OneSheeld.getArgumentData(2)[1];
		getfloat.data[2]=OneSheeld.getArgumentData(2)[2];
		getfloat.data[3]=OneSheeld.getArgumentData(2)[3];
		valueZ=getfloat.num;

		if(isCallBackAssigned)
		{
			(*changeCallBack)(valueX,valueY,valueZ);
		}
	}
}

void OrientationSensorShield::setOnValueChange(void (*userFunction)(float valueX,float valueY ,float valueZ))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

OrientationSensorShield OrientationSensor;