#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Operation income;
    cout << "Adding a new income..." << endl;

    income = addOperationDetails(INCOME);
    incomeFile.addOperationToFile(income);

    incomes.push_back(income);

    cout << "Income added..." << endl;
    system("pause");
}

Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation operation;
    DateMethods methods;

    if(type == INCOME)
    {
        operation.id = incomeFile.lastId + 1;
    }
    else if(type == EXPENSE)
    {
        operation.id = expenseFile.lastId + 1;
    }

    operation.userId = LOGGED_USER_ID;
    string sDate;
    cout << "Add the operation with current date? y/n" << endl;
    char choice = Utils::getCharacter();
    while(!(choice == 'y' || choice == 'n'))
    {
        cout << "Wrong input. Only input 'y' or 'n' is allowed." << endl;
        choice = Utils::getCharacter();
    }
    if (choice == 'y')
    {
        operation.date = methods.getCurrentDate();
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
        operation.date = methods.convertStringDateToInt(sDate);
    }

    cout << "Add the description of operation: ";
    operation.item = Utils::readLine();

    cout << "Add the amount: ";
    string inputAmount = Utils::readLine();
    while(!Utils::isValidDouble(inputAmount))
    {
        cout << "Wrong input. Give the correct number." << endl;
        inputAmount = Utils::readLine();
    }

    operation.amount = stod(inputAmount);

    return operation;

}

void BudgetManager::addExpense()
{
    Operation expense;
    cout << "Adding a new expense..." << endl;

    expense = addOperationDetails(EXPENSE);
    expenseFile.addOperationToFile(expense);
    expenses.push_back(expense);

    cout << "Expense added..." << endl;
    system("pause");
}

double BudgetManager::printAndSumOperations(vector <Operation> &operations, int beginningOfPeriod, int endOfPeriod)
{
    double sum = 0;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i].date < beginningOfPeriod)
        {
            break;
        }
        if (operations[i].date >= beginningOfPeriod && operations[i].date <= endOfPeriod)
        {
            cout << "ID: " << operations[i].id << " UserID: " << operations[i].userId
                 << " Date: " << DateMethods::convertIntDateToStringWithDashes(operations[i].date) << " Item: " << operations[i].item
                 << " Amount: " << operations[i].amount << endl;

            sum += operations[i].amount;
        }
    }
    return sum;
}

void BudgetManager::showCurrentMonthBalance()
{
    DateMethods dateMethods;
    int beginningOfPeriod = dateMethods.getCurrentMonthFirstDayDate();
    int endOfPeriod = dateMethods.getCurrentMonthLastDayDate();

    cout << "INCOMES" << endl;
    cout << "-------" << endl;
    double incomeSum = printAndSumOperations(incomes, beginningOfPeriod, endOfPeriod);
    incomes = dateMethods.sortVectorByDate(incomes);

    cout << endl;
    cout << "EXPENSES" << endl;
    cout << "--------" << endl;
    double expenseSum = printAndSumOperations(expenses, beginningOfPeriod, endOfPeriod);
    expenses = dateMethods.sortVectorByDate(expenses);

    cout << endl;
    cout << "THE GENERAL BALANCE FOR THIS MONTH" << endl;
    cout << "----------------------------------" << endl;
    cout << "Incomes: " << incomeSum << endl;
    cout << "Expenses: " << expenseSum << endl;
    cout << "The general balance: " << incomeSum - expenseSum << endl;
    system("pause");

}

void BudgetManager::showPreviousMonthBalance()
{
    DateMethods dateMethods;
    int beginningOfPeriod = dateMethods.getPreviousMonthFirstDayDate();
    int endOfPeriod = dateMethods.getPreviousMonthLastDayDate();

    cout << "INCOMES" << endl;
    cout << "-------" << endl;
    double incomeSum = printAndSumOperations(incomes, beginningOfPeriod, endOfPeriod);
    incomes = dateMethods.sortVectorByDate(incomes);

    cout << endl;
    cout << "EXPENSES" << endl;
    cout << "--------" << endl;
    double expenseSum = printAndSumOperations(expenses, beginningOfPeriod, endOfPeriod);
    expenses = dateMethods.sortVectorByDate(expenses);

    cout << endl;
    cout << "THE GENERAL BALANCE FOR PREVIOUS MONTH" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Incomes: " << incomeSum << endl;
    cout << "Expenses: " << expenseSum << endl;
    cout << "The general balance: " << incomeSum - expenseSum << endl;
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
    beginDate = methods.convertStringDateToInt(sDate);

    cout << "Give an end date in form YYYY-MM-DD: ";
    sDate = Utils::readLine();

    while(!methods.validateDate(sDate))
    {
        cout << "Incorrect date. Try again: " << endl;
        sDate = Utils::readLine();
    }

    endDate = methods.convertStringDateToInt(sDate);
    if (endDate < beginDate)
    {
        cout << "The beginning date is later than end date. Correct your input and try again" << endl;
        system("pause");
    }
    else
    {
        incomes = methods.sortVectorByDate(incomes);
        expenses = methods.sortVectorByDate(expenses);

        cout << endl;
        cout << "INCOMES" << endl;
        cout << "-------" << endl;
        double incomeSum = printAndSumOperations(incomes, beginDate, endDate);
        incomes = methods.sortVectorByDate(incomes);

        cout << endl;
        cout << "EXPENSES" << endl;
        cout << "--------" << endl;
        double expenseSum = printAndSumOperations(expenses, beginDate, endDate);
        expenses = methods.sortVectorByDate(expenses);

        cout << endl;
        cout << "THE GENERAL BALANCE FOR " << methods.convertIntDateToStringWithDashes(beginDate) << " - " << methods.convertIntDateToStringWithDashes(endDate) << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Incomes: " << incomeSum << endl;
        cout << "Expenses: " << expenseSum << endl;
        cout << "The general balance: " << incomeSum - expenseSum << endl;
        system("pause");
    }
}
