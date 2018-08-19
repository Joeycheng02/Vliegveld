//
// Created by nightnarumi on 19/08/18.
//
#include "Simulation.h"
#include "parser.h"
#include <gtest/gtest.h>

class ParserTest: public  ::testing::Test {
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

TEST_F(ParserTest, Parsing) {

    parser::full_parsing(simulation, "Simulatie.xml");
    EXPECT_EQ("Antwerp International Airport", simulation.getAirports()[0]->getName());
    EXPECT_EQ(unsigned (2), simulation.getAirports()[0]->getNumberOfRunways());
    EXPECT_EQ(10, simulation.getAirports()[0]->getNumberOfGates());
    EXPECT_EQ("ANR", simulation.getAirports()[0]->getIata());
    EXPECT_EQ("Antwerp Tower", simulation.getAirports()[0]->getCallsign());
    EXPECT_EQ("12R", simulation.getAirports()[0]->getRunways()[0]->getName());
    EXPECT_EQ("11R", simulation.getAirports()[0]->getRunways()[1]->getName());
    EXPECT_EQ("ANR", simulation.getAirports()[0]->getRunways()[0]->getAirport());

}

TEST_F(ParserTest, Parsing_Test){ // Deze test test alle attributen van de parser m.b.v. een test xml-bestand

    parser::full_parsing(simulation, "test.xml");
    EXPECT_EQ("Test airport", simulation.getAirports()[0]->getName());
    EXPECT_EQ("BEL", simulation.getAirports()[0]->getIata());
    EXPECT_EQ("Merksplas tower", simulation.getAirports()[0]->getCallsign());
    EXPECT_EQ(12, simulation.getAirports()[0]->getNumberOfGates());

    EXPECT_EQ("12M", simulation.getRunways()[0]->getName());
    EXPECT_EQ("BEL", simulation.getRunways()[0]->getAirport());
    EXPECT_EQ("grass", simulation.getRunways()[0]->getType());
    EXPECT_EQ(1212, simulation.getRunways()[0]->getLength());

    EXPECT_EQ("M48674", simulation.getAirplanes()[0]->getNumber());
    EXPECT_EQ("Nighthawk", simulation.getAirplanes()[0]->getCallsign());
    EXPECT_EQ("Nighthawk 340", simulation.getAirplanes()[0]->getModel());
    EXPECT_EQ("private", simulation.getAirplanes()[0]->getType());
    EXPECT_EQ("jet", simulation.getAirplanes()[0]->getEngine());
    EXPECT_EQ("small", simulation.getAirplanes()[0]->getSize());
    EXPECT_EQ("approaching", simulation.getAirplanes()[0]->getStatus());
    EXPECT_EQ(1, simulation.getAirplanes()[0]->getCapacity());

    remove("console_output.txt");
}

//TEST_F(VliegveldTest, fout_xml){
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_xml_0.xml"), "Failed to open file");
//    EXPECT_DEATH(parser::full_parsing(simulation, "output.txt"), "Error document empty.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_text.xml"), "Airport has no runway");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_xml_1.xml"), "Error reading end tag.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_xml_2.xml"), "Error reading end tag.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_xml_3.xml"), "Airplanes can't be empty");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_xml_4.xml"), "There are no airports available");
//    remove("console_output.txt");
//}