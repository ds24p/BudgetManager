#include "DateMethods.h"

bool DateMethods::validateDate(string &date)
{
    int year = stoi(date.substr(0, 4));

    time_t now = time(nullptr);
    tm* local_time = localtime(&now);

    if (year < 2000 || year > (local_time->tm_year + 1900))
    {
        return false;
    }
    int month = stoi(date.substr(5, 2));
    if (month > 12 || month < 1)
    {
        return false;
    }
    int daysInIncomesMonth = calculateDaysInMonth(year, month);
    int day = stoi(date.substr(8, 2));

    if (day <= daysInIncomesMonth)
    {
        return true;
    }
}

int DateMethods::getCurrentDate()
{
    time_t now = time(nullptr);
    tm* local_time = localtime(&now);

    int currentDate = (local_time->tm_year + 1900) * 10000 +
                      (local_time->tm_mon + 1) * 100 +
                      local_time->tm_mday;

    cout << "Today's date: " << convertIntDateToStringWithDashes(currentDate) << endl;
    return currentDate;
}

int DateMethods::getCurrentMonthFirstDayDate()
{
    time_t now = time(nullptr);
    tm* local_time = localtime(&now);

    local_time->tm_mday = 01;

    int currentMonthFirstDay = (local_time->tm_year + 1900) * 10000 +
                      (local_time->tm_mon + 1) * 100 + local_time->tm_mday;


    return currentMonthFirstDay;
}

int DateMethods::getCurrentMonthLastDayDate()
{
    time_t now = time(nullptr);
    tm* local_time = localtime(&now);

    local_time->tm_mday = calculateDaysInMonth(local_time->tm_year + 1900, local_time->tm_mon + 1);

    int currentMonthLastDay = (local_time->tm_year + 1900) * 10000 +
                      (local_time->tm_mon + 1) * 100 + local_time->tm_mday;

    return currentMonthLastDay;
}

int DateMethods::getPreviousMonthFirstDayDate()
{
    time_t now = time(nullptr);
    tm* local_time = localtime(&now);

    local_time->tm_mday = 01;

    int previousMonthFirstDay = (local_time->tm_year + 1900) * 10000 +
                      (local_time->tm_mon) * 100 + local_time->tm_mday;

    return previousMonthFirstDay;
}

int DateMethods::getPreviousMonthLastDayDate()
{
    time_t now = time(nullptr);
    tm* local_time = localtime(&now);

    local_time->tm_mday = calculateDaysInMonth(local_time->tm_year + 1900, local_time->tm_mon);

    int previousMonthLastDay = (local_time->tm_year + 1900) * 10000 +
                      (local_time->tm_mon + 1) * 100 + local_time->tm_mday;

    return previousMonthLastDay;
}

int DateMethods::calculateDaysInMonth(int year, int month)
{
    tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };

    time_t first_day_next_month = mktime(&time_in);

    time_in.tm_mon += 1;
    first_day_next_month = mktime(&time_in);

    tm* last_day = localtime(&first_day_next_month);
    last_day->tm_mday -= 1;

    time_t last_day_time = mktime(last_day);
    tm* end_of_month = localtime(&last_day_time);

    return end_of_month->tm_mday;
}

int DateMethods::convertStringDateToInt(const string &dateAsString)
{
    string formattedDate = dateAsString;
    formattedDate.erase(remove(formattedDate.begin(), formattedDate.end(), '-'), formattedDate.end());

    return stoi(formattedDate);
}

vector <Operation> DateMethods::sortVectorByDate(vector <Operation> &operations)
{
    sort(operations.begin(), operations.end(), [](const Operation& a, const Operation& b)
    {
        return a.date > b.date;
    });

    return operations;
}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt) {

    string dateStr = to_string(dateAsInt);

    dateStr.insert(4, "-");
    dateStr.insert(7, "-");

    return dateStr;
}
