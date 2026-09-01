
#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "MOVIE.h"
#include "USER.h"
using namespace std;
struct datastorage
{
    movie movies[100];
    userinputs user[100];
};
    bool mainmenu();
    void savetofile();
    void loadfromfile();
extern datastorage datastruct;


#endif