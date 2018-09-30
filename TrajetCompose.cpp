/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Réalisation de la classe TrajetCompose (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int TrajetCompose::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
    if (nbTrajetsCourant < nbTrajetsMax)
    {
        if (VerifierContrainte(*trajet))
        {
            tableauTrajets[nbTrajetsCourant++] = trajet;
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

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(unsigned int nbTrajetsM)
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au constructeur de TrajetCompose" << endl;
    #endif

    tableauTrajets = new Trajet*[nbTrajetsM];
    nbTrajetsMax = nbTrajetsM;
    nbTrajetsCourant = 0;
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au destructeur de TrajetCompose" << endl;
    #endif

    for (int curseur = 0; curseur < nbTrajetsCourant; curseur++)
    {
        delete tableauTrajets[curseur];
    }

    delete [] tableauTrajets;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
bool TrajetCompose::VerifierContrainte(const Trajet & trajet) const
{
    return nbTrajetsCourant == 0 || (strcmp(trajet.GetLieuDepart(), GetLieuArrivee()) == 0);
}
