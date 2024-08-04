#include "CheckParamRange.h"


int checkParamRange(float input, float lowerLimit, float upperLimit, char* FailureMsg);
{
    if(IsOutOfRange(input, lowerLimit, upperLimit))
    {
        printOnConsole(FailureMsg);
        return 0;
    }
    else {
        return 1;
    }
}

int checkChargeRate(float input,  float upperLimit, char* FailureMsg);
{
    if (input > upperLimit) {
        printOnConsole(FailureMsg);
        return 0;
    }
    else {
        return 1;
    }
}