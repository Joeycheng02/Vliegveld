//
// Created by nightnarumi on 19/08/18.
//
#include "Simulation.h"
#include "parser.h"
#include <gtest/gtest.h>

class RunwayTest: public  ::testing::Test {
protected:
    virtual void SetUp(){
    }

    virtual void TearDown() {
    }

    Simulation simulation;
    Runway runway;
};


TEST_F(RunwayTest, DefCon) {

    EXPECT_EQ("",runway.getName());
    EXPECT_EQ("",runway.getAirport());
    EXPECT_EQ("",runway.getType());
    EXPECT_EQ(0,runway.getLength());
    EXPECT_TRUE(runway.isVacant());
    EXPECT_EQ(unsigned(0),runway.getTaxipoint().size());
    EXPECT_EQ(unsigned(0),runway.getCrossing().size());
}

TEST_F(RunwayTest, Setter) {

    runway.setName("2LR");
    EXPECT_EQ("2LR",runway.getName());
    runway.setAirport("Zaventem");
    EXPECT_EQ("Zaventem",runway.getAirport());
    runway.setType("asphalt");
    EXPECT_EQ("asphalt",runway.getType());
    runway.setLength(200);
    EXPECT_EQ(200,runway.getLength());
    runway.setVacant(false);
    EXPECT_FALSE(runway.isVacant());
}

TEST_F(RunwayTest, runway){
    parser::full_parsing(simulation, "Simulatie.xml");
    // There is always 1 more taxipoint then corssings.
    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->getCrossing().size() + 1 == simulation.getAirports()[0]->getRunways()[0]->getTaxipoint().size());
    // The taxipoints are named with the alphabet.
    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->getTaxipoint()[0] > simulation.getAirports()[0]->getRunways()[0]->getTaxipoint()[1]);
    EXPECT_EQ(simulation.getAirports()[0]->getRunways()[0]->getCrossing()[0], simulation.getAirports()[0]->getRunways()[1]);



    remove("console_output.txt");
}
