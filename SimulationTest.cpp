//
// Created by nightnarumi on 19/08/18.
//
#include "Simulation.h"
#include "parser.h"
#include <gtest/gtest.h>

class SimulationTest: public  ::testing::Test {
protected:
    virtual void SetUp(){
    }

    virtual void TearDown() {
    }

    Simulation simulation;
    Runway runway;
};

TEST_F(SimulationTest, DefCon) {

    EXPECT_EQ(0, int(simulation.getAirports().size()));
    EXPECT_EQ(0, int(simulation.getAirplanes().size()));
    EXPECT_EQ(0, int(simulation.getRunways().size()));
    EXPECT_TRUE(runway.isVacant());
    EXPECT_TRUE(simulation.properlyInitialized());
    Simulation* a = &simulation;
    EXPECT_TRUE(a->properlyInitialized());
    Simulation b = simulation;
    EXPECT_FALSE(b.properlyInitialized());
    simulation.getRunways().push_back(&runway);
    EXPECT_EQ(1, int(simulation.getRunways().size()));


    remove("console_output.txt");
}