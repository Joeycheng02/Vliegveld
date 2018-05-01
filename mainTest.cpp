//
// Created by nightnarumi on 22/03/18.
//
#include "Simulation.h"
#include "parser.h"
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

    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
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

TEST_F(VliegveldTest, Parsing_Test){ // Deze test test alle attributen van de parser m.b.v. een test xml-bestand

    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), "test.xml");
    EXPECT_EQ("Test airport", simulation.getAirports()[0].getName());
    EXPECT_EQ("BEL", simulation.getAirports()[0].getIata());
    EXPECT_EQ("Merksplas tower", simulation.getAirports()[0].getCallsign());
    EXPECT_EQ(12, simulation.getAirports()[0].getNumberOfGates());

    EXPECT_EQ("12M", simulation.getRunways()[0].getName());
    EXPECT_EQ("BEL", simulation.getRunways()[0].getAirport());
    EXPECT_EQ("wood", simulation.getRunways()[0].getType());
    EXPECT_EQ(1212, simulation.getRunways()[0].getLength());

    EXPECT_EQ("M48674", simulation.getAirplanes()[0].getNumber());
    EXPECT_EQ("Nighthawk", simulation.getAirplanes()[0].getCallsign());
    EXPECT_EQ("Nighthawk 340", simulation.getAirplanes()[0].getModel());
    EXPECT_EQ("private", simulation.getAirplanes()[0].getType());
    EXPECT_EQ("jet", simulation.getAirplanes()[0].getEngine());
    EXPECT_EQ("small", simulation.getAirplanes()[0].getSize());
    EXPECT_EQ("Approaching", simulation.getAirplanes()[0].getStatus());
    EXPECT_EQ(1, simulation.getAirplanes()[0].getPassengers());
}

TEST_F(VliegveldTest, Descending) {
    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    simulation.descending(simulation.getAirplanes()[0],simulation.getAirports()[0]);
    EXPECT_EQ("Standing at gate", simulation.getAirplanes()[0].getStatus());
}

TEST_F(VliegveldTest, ExpectedErrors) {
    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    Airplane airplanetest;
    EXPECT_DEATH(simulation.descending(airplanetest, simulation.getAirports()[0]), "Airplane is not approaching");
    EXPECT_DEATH(parser::parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), "Simulatie.xml"), "Airplanes must be empty");
}

TEST_F(VliegveldTest, ascending){
    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    EXPECT_TRUE(simulation.getAirplanes()[1].getStatus() == "Standing at gate");
    simulation.ascending(simulation.getAirplanes()[1], simulation.getAirports()[0]);
    EXPECT_TRUE(simulation.getAirplanes()[1].getStatus() == "Departed");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}