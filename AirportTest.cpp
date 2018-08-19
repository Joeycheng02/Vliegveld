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
    Airplane airplane;
    Airport airport;
    Runway runway;
    Time time;
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