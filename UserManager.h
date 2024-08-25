#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UserFile.h"


class UserManager{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;
    bool checkIfLoginExist(const string &login);
    User enterUserData();

public:

    UserManager(string userFileName) : userFile(userFileName) {
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
        };
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedUserId();
    void setLoggedUserId(int id);
    void printAllUsers(vector <User> users);
};

#endif
