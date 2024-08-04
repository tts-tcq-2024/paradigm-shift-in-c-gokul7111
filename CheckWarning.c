#include "CheckWarning.h"

static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, char* WarnMsg);

static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, char* WarnMsg)
{
    int retVal = 0;
    for (int i = 0; i < NoOfBoundaryInputs; ++i) {
        if (IsInputWithinTheRange(value, boundaries.Boundary[i].lower, boundaries.Boundary[i].upper)) {
            WarnMsg = boundaries.Boundary[i].message;
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



