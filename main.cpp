#include <iostream>

#include "BudgetMainApp.h"
#include "OperationFile.h"


using namespace std;

int main()
{
   BudgetMainApp mainApp("users.xml", "incomes.xml", "expenses.xml");

    char mainMenuChoice = '0';
    char usersMenuChoice = '0';

    while(true)
    {
        if(!mainApp.isUserLoggedIn())
        {
            Utils::displayMainMenu();
            mainMenuChoice = Utils::getCharacter();
            switch (mainMenuChoice)
            {
            case '1':
                mainApp.loginUser();
                break;
            case '2':
                mainApp.registerUser();
                break;
            case '3':
                cout << "Termination of the programme" << endl;
                exit(0);
                break;
            default:
                cout << "You have entered a character not supported by the programme menu. Please try again." << endl;
                system("pause");
                break;
            }
        }
        else
        {
            Utils::displayUserMenu();
            usersMenuChoice = Utils::getCharacter();

            switch (usersMenuChoice)
            {
            case '1':
                mainApp.addIncome();
                break;
            case '2':
                mainApp.addExpense();
                break;
            case '3':
                mainApp.showCurrentMonthBalance();
                break;
            case '4':
                mainApp.showPreviousMonthBalance();
                break;
            case '5':
                mainApp.showCustomPeriodBalance();
                break;
            case '6':
                mainApp.changeUserPassword();
                break;
            case '9':
                cout << "User will be loged out" << endl;
                mainApp.logoutUser();
                system("pause");
                break;
            default:
                cout << "You have entered a character not supported by the programme menu. Please try again." << endl;
                system("pause");
                break;
            }
        }

    }

    return 0;
}
