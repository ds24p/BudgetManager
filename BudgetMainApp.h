#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include "UserManager.h"
#include "BudgetManager.h"
#include <string>
#include <iostream>

using namespace std;

class BudgetMainApp{
    UserManager userManager;
    //*budgetManager : BudgetManager
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
public:
    // BudgetMainApp (string userFileName, string incomeFileName, string expenseFileName)
    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
};


#endif
