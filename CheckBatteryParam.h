#ifndef CHECK_BATTERY_PARAM_H
#define CHECK_BATTERY_PARAM_H

#include "CheckParamRange.h"
#include "CheckWarning.h"

#define CHECK_WARN_FOR_TEMP 1
#define CHECK_WARN_FOR_SOC  1
#define CHECK_WARN_FOR_CHARGERATE 1

ParameterBoundaries SocWarnBoundaries = {
    {
        {21, 24, "Warning : Approaching Soc Low"},
        {76, 80, "Warning : Approaching Soc High"},
    }
};


ParameterBoundaries TemperatureWarnBoundaries = {
    {
        {0, 2.25, "Warning : Approaching Low Temperature"},
        {42.75, 45, "Warning : Approaching High Temperature"},
    }
};

ParameterBoundaries ChargeRateWarnBoundaries = {
    {
        {0.76, 0.8, "Warning : Approaching High charge rate"},
    }
};


int isTemperatureOk(float temperature);
int isSocOk(float soc);
int isChargeRateOk(float chargeRate);


#endif
