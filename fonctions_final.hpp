#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include "task.hpp"
#include<iostream>
#include<string>
#include <vector>
using namespace std;

void check_all_task(Task t);
void check_id_task(Task t);
void check_title_task(Task t);

bool if_avancement(int avancement);
bool if_priority(string priority);
bool if_date(int date);


#endif //FONCTIONS_H_INCLUDED