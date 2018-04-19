#include "Simulation.h"

int main() {
    Simulation simulation;
    if (simulation.parser(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                          "/home/nightnarumi/CLionProjects/Vliegveld/Simulatie.xml") == 0) {
        simulation.addRunway(simulation.getAirports(), simulation.getRunways());
        simulation.outputfile(simulation.getAirports(), simulation.getAirplanes());
        simulation.descending(simulation.getAirplanes()[0], simulation.getAirports()[0]);
        simulation.ascending(simulation.getAirplanes()[0], simulation.getAirports()[0]);
        simulation.approaching(simulation.getAirplanes()[0]);
        simulation.descending(simulation.getAirplanes()[0], simulation.getAirports()[1]);

    }
}