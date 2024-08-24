#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>

using namespace std;

class File{

    const string FILE_NAME;
    int lastId;

public:
    File (string fileName) : FILE_NAME(fileName){};

    string getFileName();
    int getLastId();
    void setLastId(int id);

};

#endif
