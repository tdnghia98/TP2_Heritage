
//---------- Réalisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

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
