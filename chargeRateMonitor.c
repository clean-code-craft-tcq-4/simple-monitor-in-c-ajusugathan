#include <stdio.h>
#include "BmsData.h"

warningInfo_st ChargeRateData_st;

int IsChargeRateOk(float chargeRate) 
{
	int ErrorStatus=0;
	ChargeRateData_st.parameterValue=0;
	ChargeRateData_st.warningLevel=0;;
    ErrorStatus=valueRangeCheck(chargeRate,CHARGERATE_MINIMUM,CHARGERATE_MAXIMUM);
	ChargeRateData_st.warningLevel=valueRangeCheck(chargeRate,CHARGERATE_WARNING_LEVEL_MINIMUM,CHARGERATE_WARNING_LEVEL_MAXIMUM);
	if(ErrorStatus)
	{
		printf(" %s %s %s : %s %f\n",ERROR,CHARGE_RATE,ERROR_COMMENT,PRESENT_VALUE,chargeRate);
	}
    ChargeRateData_st.parameterValue=chargeRate;
	return(!ErrorStatus);
}
