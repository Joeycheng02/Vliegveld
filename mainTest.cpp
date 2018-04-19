//
// Created by nightnarumi on 22/03/18.
//
#include "Simulation.h"
#include <gtest/gtest.h>

class VliegveldTest: public  ::testing::Test {
protected:
    virtual void SetUp(){
    }

    virtual void TearDown() {
    }

    Simulation simulation;
    Runway runway;
    Gate gate;
};

TEST_F(VliegveldTest, DefaultConstructor) {
    EXPECT_EQ(0, int(simulation.getAirports().size()));
    EXPECT_EQ(0, int(simulation.getAirplanes().size()));
    EXPECT_EQ(0, int(simulation.getRunways().size()));
    EXPECT_EQ(0, gate.getName());
    EXPECT_TRUE(runway.isVacant());
    EXPECT_TRUE(gate.isVacant());
}

TEST_F(VliegveldTest, Parsing) {

    simulation.parser(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    simulation.addRunway(simulation.getAirports(), simulation.getRunways());

    EXPECT_EQ("Antwerp International Airport", simulation.getAirports()[0].getName());
    EXPECT_EQ(1, simulation.getAirports()[0].getNumberOfRunways());
    EXPECT_EQ(10, simulation.getAirports()[0].getNumberOfGates());
    EXPECT_EQ("ANR", simulation.getAirports()[0].getIata());
    EXPECT_EQ("Antwerp Tower", simulation.getAirports()[0].getCallsign());
    EXPECT_EQ("11R", simulation.getAirports()[0].getRunways()[0].getName());
    EXPECT_EQ("ANR", simulation.getAirports()[0].getRunways()[0].getAirport());

    EXPECT_EQ("Brussel International Airport", simulation.getAirports()[1].getName());
    EXPECT_EQ(1, simulation.getAirports()[1].getNumberOfRunways());
    EXPECT_EQ(5, simulation.getAirports()[1].getNumberOfGates());
    EXPECT_EQ("BNR", simulation.getAirports()[1].getIata());
    EXPECT_EQ("Brussel Tower", simulation.getAirports()[1].getCallsign());
    EXPECT_EQ("12G", simulation.getAirports()[1].getRunways()[0].getName());
    EXPECT_EQ("BNR", simulation.getAirports()[1].getRunways()[0].getAirport());

}

TEST_F(VliegveldTest, Descending) {
    simulation.parser(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    simulation.addRunway(simulation.getAirports(), simulation.getRunways());
    simulation.descending(simulation.getAirplanes()[0],simulation.getAirports()[0]);
    EXPECT_EQ("Standing at gate", simulation.getAirplanes()[0].getStatus());
}

TEST_F(VliegveldTest, ExpectedErrors) {
    simulation.parser(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    simulation.addRunway(simulation.getAirports(), simulation.getRunways());
    Airplane airplanetest;
    EXPECT_DEATH(simulation.descending(airplanetest, simulation.getAirports()[0]), "Airplane is not approaching");
    EXPECT_DEATH(simulation.parser(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), "Simulatie.xml"), "Airplanes must be empty");
}

TEST_F(VliegveldTest, ascending){
    simulation.parser(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    simulation.addRunway(simulation.getAirports(), simulation.getRunways());

    EXPECT_TRUE(simulation.getAirplanes()[1].getStatus() == "Standing at gate");
    simulation.ascending(simulation.getAirplanes()[1], simulation.getAirports()[0]);
    EXPECT_TRUE(simulation.getAirplanes()[1].getStatus() == "Departed");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}