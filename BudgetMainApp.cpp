#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::registerUser()
{
    cout << "User registration" << endl;
    userManager.registerUser();
}

void BudgetMainApp::loginUser()
{
    if(!isUserLoggedIn())
    {
        cout << "User login" << endl;
        userManager.loginUser();
    }
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
    }
}

void BudgetMainApp::changeUserPassword()
{
    userManager.changeUserPassword();
}

void BudgetMainApp::logoutUser()
{
    if(isUserLoggedIn())
    {
        userManager.logoutUser();
    }
}

void BudgetMainApp::addIncome()
{
    budgetManager->addIncome();
}

void BudgetMainApp::addExpense()
{
    budgetManager->addExpense();
}

void BudgetMainApp::showCurrentMonthBalance()
{
    budgetManager->showCurrentMonthBalance();
}

void BudgetMainApp::showPreviousMonthBalance()
{
    budgetManager->showPreviousMonthBalance();
}

void BudgetMainApp::showCustomPeriodBalance()
{
    budgetManager->showCustomPeriodBalance();
}
