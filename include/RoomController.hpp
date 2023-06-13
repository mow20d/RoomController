#ifndef ROOM_CONTROLLER_HPP
#define ROOM_CONTROLLER_HPP

#include "SensorInterface.hpp"
#include "RoomControllerInterface.hpp"

class RoomController : public RoomControllerInterface{
    private:
        float temperatureMin;
        float temperatureMax;
        float threshold;
        SensorInterface& sensor;
        std::string state;

    public:
        RoomController(float i_temperatureMin, float i_temperatureMax, float i_threshold, SensorInterface& i_sensor):
    temperatureMin(i_temperatureMin),
    temperatureMax(i_temperatureMax),
    threshold(i_threshold),
    sensor(i_sensor){
    }
        ~RoomController(){};
        float getTemperatureMin() const override;
        float getTemperatureMax() const override;
        float getThreshold() const override;

        void setTemperatureMin(float i_tempMin) override;
        void setTemperatureMax(float i_tempMax) override;
        void setThreshold(float i_threshold) override;

        std::string getState() override;
        std::string checkTemperatureAndOperation() override;
    private:
        void changeTemperature(float i_temperature) override;
        float requestTemperature() override;
};
#endif