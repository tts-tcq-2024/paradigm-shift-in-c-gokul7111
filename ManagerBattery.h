#ifndef BATTERY_MANAGE_H
#define BATTERY_MANAGE_H

#include "CheckBatteryParam.h"
#include <stdio.h>

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif
