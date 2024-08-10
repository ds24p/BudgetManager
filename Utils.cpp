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
        cout << "To nie jest pojedynczy znak, sproboj ponownie." << endl;
    }

    return inputChar;
}
