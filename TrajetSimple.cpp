/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Réalisation de la classe TrajetSimple (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char* TrajetSimple::GetLieuDepart() const
// Algorithme :
//
{
    return lieuDepart;
} //----- Fin de Méthode

char* TrajetSimple::GetLieuArrivee() const
// Algorithme :
//
{
    return lieuArrivee;
} //----- Fin de Méthode

void TrajetSimple::Afficher() const
{
    cout << "{" << lieuDepart << " -> " << lieuArrivee << " : " << moyenTransport <<"}" << endl;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (char* unLD, char* unLA, char* unMT) : lieuDepart(unLD),
    lieuArrivee(unLA), moyenTransport(unMT)
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au constructeur de TrajetSimple" << endl;
    #endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple( )
// Algorithme :
//
{
    delete [] lieuDepart;
    delete [] lieuArrivee;
    delete [] moyenTransport;

    #ifdef MAP
    cout << "Appel au destructeur de TrajetSimple" << endl;
    #endif
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
