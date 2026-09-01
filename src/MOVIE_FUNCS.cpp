#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MOVIE.h"
#include "USER.h"
#include "DATA_STORAGE.h"
using namespace std;
extern datastorage datastruct;
int count_movies()
{
	// function for counting movies every time you launch
	for (int i = 0; i < 100; i++)
	{
		if (datastruct.movies[i].id == 0)
			return i;
	}
	return -1;
} //grammar checked

void add_movies()
{
	int count_of_movies = count_movies();
	cout << "Enter movie id (8 digits) : ";
	int id1;
	cin >> id1;

	for (int i = 0;i < count_of_movies;i++)
	{
		if (id1 == datastruct.movies[i].id)
		{
			cout << "there is a movie with the same id" << endl;
			cout << "please try again" << endl;
			return;
		}
	}

	datastruct.movies[count_of_movies].id = id1;
	string x = to_string(id1);

	while (x.size() != 8)
	{
		cout << "invalid id " << "Rewrite the id again (must be 8 digits) : " << endl;
		cin >> datastruct.movies[count_of_movies].id;
		x = to_string(datastruct.movies[count_of_movies].id);
	}
	cout << "Enter movie name: ";
	cin.ignore();
	getline(cin, datastruct.movies[count_of_movies].name_movie);

	cout << "Enter rental fee per day: ";
	cin >> datastruct.movies[count_of_movies].fees_per_day;

	cout << "Enter overdue fee per day: ";
	cin >> datastruct.movies[count_of_movies].over_fees_per_day;
	cout << "Movie added successfully. " << endl;
} //grammar checked

void list_of_movies()
{
	//function that loops over all movie array indexes and displays them
	int movieCount = count_movies();
	if (movieCount == 0)
	{
		cout << "there are no movies available at the moment\n"<<"please enter a movie"<<endl;
		return;
	}
	for (int i = 0; i < movieCount; i++)
	{
		cout << "\nMovie number " << i + 1 << ":\n";
		cout << "The Movie ID: " << datastruct.movies[i].id << " | " << "Name of the Movie: " << datastruct.movies[i].name_movie << " | ";

		if (datastruct.movies[i].is_rented)
		{
			cout << "(Not Available)\n";
		}

		else
		{
			cout << "(Available)\n";
		}
	}
}

void Rent_movie()
{
	cout << "            RENT MOVIE            " << endl;
	cout << "=====================================" << endl;
	int val = -1;
	int ID_user;
	cout << "Please enter your user's ID: ";
	cin >> ID_user;
	string y = to_string(ID_user);
	while (y.size()!=8)
	{
		cout << "This user's ID is incorrect!! Please enter a valid ID (8 digits)" << endl;
		cin >> ID_user;
		y = to_string(ID_user);
	}
	int NUMBER_OF_USER = countusers();
	for (int i = 0;i < NUMBER_OF_USER;i++)//NEW_B
	{
		if (ID_user == datastruct.user[i].userid)
		{
			val = i;
			break;
		}
	}
	if (val == -1)
	{
		cout << "            This ID does not exist          " << endl;
		return;
	}
	val = -1;
	long long ID_movie;
	cout << "Please enter your movie's ID: ";
	cin >> ID_movie;
	string j = to_string(ID_movie);
	while (j.size()!=8)
	{
		cout << "This movie's ID is incorrect!! Please enter a valid ID (8 digits)" << endl;
		cin >> ID_movie;
		j = to_string(ID_movie);
	}
	int NUMBER_OF_MOVIES = count_movies();
	for (int i = 0;i < NUMBER_OF_MOVIES;i++)
	{
		if (ID_movie == datastruct.movies[i].id)
		{
			val = i;
			break;
		}
	}
	if (val == -1)
	{
		cout << "            This ID is Invalid            " << endl;
		return;
	}

	else if (datastruct.movies[val].is_rented && val != -1)
	{
		cout << "            movie already rented by another customer            " << endl;
	}

	else   if (val != -1)
	{
		cout << " ----------This movie is available to rent---------- " << endl;
		cout << "rental fee per day                       : " << datastruct.movies[val].fees_per_day << endl;
		cout << "overdue fee per day                      : " << datastruct.movies[val].over_fees_per_day << endl;
		cout << "Enter current date" << endl;
		cout << "enter day :";
		cin >> datastruct.movies[val].due_date.day;
		cout << "enter month :";
		cin >> datastruct.movies[val].due_date.month;
		cout << "enter year :";
		cin >> datastruct.movies[val].due_date.year;
		cout << "Enter the number of days you will rent the movie" << endl;
		cin >> datastruct.movies[val].rented_days;
		datastruct.movies[val].is_rented = true;
		datastruct.movies[val].customer_id = ID_user;
		cout << "            Movie rented successfully            " << endl;
		datastruct.movies[val].Movie_rental_count++;//NEW_B
	}
}
//NEW_B_RETURN_MOVIE
void take_rate(int val)
{
	cout << "would you like to rate our movie(y for yes,n for no)" << endl;
	string agreement;
	cin >> agreement;
	if (agreement == "y" || agreement == "Y")
	{
		cout << "enter rating from 1 to 5 (decimals allowed)" << endl;
		float rate;
		cin >> rate;
		datastruct.movies[val].rating.push_back(rate);
		if (rate < 1 || rate > 5)
		{
			cout << "rating is out of bounds (must be from 1 to 5)" << endl;
			take_rate(val);
		}
		cout << "Thank you for visiting our store" << endl;
	}
	else if (agreement != "n" && agreement != "N")
	{
		cout << "wrong input (must be y or n)" << endl;
		take_rate(val);
	}
	else
	{
		cout << "Thank you for visiting our store" << endl;
	}
}

void Return_movie()
{
	cout << "Enter your user ID :" << endl;
	long long USER_ID;
	cin >> USER_ID;
	int val = -1;
	int NUMBER_OF_USER = countusers();
	for (int i = 0;i < NUMBER_OF_USER;i++)//NEW_B
	{
		if (USER_ID == datastruct.user[i].userid)
		{
			val = i;
			break;
		}
	}
	if (val == -1)
	{
		cout << " ----------There is no user with this ID---------- " << endl;
		return;
	}
	val = -1;
	cout << "Enter movie ID :" << endl;
	long long MOVIE_ID;
	cin >> MOVIE_ID;
	int NUMBER_OF_MOVIES = count_movies();
	for (int i = 0;i < NUMBER_OF_MOVIES;i++)
	{
		if (MOVIE_ID == datastruct.movies[i].id)
		{
			val = i;
			break;
		}
	}
	if (val == -1)
	{
		cout << "            There is no movie with this ID            " << endl;
		return;
	}
	if (datastruct.movies[val].customer_id != USER_ID)
	{
		cout << "You didn't rent this movie" << endl;
	}
	else
	{
		cout << "Enter current date" << endl;
		date return_date;
		cout << "enter day :";
		cin >> return_date.day;
		cout << "enter month :";
		cin >> return_date.month;
		cout << "enter year :";
		cin >> return_date.year;

		float fees = 0;
		fees += datastruct.movies[val].fees_per_day * datastruct.movies[val].rented_days;
		int OVER_DAYS = (return_date.year - datastruct.movies[val].due_date.year) * 365 + (return_date.month - datastruct.movies[val].due_date.month) * 30 + (return_date.day - datastruct.movies[val].due_date.day) - datastruct.movies[val].rented_days;
		fees += float(OVER_DAYS * datastruct.movies[val].over_fees_per_day);
		if (OVER_DAYS > 0)
		{
			cout << "you are late by " << OVER_DAYS << " days" << endl;
			cout << "your bill is " << fees << " EGP" << endl;
		}
		else if (OVER_DAYS < 0)
		{
			if (OVER_DAYS + datastruct.movies[val].rented_days <= 0)
			{
				cout << "input date is invalid" << endl;
				return;
			}
			else
			{
				cout << "you are early by " << OVER_DAYS*( - 1) << " day(s)" << endl;
				fees = float(OVER_DAYS + datastruct.movies[val].rented_days * datastruct.movies[val].fees_per_day);
				cout << "your bill is " << fees << " EGP" << endl;
			}
		}
		else
		{
			cout << "you are on time" << endl;
			cout << "your bill is " << fees << " EGP" << endl;
		}
		datastruct.movies[val].is_rented = false;
		datastruct.movies[val].customer_id = 0;
		take_rate(val);
	}
}
//NEW_B_MOST_RENTED_MOVE
void MOST_RENTED_MOVIE()
{
	int most_rented_1 = 0, most_rented_2 = -1, most_rented_3 = -1, most_rented_4 = -1, most_rented_5 = -1;
	int movie_count = count_movies();
	if (movie_count == 0)
	{
		cout << "there are no available movies" << endl;
		return;
	}
	for (int i = 1;i < movie_count;i++)
	{
		if (datastruct.movies[i].Movie_rental_count > datastruct.movies[most_rented_1].Movie_rental_count)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = most_rented_3;
			most_rented_3 = most_rented_2;
			most_rented_2 = most_rented_1;
			most_rented_1 = i;
		}
		else if (most_rented_2 == -1 || datastruct.movies[i].Movie_rental_count > datastruct.movies[most_rented_2].Movie_rental_count)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = most_rented_3;
			most_rented_3 = most_rented_2;
			most_rented_2 = i;
		}
		else if (most_rented_3 == -1 || datastruct.movies[i].Movie_rental_count > datastruct.movies[most_rented_3].Movie_rental_count)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = most_rented_3;
			most_rented_3 = i;
		}
		else if (most_rented_4 == -1 || datastruct.movies[i].Movie_rental_count > datastruct.movies[most_rented_4].Movie_rental_count)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = i;
		}
		else if (most_rented_5 == -1 || datastruct.movies[i].Movie_rental_count > datastruct.movies[most_rented_5].Movie_rental_count)
		{
			most_rented_5 = i;
		}
	}
	bool u = 0;
	if (movie_count == 1)
	{
		u = 1;
	}
	cout << "/***************MOST RENTED MOVIES IN OUR SHOP***************\\" << endl;
	cout << "1-" << datastruct.movies[most_rented_1].name_movie << endl;
	cout << "ID : " << datastruct.movies[most_rented_1].id << endl;
	cout << "number of times rented : " << datastruct.movies[most_rented_1].Movie_rental_count << endl;
	cout << "*************************************************************" << endl;
	if (u||most_rented_2 == most_rented_1 || most_rented_2==-1)
	{
		cout << "there are no more rented movies" << endl;
		u = 1;
	}
	else
	{
		cout << "2-" << datastruct.movies[most_rented_2].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_2].id << endl;
		cout << "number of times rented: " << datastruct.movies[most_rented_2].Movie_rental_count << endl;
	}
	cout << "*************************************************************" << endl;
	if (u||most_rented_3 == most_rented_1|| most_rented_2 == most_rented_3 || most_rented_3 == -1)
	{
		cout << "there are no more rented movies" << endl;
		u = 1;
	}
	else
	{
		cout << "3-" << datastruct.movies[most_rented_3].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_3].id << endl;
		cout << "number of times rented : " << datastruct.movies[most_rented_3].Movie_rental_count << endl;
	}
	cout << "*************************************************************" << endl;
	if (u||most_rented_4 == most_rented_1 || most_rented_4 == most_rented_3|| most_rented_4 == most_rented_2 || most_rented_4 == -1)
	{
		cout << "there are no more rented movies" << endl;
		u = 1;
	}
	else
	{
		cout << "4-" << datastruct.movies[most_rented_4].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_4].id << endl;
		cout << "number of times rented : " << datastruct.movies[most_rented_4].Movie_rental_count << endl;
	}
	cout << "*************************************************************" << endl;
	if (u||most_rented_5 == most_rented_4 || most_rented_5 == most_rented_3 || most_rented_5 == most_rented_2 || most_rented_5 == most_rented_1 || most_rented_5 == -1)
	{
		cout << "there are no more rented movies" << endl;
		u == 1;
	}
	else
	{
		cout << "5-" << datastruct.movies[most_rented_5].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_5].id << endl;
		cout << "number of times rented : " << datastruct.movies[most_rented_5].Movie_rental_count << endl;
	}
	cout << "*************************************************************" << endl;
}

void average_rating()
{
	for (int i = 0; i < count_movies(); i++)
	{
		float sum = 0;
		for (int j = 0; j < datastruct.movies[i].rating.size(); j++)
		{
			sum += datastruct.movies[i].rating[j];
		}
		datastruct.movies[i].overall_rating = sum / datastruct.movies[i].rating.size();
	}
}

void high_rates()
{
	average_rating();
	int most_rented_1 = 0, most_rented_2 = -1, most_rented_3 = -1, most_rented_4 = -1, most_rented_5 = -1;
	int movie_count = count_movies();
	if (movie_count == 0)
	{
		cout << "there are no available movie" << endl;
		return;
	}
	for (int i = 1;i < movie_count;i++)
	{
		if (datastruct.movies[i].overall_rating > datastruct.movies[most_rented_1].overall_rating)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = most_rented_3;
			most_rented_3 = most_rented_2;
			most_rented_2 = most_rented_1;
			most_rented_1 = i;
		}
		else if (most_rented_2 == -1 || datastruct.movies[i].overall_rating > datastruct.movies[most_rented_2].overall_rating)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = most_rented_3;
			most_rented_3 = most_rented_2;
			most_rented_2 = i;
		}
		else if (most_rented_3 == -1 || datastruct.movies[i].overall_rating > datastruct.movies[most_rented_3].overall_rating)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = most_rented_3;
			most_rented_3 = i;
		}
		else if (most_rented_4 == -1 || datastruct.movies[i].overall_rating > datastruct.movies[most_rented_4].overall_rating)
		{
			most_rented_5 = most_rented_4;
			most_rented_4 = i;
		}
		else if (most_rented_5 == -1 || datastruct.movies[i].overall_rating > datastruct.movies[most_rented_5].overall_rating)
		{
			most_rented_5 = i;
		}
	}
	bool u = 0;
	if (movie_count == 1)
	{
		u = 1;
	}
	cout << "/***************MOST RRNTED MOVIE IN OUR SHOP***************\\" << endl;
	cout << "1-" << datastruct.movies[most_rented_1].name_movie << endl;
	cout << "ID : " << datastruct.movies[most_rented_1].id << endl;
	cout << "rating : " << datastruct.movies[most_rented_1].overall_rating << endl;
	cout << "*************************************************************" << endl;
	if (u || most_rented_2 == most_rented_1 || most_rented_2 == -1)
	{
		cout << "there are no more rated movies " << endl;
		u = 1;
	}
	else
	{
		cout << "2-" << datastruct.movies[most_rented_2].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_2].id << endl;
		cout << "rating : " << datastruct.movies[most_rented_2].overall_rating << endl;
	}
	cout << "*************************************************************" << endl;
	if (u || most_rented_3 == most_rented_1 || most_rented_2 == most_rented_3 || most_rented_3 == -1)
	{
		cout << "there are no more rated movies " << endl;
		u = 1;
	}
	else
	{
		cout << "3-" << datastruct.movies[most_rented_3].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_3].id << endl;
		cout << "rating : " << datastruct.movies[most_rented_3].overall_rating << endl;
	}
	cout << "*************************************************************" << endl;
	if (u || most_rented_4 == most_rented_1 || most_rented_4 == most_rented_3 || most_rented_4 == most_rented_2 || most_rented_4 == -1)
	{
		cout << "there are no more rated movies" << endl;
		u = 1;
	}
	else
	{
		cout << "4-" << datastruct.movies[most_rented_4].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_4].id << endl;
		cout << "rating : " << datastruct.movies[most_rented_4].overall_rating << endl;
	}
	cout << "*************************************************************" << endl;
	if (u || most_rented_5 == most_rented_4 || most_rented_5 == most_rented_3 || most_rented_5 == most_rented_2 || most_rented_5 == most_rented_1 || most_rented_5 == -1)
	{
		cout << "there are no more rated movies" << endl;
	}
	else
	{
		cout << "5-" << datastruct.movies[most_rented_5].name_movie << endl;
		cout << "ID : " << datastruct.movies[most_rented_5].id << endl;
		cout << "rating : " << datastruct.movies[most_rented_5].overall_rating << endl;
	}
	cout << "*************************************************************" << endl;
}

void show_late_users()
{

	cout << "/************ENTER CURRENT DATE***************\\" << endl;
	date today;
	cout << "DAY   : "; cin >> today.day;
	cout << "month : "; cin >> today.month;
	cout << "year  : "; cin >> today.year;

	int number_of_movies = count_movies();
	int number_of_users = countusers();
	bool header_printed = false;
	bool found = false;

	for (int i = 0; i < number_of_movies; i++)
	{
		if (datastruct.movies[i].is_rented)
		{
			date due = datastruct.movies[i].due_date;
			int over_days = (today.year - due.year) * 360 +
				(today.month - due.month) * 30 +
				(today.day - due.day) - datastruct.movies[i].rented_days;

			if (over_days > 0)
			{
				int custmer_id = datastruct.movies[i].customer_id;

				if (!header_printed)
				{
					cout << "***************USERS WITH LATE RETURNS***************" << endl;
					header_printed = true;
				}

				for (int j = 0; j < number_of_users; j++)
				{
					if (datastruct.user[j].userid == custmer_id)
					{
						cout << "User Name: " << datastruct.user[j].username
							<< " | User ID: " << datastruct.user[j].userid << endl;
						cout << "Movie Name: " << datastruct.movies[i].name_movie
							<< " | Movie ID: " << datastruct.movies[i].id << endl;
						cout << "-------------------------------------------------" << endl;
						found = true;
						break;
					}
				}
			}
		}
	}

	if (!found)
	{
		cout << "There are no users with late returns" << endl;
	}
}

void all_rented_movie()
{



	int movie_count = count_movies();
	int user_count = countusers();
	bool found = false;

	cout << "********** List of All Rented Movies **********" << endl;
	for (int i = 0; i < movie_count; i++)
	{
		if (datastruct.movies[i].is_rented)
		{
			found = true;
			cout << "Movie Name: " << datastruct.movies[i].name_movie << endl;
			cout << "Movie ID: " << datastruct.movies[i].id << endl;
			cout << "Rented By User ID: " << datastruct.movies[i].customer_id << endl;


			for (int j = 0; j < user_count; j++)
			{
				if (datastruct.user[j].userid == datastruct.movies[i].customer_id)
				{
					cout << "Rented By User Name: " << datastruct.user[j].username << endl;
					break;
				}
			}

			cout << "Due Date: " << datastruct.movies[i].due_date.day << "/"
				<< datastruct.movies[i].due_date.month << "/"
				<< datastruct.movies[i].due_date.year << endl;

			cout << "-----------------------------------------------" << endl;
		}
	}

	if (!found)
	{
		cout << "There are no rented movies at the moment." << endl;
		cout << "***********************************************" << endl;
	}
}
