//
// Created by matth on 15/03/2018.
//

#ifndef VLIEGVELD_RUNWAY_H
#define VLIEGVELD_RUNWAY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Runway {
private:
    string name;
    string airport;
    string type;
    int length;
    bool vacant;
    vector<string> taxipoints;
    vector<string> crossings;

public:
    const string &getType() const;

    void setType(const string &type);

    const int &getLength() const;

    void setLength(const int &length);

    Runway();

    bool isVacant() const;

    void setVacant(bool vacant);

    const string &getName() const;

    void setName(const string &name);

    const string &getAirport() const;

    void setAirport(const string &airport);

    void add_Taxipoint(string crossing);

    vector<string> get_Taxipoint();

    void add_Crossing(string taxipoint);

    vector<string> get_Crossing();
};


#endif //VLIEGVELD_RUNWAY_H
