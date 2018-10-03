/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Réalisation de la classe Catalogue (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher()
// Algorithme :
//
{
	if (listeDeTrajets->GetNombreTrajetsCourant() == 0)
	{
		cout << "Le catalogue est vide." << endl;
	}
	else
	{
		cout << "Affichage du catalogue de trajets : " << endl;
		listeDeTrajets->Afficher();
	}

} //----- Fin de Méthode

bool Catalogue::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
	return listeDeTrajets->AjouterTrajet(trajet);
}

void Catalogue::RechercherTrajet(char *lieuDepart, char *lieuArrivee)
// Algorithme :
//
{
	Trajet *trajet;
	TrajetCompose *trajetCompose;
	int curseurTrajet, nombreTrajetsCorrespondants = 0;

	//Recherche simple
	cout << "Voyage de \"" << lieuDepart << "\" à \"" << lieuArrivee << "\" : " << endl;

	for (int iTrajet = 0; iTrajet < listeDeTrajets->GetNombreTrajetsCourant(); iTrajet++)
	{
		trajet = listeDeTrajets->GetTrajet(iTrajet);
		if (strcmp(lieuDepart, trajet->GetLieuDepart()) == 0 && strcmp(lieuArrivee, trajet->GetLieuArrivee()) == 0)
		{
			trajet->Afficher();
			nombreTrajetsCorrespondants++;
		}
	}

	if (nombreTrajetsCorrespondants == 0)
	{
		cout << "Aucun trajet correspondant" << endl;
	}

	//Recherche composée
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(unsigned int capaciteMax)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur Catalogue" << endl;
	#endif

	listeDeTrajets = new ListeTrajets[capaciteMax];
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au destructeur de Catalogue" << endl;
	#endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
