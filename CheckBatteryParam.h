#ifndef CHECK_BATTERY_PARAM_H
#define CHECK_BATTERY_PARAM_H

#include "CheckParamRange.h"
#include "CheckWarning.h"

#define CHECK_WARN_FOR_TEMP 1
#define CHECK_WARN_FOR_SOC  1
#define CHECK_WARN_FOR_CHARGERATE 1


int isTemperatureOk(float temperature);
int isSocOk(float soc);
int isChargeRateOk(float chargeRate);


#endif
