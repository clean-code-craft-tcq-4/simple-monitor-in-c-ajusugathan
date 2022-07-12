#include "BmsData.h"
#include <stdio.h>


int valueRangeCheck(float actualValue,float minimumValue,float maximumValue)
{
	return(actualValue < minimumValue || actualValue > maximumValue);
}

void printWarningMessage(int WarningLevel,float presentValue,char * parameterValue)
{
	if(WarningLevel)
	{
		printf("%s %s %s : %s %f\n",WARINING,parameterValue,WARNING_COMMENT,PRESENT_VALUE,presentValue);
	}
}
