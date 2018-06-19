//
// Created by nightnarumi on 22/03/18.
//
#include "Simulation.h"
#include "parser.h"
#include "output.h"
#include <gtest/gtest.h>

class VliegveldTest: public  ::testing::Test {
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

TEST_F(VliegveldTest, DefConSimulation) {

    EXPECT_EQ(0, int(simulation.getAirports().size()));
    EXPECT_EQ(0, int(simulation.getAirplanes().size()));
    EXPECT_EQ(0, int(simulation.getRunways().size()));
    EXPECT_TRUE(runway.isVacant());

}

TEST_F(VliegveldTest, DefConAirplane) {

    EXPECT_EQ("", airplane.getNumber());
    EXPECT_EQ("", airplane.getCallsign());
    EXPECT_EQ("", airplane.getModel());
    EXPECT_EQ("", airplane.getStatus());
    EXPECT_EQ(unsigned (0), airplane.getHeight());
    EXPECT_EQ("", airplane.getAirport());
    EXPECT_EQ(-1, airplane.getGateNumber());
    EXPECT_EQ(unsigned (0), airplane.getCapacity());
    EXPECT_EQ("", airplane.getType());
    EXPECT_EQ("", airplane.getEngine());
    EXPECT_EQ("", airplane.getSize());
    EXPECT_EQ(unsigned (0), airplane.getFuelCost());
    EXPECT_EQ(unsigned (0), airplane.getFuel());

}

TEST_F(VliegveldTest, SetterAirplane) {
    airplane.setNumber("123");
    EXPECT_EQ("123", airplane.getNumber());
    airplane.setCallsign("555");
    EXPECT_EQ("555", airplane.getCallsign());
    airplane.setModel("Concorde");
    EXPECT_EQ("Concorde", airplane.getModel());
    airplane.setStatus("departed");
    EXPECT_EQ("departed", airplane.getStatus());
    airplane.setHeight(2000);
    EXPECT_EQ(unsigned (2000), airplane.getHeight());
    airplane.setAirport("Zaventem");
    EXPECT_EQ("Zaventem", airplane.getAirport());
    airplane.setGateNumber(5);
    EXPECT_EQ(5, airplane.getGateNumber());
    airplane.setCapacity(100);
    EXPECT_EQ(unsigned (100), airplane.getCapacity());
    airplane.setType("airline");
    EXPECT_EQ("airline", airplane.getType());
    airplane.setEngine("jet");
    EXPECT_EQ("jet", airplane.getEngine());
    airplane.setSize("small");
    EXPECT_EQ("small", airplane.getSize());
    airplane.setFuelCost(25);
    EXPECT_EQ(unsigned (25), airplane.getFuelCost());
    airplane.setFuel(10000);
    EXPECT_EQ(unsigned (10000), airplane.getFuel());
}

TEST_F(VliegveldTest, DefConAirport) {

    EXPECT_EQ(unsigned (0), airport.getGates().size());
    EXPECT_EQ(unsigned (0), airport.getRunways().size());
    EXPECT_EQ(unsigned (0), airport.getNumberOfGates());
    EXPECT_EQ(unsigned (0), airport.getNumberOfRunways());
    EXPECT_EQ("", airport.getName());
    EXPECT_EQ("", airport.getIata());
    EXPECT_EQ("", airport.getCallsign());

}

TEST_F(VliegveldTest, DefConRunway) {

    EXPECT_EQ("",runway.getName());
    EXPECT_EQ("",runway.getAirport());
    EXPECT_EQ("",runway.getType());
    EXPECT_EQ(unsigned (0),runway.getLength());
    EXPECT_EQ(true,runway.isVacant());
    EXPECT_EQ(unsigned (0),runway.get_Taxipoint().size());
    EXPECT_EQ(unsigned (0),runway.get_Crossing().size());

}

TEST_F(VliegveldTest, DefConTime) {

    EXPECT_EQ("12:00", time.printTime());

}

TEST_F(VliegveldTest, Parsing) {

    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    EXPECT_EQ("Antwerp International Airport", simulation.getAirports()[0].getName());
    EXPECT_EQ(unsigned (1), simulation.getAirports()[0].getNumberOfRunways());
    EXPECT_EQ(unsigned (10), simulation.getAirports()[0].getNumberOfGates());
    EXPECT_EQ("ANR", simulation.getAirports()[0].getIata());
    EXPECT_EQ("Antwerp Tower", simulation.getAirports()[0].getCallsign());
    EXPECT_EQ("11R", simulation.getAirports()[0].getRunways()[0].getName());
    EXPECT_EQ("ANR", simulation.getAirports()[0].getRunways()[0].getAirport());

}

TEST_F(VliegveldTest, Parsing_Test){ // Deze test test alle attributen van de parser m.b.v. een test xml-bestand

    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), "test.xml");
    EXPECT_EQ("Test airport", simulation.getAirports()[0].getName());
    EXPECT_EQ("BEL", simulation.getAirports()[0].getIata());
    EXPECT_EQ("Merksplas tower", simulation.getAirports()[0].getCallsign());
    EXPECT_EQ(unsigned (12), simulation.getAirports()[0].getNumberOfGates());

    EXPECT_EQ("12M", simulation.getRunways()[0].getName());
    EXPECT_EQ("BEL", simulation.getRunways()[0].getAirport());
    EXPECT_EQ("grass", simulation.getRunways()[0].getType());
    EXPECT_EQ(unsigned (1212), simulation.getRunways()[0].getLength());

    EXPECT_EQ("M48674", simulation.getAirplanes()[0].getNumber());
    EXPECT_EQ("Nighthawk", simulation.getAirplanes()[0].getCallsign());
    EXPECT_EQ("Nighthawk 340", simulation.getAirplanes()[0].getModel());
    EXPECT_EQ("private", simulation.getAirplanes()[0].getType());
    EXPECT_EQ("jet", simulation.getAirplanes()[0].getEngine());
    EXPECT_EQ("small", simulation.getAirplanes()[0].getSize());
    EXPECT_EQ("approaching", simulation.getAirplanes()[0].getStatus());
    EXPECT_EQ(unsigned (1), simulation.getAirplanes()[0].getCapacity());

}

TEST_F(VliegveldTest, Descending) {

    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    simulation.getAirplanes()[0].descending(simulation.getAirports()[0], time);
    EXPECT_EQ("standing at gate", simulation.getAirplanes()[0].getStatus());

}

TEST_F(VliegveldTest, ExpectedErrors) {

    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    Airplane airplanetest;
    EXPECT_DEATH(airplanetest.descending(simulation.getAirports()[0], time), "Airplane is not approaching");
    EXPECT_DEATH(parser::parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), "Simulatie.xml"), "Airplanes must be empty");

}

TEST_F(VliegveldTest, ascending){

    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                      "Simulatie.xml");
    EXPECT_TRUE(simulation.getAirplanes()[1].getStatus() == "standing at gate");
    simulation.getAirplanes()[1].ascending(simulation.getAirports()[0], time);
    EXPECT_TRUE(simulation.getAirplanes()[1].getStatus() == "departed");

    remove ("console_output.txt");
}

TEST_F(VliegveldTest, output){
    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), "Simulatie.xml");
    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
    simulation.start();
    EXPECT_TRUE(output::compare_file("output.txt", "output_test.txt"));
}

TEST_F(VliegveldTest, output_test){
    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), "test.xml");
    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
    simulation.start();
    EXPECT_TRUE(output::compare_file("output.txt", "output_test2.txt"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}