#ifndef CHECK_PARAMM_RANGE_H
#define CHECK_PARAMM_RANGE_H

#include "HelperFunction.h"
#include <stdio.h>

int checkParamRange(float input, float lowerLimit, float upperLimit, char* FailureMsg);

int checkChargeRate(float input,  float upperLimit, char* FailureMsg);

#endif