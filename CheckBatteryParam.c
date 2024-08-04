#include "CheckBatteryParam.h"

int isTemperatureOk(float temperature) {
   checkForWarnings(temperature, TemperatureWarnBoundaries, NO_OF_TEMP_WARN_BOUNDARIES, CHECK_WARN_FOR_TEMP);
   if(IsOutOfRange(temperature, 0, 45))
   {
     printOnConsole("Temperature out of range!\n");
     return 0;
  }
  else {
    return 1;
  }
  
}

int isSocOk(float soc) {
    checkForWarnings(soc, SocWarnBoundaries, NO_OF_SOC_WARN_BOUNDARIES, CHECK_WARN_FOR_SOC);
    if (IsOutOfRange(soc, 20, 80))
    {
       printOnConsole("Charge Soc out of range!\n");
       return 0;
    }
    else {
      return 1;
    }
}

int isChargeRateOk(float chargeRate) {
  checkForWarnings(chargeRate,ChargeRateWarnBoundaries, NO_OF_CHARGERATE_WARN_BOUNDARIES);
  if (chargeRate > 0.8) {
    printOnConsole("Charge Rate out of range!\n");
    return 0;
  }
  else {
    return 1;
  }
}
