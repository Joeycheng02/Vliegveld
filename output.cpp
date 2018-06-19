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

int output::landing(Airplane &airplane, Airport &airport, Runway &runway, int check, Time &time) {
    REQUIRE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty before requesting a landing");

    ofstream file;
    file.open("output.txt", ios_base::app);
    if (!file) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    if(check == 1){
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", arriving at " << airport.getName() << "." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", radar contact, descend and maintain five thousand feet, squawk " << airplane.getSquawk_code() << "."<< endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Descend and maintain five thousand feet, sqauwking " << airplane.getSquawk_code() << ", " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 2){
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", hold south on the one eighty radial, expect further clearence at " << "time" << "." <<  endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Holding south on the one eighty radial, " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 3){
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", descend and maintain three thousand feet." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Descend and maintain three thousand feet, " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 4){
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", cleared ILS approach runway" << runway.getName() << "." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Cleared ILS approach runway " << runway.getName() << ", " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 5) {
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", runway" << runway.getName() << " vacated." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ taxi-instructions" << endl << endl;
        time.addTime(1);
    }
    file.close();

    ENSURE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty after landing");

    return 0;
}

int output::ascending(Airplane &airplane, Airport &airport, Runway &runway, int check, Time &time) {
    REQUIRE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty before requesting to ascend");

    ofstream file;
    file.open("output.txt", ios_base::app);
    if (!file) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    if(check == 1){
        file << "[" << time.printTime() << "] [AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", requesting IFR clearancy to <destination>" << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", "  << airport.getCallsign() << ", cleared to <destination>, maintain five thousand, expect flight level one zero zero - ten minutes after departure, squawk <squawk-code>, " << airplane.getCallsign() << "." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Cleared to <destination>, initial altitude five thousand, expecting one zero zero in ten, squawking" << airplane.getSquawk_code() << ", " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 2){
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << " at gate " << airplane.getGateNumber() << ", requesting pushback." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", "  << airport.getCallsign() << ", pushback approved."<< endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Pushback approved, " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 3) {
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ " << airplane.getCallsign() << " is ready to taxi." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ taxi-instructions" << endl << endl;
        time.addTime(1);
    }

    if(check == 4){
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", holding short at " << runway.getName() << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", hold position." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Holding position, " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 5){
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", holding short at " << runway.getName() << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", line-up runway " << runway.getName() << " and wait." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Lining up runway " << runway.getName() << " and wait, " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 6){
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ " << airport.getCallsign() << ", " << airplane.getCallsign() << ", holding short at " << runway.getName() << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", runway " << runway.getName() << " cleared for take-off." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Runway " << runway.getName() << " cleared for take-off, " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    if(check == 7){
        file << "[" << time.printTime() << "][ATC]" << endl
             << "$ " << airplane.getCallsign() << ", runway " << runway.getName() << " cleared for take-off." << endl;
        time.addTime(1);
        file << "[" << time.printTime() << "][AIR]" << endl
             << "$ Runway " << runway.getName() << " cleared for take-off, " << airplane.getCallsign() << "." << endl << endl;
        time.addTime(1);
    }

    file.close();

    ENSURE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty after ascending");

    return 0;
}

bool output::compare_file(string file1, string file2) {

    ifstream file_1;
    ifstream file_2;

    string word_file1;
    file_1 >> word_file1;
    string word_file2;
    file_2 >> word_file2;

    file_1.open(file1.c_str());
    if(!file_1){
        cout << "There is no file named " << file1 << endl;
        return false;
    }
    file_2.open(file2.c_str());
    if(!file_2){
        cout << "There is no file named " << file2 << endl;
        return false;
    }

    while(file_1.good()){
        if(word_file1 != word_file2){
            return false;
        }
        file_1 >> word_file1;
        file_2 >> word_file2;
    }


    file_1.close();
    file_2.close();

    return true;
}
