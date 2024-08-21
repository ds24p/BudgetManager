#include "OperationFile.h"

bool OperationFile::addOperationToFile (const Operation &operation)
{
    CMarkup xml;
    string filename = "incomes.xml";

    if (!xml.Load(filename)) {
        cout << "File not found, creating new one: " << filename << endl;
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

    if (!xml.Save(filename)) {
        cout << "Error saving file: " << filename << endl;
        return false;
    }

    return true;
}

vector <Operation> OperationFile::loadOperationsFromFile(const int loggedUserId)
{
    vector <Operation> operations;
    CMarkup xml;
    string filename = "incomes.xml";

    if (!xml.Load(filename)) {
        cout << "Failed to load file: " << filename << endl;
        cout << "(Probably no registered operations so far)." << endl;
        return operations;
    }

    xml.FindElem();
    xml.IntoElem();


    while (xml.FindElem("operation")) {
        Operation operation;

        xml.IntoElem();

        xml.FindElem("id");
        operation.id = stoi(xml.GetData());

        xml.FindElem("userId");
        operation.userId = stoi(xml.GetData());

        xml.FindElem("date");
        operation.date = stoi(xml.GetData());

        xml.FindElem("item");
        operation.item = xml.GetData();

        xml.FindElem("amount");
        operation.amount = stod(xml.GetData());

        xml.OutOfElem();

        operations.push_back(operation);
    }

    return operations;
}
