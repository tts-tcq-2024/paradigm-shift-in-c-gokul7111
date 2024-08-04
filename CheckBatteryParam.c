#include "CheckBatteryParam.h"

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

int isTemperatureOk(float temperature) {
   checkForWarnings(temperature, TemperatureWarnBoundaries, NO_OF_TEMP_WARN_BOUNDARIES, CHECK_WARN_FOR_TEMP);
   return checkParamRange(temperature, 0, 45, "Temperature out of range!\n");
  
}

int isSocOk(float soc) {
    checkForWarnings(soc, SocWarnBoundaries, NO_OF_SOC_WARN_BOUNDARIES, CHECK_WARN_FOR_SOC);
    return checkParamRange(soc, 20, 80, "Soc out of range!\n");
}

int isChargeRateOk(float chargeRate) {
  checkForWarnings(chargeRate,ChargeRateWarnBoundaries, NO_OF_CHARGERATE_WARN_BOUNDARIES, CHECK_WARN_FOR_CHARGERATE);
  return checkChargeRate(chargeRate, 0.8, "Charge rate out of range!\n");
}
