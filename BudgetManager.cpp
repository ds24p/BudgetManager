#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Operation income;
    DateMethods methods;

    income.id = incomeFile.lastId + 1;
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
    cout << "Income added..." << endl;
    system("pause");
}

void BudgetManager::addExpense()
{
    Operation expense;
    DateMethods methods;

    expense.id = expenseFile.lastId + 1;
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
    cout << "Expense added..." << endl;
    system("pause");
}

void BudgetManager::showCurrentMonthBalance()
{
    DateMethods dateMethods;
    //do osobnej funkcji w Utils
    sort(incomes.begin(), incomes.end(), [](const Operation& a, const Operation& b)
    {
        return a.date < b.date;
    });
    sort(expenses.begin(), expenses.end(), [](const Operation& a, const Operation& b)
    {
        return a.date < b.date;
    });

    //do osobnej funkcji, ktora zwraca sume + dodac optymalizacje bo wektor ktory dostaje jest przeciez posortowany

    double incomeSum = 0;
    double expenseSum = 0;

    for (int i = 0; i < incomes.size(); i++)
    {

        if (incomes[i].date >= dateMethods.getCurrentMonthFirstDayDate() && incomes[i].date <= dateMethods.getCurrentMonthLastDayDate())
        {
            //printuj i sumuj
            cout << "ID: " << incomes[i].id << ", UserID: " << incomes[i].userId
                 << ", Date: " << incomes[i].date << ", Item: " << incomes[i].item
                 << ", Amount: " << incomes[i].amount << endl;

            incomeSum += incomes[i].amount;
        }
    }

    for (int i = 0; i < expenses.size(); i++)
    {

        if (expenses[i].date >= dateMethods.getCurrentMonthFirstDayDate() || expenses[i].date <= dateMethods.getCurrentMonthLastDayDate())
        {
            //printuj i sumuj
            cout << "ID: " << expenses[i].id << ", UserID: " << expenses[i].userId
                 << ", Date: " << expenses[i].date << ", Item: " << expenses[i].item
                 << ", Amount: " << expenses[i].amount << endl;

            expenseSum += expenses[i].amount;
        }
    }

    cout << "THE GENERAL BALANCE FOR THIS MONTH" << endl;
    cout << "----------------------------------" << endl;
    cout << "Incomes: " << incomeSum << endl;
    cout << "Expenses: " << expenseSum << endl;
    cout << "The general balance: " << incomeSum + expenseSum << endl;
    system("pause");

}

void BudgetManager::showPreviousMonthBalance()
{
    DateMethods dateMethods;
    //do osobnej funkcji w Utils
    sort(incomes.begin(), incomes.end(), [](const Operation& a, const Operation& b)
    {
        return a.date < b.date;
    });
    sort(expenses.begin(), expenses.end(), [](const Operation& a, const Operation& b)
    {
        return a.date < b.date;
    });

    //do osobnej funkcji, ktora zwraca sume + dodac optymalizacje bo wektor ktory dostaje jest przeciez posortowany

    double incomeSum = 0;
    double expenseSum = 0;

    for (int i = 0; i < incomes.size(); i++)
    {

        if (incomes[i].date >= dateMethods.getPreviousMonthFirstDayDate() && incomes[i].date <= dateMethods.getPreviousMonthLastDayDate())
        {
            //printuj i sumuj
            cout << "ID: " << incomes[i].id << ", UserID: " << incomes[i].userId
                 << ", Date: " << incomes[i].date << ", Item: " << incomes[i].item
                 << ", Amount: " << incomes[i].amount << endl;

            incomeSum += incomes[i].amount;
        }
    }

    for (int i = 0; i < expenses.size(); i++)
    {

        if (expenses[i].date > dateMethods.getPreviousMonthFirstDayDate() && expenses[i].date <= dateMethods.getPreviousMonthLastDayDate())
        {
            //printuj i sumuj
            cout << "ID: " << expenses[i].id << ", UserID: " << expenses[i].userId
                 << ", Date: " << expenses[i].date << ", Item: " << expenses[i].item
                 << ", Amount: " << expenses[i].amount << endl;

            incomeSum += expenses[i].amount;
        }
    }

    cout << "THE GENERAL BALANCE FOR PREVIOUS MONTH" << endl;
    cout << "----------------------------------" << endl;
    cout << "Incomes: " << incomeSum << endl;
    cout << "Expenses: " << expenseSum << endl;
    cout << "The general balance: " << incomeSum + expenseSum << endl;
    system("pause");
}
void BudgetManager::showCustomPeriodBalance()
{
        string sDate = "";
        int beginDate = 0;
        int endDate = 0;
        DateMethods methods;

        cout << "Give a beginning date in form YYYY-MM-DD: ";
        sDate = Utils::readLine();

        while(!methods.validateDate(sDate))
        {
            cout << "Incorrect date. Try again: " << endl;
            sDate = Utils::readLine();
        }

        sDate.erase(remove(sDate.begin(), sDate.end(), '-'), sDate.end());
        beginDate = stoi(sDate);

        cout << "Give an end date in form YYYY-MM-DD: ";
        sDate = Utils::readLine();

        while(!methods.validateDate(sDate))
        {
            cout << "Incorrect date. Try again: " << endl;
            sDate = Utils::readLine();
        }

        sDate.erase(remove(sDate.begin(), sDate.end(), '-'), sDate.end());
        endDate = stoi(sDate);

        if (endDate > beginDate)
    {
        cout << "The beginning date is later than end date. Correct your input and try again" << endl;
    }
    else
    {
        sort(incomes.begin(), incomes.end(), [](const Operation& a, const Operation& b)
        {
            return a.date < b.date;
        });
        sort(expenses.begin(), expenses.end(), [](const Operation& a, const Operation& b)
        {
            return a.date < b.date;
        });

        double incomeSum = 0;
        double expenseSum = 0;

        for (int i = 0; i < incomes.size(); i++)
        {

            if (incomes[i].date >= beginDate && incomes[i].date <= endDate)
            {
                //printuj i sumuj
                cout << "ID: " << incomes[i].id << ", UserID: " << incomes[i].userId
                     << ", Date: " << incomes[i].date << ", Item: " << incomes[i].item
                     << ", Amount: " << incomes[i].amount << endl;

                incomeSum += incomes[i].amount;
            }
        }

        for (int i = 0; i < expenses.size(); i++)
        {

            if (expenses[i].date >= beginDate && expenses[i].date <= endDate)
            {
                //printuj i sumuj
                cout << "ID: " << expenses[i].id << ", UserID: " << expenses[i].userId
                     << ", Date: " << expenses[i].date << ", Item: " << expenses[i].item
                     << ", Amount: " << expenses[i].amount << endl;

                incomeSum += expenses[i].amount;
            }
        }

        cout << "THE GENERAL BALANCE FOR " << beginDate << " - " << endDate << endl;
        cout << "----------------------------------" << endl;
        cout << "Incomes: " << incomeSum << endl;
        cout << "Expenses: " << expenseSum << endl;
        cout << "The general balance: " << incomeSum + expenseSum << endl;
        system("pause");
    }
}
