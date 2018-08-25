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

    Time time;
};

TEST_F(TimeTest, DefConTime) {

    EXPECT_EQ("12:00", time.printTime());
    EXPECT_TRUE(time.properlyInitialized());
    Time* a = &time;
    EXPECT_TRUE(a->properlyInitialized());
    Time b = time;
    EXPECT_FALSE(b.properlyInitialized());
}

TEST_F(TimeTest, SetterTime) {

    time.addTime(20);
    EXPECT_EQ("12:20", time.printTime());
    time.addTime(700);
    EXPECT_EQ("00:00", time.printTime());
    time.addTime(1440);
    EXPECT_EQ("00:00", time.printTime());
    time.addTime(1500);
    EXPECT_EQ("01:00", time.printTime());
    EXPECT_DEATH(time.addTime(-5), "The given Time addTime is not properly initialized.");
    EXPECT_NO_FATAL_FAILURE(time.addTime(2147483587));
    EXPECT_DEATH(time.addTime(2147483588), "This Time addTime can't be a negative number.");


    remove("console_output.txt");
}
