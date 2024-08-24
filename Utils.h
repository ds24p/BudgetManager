#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>

using namespace std;

class Utils{
public:
    static char getCharacter();
    static string readLine();
    static bool isValidDouble(const string& str);
    static void displayMainMenu();
    static void displayUserMenu();
};

#endif
