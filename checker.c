#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
bool TemperatureIsOk(float temperature){
    if(temperature < 0 || temperature > 45){
    return false;//Temperature is NOT OK
    }
    return true;//Temperature is OK
}
bool SOCIsOk(float soc){
    if(soc < 20 || soc > 80){
    return false;//SOC is NOT OK 
    }
    return true;//SOC is OK 
}
bool ChargeRateIsOk(float chargeRate){
    if(chargeRate > 0.8){
    return false;//ChargeRate is NOT OK
    }
    return true;//chargerate is OK 
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
  int paramaeters_OK = (!TemperatureIsOk(temperature) || !SOCIsOk(soc) || !ChargeRateIsOk(chargeRate));
  if(paramaeters_OK){
    return false;
  }
  return true;
  
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));//battery is OK
  assert(!batteryIsOk(50, 85, 0.5));//battery is NOT OK
  assert(!batteryIsOk(70, 85, 0.5));//Temperature is too High
  assert(!batteryIsOk(-10, 85, 0.5));//Temperature is too Low
  assert(!batteryIsOk(40, 90, 0.5));//SOC is too High
  assert(!batteryIsOk(40, 5, 0.5));//SOC is too Low
  assert(!batteryIsOk(40, 85, 2));//Chargerate is too high

  
}
