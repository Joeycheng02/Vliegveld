//
// Created by nightnarumi on 18/06/18.
//

#include "Time.h"
#include "DesignByContract.h"

Time::Time() {
    Time::t = unsigned (720);
}

unsigned int Time::getTime() {
    unsigned int hours = t / 60;
    unsigned int minutes = t - hours * 60;
    return hours * 10000 + minutes * 100;
}

void Time::addTime(unsigned int minute) {
    REQUIRE(Time::t >= 0, "The variable is not properly initialized");
    REQUIRE(minute >= 0, "The given variable is not properly initialized");
    Time::t += minute;
    Time::t = Time::t % 1440;
    ENSURE(Time::t < 1440, "The variable exceeds the allowed time");
    ENSURE(Time::getTime() >= 0, "The variable can't be a negative number");
}