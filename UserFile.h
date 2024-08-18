#ifndef USERFILE_H
#define USERFILE_H

#include "Markup.h"
#include "User.h"
#include <vector>
//#include <iostream>
#include <string>

using namespace std;

class UserFile{

public:
    //UserFile (string userFileName);
    vector <User> loadUsersFromFile();
    bool addUserToFile (const User &user);
    bool changePasswordInFile(int id, const string &password);
};



#endif
