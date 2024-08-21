#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Operation.h"
#include "OperationFile.h"
#include "DateMethods.h"
#include "Utils.h"


enum Type{
    INCOME,
    EXPENSE
};


class BudgetManager{
    //const int LOGGED_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;
    Operation addOperationDetails(const Type &type);
    void showBalance(int startDate, int endDate);
    double calculateBalance(int startDate, int endDate, const Type &type);

public:
// BudgetManager (string incomeFileName, string expenseFileName, int loggedUserId)
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
    };


#endif
