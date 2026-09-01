#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "DATA_STORAGE.h"
#include "MOVIE.h"
#include "USER.h"
datastorage datastruct;
int main()
{
	loadfromfile();
	while (true)
	{
		if (!mainmenu())
			break;
	}
	savetofile();

}