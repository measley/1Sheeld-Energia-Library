/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#include "OneSheeld.h"
#include "SMSShield.h"

// public functions
  SMSShieldClass::SMSShieldClass()
  {
  	text=0;
  	number=0;
  	isCallBackAssigned=false;
  }
void SMSShieldClass::send(char* number,char* text)
{
	OneSheeld.sendPacket(SMS_ID,0,SEND_SMS,2,new FunctionArg(strlen(number),(byte*)number),new FunctionArg(strlen(text),(byte*)text));
}

void SMSShieldClass::processData()
{
	byte x= OneSheeld.getFunctionId();
	if(x==GET_SMS)
	{

		if(text!=0)
		{
			free(text);
		}
		if (number!=0)
		{
			free(number);
		}
		int numberlength=OneSheeld.getArgumentLength(0);
		number=(char*)malloc(sizeof(char)*(numberlength+1));
		for (int j=0; j<numberlength; j++)
		{
			number[j]=OneSheeld.getArgumentData(0)[j];
		}
		number[numberlength]='\0';
		int textlength=OneSheeld.getArgumentLength(1);
		text=(char*)malloc(sizeof(char)*(textlength+1));

		for(int i=0 ;i<textlength;i++)
		{
			text[i]=OneSheeld.getArgumentData(1)[i];
		}
			text[textlength]='\0';

		if(isCallBackAssigned)
		{
			(*changeCallBack)(number,text);
		}
	}
}
void SMSShieldClass::setOnSmsReceive(void (*userFunction)(char * number ,char * text))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}
char * SMSShieldClass::getNumber()
{
	return number;
}

char * SMSShieldClass::getSms()
{
	return text;
}
// instantiate object for users
SMSShieldClass SMS;