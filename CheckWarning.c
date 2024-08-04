#include "CheckWarning.h"

static char WarnMessage[50];

static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs);

static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs)
{
    int retVal = 0;
    for (int i = 0; i < NoOfBoundaryInputs; ++i) {
        if (IsInputWithinTheRange(value, boundaries.Boundary[i].lowerLimit, boundaries.Boundary[i].upperLimit)) {
            strcpy(WarnMessage, strcpyWboundaries.Boundary[i].warnMessage);
            retVal = 1;
        }
    }
    return retVal;
}

void checkForWarnings(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, bool performWarnCheck)
{
  if(performWarnCheck)
  {
      if(IsWarningFound(value, boundaries, NoOfBoundaryInputs))
      {
        printOnConsole(WarnMessage);
      }
  }
}



