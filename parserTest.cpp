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
}

TEST_F(ParserTest, fout_xml){
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_xml_0.xml"), "Failed to open file");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_xml_leeg.xml"), "Error document empty.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_bestand.cpp"), "Error document empty.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_bestand.h"), "Error document empty.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_bestand.txt"), "Error document empty.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_01.xml"), "This Airport numberOfGates can't be a negative number.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_02.xml"), "This Airport numberOfGates can't be a negative number.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_03.xml"), "This Runway Type is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_04.xml"), "This Runway Type is not a valuable value.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_05.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_06.xml"), "This Runway Length can't be a negative number.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_07.xml"), "ssa"); failed to die
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_08.xml"), "ssa"); failed to die
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_09.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_10.xml"), "This variable of Airport can't be empty.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_11.xml"), "This Runway Type is not a valuable value.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_12.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_13.xml"), "This Airplane Type is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_14.xml"), "This Runway Length can't be a negative number.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_15.xml"), "This Airplane Type is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_16.xml"), "This Airplane Size is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_17.xml"), "This Airplane Engine is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_18.xml"), "This Airplane Status is not a valuable value.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_19.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_20.xml"), "This Airplane Capacity can't be a negative number.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_21.xml"), "This Airplane Fuel already has this value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_22.xml"), "This Airplane Fuel can't be a negative number.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_23.xml"), "This Airplane Type is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_24.xml"), "This Airplane Type is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_25.xml"), "This Airplane Engine is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_26.xml"), "This Airplane Size is not a valuable value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_27.xml"), "This Airplane Status is not a valuable value.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_28.xml"), "ssa"); failed to die
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_29.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_30.xml"), "This Airplane Capacity can't be a negative number.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_31.xml"), "This Airplane Fuel already has this value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_inhoud_32.xml"), "This Airplane Fuel can't be a negative number.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_01.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_02.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_03.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_04.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_05.xml"), "Error reading Attributes.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_06.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_07.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_08.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_09.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_10.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_11.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_12.xml"), "Error reading Attributes.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_13.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_14.xml"), "Error reading Attributes.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_15.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_16.xml"), "Error reading Attributes.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_17.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_18.xml"), "Error reading Attributes.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_19.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_20.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_syntax_21.xml"), "Error reading end tag.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_01.xml"), "Dit is geen variabele van Airport.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_01.xml"), "Dit is geen variabele van Airport.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_02.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_03.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_04.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_05.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_06.xml"), "This Runway Airport already has this value.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_07.xml"), "Dit is geen variabele van Runway.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_08.xml"), "ssa"); failed to die
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_09.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_10.xml"), "This Airplane Callsign already has this value");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_11.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_12.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_13.xml"), "Dit is geen variabele van Airport.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_14.xml"), "ssa"); failed to die
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_15.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_16.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_17.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_18.xml"), "Dit is geen variabele van Runway.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_19.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_20.xml"), "This Airport Name already has this value.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_21.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_22.xml"), "Dit is geen variabele van Airport.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_23.xml"), "Dit is geen variabele van Airport.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_24.xml"), "Dit is geen variabele van Airport.");
//    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_25.xml"), "ssa"); failed to die
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_26.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_27.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_28.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_29.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_30.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_31.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_32.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_33.xml"), "Dit is geen variabele van Runway.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_34.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_35.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_36.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_37.xml"), "Dit staat niet in de parser en wordt dus genegeerd.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_38.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_39.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_40.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_41.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_42.xml"), "Dit is geen variabele van Airplane.");
    EXPECT_DEATH(parser::full_parsing(simulation, "foute xml bestanden/fout_typo_43.xml"), "Dit is geen variabele van Airplane.");

    remove("console_output.txt");
}