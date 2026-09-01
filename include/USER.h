#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "MOVIE.h"
using namespace std;

struct userinputs
{
	int userid = 0;
	string username = "0";
};
	void userinput();
	void showuserinformation();
	int countusers();

#endif