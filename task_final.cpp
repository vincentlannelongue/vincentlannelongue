#include "task.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// Constructeurs
    Task::Task() : id(0) {} 

    Task::Task(int new_id, int new_av, string new_title, string new_pr, string new_descr) : id(new_id), avancement(new_av), title(new_title), priority(new_pr), description(new_descr) 
    { } 
// Intéraction avec les fichiers
    void Task::from_save(string nomSave)     
    {   nomFichier = nomSave;
        ifstream flux_entrant(nomFichier.c_str());       //Lecture du fichier
        if (flux_entrant)
        {
            flux_entrant.seekg(0, ios::beg);
            flux_entrant>>id;
            flux_entrant>>avancement;
            flux_entrant>>datedebut;
            flux_entrant>>datefin;
            flux_entrant.ignore();
            getline(flux_entrant, description);
            getline(flux_entrant, title);
            getline(flux_entrant, priority); 
            string comm;
            while (getline(flux_entrant, comm))
            {   commentaires.push_back(comm); }
        }
        else
        {cout<<"ERREUR : le fichier ne s'ouvre pas pour from_save"<<endl;}
    }

    void Task::save(string nomSave)         
    {
        nomFichier = nomSave;
        ofstream flux_sortant(nomFichier.c_str());       //Ouverture du fichier pour modifications
        if (flux_sortant)
        {
            flux_sortant.seekp(0, ios::beg);
            flux_sortant<<id<<endl;
            flux_sortant<<avancement<<endl;
            flux_sortant<<datedebut<<endl;
            flux_sortant<<datefin<<endl;
            flux_sortant<<description<<endl;
            flux_sortant<<title<<endl;
            flux_sortant<<priority<<endl;
            int it = 0;
            for (it = 0 ; it < commentaires.size(); it++ )
            { flux_sortant<<commentaires[it]<<endl;}
        }
        else
        {cout<<"ERREUR : le fichier ne s'ouvre pas pour save"<<endl;}
    }

// Récupération d'attributs
    string Task::get_title() {return title;}
    int Task::get_id() {return id;}
    string Task::get_priority() {return priority;}
    int Task::get_avancement() {return avancement;}
    string Task::get_description() {return description;}
    string Task::get_nomFichier() {return nomFichier;}
    int Task::get_datedebut(){return datedebut;}
    int Task::get_datefin(){return datefin;}
    vector <string> Task::get_commentaires(){return commentaires;}


//Modification d'attributs
    void Task::modif_title(string new_title) {title = new_title;}   
    void Task::modif_id(int new_id) {id = new_id;}
    void Task::modif_priority(string new_priority) {priority = new_priority;}
    void Task::modif_avancement(int new_avancement) {avancement = new_avancement;}
    void Task::modif_description(string new_description) {description = new_description;}
    void Task::modif_nomFichier(string new_nomFichier) {nomFichier = new_nomFichier;}
    void Task::modif_datedebut(int new_datedebut){datedebut = new_datedebut;}
    void Task::modif_datefin(int new_datefin){datefin = new_datefin;}

    void Task::add_commentaire(string new_commentaire){commentaires.push_back(new_commentaire);}
    