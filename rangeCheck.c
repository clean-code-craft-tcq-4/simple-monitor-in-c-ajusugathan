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
		printf("Warning!! : %s reaching threshold value ,Present %s value = %f\n",parameterValue,parameterValue,presentValue);
	}
}