#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <vector>
#include <iostream>

#include "Operation.h"
#include "Markup.h"
#include "File.h"

using namespace std;

class OperationFile : public File
{

public:

    OperationFile (string fileName) : File(fileName){};
    vector <Operation>loadOperationsFromFile (const int loggedUserId);
    bool addOperationToFile (const Operation &operation);

};

#endif
