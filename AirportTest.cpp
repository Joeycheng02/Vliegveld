//
// Created by nightnarumi on 19/08/18.
//

#include "Simulation.h"
#include "parser.h"
#include <gtest/gtest.h>

class AirportTest: public  ::testing::Test {
protected:
    virtual void SetUp(){
    }

    virtual void TearDown() {
    }

    Simulation simulation;
    Airport airport;
};

TEST_F(AirportTest, DefCon) {

    EXPECT_EQ(unsigned (0), airport.getGates().size());
    EXPECT_EQ(unsigned (0), airport.getRunways().size());
    EXPECT_EQ(0, airport.getNumberOfGates());
    EXPECT_EQ(unsigned(0), airport.getNumberOfRunways());
    EXPECT_EQ("", airport.getName());
    EXPECT_EQ("", airport.getIata());
    EXPECT_EQ("", airport.getCallsign());
}

TEST_F(AirportTest, Setter) {

    airport.setNumberOfGates(5);
    EXPECT_EQ(5, airport.getNumberOfGates());
    airport.setName("Zaventem");
    EXPECT_EQ("Zaventem", airport.getName());
    airport.setIata("BRU");
    EXPECT_EQ("BRU", airport.getIata());
    airport.setCallsign("Brussels Tower");
    EXPECT_EQ("Brussels Tower", airport.getCallsign());
}

TEST_F(AirportTest, permission) {

    parser::full_parsing(simulation, "Simulatie.xml");
    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->isVacant());
    EXPECT_TRUE(simulation.getAirports()[0]->permissionToAscend(0));
    simulation.getAirports()[0]->getRunways()[0]->setVacant(false);
    EXPECT_FALSE(simulation.getAirports()[0]->permissionToAscend(0));
    EXPECT_FALSE(simulation.getAirports()[0]->permissionToDescend(12000));
    EXPECT_TRUE(simulation.getAirports()[0]->permissionToDescend(10000));
    EXPECT_TRUE(simulation.getAirports()[0]->permissionToDescend(5000));
    EXPECT_FALSE(simulation.getAirports()[0]->permissionToDescend(3000));
    simulation.getAirports()[0]->getRunways()[0]->setVacant(true);
    EXPECT_TRUE(simulation.getAirports()[0]->permissionToDescend(3000));
}

TEST_F(AirportTest, edgeCases){

    parser::full_parsing(simulation, "Simulatie.xml");
    EXPECT_DEATH(simulation.getAirports()[0]->setNumberOfGates(-5), "The variable can't be a negative number");
    EXPECT_DEATH(simulation.getAirports()[0]->setNumberOfGates(-1), "The variable can't be a negative number");
    simulation.getAirports()[0]->setNumberOfGates(0);
    EXPECT_EQ(-0, simulation.getAirports()[0]->getNumberOfGates());
    simulation.getAirports()[0]->setNumberOfGates(164);
    EXPECT_EQ(164, simulation.getAirports()[0]->getNumberOfGates());

    simulation.getAirports()[0]->setName("test123");
    EXPECT_EQ("test123", simulation.getAirports()[0]->getName());

    simulation.getAirports()[0]->setIata("test1234");
    EXPECT_EQ("test1234", simulation.getAirports()[0]->getIata());

    simulation.getAirports()[0]->setCallsign("test12");
    EXPECT_EQ("test12", simulation.getAirports()[0]->getCallsign());

    EXPECT_EQ(unsigned (164), simulation.getAirports()[0]->getGates().size());

    EXPECT_EQ(unsigned (2), simulation.getAirports()[0]->getRunways().size());

    remove("console_output.txt");
}