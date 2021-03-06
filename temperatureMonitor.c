#include <stdio.h>
#include "BmsData.h"
warningInfo_st temperatureData_st;

int IsTemperatureOk(float temperature) 
{
	int ErrorStatus=0;
	temperatureData_st.parameterValue=0;
	temperatureData_st.warningLevel=0;
    ErrorStatus=valueRangeCheck(temperature,TEMPERATURE_MINIMUM,TEMPERATURE_MAXIMUM);
	temperatureData_st.warningLevel=valueRangeCheck(temperature,TEMPERATURE_WARNING_LEVEL_MINIMUM,TEMPERATURE_WARNING_LEVEL_MAXIMUM);
	if(ErrorStatus)
	{
		printf(" %s %s %s : %s %f\n",ERROR,TEMPERATURE,ERROR_COMMENT,PRESENT_VALUE,temperature);
	}
	temperatureData_st.parameterValue=temperature;
	return(!ErrorStatus);
}
