#include <stdio.h>
#include <assert.h>
#include <string.h>

#define CHECK_WARN_FOR_TEMP 1
#define CHECK_WARN_FOR_SOC  1
#define CHECK_WARN_FOR_CHARGERATE 1

#define NO_OF_TEMP_WARN_BOUNDARIES 2
#define NO_OF_SOC_WARN_BOUNDARIES 2
#define NO_OF_CHARGERATE_WARN_BOUNDARIES 1

typedef struct {
    float lower;
    float upper;
    char message[50];
    int state;
    
} Range;

typedef struct {
    Range ranges[5];
} ParameterBoundaries;

ParameterBoundaries SocWarnBoundaries = {
    {
        {21, 24, "Warning : Approaching Soc Low", WARNING},
        {76, 80, "Warning : Approaching Soc High", WARNING},
    }
};


ParameterBoundaries TemperatureWarnBoundaries = {
    {
        {0, 2.25, "Warning : Approaching Low Temperature", WARNING},
        {42.75, 45, "Warning : Approaching High Temperature", WARNING},
    }
};

ParameterBoundaries ChargeRateWarnBoundaries = {
    {
        {0.76, 0.8, "Warning : Approaching High charge rate", WARNING},
    }
};

void printOnConsole(const char *message)
{
    printf("%s\n", message);
}

void printOnWarning(int state, const char *message)
{ 
  if(state == WARNING)
  {
    printOnConsole("%s\n", message);
  }
}

bool IsWithinTheRange(float input, float lower, float upper)
{
    if (input >= lower && value <= upper)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool IsOutOfRange(float input, float lower, float upper)
{
    if (input < lower || value > upper)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkForWarnings(flaot value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs)
{
    for (int i = 0; i < NoOfBoundaryInputs; ++i) {
        if (IsWithinTheRange(value, boundaries.ranges[i].lower,boundaries.ranges[i].upper)) {
            return boundaries.ranges[i].state;
            printOnConsole(boundaries.ranges[i].state, boundaries.ranges[i].message);
        }
    }
}

int isTemperatureOk(float temperature) {
  if (IsOutOfRange(temperature, 0, 45)) {
    printOnConsole("Temperature out of range!\n");
    return 0;
  }
  else{
#if(CHECK_WARN_FOR_TEMP ==1)
    if(checkForWarnings(temperature, TemperatureBoundaries, NO_OF_TEMP_WARN_BOUNDARIES))
    {
       return 0;
    }
    else{
      return 1;
    }
#else
    return 1;
#endif
  }
}

int isSocOk(float soc) {
  if (IsOutOfRange(soc, 20, 80)) {
    printOnConsole("State of Charge out of range!\n");
    return 0;
  }
  else{
#if(CHECK_WARN_FOR_SOC ==1)
    if(checkForWarnings(soc, SocBoundaries, NO_OF_SOC_WARN_BOUNDARIES))
    {
       return 0;
    }
    else{
      return 1;
    }
#else
    return 1;
#endif
  }
}

int isChargeRateOk(float chargeRate) {
  if (chargeRate > 0.8) {
    printOnConsole("Charge Rate out of range!\n");
    return 0;
  }
  else {
#if(CHECK_WARN_FOR_SOC ==1)
    if(checkForWarnings(chargeRate,ChargeRateBoundaries, NO_OF_CHARGERATE_WARN_BOUNDARIES))
    {
       return 0;
    }
    else{
      return 1;
    }
#else
    return 1;
#endif
  }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(25, 18, 0));
  assert(!batteryIsOk(25, 25, 1));
}
