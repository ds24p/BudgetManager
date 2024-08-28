#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>

using namespace std;

class File{

    const string FILE_NAME;

public:
    File (string fileName) : FILE_NAME(fileName){
        lastId = 0; };

    int lastId;
    string getFileName();
    int getLastId();
    void setLastId(int id);

};

#endif
