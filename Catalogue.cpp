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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher()
// Algorithme :
//
{
	cout << "Affichage du catalogue de trajets : " << endl;
	listeDeTrajets->Afficher();
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
	int curseurTrajet;

	//Recherche simple
	cout << "[RECHERCHE SIMPLE] Voyage de " << lieuDepart << " à " << lieuArrivee << " : " << endl;
	for (int iTrajet = 0; iTrajet < listeDeTrajets->GetNombreTrajetsCourant(); iTrajet++)
	{
		trajet = listeDeTrajets->GetTrajet(iTrajet);
		if (strcmp(lieuDepart, trajet->GetLieuDepart()) == 0 && strcmp(lieuArrivee, trajet->GetLieuArrivee()) == 0)
		{
			trajet->Afficher();
		}
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
