
#include <stdio.h>
#include <assert.h>
#include <string.h>

void printOnConsole(const char *message)
{
    printf("%s\n", message);
}

int IsInputWithinTheRange(float input, float lowerLimit, float upperLimit)
{
    if (input >= lowerLimit && input <= upperLimit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsInputOutOfRange(float input, float lowerLimit, float upperLimit)
{
    if (input < lowerLimit || input > upperLimit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

