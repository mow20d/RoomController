#include <iostream>
#include <gtest/gtest.h>
#include "RoomController.hpp"
#include "SensorInterface.hpp"
#include "Sensor.hpp"
#include "SensorMock.hpp"
#include <memory>

class myTestFixture: public testing::Test { 
public: 
   myTestFixture( ) { 
   
    std::cout<<"testRoomControlle is null "<<(mTestRoomController == nullptr)<<std::endl;
    mTestRoomController = std::make_unique<RoomController>(20.,25.,0.5,mSensor);

   } 

   void SetUp( ) { 
   }

   void TearDown( ) { 
   }

   ~myTestFixture( )  { 

   }

   SensorMock mSensor;
   std::unique_ptr<RoomController> mTestRoomController;
};

TEST_F (myTestFixture, checkTemperatureAndOperation) { 

	EXPECT_CALL(mSensor, readTemperature()).Times(1).WillOnce(testing::Return(26.5));
	std::string result = mTestRoomController->checkTemperatureAndOperation();
	
	ASSERT_EQ(result,"COOLING");

}

TEST_F (myTestFixture, COLLING) { 

	EXPECT_CALL(mSensor, readTemperature()).Times(1).WillOnce(testing::Return(30.));
	std::string result = mTestRoomController->checkTemperatureAndOperation();
	
	ASSERT_EQ(result,"COOLING");

}

TEST_F (myTestFixture, DoNothing) { 

	EXPECT_CALL(mSensor, readTemperature()).Times(1).WillOnce(testing::Return(20.));
	std::string result = mTestRoomController->checkTemperatureAndOperation();
	
	ASSERT_EQ(result,"STOP");

}

TEST_F (myTestFixture, HEATING) { 

	EXPECT_CALL(mSensor, readTemperature()).Times(1).WillOnce(testing::Return(19.));
	std::string result = mTestRoomController->checkTemperatureAndOperation();
	
	ASSERT_EQ(result,"HEATING");

}

TEST_F (myTestFixture, changeThresholdAndStopHeating) { 

	EXPECT_CALL(mSensor, readTemperature()).Times(1).WillOnce(testing::Return(19.9));
	mTestRoomController->setThreshold(0.1);
    std::string result = mTestRoomController->checkTemperatureAndOperation();
	ASSERT_EQ(result,"STOP");

}

TEST_F (myTestFixture, TemperatureMax) { 
    mTestRoomController->setTemperatureMax(30.4);
	EXPECT_CALL(mSensor, readTemperature()).Times(1).WillOnce(testing::Return(26));
    std::string result = mTestRoomController->checkTemperatureAndOperation();
	ASSERT_EQ(result,"STOP");

}

TEST_F (myTestFixture, TemperatureMin) { 
    mTestRoomController->setTemperatureMin(25);
	EXPECT_CALL(mSensor, readTemperature()).Times(1).WillOnce(testing::Return(24));
    std::string result = mTestRoomController->checkTemperatureAndOperation();
	ASSERT_EQ(result,"HEATING");

}

