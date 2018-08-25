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
    EXPECT_TRUE(runway.properlyInitialized());
    Runway* a = &runway;
    EXPECT_TRUE(a->properlyInitialized());
    Runway b = runway;
    EXPECT_FALSE(b.properlyInitialized());
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
    EXPECT_DEATH(runway.setName(""), "A Runway Name can't have an empty string.");
}

TEST_F(RunwayTest, runway){

    parser::full_parsing(simulation, "Simulatie.xml");
    // There is always 1 more taxipoint than crossings.
    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->getCrossing().size() + 1 == simulation.getAirports()[0]->getRunways()[0]->getTaxipoint().size());
    // The taxipoints are named with the alphabet.
    EXPECT_TRUE(simulation.getAirports()[0]->getRunways()[0]->getTaxipoint()[0] > simulation.getAirports()[0]->getRunways()[0]->getTaxipoint()[1]);
    EXPECT_EQ(simulation.getAirports()[0]->getRunways()[0]->getCrossing()[0], simulation.getAirports()[0]->getRunways()[1]);
}

TEST_F(RunwayTest, edgeCases){

    parser::full_parsing(simulation, "test2.xml");
    simulation.getRunways()[0]->setName("TestName");
    EXPECT_EQ("TestName", simulation.getRunways()[0]->getName());

    simulation.getRunways()[0]->setAirport("TestAirport");
    EXPECT_EQ("TestAirport", simulation.getRunways()[0]->getAirport());

    EXPECT_DEATH(simulation.getRunways()[0]->setType("asphalt"), "The variable already has this value");
    EXPECT_DEATH(simulation.getRunways()[0]->setType("asphal"), "This is not a valuable value");
    simulation.getRunways()[0]->setType("grass");
    EXPECT_EQ("grass", simulation.getRunways()[0]->getType());

    EXPECT_DEATH(simulation.getRunways()[0]->setLength(-5), "The variable can't be a negative number");
    EXPECT_DEATH(simulation.getRunways()[0]->setLength(-1), "The variable can't be a negative number");
    simulation.getRunways()[0]->setLength(0);
    EXPECT_EQ(0, simulation.getRunways()[0]->getLength());
    simulation.getRunways()[0]->setLength(164);
    EXPECT_EQ(164, simulation.getRunways()[0]->getLength());

    EXPECT_EQ(unsigned (0), simulation.getRunways()[0]->getTaxipoint().size());

    EXPECT_EQ(unsigned (0), simulation.getRunways()[0]->getCrossing().size());

    EXPECT_EQ(unsigned (0), simulation.getRunways()[0]->getCrossings_string().size());

    remove("console_output.txt");
}
