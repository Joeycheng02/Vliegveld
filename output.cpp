//
// Created by nightnarumi on 02/05/18.
//

#include <fstream>
#include "output.h"
#include "DesignByContract.h"

int output::outputfile(vector<Airport> &airports, vector<Airplane> &airplanes) {

    REQUIRE(!airplanes.empty(), "There are no airplanes available");
    REQUIRE(!airports.empty(), "There are no airports available");

    //Open the file + exception.
    ofstream console("console_output.txt");
    if (!console) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }


    //Open the file + exception.
    ofstream file("output.txt");
    if (!file) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    //For test purposes
    console << "Writing..." << endl << endl;


    //Writes the information of all the airports in the output.txt file.
    for (int i = 0; i < int(airports.size()); ++i) {

        file << "Airport: " << airports[i].getName() << " " << "(" << airports[i].getIata() << ")" << endl;
        file << " --> gates: " << airports[i].getNumberOfGates() << endl;
        file << " --> runways: " << airports[i].getNumberOfRunways() << endl;
        file << endl;

    }

    //For test purposes
    console << "Airports completed!" << endl << endl;

    //Triple Whiteline
    file << endl << endl;

    //Writes the information of all the airports in the output.txt file.
    for (int i = 0; i < int(airplanes.size()); ++i) {

        file << "Airplane: " << airplanes[i].getCallsign() << " " << "(" << airplanes[i].getNumber() << ")" << endl;
        file << " --> model: " << airplanes[i].getModel() << endl;
        file << endl;

    }

    //For test purposes
    console << "Airplanes completed!" << endl << endl;

    //Close the file and return.
    file.close();
    console.close();
    return 0;
}

int output::landing(Airplane &airplane, Airport &airport, Runway &runway, int check) {
    ofstream file;
    file.open("output.txt", ios_base::app);
    if (!file) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    if(check == 1){
        file << "[1][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", arriving at " << airport.getName() << "." << endl
             << "[2][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", radar contact, descend and maintain five thousand feet, squawk " << "squawk code."<< endl
             << "[3][AIR]" << endl
             << "$ Descend and maintain five thousand feet, sqauwking " << "squawk code" << ", " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 2){
        file << "[1][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", hold south on the one eighty radial, expect further clearence at " << "time" << "." <<  endl
             << "[2][AIR]" << endl
             << "$ Holding south on the one eighty radial, " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 3){
        file << "[1][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", descend and maintain three thousand feet." << endl
             << "[1][AIR]" << endl
             << "$ Descend and maintain three thousand feet, " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 4){
        file << "[1][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", cleared ILS approach runway" << runway.getName() << "." << endl
             << "[1][AIR]" << endl
             << "$ Cleared ILS approach runway " << runway.getName() << ", " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 5) {
        file << "[1][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", runway" << runway.getName() << " vacated." << endl
             << "[2][ATC]" << endl
             << "$ taxi-instructions" << endl << endl;
    }
    file.close();
    return 0;
}

int output::ascending(Airplane &airplane, Airport &airport, Runway &runway, int check) {
    ofstream file;
    file.open("output.txt", ios_base::app);
    if (!file) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    if(check == 1){
        file << "[1][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", requesting IFR clearancy to <destination>" << endl
             << "[2][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", "  << airport.getCallsign() << ", cleared to <destination>, maintain five thousand, expect flight level one zero zero - ten minutes after departure, squawk <squawk-code>, " << airplane.getCallsign() << "." << endl
             << "[3][AIR]" << endl
             << "$ Cleared to <destination>, initial altitude five thousand, expecting one zero zero in ten, squawking <squawk-code>, " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 2){
        file << "[1][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << " at gate " << airplane.getGateNumber() << ", requesting pushback." << endl
             << "[2][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", "  << airport.getCallsign() << ", pushback approved."<< endl
             << "[3][AIR]" << endl
             << "$ Pushback approved, " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 3) {
        file << "[1][AIR]" << endl
             << "$ " << airplane.getCallsign() << " is ready to taxi." << endl
             << "[2][ATC]" << endl
             << "$ taxi-instructions" << endl << endl;
    }

    if(check == 4){
        file << "[1][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", holding short at " << runway.getName() << endl
             << "[2][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", hold position." << endl
             << "[3][AIR]" << endl
             << "$ Holding position, " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 5){
        file << "[1][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", holding short at " << runway.getName() << endl
             << "[2][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", line-up runway " << runway.getName() << " and wait." << endl
             << "[3][AIR]" << endl
             << "$ Lining up runway " << runway.getName() << " and wait, " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 6){
        file << "[1][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", holding short at " << runway.getName() << endl
             << "[2][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", runway " << runway.getName() << " cleared for take-off." << endl
             << "[3][AIR]" << endl
             << "$ Runway " << runway.getName() << " cleared for take-off, " << airplane.getCallsign() << "." << endl << endl;
    }

    if(check == 7){
        file << "[1][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", runway " << runway.getName() << " cleared for take-off." << endl
             << "[1][AIR]" << endl
             << "$ Runway " << runway.getName() << " cleared for take-off, " << airplane.getCallsign() << "." << endl << endl;
    }

    file.close();
    return 0;
}
