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
