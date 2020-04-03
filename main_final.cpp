#include <iostream>
#include <string>
#include <vector>
#include <fstream> // pour gérer les flux entrants et sortants
#include <sstream> // pour convertir int en string
#include "task.hpp"
#include "fonctions.hpp"
using namespace std;

// on peut créer un fichier 'dico.txt', dans lequel les noms des flux déjà existants sont répertoriés
// ce fichier ne sera jamais détruit, il servira au démarrage à recréer tous les objets


int main()
{
const string chemin("/Users/vincent/Documents/Cours/Info/C++/Programmes/TP_ouvrier/"); // Il faut ici rentrer l'adresse de l'endroit où vous voulez stocker les tâches.
string chemin_dico(chemin);
chemin_dico.append("dico.txt");

int compteur(0);    // nombre de tâches déjà existantes
vector <Task> taches;

ifstream fluxDico(chemin_dico.c_str());
if (fluxDico)
{
    fluxDico.seekg(0, ios::beg);
    string ligne;
    while (getline(fluxDico, ligne))
    {   Task t;
        t.from_save(ligne);
        taches.push_back(t); 
    }
    compteur = taches.size();
}
else 
{ ofstream fluxDico(chemin_dico.c_str()); }

//cout<<"Combien de tâches déjà existantes : "<<compteur<<endl; 


    cout<<"\n Bienvenue dans la todo_list !"<<endl;
    cout<<"Plusieurs fonctionnalités sont disponibles : "<<endl;
    cout<<"- Si vous tapez 'create' vous pourrez créer une nouvelle tâche. "<<endl;
    cout<<"- Si vous tapez 'modify' vous pourrez modifier une des tâches déjà existantes."<<endl;
    cout<<"- Si vous tapez 'list' vous pourrez lister les tâches qui répondent à un critère de votre choix."<<endl;
    cout<<"- Si vous tapez 'infos' vous pourrez lire un rapide descriptif de ce programme, et de ce qui constitue une tâche."<<endl;
    cout<<"A tout moment, si vous tapez 'quit', le programme s'arrétera. La suite des fonctions possibles vous sera expliquée au fur et à mesure."<<endl;


string rep_user;
cin>>rep_user;
cout<<endl;
while (rep_user.compare("quit")!=0)
{   

    if (rep_user.compare("create")==0)      
    {
        cout<<"\n Vous avez choisi de créer une nouvelle tâche. Il faut rentrer les informations de la nouvelle tâche."<<endl;
        
        Task new_task;
        if (compteur > 10)
            {rep_user = "quit";}
        else
        {int new_id(compteur + 1);         // l'id le nombre de tâches déjà existantes + 1
        new_task.modif_id(new_id);
        int new_avancement;           // on déclare toutes les variables de la nouvelle tâche
        int new_datedebut;
        int new_datefin;
        string new_title;
        string new_priority;
        string new_description;

        string chemin_new(chemin);      // on donne le nom du fichier de save de la nouvelle tâche, grâce à new_id (qu'on convertis)
        chemin_new.append("tache_");
        ostringstream os;                   
        os << new_id; 
        string temp= os.str(); 
        chemin_new.append(temp);  
        chemin_new.append(".txt");                      

        cout<<"- Entrez le titre de la nouvelle tâche :"<<endl;
            cin.ignore();
            getline(cin, new_title);
            new_task.modif_title(new_title);
        
        cout<<"\n - Entrez la date de début de la nouvelle tâche (sous la forme AAAAMMJJ) :"<<endl;
            cin>>new_datedebut;
            while (!if_date(new_datedebut))
            {cin>>new_datedebut;}
            new_task.modif_datedebut(new_datedebut);
        cout<<"\n - Entrez la date de fin de la nouvelle tâche (sous la forme AAAAMMJJ) :"<<endl;
            cin>>new_datefin;
            while (!if_date(new_datefin))
            {cin>>new_datefin;}
            new_task.modif_datefin(new_datefin);
        cout<<"\n - Entrez l'avancement de la nouvelle tâche (ça doit être un chiffre entre 0 et 100):"<<endl;
            cin>>new_avancement;
            while (!if_avancement(new_avancement))
            {cin>>new_avancement;}
            new_task.modif_avancement(new_avancement);
            cin.ignore();
        cout<<"\n - Entrez la priorité de la nouvelle tâche (low, medium ou high) :"<<endl;
            getline(cin, new_priority);
            while (!if_priority(new_priority))
            {getline(cin, new_priority);}
            new_task.modif_priority(new_priority);
        cout<<"\n - Entrez la description de la nouvelle tâche :"<<endl;
            getline(cin, new_description);
            new_task.modif_description(new_description);
        cout<<"\n - Si vous souhaitez rentrer des commentaires pour cette tâche, tapez 'comm', sinon tapez 'pass'."<<endl;
        string rep_comm;
        
        cin>>rep_comm;
        while (rep_comm.compare("pass")!=0) 
            if (rep_comm.compare("comm")==0)
            {   string new_comm;
                cout<<"Veuillez entrer votre commentaire :"<<endl;
                cin.ignore();
                getline(cin, new_comm);
                new_task.add_commentaire(new_comm);
                cout<<"\n Si vous souhaitez ajouter un commentaire, tapez 'comm'. Sinon, tapez 'pass'."<<endl;
                cin>>rep_comm;
            }
            else
            {   cout<<"Commande incorrecte ; vous pouvez entrer 'comm' ou 'pass'."<<endl;
                cin>>rep_comm; }
        

    
        string rep_create;
        cout<<"\n Si vous souhaitez vérifier les informations de la tâche que vous venez de rentrer, tapez 'check'."<<endl;
        cout<<"Si vous souhaitez annuler la saisie de cette tâche, tapez 'delete'."<<endl;
        cout<<"Si vous êtes satisfait de la nouvelle tâche, tapez 'ok' pour l'enregistrer."<<endl;
        
        
        cin>>rep_create;
        while (rep_create.compare("quit")!=0)              //PB : la boucle ne prend pas en compte la première commande.. tjrs un 'pas compris' qui sort en 1er
        {   
            if (rep_create.compare("check")==0)             // on vérifie la nouvelle tâche
            {   cout<<"\n Voici la tâche que vous venez de créer : "<<endl;
                check_all_task(new_task); 
                cout<<"\n Vous pouvez maintenant la supprimer avec 'delete' ou l'enregistrer avec 'ok'."<<endl;
                cin>>rep_create;  }

            else if (rep_create.compare("delete")==0)       // on annule la saisie de la nouvelle tâche
            {   cout<<"\n La tâche que vous venez de rentrer ne sera pas créée."<<endl;
                rep_create = "quit"; }

            else if (rep_create.compare("ok")==0)           // on valide la nouvelle tâche et on la rentre dans la sauvegarde
            {
                cout<<"\n Vous venez de créer une tâche !"<<endl;
                compteur++; 
                new_task.save(chemin_new);
                taches.push_back(new_task);
                ofstream fluxDico_new(chemin_dico.c_str(), ios::app); // rajoutons le nom de la nouvelle tâche au dico
                fluxDico_new<<chemin_new<<endl;
                rep_create = "quit";
            }
            else 
            {   cout<<"Commande incorrecte ; vous pouvez entrer 'check', 'ok' ou 'delete'."<<endl;
                cin>>rep_create; }
            
        } 
        
        }
    }   // fin 'create'

    else if (rep_user.compare("modify")==0) // Reste que les commentaires à faire (même principe que le reste, faut juste parcourir les commentaires avec une boucle)
    {
        string rep_change;
        cout<<"Vous souhaitez modifier une tâche. Il va falloir donner l'identifiant de la tâche concernée."<<endl;
        cout<<"Si vous souhaitez afficher toutes les tâches (titre et identifiant), entrez 'print'."<<endl;
        cout<<"Si vous connaissez déjà l'identifiant de la tâche, entrez 'ok'."<<endl;

        cin>>rep_change;
        while  (rep_change.compare("ok")!=0)
        {
            if (rep_change.compare("print")==0)
            {   cout<<"Voici toutes vos tâches, titre et identifiant : "<<endl;
                int it(0);
                for (it = 0 ; it < compteur ; it++)
                {   check_id_task(taches[it]); }
                cout<<"Tapez 'ok' si vous avez l'identifiant de la tâche à modifier. "<<endl;
            }
            else { cout<<"Commande incorrecte, tapez 'print' ou 'ok'."<<endl;}
            cin>>rep_change;
        }
        int id_modif;
        cout<<"Rentrez maintenant l'identifiant de la tâche que vous souhaitez modifier."<<endl;
        cin>>id_modif;
        int place_modif;    // on doit maintenant retrouver la tâche parmi notre vector 'taches', grâce à son identifiant
        int it(0);
        for (it = 0 ; it < compteur ; it++)     // on parcourt 'taches', et on trouve la tâche concernée
        {   int id_temp(taches[it].get_id());
            if (id_temp == id_modif)
            { place_modif = it; } 
        }
        Task task_modif(taches[place_modif]);       // On fait une copie de la tâche à modifier
        cout<<"\n Vous avez choisi la tâche suivante : "<<endl;
        check_all_task(task_modif);
        cout<<"Vous allez pouvoir modifier la tâche. A chaque information, vous pouvez taper 'change' si vous souhaitez l'information modifier, ou'pass' si vous ne souhaitez pas la modifier."<<endl;
        cout<<"Veuillez entrer les nouvelles informations : "<<endl;

        int new_avancement;           // on déclare toutes les nouvelles variables de la tâche
        
        string new_priority;
        string new_description;
        int new_datedebut;
        int new_datefin;

        cout<<"\n - Titre : entrez 'change' pour modifier ou 'pass'."<<endl;
            string rep_title;
            cin>>rep_title;
            while (rep_title.compare("pass")!=0)
            {   if (rep_title.compare("change")==0)
                {   cout<<"Entrez maintenant le nouveau titre."<<endl;
                    string new_title;
                    cin.ignore();
                    getline(cin, new_title);
                    task_modif.modif_title(new_title); 
                    cout<<"Tapez 'pass' si ce nouveau titre vous convient, 'change' si vous souhaitez le modifier."<<endl;; }
                else
                {   cout<<"Commande incorrecte, tapez 'change' ou 'pass'."<<endl;}
                cin>>rep_title; 
            }

        cout<<"\n - Avancement : entrez 'change' pour modifier ou 'pass'."<<endl;
            string rep_avancement;
            cin>>rep_avancement;
            while (rep_avancement.compare("pass")!=0)
            {   if (rep_avancement.compare("change")==0)
                {   cout<<"Entrez maintenant le nouvel avancement (ça doit être un chiffre entre 0 et 100)."<<endl;
                    cin>>new_avancement;
                    while (!if_avancement(new_avancement))
                    {cin>>new_avancement;}
                    task_modif.modif_avancement(new_avancement); 
                    cout<<"Tapez 'pass' si ce nouvel avancement vous convient, 'change' si vous souhaitez le modifier."<<endl;; }
                else
                {   cout<<"Commande incorrecte, tapez 'change' ou 'pass'."<<endl;}
                cin>>rep_avancement; 
            }

        
        cout<<"\n - Priorité : entrez 'change' pour modifier ou 'pass'."<<endl;  
            string rep_priority;
            cin>>rep_priority;
            while (rep_priority.compare("pass")!=0)
            {   if (rep_priority.compare("change")==0)
                {   cout<<"Entrez maintenant la nouvelle priorité (low high ou medium)."<<endl;
                    cin>>new_priority;
                    while (!if_priority(new_priority))
                    {cin>>new_priority;}
                    task_modif.modif_priority(new_priority); 
                    cout<<"Tapez 'pass' si cette nouvelle priorité vous convient, 'change' si vous souhaitez la modifier."<<endl;; }
                else
                {   cout<<"Commande incorrecte, tapez 'change' ou 'pass'."<<endl;
                cin>>rep_priority; 
            }
        
        cout<<"\n - Description : entrez 'change' pour modifier ou 'pass'."<<endl;
            string rep_description;
            cin>>rep_description;
            while (rep_description.compare("pass")!=0)
            {   if (rep_description.compare("change")==0)
                {   cout<<"Entrez maintenant la nouvelle description."<<endl;
                    cin.ignore();
                    getline(cin,new_description);
                    task_modif.modif_description(new_description); 
                    cout<<"Tapez 'pass' si cette nouvelle description vous convient, 'change' si vous souhaitez la modifier."<<endl;; }
                else
                {   cout<<"Commande incorrecte, tapez 'change' ou 'pass'."<<endl;}
                cin>>rep_description; 
            }
        
        cout<<"\n - Date de début : entrez 'change' pour modifier ou 'pass'."<<endl;
            string rep_datedebut;
            cin>>rep_datedebut;
            while (rep_datedebut.compare("pass")!=0)
            {   if (rep_datedebut.compare("change")==0)
                {   cout<<"Entrez maintenant la nouvelle date de début (AAAAMMJJ)."<<endl;
                    cin>>new_datedebut;
                    while (!if_date(new_datedebut))
                    {cin>>new_datedebut;}
                    task_modif.modif_datedebut(new_datedebut); 
                    cout<<"Tapez 'pass' si cete nouvelel date de début vous convient, 'change' si vous souhaitez la modifier."<<endl;; }
                else
                {   cout<<"Commande incorrecte, tapez 'change' ou 'pass'."<<endl;}
                cin>>rep_datedebut; 
            }

        cout<<"\n - Date de fin : entrez 'change' pour modifier ou 'pass'."<<endl;
            string rep_datefin;
            cin>>rep_datefin;
            while (rep_datefin.compare("pass")!=0)
            {   if (rep_datefin.compare("change")==0)
                {   cout<<"Entrez maintenant la nouvelle date de fin (AAAAMMJJ)."<<endl;
                    cin>>new_datefin;
                    while (!if_date(new_datefin))
                    {cin>>new_datefin;}
                    task_modif.modif_datefin(new_datefin); 
                    cout<<"Tapez 'pass' si cete nouvelel date de fin vous convient, 'change' si vous souhaitez la modifier."<<endl;; }
                else
                {   cout<<"Commande incorrecte, tapez 'change' ou 'pass'."<<endl;}
                cin>>rep_datefin; 
            }
        // commentaires
        cout<<"\n Voici la tâche modifiée :"<<endl;
        check_all_task(task_modif);
        cout<<"\n Si vous êtes satisfait de la nouvelle tâche, tapez 'ok'. Sinon, tapez 'cancel'."<<endl;

        string rep_change2;
        cin>>rep_change2;
        while (rep_change2.compare("quit")!=0)
        {
            if (rep_change2.compare("ok")==0)
            {   
                string chemin_modif(task_modif.get_nomFichier());
                taches[place_modif] = task_modif;       // on remplace la tâche à modifier dans 'taches' par la nouvelle tâche
                taches[place_modif].save(chemin_modif);    // on actualise la sauvegarde
                rep_change2 = "quit";
            }
            else if (rep_change2.compare("cancel")==0)
            {   rep_change2 = "quit";}
            else 
            {   cout<<"Commande incorrecte, tapez 'ok' ou 'cancel'."<<endl; }
        }

    }   // fin 'modify'

    else if (rep_user.compare("list")==0)   // 'Tri par date pas fait, mais même principe qu'avancement (inégalités)
    {
        cout<<"Vous souhaitez afficher certaines tâches. Vous allez pouvoir afficher les titres des tâches, puis si besoin afficher une tâche en entier."<<endl;
        cout<<"- Si vous souhaitez afficher toutes les tâches, tapez 'all'."<<endl;
        cout<<"- Si vous souhaitez trier les tâches par priorité, tapez 'priority'."<<endl;
        cout<<"- Si vous souhaitez trier les tâches par avancement, tapez 'avancement'."<<endl;
        cout<<"- Si vous souhaitez trier les tâches par dates, tapez 'date' (pas fini)."<<endl;
        cout<<"- Si vous souhaitez afficher une tâche en entier, et que vous connaissez son identifiant, tapez 'one'."<<endl;
        cout<<"- Sinon, tapez 'quit'. \n"<<endl;
        
        string rep_list;
        cin>>rep_list;
        while (rep_list.compare("quit")!=0)
        {
            if (rep_list.compare("all")==0)
            {   cout<<"Voici toutes vos tâches, titre et identifiant : "<<endl;
                int it(0);
                for (it = 0 ; it < compteur ; it++)
                {   check_id_task(taches[it]); }
            }

            else if (rep_list.compare("priority")==0)
            {   string rep_priority;
                cout<<"Veuillez rentrer la priorité souhaitée (parmi low, medium et high)."<<endl;
                cin>>rep_priority;
                while(!if_priority(rep_priority))
                { cin>>rep_priority; }
                cout<<"Voici la liste des tâches à la priorité "<<rep_priority<<endl;
                vector <Task> taches_priority; 
                int it(0);
                string priority;
                for (it = 0 ; it < compteur ; it++)
                    {priority = taches[it].get_priority();
                    if (priority.compare(rep_priority)==0)
                    {   taches_priority.push_back(taches[it]); 
                        check_id_task(taches[it]);  } }
            }

            else if (rep_list.compare("avancement")==0)
            {   int avancement_lim;
                string rep_avancement;
                cout<<"Vous pouvez regarder les tâches avec un avancement supérieur ou inférieur à celui que vous rentrez."<<endl;
                cout<<"Veuillez rentrer l'avancement souhaité (entre 0 et 100)."<<endl;
                cin>>avancement_lim;
                while(!if_avancement(avancement_lim))
                { cin>>avancement_lim; }
                int it = 0;
                vector <int> list_sup;
                vector <int> list_inf;
                for (it = 0 ; it<taches.size() ; it++ )
                {
                    if (taches[it].get_avancement() < avancement_lim)
                        {list_inf.push_back(it); }
                    else 
                        {list_sup.push_back(it); }
                }

                cout<<"Rentrez 'sup' si vous voulez lister les tâches à avancement supérieur, rentrez 'inf' pour les tâches à avancement inférieur."<<endl;
                cin>>rep_avancement;
                if (rep_avancement.compare("sup")==0)
                {   it = 0;
                    for (it = 0; it<list_sup.size(); it++)
                    {   check_all_task(taches[list_sup[it]]);   }
                }
                else if (rep_avancement.compare("inf")==0)
                {   it = 0;
                    for (it = 0; it<list_inf.size(); it++)
                    {   check_all_task(taches[list_inf[it]]);   }
                }

                
            }

            else if (rep_list.compare("one")==0)
            {   int id_print;
                cout<<"Veuillez rentrer l'identifiant de la tâche que vous souhaitez afficher : "<<endl;
                cin>>id_print;

                int place_print;    // on doit maintenant retrouver la tâche parmi notre vector 'taches', grâce à son identifiant
                int it(0);
                for (it = 0 ; it < compteur ; it++)     // on parcourt 'taches', et on trouve la tâche concernée
                {   int id_temp(taches[it].get_id());
                    if (id_temp == id_print)
                    {   place_print = it; } 
                }

                cout<<"Voici la tâche ayant pour identifiant "<<id_print<<" : \n"<<endl;
                check_all_task(taches[place_print]);
            }
            else { cout<<"Commande incorrecte, tapez 'all', 'priority', 'avancement', 'one' ou 'quit'."<<endl;}
            cin>>rep_list;
        }
    }   // fin 'list'

    else if (rep_user.compare("infos")==0) //
    {
        cout<<"\n Ce programme est une todo-list, il va vous permettre d'enregistrer des tâches, de les lire et les modifier."<<endl;
        cout<<"Une tâche se constitue : "<<endl;
        cout<<" - d'un identifiant (un chiffre) qui vous sert à retrouver une tâche."<<endl;
        cout<<" - d'un avancement : c'est un pourcentage, il faut donc rentrer un chiffre entre 0 et 100, sinon ça ne marche pas. "<<endl;
        cout<<" - d'une date de début et de fin, sous le format AAAAMMJJ."<<endl;
        cout<<" - d'un titre. "<<endl;
        cout<<" - d'une description (petit texte). "<<endl;
        cout<<" - d'une priorité : il faut rentrer 'low', 'medium' ou 'high'. "<<endl;
        cout<<" - de commentaires."<<endl;
        cout<<"Vous pouvez maintenant taper 'create', 'modify', 'list' ou 'quit'."<<endl;
        
    }   // fin 'infos'
    else
    {
        cout<<"Commande incorrecte."<<endl;
    }
    cout<<"Vous êtes de retour au menu principal, vous pouvez taper une commande(create, change, list ou infos), ou entrer 'quit' pour arréter le programme."<<endl;
    cin>>rep_user;
    
     
}
};