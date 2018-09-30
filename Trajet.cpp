
//---------- Réalisation de la classe Trajet --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


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


//${file_base}::${file_base} ( )
// Algorithme :
//
//{
//#ifdef MAP
//cout << "Appel au constructeur de <${file_base}>" << endl;
//#endif
//} //----- Fin de ${file_base}

bool Trajet::operator == (const Trajet & unTrajet) const {
    return ((iD == unTrajet.iD) && (type == unTrajet.type));
}

Trajet::~Trajet( )
// Algorithme :
//
{
#ifdef MAP
cout << "Appel au destructeur de <${file_base}>" << endl;
#endif
} //----- Fin de ~${file_base}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
