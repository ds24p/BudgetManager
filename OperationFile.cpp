#include "OperationFile.h"

bool OperationFile::addOperationToFile (const Operation &operation)
{
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        cout << "File not found, creating new one: " << getFileName() << endl;
        xml.AddElem("operations");
    }

    xml.FindElem("operations");
    xml.IntoElem();

    xml.AddElem("operation");
    xml.IntoElem();

    xml.AddElem("id", to_string(operation.id));
    xml.AddElem("userId", operation.userId);
    xml.AddElem("date", operation.date);
    xml.AddElem("item", operation.item);
    xml.AddElem("amount", operation.amount);

    xml.OutOfElem();

    setLastId(operation.id);

    if (!xml.Save(getFileName())) {
        cout << "Error saving file: " << getFileName() << endl;
        return false;
    }

    return true;
}

vector <Operation> OperationFile::loadOperationsFromFile(const int loggedUserId)
{
    vector <Operation> operations;
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        cout << "Failed to load file: " << getFileName() << endl;
        cout << "(Probably no registered operations so far)." << endl;
        return operations;
    }

    xml.FindElem();
    xml.IntoElem();

    int previousId = 0;

    while (xml.FindElem("operation")) {
        Operation operation;

        xml.IntoElem();

        xml.FindElem("id");
        operation.id = stoi(xml.GetData());
        previousId = operation.id;

        xml.FindElem("userId");
        operation.userId = stoi(xml.GetData());

        xml.FindElem("date");
        operation.date = stoi(xml.GetData());

        xml.FindElem("item");
        operation.item = xml.GetData();

        xml.FindElem("amount");
        operation.amount = stod(xml.GetData());

        xml.OutOfElem();

        if(operation.userId == loggedUserId)
        {
            operations.push_back(operation);
        }

        setLastId(previousId);
    }

    return operations;
}
