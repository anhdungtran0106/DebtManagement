#ifndef _USER_
#define _USER_

#include <iostream>
#include <string>

using namespace std;

class User
{
    private:
        string name, phone_number;
    
    public:
        User()
        {
            name = phone_number = "";
        }
        User(string _name, string _phone_number)
        {
            name = _name;
            phone_number = _phone_number;
        }

        void insertInformation() {
            cout << "\tUsername: ";
            getline(cin, name);
            cout << "\tUser Phone Number: ";
            getline(cin, phone_number);
        }
        string getName()
        {
            return name;
        }
        string getPhoneNumber()
        {
            return phone_number;
        }
};

#endif