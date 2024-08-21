#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <vector>
#include <iostream>

#include "Operation.h"
#include "Markup.h"

using namespace std;

class OperationFile{

public:
// OperationFile (string fileName)
    vector <Operation>loadOperationsFromFile (const int loggedUserId);
    bool addOperationToFile (const Operation &operation);

};

#endif
