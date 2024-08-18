#include <iostream>

#include "BudgetMainApp.h"

using namespace std;

int main()
{
    BudgetMainApp mainApp;

    mainApp.registerUser();
    mainApp.loginUser();
    mainApp.changeUserPassword();
    mainApp.logoutUser();
    mainApp.loginUser();

    return 0;
}
