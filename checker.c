#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if((temperature < 0 || temperature > 45) || (chargeRate > 0.8) || (soc < 20 || soc > 80)){
    return 0;
  }
  else{
    return 1;
  }

}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(25, 18, 0));
  assert(!batteryIsOk(25, 25, 1));
}
