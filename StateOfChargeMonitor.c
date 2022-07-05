#include <stdio.h>
#include "BmsData.h"

warningInfo_st SocData_st;

int IsSocOk(float soc) 
{
	int ErrorStatus=0;
	SocData_st.parameterValue=0;
	SocData_st.warningLevel=0;
    ErrorStatus=valueRangeCheck(soc,SOC_MINIMUM,SOC_MAXIMUM);
	SocData_st.warningLevel=valueRangeCheck(soc,SOC_WARNING_LEVEL_MINIMUM,SOC_WARNING_LEVEL_MAXIMUM);
	if(ErrorStatus)
	{
		printf(" !! ERROR !! State of Charge %f is more than the threshold range \n",soc);
	}
	SocData_st.parameterValue=soc;
	return(!ErrorStatus);
}