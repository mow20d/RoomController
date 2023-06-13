#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP

class SensorInterface{
    public:
    virtual ~SensorInterface() = default;
    virtual float readTemperature() = 0  ;
    virtual void setTemperature(float& i_temperature) = 0 ;

};

#endif