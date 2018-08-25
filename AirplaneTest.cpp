//
// Created by nightnarumi on 19/08/18.
//

#include "Simulation.h"
#include "parser.h"
#include <gtest/gtest.h>

class AirplaneTest: public  ::testing::Test {
protected:
    virtual void SetUp(){
    }

    virtual void TearDown() {
    }

    Simulation simulation;
    Airplane airplane;
    Time time;
};

TEST_F(AirplaneTest, DefCon) {

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

TEST_F(AirplaneTest, Setter) {

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

TEST_F(AirplaneTest, Ascending){

    Time* _time = &time;
    parser::full_parsing(simulation, "Simulatie.xml");
    EXPECT_EQ(0, simulation.getAirplanes()[1]->getHeight());
    EXPECT_TRUE(simulation.getAirplanes()[1]->getStatus() == "standing at gate");
    simulation.getAirplanes()[1]->ascending(simulation.getAirports()[0], _time);
    EXPECT_TRUE(simulation.getAirplanes()[1]->getStatus() == "departed");
    EXPECT_EQ(5000, simulation.getAirplanes()[1]->getHeight());
    EXPECT_EQ(-1, simulation.getAirplanes()[1]->getGateNumber());
    EXPECT_DEATH(simulation.getAirplanes()[1]->ascending(simulation.getAirports()[0], _time), "Airplane is not standing at a gate");
}

TEST_F(AirplaneTest, Descending) {

    Time* _time = &time;
    parser::full_parsing(simulation, "Simulatie.xml");
    EXPECT_TRUE(simulation.getAirplanes()[0]->getStatus() == "approaching");
    simulation.getAirplanes()[0]->descending(simulation.getAirports()[0], _time);
    EXPECT_TRUE(simulation.getAirplanes()[0]->getStatus() == "standing at gate");
    EXPECT_EQ(0, simulation.getAirplanes()[0]->getHeight());
    EXPECT_EQ(1, simulation.getAirplanes()[1]->getGateNumber());
    EXPECT_EQ(2, simulation.getAirplanes()[0]->getGateNumber());
    EXPECT_DEATH(simulation.getAirplanes()[0]->descending(simulation.getAirports()[0], _time), "Airplane is not approaching");
}

TEST_F(AirplaneTest, Airplane_edgeCases) {
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

    EXPECT_DEATH(simulation.getAirplanes()[0]->setType("private"), "The variable already has this value");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setType("privat"), "This is not a valuable value");
    simulation.getAirplanes()[0]->setType("military");
    EXPECT_EQ("military", simulation.getAirplanes()[0]->getType());
    simulation.getAirplanes()[0]->setType("emergency");
    EXPECT_EQ("emergency", simulation.getAirplanes()[0]->getType());
    EXPECT_DEATH(simulation.getAirplanes()[0]->setType("emmergency"), "This is not a valuable value");

    EXPECT_DEATH(simulation.getAirplanes()[0]->setEngine("propeler"), "This is not a valuable value");
    simulation.getAirplanes()[0]->setEngine("propeller");
    EXPECT_EQ("propeller", simulation.getAirplanes()[0]->getEngine());
    EXPECT_DEATH(simulation.getAirplanes()[0]->setEngine("jey"), "This is not a valuable value");

    EXPECT_DEATH(simulation.getAirplanes()[0]->setSize("small"), "The variable already has this value");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setSize("smal"), "This is not a valuable value");
    simulation.getAirplanes()[0]->setSize("medium");
    EXPECT_EQ("medium", simulation.getAirplanes()[0]->getSize());
    simulation.getAirplanes()[0]->setSize("large");
    EXPECT_EQ("large", simulation.getAirplanes()[0]->getSize());
    EXPECT_DEATH(simulation.getAirplanes()[0]->setSize("larg"), "This is not a valuable value");

    EXPECT_DEATH(simulation.getAirplanes()[0]->setStatus("approaching"), "The variable already has this value");
    EXPECT_DEATH(simulation.getAirplanes()[0]->setStatus("approachin"), "This is not a valuable value");
    simulation.getAirplanes()[0]->setStatus("standing at gate");
    EXPECT_EQ("standing at gate", simulation.getAirplanes()[0]->getStatus());
    simulation.getAirplanes()[0]->setStatus("departed");
    EXPECT_EQ("departed", simulation.getAirplanes()[0]->getStatus());
    EXPECT_DEATH(simulation.getAirplanes()[0]->setStatus("depated"), "This is not a valuable value");

    remove("console_output.txt");
}