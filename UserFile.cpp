#include "UserFile.h"

vector <User> UserFile::loadUsersFromFile()
{
    vector <User> users;
    CMarkup xml;
    string filename = "users.xml";

    if (!xml.Load(filename)) {
        cout << "Failed to load file: " << filename << endl;
        cout << "(You are probably the first user of this program)." << endl;
        return users;
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("user")) {
        User user;

        xml.IntoElem();

        xml.FindElem("id");
        user.id = stoi(xml.GetData());

        xml.FindElem("firstName");
        user.firstName = xml.GetData();

        xml.FindElem("lastName");
        user.lastName = xml.GetData();

        xml.FindElem("login");
        user.login = xml.GetData();

        xml.FindElem("password");
        user.password = xml.GetData();

        xml.OutOfElem();

        users.push_back(user);
    }

    return users;
}

bool UserFile::addUserToFile(const User &user)
{
    CMarkup xml;
    string filename = "users.xml";

    if (!xml.Load(filename)) {
        cout << "File not found, creating new one: " << filename << endl;
        xml.AddElem("users");
    }

    xml.FindElem("users");
    xml.IntoElem();

    xml.AddElem("user");
    xml.IntoElem();

    xml.AddElem("id", to_string(user.id));
    xml.AddElem("firstName", user.firstName);
    xml.AddElem("lastName", user.lastName);
    xml.AddElem("login", user.login);
    xml.AddElem("password", user.password);

    xml.OutOfElem();

    if (!xml.Save(filename)) {
        cout << "Error saving file: " << filename << endl;
        return false;
    }

    return true;
}

bool UserFile::changePasswordInFile(int id, const string &password)
{
     CMarkup xml;
     string filename = "users.xml";

    if (!xml.Load(filename)) {
        cout << "Failed to load file: " << filename << endl;
        return false;
    }

    if (!xml.FindElem("users")) {
        cout << "Invalid XML structure: Missing <users> root element." << endl;
        return false;
    }

    xml.IntoElem();

    while (xml.FindElem("user")) {
        xml.IntoElem();

        xml.FindElem("id");
        int currentId = stoi(xml.GetData());

        if (currentId == id) {
            if (xml.FindElem("password")) {
                xml.SetData(password);
                xml.OutOfElem();

                if (!xml.Save(filename)) {
                    cout << "Error saving file: " << filename << endl;
                    return false;
                }

                return true;
            }
        }

        xml.OutOfElem();
    }

    cout << "User with ID " << id << " not found." << endl;
    return false;
}
