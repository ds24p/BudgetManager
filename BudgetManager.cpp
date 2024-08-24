#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Operation income;
    DateMethods methods;

    income.id = incomeFile.getLastId() + 1;
    income.userId = LOGGED_USER_ID;
    int date;
    string sDate;
    cout << "Adding a new income..." << endl;
    cout << "Add the operation with current date? y/n" << endl;
    char choice = Utils::getCharacter();
    while(!(choice == 'y' || choice == 'n'))
    {
        cout << "Wrong input. Only input 'y' or 'n' is allowed." << endl;
        choice = Utils::getCharacter();
    }
    if (choice == 'y')
    {
        date = methods.getCurrentDate();
    }
    else if (choice == 'n')
    {
        cout << "Give a date in form YYYY-MM-DD: ";
        sDate = Utils::readLine();

        while(!methods.validateDate(sDate))
        {
            cout << "Incorrect date. Try again: " << endl;
            sDate = Utils::readLine();
        }

        sDate.erase(remove(sDate.begin(), sDate.end(), '-'), sDate.end());
        date = stoi(sDate);
    }

    cout << "Add the description of operation: ";
    string item = Utils::readLine();

    cout << "Add the amount: ";
    string inputAmount = Utils::readLine();
    while(!Utils::isValidDouble(inputAmount))
    {
        cout << "Wrong input. Give the correct number." << endl;
        inputAmount = Utils::readLine();
    }
    double amount = stod(inputAmount);

    incomeFile.addOperationToFile(income);
    incomes.push_back(income);
}

void BudgetManager::addExpense()
{
    Operation expense;
    DateMethods methods;

    expense.id = expenseFile.getLastId() + 1;
    expense.userId = LOGGED_USER_ID;
    int date;
    string sDate;
    cout << "Adding a new expense..." << endl;
    cout << "Add the operation with current date? y/n" << endl;
    char choice = Utils::getCharacter();
    while(!(choice == 'y' || choice == 'n'))
    {
        cout << "Wrong input. Only input 'y' or 'n' is allowed." << endl;
        choice = Utils::getCharacter();
    }
    if (choice == 'y')
    {
        date = methods.getCurrentDate();
    }
    else if (choice == 'n')
    {
        cout << "Give a date in form YYYY-MM-DD: ";
        sDate = Utils::readLine();

        while(!methods.validateDate(sDate))
        {
            cout << "Incorrect date. Try again: " << endl;
            sDate = Utils::readLine();
        }

        sDate.erase(remove(sDate.begin(), sDate.end(), '-'), sDate.end());
        date = stoi(sDate);
    }

    cout << "Add the description of operation: ";
    string item = Utils::readLine();

    cout << "Add the amount: ";
        string inputAmount = Utils::readLine();
    while(!Utils::isValidDouble(inputAmount))
    {
        cout << "Wrong input. Give the correct number." << endl;
        inputAmount = Utils::readLine();
    }
    double amount = stod(inputAmount);

    expenseFile.addOperationToFile(expense);
    expenses.push_back(expense);
}

void BudgetManager::showCurrentMonthBalance()
{
    ;
}

void BudgetManager::showPreviousMonthBalance()
{
    ;
}
void BudgetManager::showCustomPeriodBalance()
{
    ;
}
