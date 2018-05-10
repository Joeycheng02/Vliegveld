//
// Created by nightnarumi on 02/05/18.
//

#include <fstream>
#include "output.h"
#include "DesignByContract.h"

int output::outputfile(vector<Airport> &airports, vector<Airplane> &airplanes) {

    REQUIRE(airplanes.size() != 0, "There are no airplanes available");
    REQUIRE(airports.size() != 0, "There are no airports available");

    //Open the file + exception.
    ofstream file("output.txt");
    if (!file) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    //For test purposes
    cout << "Writing..." << endl << endl;


    //Writes the information of all the airports in the output.txt file.
    for (int i = 0; i < int(airports.size()); ++i) {

        file << "Airport: " << airports[i].getName() << " " << "(" << airports[i].getIata() << ")" << endl;
        file << " --> gates: " << airports[i].getNumberOfGates() << endl;
        file << " --> runways: " << airports[i].getNumberOfRunways() << endl;
        file << endl;

    }

    //For test purposes
    cout << "Airports completed!" << endl << endl;

    //Triple Whiteline
    file << endl << endl;

    //Writes the information of all the airports in the output.txt file.
    for (int i = 0; i < int(airplanes.size()); ++i) {

        file << "Airplane: " << airplanes[i].getCallsign() << " " << "(" << airplanes[i].getNumber() << ")" << endl;
        file << " --> model: " << airplanes[i].getModel() << endl;
        file << endl;

    }

    //For test purposes
    cout << "Airplanes completed!" << endl << endl;

    //Close the file and return.
    file.close();
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
             << "$ " << airplane.getCallsign() << ", radar contact, descend and maintain five thousand feet, squawk " << "squawk code"<< endl
             << "[3][AIR]" << endl
             << "$ Descend and maintain five thousand feet, sqauwking " << "squawk code" << ", " << airplane.getCallsign() << endl;
    }

    if(check == 2){
        file << "[1][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", hold south on the one eighty radial, expect further clearence at " << "time" << "." <<  endl
             << "[2][AIR]" << endl
             << "$ Holding south on the one eighty radial, " << airplane.getCallsign() << "." << endl;
    }





    file.close();
    return 0;
}