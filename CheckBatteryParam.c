#include "CheckBatteryParam.h"

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
