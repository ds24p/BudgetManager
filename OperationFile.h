#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

class OperationFile{
// OperationFile (string fileName)
    vector <Operation>loadOperationsFromFile (const int loggedUserId);
    bool addOperationToFile (const Operation &operation);

};

#endif
