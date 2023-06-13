#include "RoomController.hpp"
#include <string>
#include <memory>


 float RoomController::getTemperatureMin() const {
        return temperatureMin;
    }
 float RoomController::getTemperatureMax() const{

        return temperatureMax;
}
 float RoomController::getThreshold() const{

        return threshold;
}

void RoomController::setTemperatureMin(float i_tempMin)
{
    temperatureMin= i_tempMin;
}
void RoomController::setTemperatureMax(float i_tempMax)
{
    temperatureMax= i_tempMax;
}
void RoomController::setThreshold(float i_threshold){
    threshold= i_threshold;
}


std::string RoomController::getState(){
    return state;
}


void RoomController::changeTemperature(float i_temprature ){
    if(i_temprature> temperatureMax+threshold){
        if(state!="COOLING")
        {
            state="COOLING";
        }
    }
    else if(i_temprature< temperatureMin-threshold){
        if(state!="HEATING")
        {
            state="HEATING";
        }
        
    }else{
        state="STOP";
    }
}

float RoomController::requestTemperature(){
    return sensor.readTemperature();
}

std::string RoomController::checkTemperatureAndOperation(){
    float t = requestTemperature();
    changeTemperature(t);
    return getState();
 }
