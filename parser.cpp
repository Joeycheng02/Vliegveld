//
// Created by knoetson on 01.05.18.
//

#include "parser.h"
#include "DesignByContract.h"

int parser::parsing(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways, const char* path) {

    REQUIRE(airplanes.empty(), "Airplanes must be empty");
    REQUIRE(airports.empty(), "Airports must be empty");
    REQUIRE(runways.empty(), "Runways must be empty");

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
        if (elemName != "AIRPORT" and elemName != "RUNWAY" and elemName != "AIRPLANE"){
            cout << elemName << " staat niet in de parser en wordt dus genegeerd." << endl;
            continue;
        }
        if (elemName == "AIRPORT") {
            Airport airport;
            for (TiXmlElement *elem2 = elem->FirstChildElement(); elem2 != NULL;
                 elem2 = elem2->NextSiblingElement()) {
                string elem2Name = elem2->Value();

                if (elem2Name != "name" and elem2Name != "iata" and elem2Name != "callsign" and elem2Name != "gates"){
                    cout << elem2Name << " is geen variabele van Airport." << endl;
                }

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
                        for(unsigned int k = 0; k<t.size(); k++) {
                            if (t[k] != '0' and t[k] != '1' and t[k] != '2' and t[k] != '3' and t[k] != '4' and
                                t[k] != '5'
                                and t[k] != '6' and t[k] != '7' and t[k] != '8' and t[k] != '9') {
                                cout << "De " << elem2Name << " moet een integer zijn.";
                                return -1;
                            }
                        }
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

                if (elem2Name != "name" and elem2Name != "airport" and elem2Name != "type" and elem2Name != "length"){
                    cout << elem2Name << " is geen variabele van Runway." << endl;
                }

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
                if (elem2Name == "type"){
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        runway.setType(t);
                    }
                }
                if (elem2Name == "length"){
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        int i;
                        for(unsigned int k = 0; k<t.size(); k++) {
                            if (t[k] != '0' and t[k] != '1' and t[k] != '2' and t[k] != '3' and t[k] != '4' and
                                t[k] != '5'
                                and t[k] != '6' and t[k] != '7' and t[k] != '8' and t[k] != '9') {
                                cout << "De " << elem2Name << " moet een integer zijn.";
                                return -1;
                            }
                        }
                        sscanf(t.c_str(), "%d", &i);
                        runway.setLength(i);
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

                if (elem2Name != "model" and elem2Name != "number" and elem2Name != "callsign" and elem2Name != "type" and elem2Name != "engine" and elem2Name != "size" and
                    elem2Name != "status" and elem2Name != "capacity"){
                    cout << elem2Name << " is geen variabele van Airplane." << endl;
                }

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
                if (elem2Name == "type") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airplane.setType(t);
                    }
                }
                if (elem2Name == "engine") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airplane.setEngine(t);
                    }
                }
                if (elem2Name == "size") {
                    for (TiXmlNode *e = elem2->FirstChild(); e != NULL; e = e->NextSibling()) {
                        TiXmlText *text = e->ToText();
                        if (text == NULL)
                            continue;
                        std::string t = text->Value();
                        airplane.setSize(t);
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
                        const std::string t = text->Value();
                        int i;
                        for(unsigned int k = 0; k<t.size(); k++){
                            if(t[k]!='0' and t[k]!='1' and t[k]!='2' and t[k]!='3' and t[k]!='4' and t[k]!='5'
                               and t[k]!='6' and t[k]!='7' and t[k]!='8' and t[k]!='9'){
                                cout << "De " << elem2Name << " moet een integer zijn.";
                                return -1;
                            }
                        }
                        sscanf(t.c_str(), "%d", &i);
                        airplane.setCapacity(i);
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

    ENSURE(!airplanes.empty(), "Airplanes can't be empty");
    ENSURE(!airports.empty(), "Airports can't be empty");
    ENSURE(!runways.empty(), "Runways can't be empty");

    return 0;
}

void parser::addRunway(vector <Airport> &airports, vector <Runway> &runways) {

    REQUIRE(!runways.empty(), "There are no runways available");
    REQUIRE(!airports.empty(), "There are no airports available");

    for (int i = 0; i < int(runways.size()); ++i) {
        for (int j = 0; j < int(airports.size()); ++j) {
            if(runways[i].getAirport() == airports[j].getIata()) {
                airports[j].addRunways(runways[i]);
            }
        }
    }
    for (int k = 0; k < int(airports.size()); ++k) {
        ENSURE(!airports[k].getRunways().empty(), "Airport has no runway");
    }
}

void parser::full_parsing(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways,
                          const char *path) {
    parsing(airports, airplanes, runways, path);
    addRunway(airports, runways);
}