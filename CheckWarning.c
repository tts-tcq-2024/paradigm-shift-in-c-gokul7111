#include "CheckWarning.h"

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


static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, char* WarnMsg);

static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, char* WarnMsg)
{
    int retVal = 0;
    for (int i = 0; i < NoOfBoundaryInputs; ++i) {
        if (IsInputWithinTheRange(value, boundaries.Boundary[i].lowerLimit, boundaries.Boundary[i].upperLimit)) {
            WarnMsg = boundaries.Boundary[i].warnMessage;
            retVal = 1;
        }
    }
    return retVal;
}

void checkForWarnings(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, bool performWarnCheck)
{
  char* WarnMessage = 0;
  if(performWarnCheck)
  {
      if(IsWarningFound(value, boundaries, NoOfBoundaryInputs, WarnMessage))
      {
        printOnConsole(WarnMessage);
      }
  }
}



