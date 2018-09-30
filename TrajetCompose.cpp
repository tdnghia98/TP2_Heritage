
//---------- Réalisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int TrajetCompose::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
    if (nbTrajetsCourant < nbTrajetsMax)
    {
        if (VerifierContrainte(*trajet)) // contrainte vérifiée
        {
            tableauTrajets[nbTrajetsCourant] = trajet;
            nbTrajetsCourant++;
            return AJOUTE;
        }

        return CONTRAINTE_NON_VERIFIEE;
    }

    return PLEIN;
} //----- Fin de Méthode

char* TrajetCompose::GetLieuDepart() const
// Algorithme :
//
{
    return (*tableauTrajets[0]).GetLieuDepart();
} //----- Fin de Méthode

char* TrajetCompose::GetLieuArrivee() const
// Algorithme :
//
{
    return (*tableauTrajets[nbTrajetsCourant - 1]).GetLieuArrivee();
} //----- Fin de Méthode

void TrajetCompose::Afficher() const
{
    cout << "{" << endl;
    for (int curseur = 0; curseur < nbTrajetsCourant; curseur++)
    {
        cout << "\t";
        (*tableauTrajets[curseur]).Afficher();
    }
    cout << "}" << endl;
}


//------------------------------------------------- Surcharge d'opérateurs
//${file_base} & ${file_base}::operator = ( const ${file_base} & un${file_base} )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(unsigned int nbTrajetsM)
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au constructeur de <${file_base}>" << endl;
    #endif

    tableauTrajets = new Trajet*[nbTrajetsM];
    nbTrajetsMax = nbTrajetsM;
    nbTrajetsCourant = 0;
}


TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au destructeur de <${file_base}>" << endl;
    #endif

    for (int curseur = 0; curseur < nbTrajetsCourant; curseur++)
    {
        delete tableauTrajets[curseur];
    }

    delete [] tableauTrajets;
} //----- Fin de ~${file_base}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
bool TrajetCompose::VerifierContrainte(const Trajet & trajet) const
{
    return nbTrajetsCourant == 0 || (strcmp(trajet.GetLieuDepart(), GetLieuArrivee()) == 0);
}
