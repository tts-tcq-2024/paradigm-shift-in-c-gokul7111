#include "CheckWarning.h"
#include "HelperFunction.h"

static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs);

static int IsWarningFound(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, char* WarnMsg)
{
    int retVal = 0;
    for (int i = 0; i < NoOfBoundaryInputs; ++i) {
        if (IsWithinTheRange(value, boundaries.ranges[i].lower,boundaries.ranges[i].upper)) {
            WarnMsg = boundaries.ranges[i].message;
            retVal = 1;
        }
    }
}

void checkForWarnings(float value ,ParameterBoundaries boundaries, int NoOfBoundaryInputs, boolean performWarnCheck)
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



