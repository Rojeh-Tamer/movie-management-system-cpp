#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MOVIE.h"
#include "DATA_STORAGE.h"
#include "USER.h"
using namespace std;
extern datastorage datastruct;
bool mainmenu()
{
    int number;
    cout << "Welcome to 7 up movie store!\n";
    cout << "1. Add a user\n";
    cout << "2. List users\n";
    cout << "3. Add a movie\n";
    cout << "4. List movies\n";
    cout << "5. Rent a movie\n";
    cout << "6. Return a movie\n";
    cout << "7. Show most rented movies\n";
    cout << "8. Show highest rated movies\n";
    cout << "9. list of late users\n";
    cout << "10. list of rented movies\n";
    cout << "11. Exit\n";
    cout << "Enter choice: ";
    cin >> number;
    switch (number)
    {
    case 1:
        userinput();
        return 1;
    case 2:
        showuserinformation();
        return 1;
    case 3:
        add_movies();
        return 1;
    case 4:
        list_of_movies();
        return 1;
    case 5:
        Rent_movie();
        return 1;
    case 6:
        Return_movie();
        return 1;
    case 7:
        MOST_RENTED_MOVIE();
        return 1;
    case 8:
        high_rates();
        return 1;
    case 9:
        show_late_users();
        return 1;
    case 10:
        all_rented_movie();
        return 1;
    case 11:
        cout << "Thank you for using our service!"<<endl;
        return 0;
    default:
        cout << "Invalid choice! Please choose a valid number\n";
        return 1;
    }

}