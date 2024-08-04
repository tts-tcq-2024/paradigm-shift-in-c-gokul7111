#ifndef BATTERY_MANAGE_H
#define BATTERY_MANAGE_H

#include "CheckBatteryParam.h"

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif
