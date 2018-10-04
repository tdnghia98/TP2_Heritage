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
#include "CollectionTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int TrajetCompose::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
	if (ContrainteLieuEstVerifiee(*trajet))
	{
		listeDeTrajets->AjouterTrajet(trajet);
		return AJOUTE;
	}
	return CONTRAINTE_NON_VERIFIEE;

} //----- Fin de Méthode

char* TrajetCompose::GetLieuDepart() const
// Algorithme :
//
{
    return listeDeTrajets->GetPremierTrajet()->GetLieuDepart();
} //----- Fin de Méthode

char* TrajetCompose::GetLieuArrivee() const
// Algorithme :
//
{
    return listeDeTrajets->GetDernierTrajet()->GetLieuArrivee();
} //----- Fin de Méthode

void TrajetCompose::Afficher(int profondeur) const
{
    listeDeTrajets->Afficher(profondeur);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(unsigned int capaciteMax)
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au constructeur de TrajetCompose" << endl;
    #endif

	listeDeTrajets = new CollectionTrajets[capaciteMax];
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au destructeur de TrajetCompose" << endl;
    #endif
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
bool TrajetCompose::ContrainteLieuEstVerifiee(const Trajet & trajet) const
{
	return listeDeTrajets->EstVide() || (strcmp(listeDeTrajets->GetDernierTrajet()->GetLieuArrivee(), trajet.GetLieuDepart()) == 0);
}
