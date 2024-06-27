#include <stdio.h>
#include <assert.h>

int IsTemperatureOk(float temperature)
{
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}

int IsSocOk(float soc)
{
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}

int IsChargeRateOk(float chargeRate)
{
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(IsTemperatureOk(temperature) || IsSocOk(soc) || (IsChargeRateOk(chargeRate))){
    return 1;
  }
  else{
    return 0;
  }

}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
