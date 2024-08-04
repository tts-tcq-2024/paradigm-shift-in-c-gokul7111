#ifndef TESTCASES_H
#define TESTCASES_H

#include <assert.h>
#include <stdio.h>
#include "ManageBattery.h"

void testTemperatureBelowLowerLimit();
void testTemperatureAboveUpperLimit();
void testSocBelowLowerLimit();
void testSocAboveUpperLimit();
void testChargeRateAboveUpperLimit();
void testApproachingLowerTemperatureLimit();
void testApproachingHigherTemperatureLimit();
void testApproachingDischarge();
void testApproachingChargePeak();
void testApproachingMaxChargeRate();

#endif 