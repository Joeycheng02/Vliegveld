#include "Simulation.h"
#include "parser.h"
#include "output.h"

using namespace std;

int main() {
    Simulation simulation;
    parser::full_parsing(simulation, "test.xml");
    output::outputfile(simulation.getAirports(), simulation.getAirplanes());
    simulation.start();

    //console output
    ifstream file ("console_output.txt");
    if (file.is_open()) {
        cout << file.rdbuf();
    }
    remove("console_output.txt");
}