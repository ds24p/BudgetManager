#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"


class UserManager{
    int loggedUserId;
    vector <User> users;
    //UserFile userFile;
    bool checkIfLoginExist(const string &login);
    User enterUserData();
//- findUserByLogin(const string &login, vector <User>::iterator &itr) : void
//- findUserById(vector <User>::iterator& itr) : void
public:
    //UserManager (string userFileName)
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedUserId();
    void setLoggedUserId(int id);
};

#endif
