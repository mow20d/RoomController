#include <iostream>
#include "Sensor.hpp"

float Sensor::readTemperature() {
    return temperature;
}

void  Sensor::setTemperature(float& i_temperature) {
    temperature= i_temperature;
}
