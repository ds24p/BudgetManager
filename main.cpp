#include <iostream>

#include "BudgetMainApp.h"
#include "OperationFile.h"


using namespace std;

int main()
{
    BudgetMainApp mainApp;

    Operation brandNew;
    brandNew.amount = 12.90;
    brandNew.date = 12092022;
    brandNew.id = 5;
    brandNew.item = "sth";
    brandNew.userId = 1;

    OperationFile operation;
    bool good = operation.addOperationToFile(brandNew);

    vector <Operation> operationen = operation.loadOperationsFromFile(9);


   // mainApp.loginUser();

    //BudgetManager manager;
    //manager.addIncome();
    //manager.addExpense();

   // mainApp.logoutUser();

    return 0;
}
