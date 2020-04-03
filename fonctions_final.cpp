#include "task.hpp"
#include "fonctions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void check_all_task(Task t)                 // affiche toutes les infos de la tâche t
{   string check_title(t.get_title());
    string check_priority(t.get_priority());
    int check_avancement(t.get_avancement());
    string check_description(t.get_description());
    int check_datedebut(t.get_datedebut());
    int check_datefin(t.get_datefin());
    vector <string> check_commentaires(t.get_commentaires());
    cout<<"Titre : "<<check_title<<endl;
    cout<<"Priorité : "<<check_priority<<endl;
    cout<<"Avancement : "<<check_avancement<<"%"<<endl;
    cout<<"Description : "<<check_description<<endl;
    cout<<"Date de début : "<<check_datedebut<<endl;
    cout<<"Date de fin : "<<check_datefin<<endl;
    cout<<"Commentaires : ";
    int it = 0;
    for (it = 0 ; it<check_commentaires.size() ; it++)
    {
        cout<<check_commentaires[it]<<" / ";
    }
    cout<< "\n" <<endl;
};

void check_id_task(Task t)              // affiche le titre et l'id de la tâche t
{   string check_title(t.get_title());
    int check_id(t.get_id());
    cout<<"Titre de la tâche : "<< check_title << " ; identifiant de la tâche : " << check_id <<endl;
};

void check_title_task(Task t)
{   string check_title(t.get_title());
    cout<<"Titre de la tâche : "<< check_title<<endl;
};

bool if_avancement(int avancement)      // vérifie les avancements
{   if (avancement<101 && avancement>=0) 
    { return true; }
    else
    {   cout<<"Ce n'est pas un avancement ; l'avancement doit être un chiffre entre 0 et 100."<<endl;
        return false;}
};

bool if_priority(string priority)       // vérifie les priorités
{   if (priority.compare("low")==0)
    { return true; }
    else if (priority.compare("medium")==0)
    { return true; }
    else if (priority.compare("high")==0)
    { return true; }
    else
    {   cout<<"Ce n'est pas une priorité ; une priorité doit être 'low', 'medium', ou 'high'. "<<endl;
        return false; }   
};

bool if_date(int date)                  // vérifie les dates
{   int year = date/10000 ;
    int month = (date - 10000*year)/100 ;
    int day = (date - 10000*year - 100*month) ;
    if (day>31 || day<1) 
    {   cout<<"Ce n'est pas une date. Une date doit être au format AAAAMMJJ."<<endl;
        return false; }
    else if (month>12 || month<1) 
     {   cout<<"Ce n'est pas une date. Une date doit être au format AAAAMMJJ."<<endl;
         return false; }
    else if (year>2050 || year<2015) 
     {   cout<<"Ce n'est pas une date. Une date doit être au format AAAAMMJJ."<<endl;
         return false; }
    else {return true; }
};