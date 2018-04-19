//
// Created by nightnarumi on 21/03/18.
//

#ifndef VLIEGVELD_GATE_H
#define VLIEGVELD_GATE_H

#include <iostream>
#include <string>
using namespace std;

class Gate {
private:
    int name;
    string airport;
    bool vacant;
public:
    Gate();

    const string &getAirport() const;

    void setAirport(const string &airport);

    int getName() const;

    void setName(int name);

    bool isVacant() const;

    void setVacant(bool vacant);
};


#endif //VLIEGVELD_GATE_H
