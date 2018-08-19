//
// Created by nightnarumi on 19/08/18.
//
#include "Simulation.h"
#include "parser.h"
#include <gtest/gtest.h>

class TimeTest: public  ::testing::Test {
protected:
    virtual void SetUp(){
    }

    virtual void TearDown() {
    }

    Simulation simulation;
    Airplane airplane;
    Airport airport;
    Runway runway;
    Time time;
};

TEST_F(TimeTest, DefConTime) {

    EXPECT_EQ("12:00", time.printTime());

}

TEST_F(TimeTest, SetterTime) {

    time.addTime(20);
    EXPECT_EQ("12:20", time.printTime());
    time.addTime(700);
    EXPECT_EQ("00:00", time.printTime());

    remove("console_output.txt");
}
