#ifndef HELPERFUNCTION_H
#define HELPERFUNCTION_H

#include <stdio.h>
#include <string.h>

void printOnConsole(const char *message); 
int IsInputWithinTheRange(float input, float lowerLimit, float upperLimit);
int IsInputOutOfRange(float input, float lowerLimit, float upperLimit);

#endif 
