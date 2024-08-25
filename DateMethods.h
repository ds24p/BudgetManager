#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <map>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Operation.h"

using namespace std;

class DateMethods{

    void calculateCurrentDate(map<string, int> &currentDate);
    int isYearLeap(int year);

public:
    bool validateDate(string &date);
    int convertStringDateToInt(const string &dateAsString);
    string convertIntDateToStringWithDashes(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getCurrentMonthLastDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();
    int calculateDaysInMonth(int year, int month);

};

#endif
