#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "SensorInterface.hpp"

class Sensor: public SensorInterface {
    private:
    float temperature;

    public:

    Sensor(float& i_temperature){
       temperature= i_temperature;
    }
    ~Sensor(){};
    float readTemperature() override;
    void setTemperature(float& i_temperature) override;


};

#endif