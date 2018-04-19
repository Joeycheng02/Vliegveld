//
// Created by nightnarumi on 22/03/18.
//

#include "Simulation.h"
#include "DesignByContract.h"
using namespace std;

int Simulation::outputfile(vector<Airport> &airports, vector<Airplane> &airplanes) {

    REQUIRE(airplanes.size() != 0, "There are no airplanes available");
    REQUIRE(airports.size() != 0, "There are no airports available");

    //Open the file + exception.
    ofstream file ("output.txt");
    if ( !file ) {
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
        file << " --> Capacity: " << airplanes[i].getPassengers() << endl;
        file << endl;

    }

    //For test purposes
    cout << "Airplanes completed!" << endl << endl;

    //Close the file and return.
    file.close();
    return 0;
}

int Simulation::descending(Airplane &airplane, Airport &airport) {

    REQUIRE (airplane.getStatus() == "Approaching", "Airplane is not approaching");

    Gate gate;

    for (int i = 0; i <= airport.getNumberOfGates(); ++i) {
        if (i == airport.getNumberOfGates()) {
            cout << "Instructing " << airplane.getCallsign() << " to take a holding pattern untill a clearance is made to land." << endl;
            return -1;
        }
        if (airport.getGates()[i].isVacant()) {
            airport.getGates()[i].setVacant(false);
            gate = airport.getGates()[i];
            break;
        }
    }

    int runwayNumber;
    for (int i = 0; i <= airport.getNumberOfRunways(); ++i) {
        if (i == airport.getNumberOfRunways()) {
            cout << "Instructing " << airplane.getCallsign() << " to wait untill there is a free runway." << endl;
            return -1;
        }

        if (airport.getRunways()[i].isVacant()) {
            airport.getRunways()[i].setVacant(false);
            runwayNumber = i;
            break;
        }
    }

    if (airplane.getHeight() != 10000) {
        cout << "Instructing " << airplane.getCallsign() << " to get an height of 10.000ft." << endl;
        airplane.setHeight(10000);
    }
    cout << airplane.getCallsign() << " is approaching " << airport.getName() << " at 10.000ft." << endl;
    while (airplane.getHeight() > 1000) {
        airplane.setHeight(airplane.getHeight() - 1000);
        cout << airplane.getCallsign() << " descended to " << airplane.getHeight() << " ft." << endl;
    }
    airplane.setHeight(airplane.getHeight() - 1000);
    cout << airplane.getCallsign() << " is landing at "<< airport.getName() << " on runway " << airport.getRunways()[runwayNumber].getName() << endl;
    cout << airplane.getCallsign() << " has landed at "<< airport.getName() << " on runway " << airport.getRunways()[runwayNumber].getName() << endl;
    cout << airplane.getCallsign() << " is taxiing to Gate " << gate.getName() << endl;
    cout << airplane.getCallsign() << " is standing at Gate " << gate.getName() << endl;
    airport.getRunways()[runwayNumber].setVacant(true);
    airplane.setAirport(airport.getName());
    airplane.setGateNumber(gate.getName());
    airplane.setStatus("Standing at gate");
    cout << airplane.getPassengers() << " passengers exited " << airplane.getCallsign() << " at gate " << gate.getName() << " of " << airport.getName() << endl;
    cout << airplane.getCallsign() << " has been checked for technical malfunctions" << endl << endl;

    ENSURE(airplane.getStatus() == "Standing at gate", "Airplane is not standing at a gate");
    ENSURE(airplane.getAirport() == airport.getName(), "Airplane is not standing at the right airport");

    return 0;
}


int Simulation::ascending (Airplane &airplane, Airport &airport) {

    REQUIRE (airplane.getStatus() == "Standing at gate", "Airplane is not standing at a gate");

    REQUIRE (airplane.getAirport() == airport.getName(), "This airplane does not belong to the given aiport.");

    int runwayNumber;

    for (int i = 0; i <= airport.getNumberOfRunways(); ++i) {
        if (i == airport.getNumberOfRunways()) {
            cout << "Instructing " << airplane.getCallsign() << " to wait untill there is a free runway." << endl;
            return -1;
        }

        if (airport.getRunways()[i].isVacant()) {
            airport.getRunways()[i].setVacant(false);
            runwayNumber = i;
            break;
        }
    }

    cout << airplane.getCallsign() << " has been refueled" << endl;
    cout << airplane.getPassengers() << " passengers boarded " << airplane.getCallsign() << " at gate " << airport.getGates()[airplane.getGateNumber()-1].getName() << " of " << airport.getName() << endl;

    airport.getGates()[airplane.getGateNumber()-1].setVacant(true);
    airplane.setGateNumber(-1);

    cout << airplane.getCallsign() << " is taxiing to runway " << airport.getRunways()[runwayNumber].getName() << "." << endl;
    cout << airplane.getCallsign() << " is taking off at " << airport.getName() << " on runway " << airport.getRunways()[runwayNumber].getName() << endl;

    while (airplane.getHeight() < 5000) {
        airplane.setHeight(airplane.getHeight() + 1000);
        cout << airplane.getCallsign() << " has ascended to " << airplane.getHeight() << " ft." << endl;
    }
    cout << airplane.getCallsign() << " has left " << airport.getName() << endl << endl;
    airport.getRunways()[runwayNumber].setVacant(true);
    airplane.setAirport("No airplane assigned");
    airplane.setStatus("Departed");
    return 0;

    ENSURE(airport.getRunways()[runwayNumber].isVacant(), "Runway is still occupied");
    ENSURE(airplane.getGateNumber() == -1, "Airplane is still at a gate");
}




void Simulation::addRunway(vector <Airport> &airports, vector <Runway> &runways) {

    REQUIRE(runways.size() != 0, "There are no runways available");
    REQUIRE(airports.size() != 0, "There are no airports available");

    for (int i = 0; i < int(runways.size()); ++i) {
        for (int j = 0; j < int(airports.size()); ++j) {
            if(runways[i].getAirport() == airports[j].getIata()) {
                airports[j].addRunways(runways[i]);
            }
        }
    }
    for (int k = 0; k < int(airports.size()); ++k) {
        ENSURE(airports[k].getRunways().size() != 0, "Airport has no runway");
    }
}

int Simulation::parser(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways, const char* path) {

    REQUIRE(airplanes.size() == 0, "Airplanes must be empty");
    REQUIRE(airports.size() == 0, "Airports must be empty");
    REQUIRE(runways.size() == 0, "Runways must be empty");

    TiXmlDocument doc;
    if (!doc.LoadFile(path)) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return -1;
    }

    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return -1;
    }

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL;
         elem = elem->NextSiblingElement()) {
        std::string elemName = elem->Value();

        if (elemName == "AIRPORT") {
            Airport airport;
            for (TiXmlElement *elem2 = elem->FirstChildElement(); elem2 != NULL;
                 elem2 = elem2->NextSiblingElement()) {
                string elem2Name = elem2->Value();

                if (elem2Name == "name") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airport.setName(t);
                    }
                }
                if (elem2Name == "iata") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airport.setIata(t);
                    }
                }
                if (elem2Name == "callsign") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airport.setCallsign(t);
                    }
                }
                if (elem2Name == "gates") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        int i;
                        sscanf(t.c_str(), "%d", &i);
                        airport.setNumberOfGates(i);
                    }
                }
            }
            airports.push_back(airport);
        }

        if (elemName == "RUNWAY") {
            Runway runway;
            for (TiXmlElement *elem2 = elem->FirstChildElement(); elem2 != NULL;
                 elem2 = elem2->NextSiblingElement()) {
                string elem2Name = elem2->Value();

                if (elem2Name == "name") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        runway.setName(t);
                    }
                }
                if (elem2Name == "airport") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        runway.setAirport(t);
                    }
                }
            }
            runways.push_back(runway);
        }
        if (elemName == "AIRPLANE") {
            Airplane airplane;
            for (TiXmlElement *elem2 = elem->FirstChildElement(); elem2 != NULL;
                 elem2 = elem2->NextSiblingElement()) {
                string elem2Name = elem2->Value();

                if (elem2Name == "number") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airplane.setNumber(t);
                    }
                }
                if (elem2Name == "callsign") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airplane.setCallsign(t);
                    }
                }
                if (elem2Name == "model") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airplane.setModel(t);
                    }
                }
                if (elem2Name == "status") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airplane.setStatus(t);
                    }
                }
                if (elem2Name == "capacity") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        int i;
                        sscanf(t.c_str(), "%d", &i);
                        airplane.setPassengers(i);
                    }
                }
            }
            airplanes.push_back(airplane);
        }
    }
    doc.Clear();
    for (int j = 0; j < int(airplanes.size()); ++j) {
        if (airplanes[j].getStatus() == "Standing at gate") {
            for (int i = 0; i < int(airports.size()+1); ++i) {
                if (i == int(airports.size())) {
                    cout << "No gates available anymore." << endl;
                    return -1;
                }
                if (airplanes[j].getGateNumber() == -1) {
                    for (int k = 0; k < airports[i].getNumberOfGates(); ++k) {
                        if (airports[i].getGates()[k].isVacant()) {
                            airplanes[j].setAirport(airports[i].getName());
                            airplanes[j].setHeight(0);
                            airplanes[j].setGateNumber(k+1);
                            airports[i].getGates()[k].setVacant(false);
                            break;
                        }
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    ENSURE(airplanes.size() != 0, "Airplanes can't be empty");
    ENSURE(airports.size() != 0, "Airports can't be empty");
    ENSURE(runways.size() != 0, "Runways can't be empty");

    return 0;
}

vector<Airport> &Simulation::getAirports() {
    return airports;
}

vector<Airplane> &Simulation::getAirplanes() {
    return airplanes;
}

vector<Runway> &Simulation::getRunways() {
    return runways;
}

int Simulation::approaching(Airplane &airplane) {
    REQUIRE(airplane.getStatus() == "Departed", "Airplane is not in the air or is already approaching");
    airplane.setStatus("Approaching");
    cout << airplane.getCallsign() << " is approaching" << endl << endl;
    ENSURE(airplane.getStatus() == "Approaching", "Airplane is not approaching");
    return 0;
}
