#ifndef TASK_H
#define TASK_H
#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Task
{
    private :
    string nomFichier;  // fichier texte pour sauvegarde 
    int id;
    int avancement;     
    int datedebut;
    int datefin;
    string description;
    string title;
    string priority;
    vector <string> commentaires;

    public :
// Constructeurs
    Task(); // quand la tâche existe déjà dans un fichier, il suffira de faire un from_save pour l'initialiser.
    Task(int new_id, int new_av, string new_title, string new_pr, string new_descr);  // quand la tâche doit être créée, on utilisera save pour la mettre dans un fichier

// Pas besoin de destructeur, puisque pas d'allocution dynamique de mémoire

// Intéraction avec le fichier de sauvegarde
    void from_save(string nomSave);
    void save(string nomSave);

// Récupération d'attributs
    string get_title();
    int get_id();     
    string get_priority();    
    int get_avancement();
    string get_description();  
    string get_nomFichier();
    int get_datedebut();
    int get_datefin();
    vector <string> get_commentaires();


// Modification d'attributs
    void modif_title(string new_title);
    void modif_id(int new_id);
    void modif_priority(string new_priority);
    void modif_avancement(int new_avancement);
    void modif_description(string new_description);
    void modif_nomFichier(string new_nomFichier);
    void modif_datedebut(int new_datedebut);
    void modif_datefin(int new_datefin);

    void add_commentaire(string new_commentaire);
};
#endif