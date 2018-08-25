//
// Created by nightnarumi on 19/08/18.
//
#include "Simulation.h"
#include "parser.h"
#include "output.h"
#include <gtest/gtest.h>

class OutputTest: public  ::testing::Test {
protected:
    virtual void SetUp(){
    }

    virtual void TearDown() {
    }

    Simulation simulation;
};

TEST_F(OutputTest, output){

    parser::full_parsing(simulation, "Simulatie.xml");
    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
    simulation.start();
    EXPECT_TRUE(output::compare_file("output.txt", "output_test.txt"));
}

TEST_F(OutputTest, output_test){

    parser::full_parsing(simulation, "test.xml");
    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
    simulation.start();
    EXPECT_TRUE(output::compare_file("output.txt", "output_test2.txt"));
}

TEST_F(OutputTest, output_test2){

    parser::full_parsing(simulation, "test2.xml");
    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
    simulation.start();
    EXPECT_TRUE(output::compare_file("output.txt", "output_test3.txt"));
    
    remove("console_output.txt");
}