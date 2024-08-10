#include <iostream>

#include "UserManager.h"

using namespace std;

int main()
{
    UserManager manager;
    manager.setLoggedUserId(0);
    cout << manager.isUserLoggedIn() << endl;

    manager.registerUser();
    manager.loginUser();

    cout << manager.isUserLoggedIn() << endl;
    manager.changeUserPassword();

    manager.logoutUser();
    cout << manager.isUserLoggedIn() << endl;

    manager.loginUser();



    return 0;
}
