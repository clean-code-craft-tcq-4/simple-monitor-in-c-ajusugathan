#include "language.h"

#define CALCULATE_TOLERANCE(x) (float)(x*(0.05))

/*Threshold values*/
#define TEMPERATURE_MINIMUM 0
#define TEMPERATURE_MAXIMUM 45

#define SOC_MINIMUM 20
#define SOC_MAXIMUM 80

#define CHARGERATE_MINIMUM 0.0F
#define CHARGERATE_MAXIMUM 0.8F

/*Warning level values */
#define TEMPERATURE_WARNING_LEVEL_MINIMUM (TEMPERATURE_MINIMUM + CALCULATE_TOLERANCE(TEMPERATURE_MAXIMUM))
#define TEMPERATURE_WARNING_LEVEL_MAXIMUM (TEMPERATURE_MAXIMUM - CALCULATE_TOLERANCE(TEMPERATURE_MAXIMUM))

#define SOC_WARNING_LEVEL_MINIMUM  (SOC_MINIMUM + CALCULATE_TOLERANCE(SOC_MAXIMUM))
#define SOC_WARNING_LEVEL_MAXIMUM  (SOC_MAXIMUM - CALCULATE_TOLERANCE(SOC_MAXIMUM))

#define CHARGERATE_WARNING_LEVEL_MINIMUM (CHARGERATE_MINIMUM + CALCULATE_TOLERANCE(CHARGERATE_MAXIMUM))
#define CHARGERATE_WARNING_LEVEL_MAXIMUM (CHARGERATE_MAXIMUM - CALCULATE_TOLERANCE(CHARGERATE_MAXIMUM))


typedef struct{
	float parameterValue;
	int warningLevel;
}warningInfo_st;

extern warningInfo_st temperatureData_st;
extern warningInfo_st SocData_st;
extern warningInfo_st ChargeRateData_st;

int valueRangeCheck(float actualValue,float mininmumValue,float maximumValue);
void printWarningMessage(int WarningLevel,float presentValue,char * parameterValue);
int IsTemperatureOk(float temperature);
int IsSocOk(float soc);
int IsChargeRateOk(float chargeRate);
