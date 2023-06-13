#ifndef ROOM_CONTROLLER_INTERFACE_HPP
#define ROOM_CONTROLLER_INTERFACE_HPP

#include <string>
class RoomControllerInterface
{
public:
    virtual ~RoomControllerInterface() = default;
    virtual float getTemperatureMin() const = 0;
    virtual float getTemperatureMax() const = 0;;
    virtual float getThreshold() const  = 0;;
    
    virtual void setTemperatureMin(float i_tempMin) = 0;;
    virtual void setTemperatureMax(float i_tempMax) = 0;;
    virtual void setThreshold(float i_threshold) = 0;;

    virtual std::string getState() = 0;
    virtual std::string checkTemperatureAndOperation()=0;

    private:
    virtual void changeTemperature(float i_temperature)  = 0;;
    virtual float requestTemperature() = 0;;
   
};

#endif