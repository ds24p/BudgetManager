#ifndef USERFILE_H
#define USERFILE_H

#include "Markup.h"
#include "User.h"
#include "File.h"
#include <vector>
#include <string>

using namespace std;

class UserFile : public File
{

public:
    UserFile (string userFileName) : File(userFileName){};
    vector <User> loadUsersFromFile();
    bool addUserToFile (const User &user);
    bool changePasswordInFile(int id, const string &password);
};



#endif
