#include <stdio.h>
#include <assert.h>
#include "BmsData.h"

char* BmsPrameters[] = {"Temperature", "State of Charge", "Charging Rate"};

int batteryIsOk(float temperature, float soc, float chargeRate) {
	int temperatureStatus=0;
	int SocStatus=0;
	int ChargeRateStatus=0;
	temperatureStatus=IsTemperatureOk(temperature);
	SocStatus=IsSocOk(soc);
	ChargeRateStatus=IsChargeRateOk(chargeRate);
	int IsBattaeryOkValue=(temperatureStatus&SocStatus&ChargeRateStatus);
    if(IsBattaeryOkValue)
	{
		printWarningMessage(temperatureData_st.warningLevel,temperatureData_st.parameterValue,BmsPrameters[0]);
		printWarningMessage(SocData_st.warningLevel,SocData_st.parameterValue,BmsPrameters[1]);
		printWarningMessage(ChargeRateData_st.warningLevel,ChargeRateData_st.parameterValue,BmsPrameters[2]);
	}
	return(IsBattaeryOkValue);
}

int main() {
  /*warning leve limit check */
  assert(batteryIsOk(2.25,24,0.04));
  assert(batteryIsOk(42.75,76,0.76));
  /*error limit check */
  assert(batteryIsOk(0,20,0));
  assert(batteryIsOk(45,80,0.8));
  /*check warning if level more than Upper& less than lower */
  assert(batteryIsOk(43,77,0.77));
  assert(batteryIsOk(2,23,.03));
  /*check error if level more than Upper& less than lower */
  assert(!batteryIsOk(-1,19,0));
  assert(!batteryIsOk(46,82,0.9));
  /*any one parameter breach */
  assert(!batteryIsOk(50,30,0.5));
  assert(!batteryIsOk(40,85,0.6));
  assert(!batteryIsOk(43,40,0.9));
  /*test valueRangeCheck() with boundary,within range,above upper& below lower limits */
  assert(!valueRangeCheck(10,10,20));
  assert(!valueRangeCheck(20,10,20));
  assert(!valueRangeCheck(15,10,20));
  assert(valueRangeCheck(5,10,20));
  assert(valueRangeCheck(25,10,20));
 /*test IsTemperatureOk() with boundary,within range,above upper& below lower limits */
  assert(IsTemperatureOk(0));
  assert((temperatureData_st.warningLevel));
  assert(IsTemperatureOk(45));
  assert((temperatureData_st.warningLevel));
  assert(IsTemperatureOk(40));
  assert(!(temperatureData_st.warningLevel));
  assert(!IsTemperatureOk(-1));
  assert((temperatureData_st.warningLevel));
  assert(!IsTemperatureOk(46));
  assert((temperatureData_st.warningLevel));
 /*test IsSocOk() with boundary,within range,above upper& below lower limits */
  assert(IsSocOk(20));
  assert((SocData_st.warningLevel));
  assert(IsSocOk(80));
  assert((SocData_st.warningLevel));
  assert(IsSocOk(40));
  assert(!(SocData_st.warningLevel));
  assert(!IsSocOk(15));
  assert((SocData_st.warningLevel));
  assert(!IsSocOk(85));
  assert((SocData_st.warningLevel));
 /*test IsSocOk() with boundary,within range,above upper limit */
  assert(IsChargeRateOk(0));
  assert((ChargeRateData_st.warningLevel));
  assert(IsChargeRateOk(0.8));
  assert((ChargeRateData_st.warningLevel));
  assert(IsChargeRateOk(0.5));
  assert(!(ChargeRateData_st.warningLevel));
  assert(!IsChargeRateOk(0.9));
  assert((ChargeRateData_st.warningLevel));
}
