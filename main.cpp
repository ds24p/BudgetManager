#include <iostream>

#include "BudgetMainApp.h"
#include "OperationFile.h"


using namespace std;

int main()
{
    BudgetMainApp mainApp("users.xml", "incomes.xml", "expenses.xml");

    /*UserFile usFile("users.xml");
    vector <User> users = usFile.loadUsersFromFile();

    for (const auto& op : users) {

        cout << "ID: " << op.id << ", FirstName: " << op.firstName
                  << ", lastName: " << op.lastName << ", login: " << op.login
                  << ", password: " << op.password << endl;
    }


    OperationFile file("incomes.xml");
    //app.addIncome();

     vector <Operation> operations = file.loadOperationsFromFile(1);

     for (const auto& op : operations) {
        cout << "ID: " << op.id << ", UserID: " << op.userId
                  << ", Date: " << op.date << ", Item: " << op.item
                  << ", Amount: " << op.amount << endl;
    } */
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
