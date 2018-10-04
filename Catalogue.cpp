
//---------- Réalisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include <cstring>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

////------------------------------------------------- Surcharge d'opérateurs
//${file_base} & ${file_base}::operator = ( const ${file_base} & un${file_base} )
//// Algorithme :
////
//{
//} //----- Fin de operator =

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() {
    cout << "Affichage du catalogue de Trajet: {\n";
    for (int i = 0; i < nbTrajetActuel; i++) {
        cout << "\t";
        (*tableauTrajet[i]).Afficher();
    }
    cout << "}" <<endl;
}

void Catalogue::rechercheTrajet() {
    bool trouveTrajets = false;
    char lD[100];
    char lA[100];
    cout << "Lieu de depart : ";
    cin >> lD;
    cout << "Lieu d'arrive : ";
    cin >> lA;
    cout << "Les trajets  possibles pour aller de " << lD << " a " << lA << " sont: \n";
    for (int i = 0; i < nbTrajetActuel; i++) {
        if (strcmp(tableauTrajet[i]->GetLieuDepart(), lD) == 0 && strcmp(tableauTrajet[i]->GetLieuArrivee(), lA) == 0) {
            cout << "- ";
            tableauTrajet[i] ->Afficher();
            trouveTrajets = true;
        }
    }
    if (!trouveTrajets) {
        cout << "Pas de trajet possible";
    }

}

void Catalogue::rechercheTrajetAvancee() {
    char lD[100];
    char lA[100];
    cout << "Lieu de depart : ";
    cin >> lD;
    cout << "Lieu d'arrive : ";
    cin >> lA;
    Trajet* parcoursPossible[nbTrajetActuel];
    // Parcours en profondeurs
    for (int i = 0; i < nbTrajetActuel; i++) {
        if(strcmp(tableauTrajet[i]->GetLieuArrivee(), lA) == 0) {
            // Bon lieu de depart
            Trajet* sommet = tableauTrajet[i];
            for (int j = 0; j < nbTrajetActuel; j++) {

            }
        }
    }
}

void parcoursEnProfondeur() {

}

int Catalogue::ajouterTrajet(Trajet * trajet) {
    if (nbTrajetActuel < nbTrajetMax) {
        if (!Exist(*trajet)) {
            tableauTrajet[nbTrajetActuel] = trajet;
            nbTrajetActuel++;
            return AJOUTE;
        } else {
            return EXISTE_DEJA;
        }
    }
    return PLEIN;
}



//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(int n)
{
#ifdef MAP
cout << "Appel au constructeur de copie de <${file_base}>" << endl;
#endif
    nbTrajetMax = n;
    tableauTrajet = new Trajet* [n];
    nbTrajetActuel = 0;
}

Catalogue::~Catalogue()
{
#ifdef MAP
cout << "Appel au destructeur de <${file_base}>" << endl;
#endif
// Virer tous les onjets Trajet dans le tableau
    for (int i = 0; i < nbTrajetMax; i++) {
        delete tableauTrajet[i];
    }
    // Virer le tableau trajet
    delete[] tableauTrajet;
} //----- Fin de ~${file_base}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool Catalogue::Exist(Trajet &unTrajet) const {
    for(int curseur = 0; curseur < nbTrajetActuel; curseur++) {
        if (*tableauTrajet[curseur] == unTrajet) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------- Méthodes privées
