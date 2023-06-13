#include "SensorInterface.hpp"
#include <gmock/gmock.h>

class SensorMock : public SensorInterface {
        public:
        MOCK_METHOD(float, readTemperature, (), (override));
        MOCK_METHOD(void,setTemperature,(float& temperature),(override));
};

