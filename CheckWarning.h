#ifndef INIT_WARN_BOUNDARY_DEF
#define INIT_WARN_BOUNDARY_DEF

#include "HelperFunction.h"
#include <stdio.h>
#include <stdbool.h>

#define NO_OF_TEMP_WARN_BOUNDARIES 2
#define NO_OF_SOC_WARN_BOUNDARIES 2
#define NO_OF_CHARGERATE_WARN_BOUNDARIES 1

typedef struct {
    float lowerLimit;
    float upperLimit;
    char warnMessage[50];
    
} BoundaryInput;

typedef struct {
    BoundaryInput Boundary[5];
} ParameterBoundaries;

void checkForWarnings(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, bool performWarnCheck);

#endif
