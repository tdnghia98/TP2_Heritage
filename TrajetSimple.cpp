
//---------- Réalisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

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


//------------------------------------------------- Surcharge d'opérateurs
//${file_base} & ${file_base}::operator = ( const ${file_base} & un${file_base} )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//${file_base}::${file_base} ( const ${file_base} & un${file_base} )
// Algorithme :
//
//{
//#ifdef MAP
//cout << "Appel au constructeur de copie de <${file_base}>" << endl;
//#endif
//} //----- Fin de ${file_base} (constructeur de copie)

TrajetSimple::TrajetSimple (char* unLD, char* unLA, char* unMT) : lieuDepart(unLD),
    lieuArrivee(unLA), moyenTransport(unMT)
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au constructeur de <${file_base}>" << endl;
    #endif
} //----- Fin de ${file_base}


TrajetSimple::~TrajetSimple( )
// Algorithme :
//
{
    delete [] lieuDepart;
    delete [] lieuArrivee;
    delete [] moyenTransport;

    #ifdef MAP
    cout << "Appel au destructeur de <${file_base}>" << endl;
    #endif
} //----- Fin de ~${file_base}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
