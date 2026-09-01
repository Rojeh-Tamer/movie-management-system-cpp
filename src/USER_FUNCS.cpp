#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "USER.h"
#include "DATA_STORAGE.h"
using namespace std;
extern datastorage datastruct;
void userinput()
{
    int usercount = countusers();
    cout << "Enter your id (8 digits) :" << endl;
    int id2;
    cin >> id2;
    cout << "Enter your name :" << endl;
    cin.ignore();
    getline(cin, datastruct.user[usercount].username);
    int* ptr = &usercount;
    for (int i = 0;i < *ptr;i++)
    {
        if (id2 == datastruct.user[i].userid)
        {
            cout << "there is a user with the same id" << endl;
            cout << "please try agin" << endl;
            return;
        }
    }
    datastruct.user[usercount].userid = id2;
    //turns the ID from int to a string and stores it in x
    string x = to_string(datastruct.user[usercount].userid);

    while (x.size() != 8)
    {
        cout << "invalid id " << "Rewrite the id again (must be 8 digits) : " << endl;
        cin >> datastruct.user[usercount].userid;
        x = to_string(datastruct.user[usercount].userid);
    }
    cout << "saved succesfully." << endl;
}

int countusers()
{
    for (int i = 0; i < 100; i++)
    {
        if (datastruct.user[i].userid == 0)
            return i;
    }
    return -1;
}

void showuserinformation()
{

    for (int i = 0; i < 100; i++)
    {
        if (datastruct.user[0].userid == 0)
        {
            cout << "The list is empty please enter a user." << endl;
            mainmenu();
            break;
        }
        if (datastruct.user[i].userid == 0)
            break;
        cout << "----user list----" << endl;
        cout << i + 1 << "-" << datastruct.user[i].username << " -- " << "  id is :" << datastruct.user[i].userid << endl;
    }
    cout << "-----------------" << endl;
}

