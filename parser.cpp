//
// Created by knoetson on 01.05.18.
//

#include "parser.h"
#include "DesignByContract.h"

int parser::parsing(vector<Airport*> &airports, vector<Airplane*> &airplanes, vector<Runway*> &runways, const char* path) {

    REQUIRE(airplanes.empty(), "Airplanes must be empty.");
    REQUIRE(airports.empty(), "Airports must be empty.");
    REQUIRE(runways.empty(), "Runways must be empty.");
    ofstream console("console_output.txt", fstream::app);
    bool one_airport = false;
    vector<Airplane*> airplanes_temp;

    TiXmlDocument doc;
    REQUIRE(doc.LoadFile(path), doc.ErrorDesc());

    TiXmlElement *root = doc.FirstChildElement();
    REQUIRE((root != NULL), "Failed to load file: No root element.");

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL;
         elem = elem->NextSiblingElement()) {
        std::string elemName = elem->Value();
        REQUIRE((elemName == "AIRPORT" or elemName == "RUNWAY" or elemName == "AIRPLANE"), "Dit staat niet in de parser en wordt dus genegeerd.");
        if (elemName == "AIRPORT") {
            if(!one_airport) {
                Airport* airport = new Airport();
                for (TiXmlElement *elem2 = elem->FirstChildElement(); elem2 != NULL;
                     elem2 = elem2->NextSiblingElement()) {
                    string elem2Name = elem2->Value();

                    REQUIRE(elem2->FirstChild() != NULL, "This variable of Airport can't be empty.");
                    REQUIRE((elem2Name == "name" or elem2Name == "iata" or elem2Name == "callsign" or
                        elem2Name == "gates"), "Dit is geen variabele van Airport.");

                    if (elem2Name == "name") {
                        for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                            TiXmlText *text = e->ToText();
                            std::string t = text->Value();
                            airport->setName(t);
                        }
                    }
                    if (elem2Name == "iata") {
                        for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                            TiXmlText *text = e->ToText();
                            std::string t = text->Value();
                            airport->setIata(t);
                        }
                    }
                    if (elem2Name == "callsign") {
                        for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                            TiXmlText *text = e->ToText();
                            std::string t = text->Value();
                            airport->setCallsign(t);
                        }
                    }
                    if (elem2Name == "gates") {
                        for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                            TiXmlText *text = e->ToText();
                            std::string t = text->Value();
                            int i;
//                            for (unsigned int k = 0; k < t.size(); k++) {
//                                if (t[k] != '0' and t[k] != '1' and t[k] != '2' and t[k] != '3' and t[k] != '4' and
//                                    t[k] != '5'
//                                    and t[k] != '6' and t[k] != '7' and t[k] != '8' and t[k] != '9') {
//                                    console << "De " << elem2Name << " moet een integer zijn.";
//                                    return -1;
//                                }
//                            }
                            sscanf(t.c_str(), "%d", &i);
                            airport->setNumberOfGates(i);
                        }
                    }
                }
                airports.push_back(airport);
                one_airport = true;
            }
        }

        if (elemName == "RUNWAY") {
            Runway* runway = new Runway();
            vector<string> crossings;
            for (TiXmlElement *elem2 = elem->FirstChildElement(); elem2 != NULL;
                 elem2 = elem2->NextSiblingElement()) {
                string elem2Name = elem2->Value();

                REQUIRE(elem2->FirstChild() != NULL, "This variable of Runway can't be empty.");
                REQUIRE((elem2Name == "name" or elem2Name == "airport" or elem2Name == "type" or elem2Name == "length"
                        or elem2Name == "TAXIROUTE"), "Dit is geen variabele van Runway.");

                if (elem2Name == "name") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        runway->setName(t);
                    }
                }
                if (elem2Name == "airport") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        runway->setAirport(t);
                    }
                }
                if (elem2Name == "type"){
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        runway->setType(t);
                    }
                }
                if (elem2Name == "length"){
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        int i;
                        sscanf(t.c_str(), "%d", &i);
                        runway->setLength(i);
                    }
                }
                if (elem2Name == "TAXIROUTE"){
                    for(TiXmlElement* elem3 = elem2->FirstChildElement(); elem3 != NULL;
                        elem3 = elem3->NextSiblingElement()){
                        string elem3Name = elem3->Value();

                        REQUIRE(elem3->FirstChild() != NULL, "This variable of Taxiroute can't be empty.");
                        REQUIRE((elem3Name == "taxipoint" or elem3Name == "crossing"), "Dit is geen variabele van Runway.");

                        if (elem3Name == "taxipoint"){
                            for (TiXmlNode *e = elem3->FirstChild(); e != NULL; e = e->NextSibling()) {
                                TiXmlText *text = e->ToText();
                                std::string t = text->Value();
                                runway->addTaxipoint(t);
                            }
                        }
                        if (elem3Name == "crossing"){
                            for (TiXmlNode *e = elem3->FirstChild(); e != NULL; e = e->NextSibling()) {
                                TiXmlText *text = e->ToText();
                                std::string t = text->Value();
                                runway->addCrossings_string(t);
                            }
                        }
                    }
                }
            }
            runways.push_back(runway);
        }
        if (elemName == "AIRPLANE") {
            Airplane* airplane = new Airplane();
            for (TiXmlElement *elem2 = elem->FirstChildElement(); elem2 != NULL;
                 elem2 = elem2->NextSiblingElement()) {
                string elem2Name = elem2->Value();

                REQUIRE(elem2->FirstChild() != NULL, "This variable of Airplane can't be empty.");
                REQUIRE(elem2Name == "model" or elem2Name == "number" or elem2Name == "callsign" or elem2Name == "type" or elem2Name == "engine" or elem2Name == "size" or
                    elem2Name == "status" or elem2Name == "capacity" or elem2Name == "fuel", "Dit is geen variabele van Airplane.");

                if (elem2Name == "number") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        airplane->setNumber(t);
                    }
                }
                if (elem2Name == "callsign") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        airplane->setCallsign(t);
                    }
                }
                if (elem2Name == "model") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        airplane->setModel(t);
                    }
                }
                if (elem2Name == "type") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        airplane->setType(t);
                    }
                }
                if (elem2Name == "engine") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        airplane->setEngine(t);
                    }
                }
                if (elem2Name == "size") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        airplane->setSize(t);
                    }
                }
                if (elem2Name == "status") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        std::string t = text->Value();
                        airplane->setStatus(t);
                    }
                }
                if (elem2Name == "capacity") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        const std::string t = text->Value();
                        int i;
                        sscanf(t.c_str(), "%d", &i);
                        airplane->setCapacity(i);
                    }
                }
                if (elem2Name == "fuel") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        const std::string t = text->Value();
                        int i;
                        sscanf(t.c_str(), "%d", &i);
                        airplane->setFuel(i);
                    }
                }
            }
            if (airplane->getSize() == "small" and airplane->getEngine() == "propeller") {
                airplane->setFuelCost(10);
            } else if (airplane->getSize() == "small" and airplane->getEngine() == "jet") {
                airplane->setFuelCost(25);
            } else if (airplane->getSize() == "medium" and airplane->getEngine() == "propeller") {
                airplane->setFuelCost(50);
            } else if (airplane->getSize() == "medium" and airplane->getEngine() == "jet") {
                airplane->setFuelCost(175);
            } else if (airplane->getSize() == "large" and airplane->getEngine() == "propeller") {
                airplane->setFuelCost(100);
            } else if (airplane->getSize() == "large" and airplane->getEngine() == "jet") {
                airplane->setFuelCost(250);
            }
            airplanes_temp.push_back(airplane);
        }
    }
    for(unsigned int a = 0; a < airplanes_temp.size(); a++){
        airplanes.push_back(airplanes_temp[a]);
    }

    doc.Clear();
    for (int j = 0; j < int(airplanes.size()); ++j) {
        if (airplanes[j]->getStatus() == "standing at gate") {
            REQUIRE(0 != int(airports.size()), "No gates available anymore.");
            if (airplanes[j]->getGateNumber() == -1) {
                for (int k = 0; k < airports[0]->getNumberOfGates(); ++k) {
                    if (airports[0]->getGates()[k]) {
                        airplanes[j]->setAirport(airports[0]->getName());
                        airplanes[j]->setHeight(0);
                        airplanes[j]->setGateNumber(k+1);
                        airports[0]->getGates()[k] = false;
                        break;
                    }
                }
            }
            else {
                break;
            }
        }
    }

    ENSURE(!airplanes.empty(), "Airplanes can't be empty.");
    ENSURE(!airports.empty(), "Airports can't be empty.");
    ENSURE(!runways.empty(), "Runways can't be empty.");
    console.close();

    return 0;
}

void parser::addRunway(vector <Airport*> &airports, vector <Runway*> &runways) {

    REQUIRE(!runways.empty(), "There are no runways available.");
    REQUIRE(!airports.empty(), "There are no airports available.");

    for (int i = 0; i < int(runways.size()); ++i) {
        for (int j = 0; j < int(airports.size()); ++j) {
            if(runways[i]->getAirport() == airports[j]->getIata()) {
                airports[j]->addRunways(runways[i]);
            }
        }
    }
    for (int k = 0; k < int(airports.size()); ++k) {
        ENSURE(!airports[k]->getRunways().empty(), "Airport has no runway.");
    }

    for(unsigned int R = 0; R < runways.size(); R++){
        for(unsigned int s = 0; s < runways[R]->getCrossings_string().size(); s++){
            for(unsigned int r = 0; r < runways.size(); r++){
                if(runways[r]->getName() == runways[R]->getCrossings_string()[s]){
                    runways[R]->addCrossing(runways[r]);
                }
            }
        }
    }
}

void parser::full_parsing(Simulation &simulation, const char *path) {

    ofstream console("console_output.txt", fstream::app);


    REQUIRE((parsing(simulation.getAirports(), simulation.getAirplanes(), simulation.getRunways(), path) == 0), "Er is iets mis gegaan met de parsing.");
    console.close();
    addRunway(simulation.getAirports(), simulation.getRunways());
}