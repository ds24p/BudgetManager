#include "UserManager.h"
#include "Utils.h"

User UserManager::enterUserData()
{
    User newUser;
    newUser.id = Utils::getCharacter();
    //newUser.id = determine usersId
    newUser.firstName = Utils::readLine();
    newUser.lastName = Utils::readLine();
    string login;
    do
    {
        cout << "Create unique User Login: " << endl;
        login = Utils::readLine();
    } while(checkIfLoginExist(login));
    newUser.login = login;
    newUser.password = Utils::readLine();
    return newUser;
}

void UserManager::registerUser(){

    User newUser = enterUserData();
    //newUser.id = determine usersId

    users.push_back(newUser);
    //zapisz uzytkownika do pliku uzytkownicy xml

    cout << "User successfully registered." << endl;
;}

void UserManager::loginUser()
{
    cout << "Enter login: " << endl;
        string login = Utils::readLine();
        if(checkIfLoginExist(login))
        {
            for (int i = 0; i < users.size(); i++) {
                if (users[i].login == login) {
                        cout << "Enter password" << endl;
                        string password = Utils::readLine();
                        if(users[i].password == password)
                        {
                            loggedUserId = users[i].id;
                            cout << "User logged in" << endl;
                        }
                        else{
                            cout << "Wrong password" << endl;
                        }

                }
        }
        }
        else{
            cout << "User with this login doesn't exist. Register user." << endl;
        }
}

void UserManager::changeUserPassword(){

    cout << "Enter new password: " << endl;
    string password = Utils::readLine();

    for (int i = 0; i < users.size(); i++) {
            if (users[i].id == loggedUserId)
            {
                users[i].password = password;
            }
    }

    cout << "Password successfully changed" << endl;



    //aktualizacja pliku xml
}

void UserManager::logoutUser()
{
        loggedUserId = 0;
        cout << "User logged out." << endl;
}

bool UserManager::isUserLoggedIn()
{
    if(loggedUserId != 0)
        return true;
    return false;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

void UserManager::setLoggedUserId(int id)
{
    loggedUserId = id;
}

bool UserManager::checkIfLoginExist(const string &login)
{
    for (const auto& user : users) {
        if (user.login == login) {
            return true;
        }
    }
    return false;
}
