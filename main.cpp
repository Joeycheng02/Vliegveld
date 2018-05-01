#include "Simulation.h"
#include "parser.h"

int main() {
    Simulation simulation;
    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                        "Simulatie.xml");
    simulation.outputfile(simulation.getAirports(), simulation.getAirplanes());
    simulation.descending(simulation.getAirplanes()[0], simulation.getAirports()[0]);
    simulation.ascending(simulation.getAirplanes()[0], simulation.getAirports()[0]);
    simulation.approaching(simulation.getAirplanes()[0]);
    simulation.descending(simulation.getAirplanes()[0], simulation.getAirports()[1]);

}