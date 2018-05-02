#include "Simulation.h"
#include "parser.h"
#include "output.h"
#include "Airplane.h"
#include "Airport.h"
#include "Runway.h"

using namespace std;

int main() {
    Simulation simulation;
    parser::full_parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(),
                        "Simulatie.xml");
    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
//    Airplane.descending(simulation.getAirplanes()[0], simulation.getAirports()[0]);
//    Airplane.ascending(simulation.getAirplanes()[0], simulation.getAirports()[0]);
//    Airplane.approaching(simulation.getAirplanes()[0]);
//    Airplane.descending(simulation.getAirplanes()[0], simulation.getAirports()[1]);

}