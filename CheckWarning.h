#ifndef INIT_WARN_BOUNDARY_DEF
#define INIT_WARN_BOUNDARY_DEF

#include <stdio.h>

#define NO_OF_TEMP_WARN_BOUNDARIES 2
#define NO_OF_SOC_WARN_BOUNDARIES 2
#define NO_OF_CHARGERATE_WARN_BOUNDARIES 1

typedef struct {
    float lowerLimit;
    float upperLimit;
    char warnMessage[50];
    
} BoundaryInput;

typedef struct {
    BoundaryInput Boundaries[5];
} ParameterBoundaries;

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

void checkForWarnings(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, boolean performWarnCheck);

#endif
