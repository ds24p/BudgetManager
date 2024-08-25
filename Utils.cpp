#include "Utils.h"



string Utils::readLine()
{
    string input;
    getline(cin, input);
    return input;
}

char Utils::getCharacter()
{
    string ciagZnakow = "";
    char inputChar = (0);

    while(true)
    {
        ciagZnakow = readLine();

        if (ciagZnakow.length() == 1)
        {
            inputChar = ciagZnakow[0];
            break;
        }
        cout << "This is not a single character, try again." << endl;
    }

    return inputChar;
}

bool Utils::isValidDouble(const string& str)
{
    if (str.empty()) return false;

    char* end = nullptr;
    strtod(str.c_str(), &end);

    return (*end == '\0');
}

void Utils::displayMainMenu()
{
    system("cls");
    cout << "BUDGET MANAGER - MAIN MENU" << endl;
    cout << "--------------------------" << endl;
    cout << "Choose the option: " << endl;
    cout << "   1. Login User" << endl;
    cout << "   2. Register new User" << endl;
    cout << "   3. Termination of the programme" << endl;
}

void Utils::displayUserMenu()
{
    system("cls");
    cout << "BUDGET MANAGER - USER MENU" << endl;
    cout << "--------------------------" << endl;
    cout << "Choose the option: " << endl;
    cout << "   1. Add income" << endl;
    cout << "   2. Add expense" << endl;
    cout << "   3. Show current month balance" << endl;
    cout << "   4. Show previous month balance" << endl;
    cout << "   5. Show custom period balance" << endl;
    cout << "   6. Change user password" << endl;
    cout << "   9. Log out" << endl;
}
