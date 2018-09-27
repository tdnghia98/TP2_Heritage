
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

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() {
    cout << "Affichage du tableau de Trajet: ";
    for (int i = 0; i < nbTrajetActuel; i++) {
        tableauTrajet[i].Afficher();
    }
    cout << endl;
}


////------------------------------------------------- Surcharge d'opérateurs
//${file_base} & ${file_base}::operator = ( const ${file_base} & un${file_base} )
//// Algorithme :
////
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(int n)
{// n = nb Trajet max
#ifdef MAP
cout << "Appel au constructeur de copie de <${file_base}>" << endl;
#endif
    nbTrajetMax = n;
    tableauTrajet = new Trajet*[n];
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

//------------------------------------------------------- Méthodes privées
