#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <map>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

#include "Operation.h"

using namespace std;

class DateMethods{

    int isYearLeap(int year);

public:
    bool validateDate(string &date);
    int convertStringDateToInt(const string &dateAsString);
    static string convertIntDateToStringWithDashes(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getCurrentMonthLastDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();
    int calculateDaysInMonth(int year, int month);
    vector <Operation> sortVectorByDate(vector <Operation> &operations);

};

#endif
