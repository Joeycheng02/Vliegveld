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

//TEST_F(VliegveldTest, DefConSimulation) {
//
//    EXPECT_EQ(0, int(simulation.getAirports().size()));
//    EXPECT_EQ(0, int(simulation.getAirplanes().size()));
//    EXPECT_EQ(0, int(simulation.getRunways().size()));
//    EXPECT_TRUE(runway.isVacant());
//
//}

TEST_F(VliegveldTest, DefConAirplane) {

    EXPECT_EQ("", airplane.getNumber());
    EXPECT_EQ("", airplane.getCallsign());
    EXPECT_EQ("", airplane.getModel());
    EXPECT_EQ("", airplane.getStatus());
    EXPECT_EQ(0, airplane.getHeight());
    EXPECT_EQ("", airplane.getAirport());
    EXPECT_EQ(-1, airplane.getGateNumber());
    EXPECT_EQ(0, airplane.getCapacity());
    EXPECT_EQ("", airplane.getType());
    EXPECT_EQ("", airplane.getEngine());
    EXPECT_EQ("", airplane.getSize());
    EXPECT_EQ(0, airplane.getFuelCost());
    EXPECT_EQ(0, airplane.getFuel());
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
    EXPECT_EQ(2000, airplane.getHeight());
    airplane.setAirport("Zaventem");
    EXPECT_EQ("Zaventem", airplane.getAirport());
    airplane.setGateNumber(5);
    EXPECT_EQ(5, airplane.getGateNumber());
    airplane.setCapacity(100);
    EXPECT_EQ(100, airplane.getCapacity());
    airplane.setType("private");
    EXPECT_EQ("private", airplane.getType());
    airplane.setEngine("jet");
    EXPECT_EQ("jet", airplane.getEngine());
    airplane.setSize("small");
    EXPECT_EQ("small", airplane.getSize());
    airplane.setFuelCost(25);
    EXPECT_EQ(25, airplane.getFuelCost());
    airplane.setFuel(10000);
    EXPECT_EQ(10000, airplane.getFuel());

}

TEST_F(VliegveldTest, ascending){

    parser::full_parsing(simulation, "Simulatie.xml");
    EXPECT_EQ(0, simulation.getAirplanes()[1]->getHeight());
    EXPECT_TRUE(simulation.getAirplanes()[1]->getStatus() == "standing at gate");
    simulation.getAirplanes()[1]->ascending(simulation.getAirports()[0], time);
    EXPECT_TRUE(simulation.getAirplanes()[1]->getStatus() == "departed");
    EXPECT_EQ(5000, simulation.getAirplanes()[1]->getHeight());
    EXPECT_EQ(-1, simulation.getAirplanes()[1]->getGateNumber());
    EXPECT_DEATH(simulation.getAirplanes()[1]->ascending(simulation.getAirports()[0], time), "Airplane is not standing at a gate");
}

TEST_F(VliegveldTest, Descending) {

    parser::full_parsing(simulation, "Simulatie.xml");
    EXPECT_TRUE(simulation.getAirplanes()[0]->getStatus() == "approaching");
    simulation.getAirplanes()[0]->descending(simulation.getAirports()[0], time);
    EXPECT_TRUE(simulation.getAirplanes()[0]->getStatus() == "standing at gate");
    EXPECT_EQ(0, simulation.getAirplanes()[0]->getHeight());
    EXPECT_EQ(1, simulation.getAirplanes()[1]->getGateNumber());
    EXPECT_EQ(2, simulation.getAirplanes()[0]->getGateNumber());
    EXPECT_DEATH(simulation.getAirplanes()[0]->descending(simulation.getAirports()[0], time), "Airplane is not approaching");

}

//TEST_F(VliegveldTest, DefConAirport) {
//
//    EXPECT_EQ(unsigned (0), airport.getGates().size());
//    EXPECT_EQ(unsigned (0), airport.getRunways().size());
//    EXPECT_EQ(0, airport.getNumberOfGates());
//    EXPECT_EQ(unsigned(0), airport.getNumberOfRunways());
//    EXPECT_EQ("", airport.getName());
//    EXPECT_EQ("", airport.getIata());
//    EXPECT_EQ("", airport.getCallsign());
//
//}

//TEST_F(VliegveldTest, SetterAirport) {
//
//    airport.setNumberOfGates(5);
//    EXPECT_EQ(5, airport.getNumberOfGates());
//    airport.setName("Zaventem");
//    EXPECT_EQ("Zaventem", airport.getName());
//    airport.setIata("BRU");
//    EXPECT_EQ("BRU", airport.getIata());
//    airport.setCallsign("Brussels Tower");
//    EXPECT_EQ("Brussels Tower", airport.getCallsign());
//
//}

//TEST_F(VliegveldTest, Airport) {
//
//    parser::full_parsing(simulation, "Simulatie.xml");
//    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->isVacant());
//    EXPECT_TRUE(simulation.getAirports()[0]->permissionToAscend(0));
//    simulation.getAirports()[0]->getRunways()[0]->setVacant(false);
//    EXPECT_FALSE(simulation.getAirports()[0]->permissionToAscend(0));
//    EXPECT_FALSE(simulation.getAirports()[0]->permissionToDescend(12000));
//    EXPECT_TRUE(simulation.getAirports()[0]->permissionToDescend(10000));
//    EXPECT_TRUE(simulation.getAirports()[0]->permissionToDescend(5000));
//    EXPECT_FALSE(simulation.getAirports()[0]->permissionToDescend(3000));
//    simulation.getAirports()[0]->getRunways()[0]->setVacant(true);
//    EXPECT_TRUE(simulation.getAirports()[0]->permissionToDescend(3000));
//}
//
//TEST_F(VliegveldTest, DefConRunway) {
//
//    EXPECT_EQ("",runway.getName());
//    EXPECT_EQ("",runway.getAirport());
//    EXPECT_EQ("",runway.getType());
//    EXPECT_EQ(0,runway.getLength());
//    EXPECT_TRUE(runway.isVacant());
//    EXPECT_EQ(unsigned(0),runway.getTaxipoint().size());
//    EXPECT_EQ(unsigned(0),runway.getCrossing().size());
//
//}
//
//TEST_F(VliegveldTest, SetterRunway) {
//
//    runway.setName("2LR");
//    EXPECT_EQ("2LR",runway.getName());
//    runway.setAirport("Zaventem");
//    EXPECT_EQ("Zaventem",runway.getAirport());
//    runway.setType("asphalt");
//    EXPECT_EQ("asphalt",runway.getType());
//    runway.setLength(200);
//    EXPECT_EQ(200,runway.getLength());
//    runway.setVacant(false);
//    EXPECT_FALSE(runway.isVacant());
//
//}
//
//TEST_F(VliegveldTest, runway){
//    parser::full_parsing(simulation, "Simulatie.xml");
//    // There is always 1 more taxipoint then corssings.
//    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->getCrossing().size() + 1 == simulation.getAirports()[0]->getRunways()[0]->getTaxipoint().size());
//    // The taxipoints are named with the alphabet.
//    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->getTaxipoint()[0] > simulation.getAirports()[0]->getRunways()[0]->getTaxipoint()[1]);
//    EXPECT_EQ(simulation.getAirports()[0]->getRunways()[0]->getCrossing()[0], simulation.getAirports()[0]->getRunways()[1]);
//}

//TEST_F(VliegveldTest, DefConTime) {
//
//    EXPECT_EQ("12:00", time.printTime());
//
//}
//
//TEST_F(VliegveldTest, SetterTime) {
//
//    time.addTime(20);
//    EXPECT_EQ("12:20", time.printTime());
//    time.addTime(700);
//    EXPECT_EQ("00:00", time.printTime());
//
//}

//TEST_F(VliegveldTest, Parsing) {
//
//    parser::full_parsing(simulation, "Simulatie.xml");
//    EXPECT_EQ("Antwerp International Airport", simulation.getAirports()[0]->getName());
//    EXPECT_EQ(unsigned (2), simulation.getAirports()[0]->getNumberOfRunways());
//    EXPECT_EQ(10, simulation.getAirports()[0]->getNumberOfGates());
//    EXPECT_EQ("ANR", simulation.getAirports()[0]->getIata());
//    EXPECT_EQ("Antwerp Tower", simulation.getAirports()[0]->getCallsign());
//    EXPECT_EQ("12R", simulation.getAirports()[0]->getRunways()[0]->getName());
//    EXPECT_EQ("11R", simulation.getAirports()[0]->getRunways()[1]->getName());
//    EXPECT_EQ("ANR", simulation.getAirports()[0]->getRunways()[0]->getAirport());
//
//}
//
//TEST_F(VliegveldTest, Parsing_Test){ // Deze test test alle attributen van de parser m.b.v. een test xml-bestand
//
//    parser::full_parsing(simulation, "test.xml");
//    EXPECT_EQ("Test airport", simulation.getAirports()[0]->getName());
//    EXPECT_EQ("BEL", simulation.getAirports()[0]->getIata());
//    EXPECT_EQ("Merksplas tower", simulation.getAirports()[0]->getCallsign());
//    EXPECT_EQ(12, simulation.getAirports()[0]->getNumberOfGates());
//
//    EXPECT_EQ("12M", simulation.getRunways()[0]->getName());
//    EXPECT_EQ("BEL", simulation.getRunways()[0]->getAirport());
//    EXPECT_EQ("grass", simulation.getRunways()[0]->getType());
//    EXPECT_EQ(1212, simulation.getRunways()[0]->getLength());
//
//    EXPECT_EQ("M48674", simulation.getAirplanes()[0]->getNumber());
//    EXPECT_EQ("Nighthawk", simulation.getAirplanes()[0]->getCallsign());
//    EXPECT_EQ("Nighthawk 340", simulation.getAirplanes()[0]->getModel());
//    EXPECT_EQ("private", simulation.getAirplanes()[0]->getType());
//    EXPECT_EQ("jet", simulation.getAirplanes()[0]->getEngine());
//    EXPECT_EQ("small", simulation.getAirplanes()[0]->getSize());
//    EXPECT_EQ("approaching", simulation.getAirplanes()[0]->getStatus());
//    EXPECT_EQ(1, simulation.getAirplanes()[0]->getCapacity());
//
//}

//TEST_F(VliegveldTest, output){
//    parser::full_parsing(simulation, "Simulatie.xml");
//    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
//    simulation.start();
//    EXPECT_TRUE(output::compare_file("output.txt", "output_test.txt"));
//}
//
//TEST_F(VliegveldTest, output_test){
//    parser::full_parsing(simulation, "test.xml");
//    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
//    simulation.start();
//    EXPECT_TRUE(output::compare_file("output.txt", "output_test2.txt"));
//    remove("console_output.txt");
//}

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

TEST_F(VliegveldTest, Airplane_edgeCases) {
    parser::full_parsing(simulation, "test.xml");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setCapacity(-100), "The variable can't be a negative number");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setCapacity(-1), "The variable can't be a negative number");
    simulation.getAirplanes()[0]->setCapacity(148751);
    EXPECT_EQ(148751, simulation.getAirplanes()[0]->getCapacity());

    EXPECT_DEATH(simulation.getAirplanes()[0]->setGateNumber(-5), "The variable can't be less than -1");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setGateNumber(-2), "The variable can't be less than -1");
    simulation.getAirplanes()[0]->setGateNumber(-1);
    EXPECT_EQ(-1, simulation.getAirplanes()[0]->getGateNumber());
    simulation.getAirplanes()[0]->setGateNumber(164);
    EXPECT_EQ(164, simulation.getAirplanes()[0]->getGateNumber());

    EXPECT_DEATH(simulation.getAirplanes()[0]->setHeight(-10000), "The variable can't be a negative number");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setHeight(-1), "The variable can't be a negative number");
    simulation.getAirplanes()[0]->setHeight(1);
    EXPECT_EQ(1, simulation.getAirplanes()[0]->getHeight());
    simulation.getAirplanes()[0]->setHeight(10000);
    EXPECT_EQ(10000, simulation.getAirplanes()[0]->getHeight());

    EXPECT_DEATH(simulation.getAirplanes()[0]->setFuel(-453), "The variable can't be a negative number");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setFuel(-1), "The variable can't be a negative number");
    simulation.getAirplanes()[0]->setFuel(1);
    EXPECT_EQ(1, simulation.getAirplanes()[0]->getFuel());
    simulation.getAirplanes()[0]->setFuel(2000);
    EXPECT_EQ(2000, simulation.getAirplanes()[0]->getFuel());

    EXPECT_DEATH(simulation.getAirplanes()[0]->setFuelCost(-10), "The variable can't be a negative number");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setFuelCost(-1), "The variable can't be a negative number");
    simulation.getAirplanes()[0]->setFuelCost(1);
    EXPECT_EQ(1, simulation.getAirplanes()[0]->getFuelCost());
    simulation.getAirplanes()[0]->setFuelCost(100);
    EXPECT_EQ(100, simulation.getAirplanes()[0]->getFuelCost());


    remove("console_output.txt");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}