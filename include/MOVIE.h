
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "USER.h"
using namespace std;

struct date
{
    int day = 0;
    int month = 0;
    int year = 0;

};
struct movie
{
    string name_movie = "0";
    int id = 0;
    bool is_rented = 0;
    float fees_per_day = 0;
    float over_fees_per_day = 0;
    vector<float> rating;
    float overall_rating = 0;
    date current_date;
    date due_date;
    int rented_days = 0;
    int customer_id = 0;
    int Movie_rental_count = 0;//NEW_B
    long long num_of_rating=0;
};
     int count_movies();
     void add_movies();
     void list_of_movies();
     void Rent_movie();
     void Return_movie();
     void MOST_RENTED_MOVIE();
     void average_rating(vector<float>& a);
     void high_rates();
     void take_rate(int val);
     void show_late_users();
     void all_rented_movie();

#endif

