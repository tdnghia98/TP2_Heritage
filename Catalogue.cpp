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
void Catalogue::Afficher(int profondeur)
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
		listeDeTrajets->Afficher(profondeur);
	}

} //----- Fin de Méthode

void Catalogue::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
	listeDeTrajets->AjouterTrajet(trajet);
}

void Catalogue::RechercherVoyageSimple(char *lieuDepart, char *lieuArrivee)
{
	Trajet *trajet;
	int *nombreVoyagesTrouves = new int;

	cout << "Voyage de \"" << lieuDepart << "\" à \"" << lieuArrivee << "\" : " << endl;

	*nombreVoyagesTrouves = 0;
	for (int iTrajet = 0; iTrajet < listeDeTrajets->GetNombreTrajetsCourant(); iTrajet++)
	{
		trajet = listeDeTrajets->GetTrajet(iTrajet);
		if (strcmp(lieuDepart, trajet->GetLieuDepart()) == 0 && strcmp(lieuArrivee, trajet->GetLieuArrivee()) == 0)
		{
			cout << "VOYAGE " << ++(*nombreVoyagesTrouves) << " : " << endl;
			trajet->Afficher();
		}
	}

	if (*nombreVoyagesTrouves == 0)
	{
		cout << "Aucun voyage trouve !" << endl;
	}

	delete nombreVoyagesTrouves;
}

void Catalogue::RechercherVoyageCompose(char *lieuDepart, char *lieuArrivee)
// Algorithme :
//
{
	Trajet *trajet;
	int *nombreVoyagesTrouves = new int;

	cout << "Voyage de \"" << lieuDepart << "\" à \"" << lieuArrivee << "\" : " << endl;

	CollectionTrajets *listeTraitement = new CollectionTrajets;
	*nombreVoyagesTrouves = 0;
	for (int iTrajet = 0; iTrajet < listeDeTrajets->GetNombreTrajetsCourant(); iTrajet++)
	{
		trajet = listeDeTrajets->GetTrajet(iTrajet);
		if (strcmp(lieuDepart, trajet->GetLieuDepart()) == 0)
		{
			listeTraitement->AjouterTrajet(trajet);
			ParcoursProfondeur(trajet, listeTraitement, lieuDepart, lieuArrivee, nombreVoyagesTrouves);
			listeTraitement->RetirerDernierTrajet();
		}
	}

	if (*nombreVoyagesTrouves == 0)
	{
		cout << "Aucun voyage trouve !" << endl;
	}

	delete nombreVoyagesTrouves;
}

// void Catalogue::RechercherTrajet(char *lieuDepart, char *lieuArrivee)
// // Algorithme :
// //
// {
// 	Trajet *trajet;
// 	int *nombreVoyagesTrouves = new int;
//
// 	cout << "Voyage de \"" << lieuDepart << "\" à \"" << lieuArrivee << "\" : " << endl;
//
// 	CollectionTrajets *listeTraitement = new CollectionTrajets;
// 	*nombreVoyagesTrouves = 0;
// 	for (int iTrajet = 0; iTrajet < listeDeTrajets->GetNombreTrajetsCourant(); iTrajet++)
// 	{
// 		trajet = listeDeTrajets->GetTrajet(iTrajet);
// 		if (strcmp(lieuDepart, trajet->GetLieuDepart()) == 0)
// 		{
// 			listeTraitement->AjouterTrajet(trajet);
// 			ParcoursProfondeur(listeDeTrajets, trajet, listeTraitement, lieuDepart, lieuArrivee, nombreVoyagesTrouves);
// 			listeTraitement->RetirerDernierTrajet();
// 		}
// 	}
//
// 	if (*nombreVoyagesTrouves == 0)
// 	{
// 		cout << "Aucun voyage trouve !" << endl;
// 	}
//
// 	delete nombreVoyagesTrouves;
// }

// void Catalogue::AjouterTrajet(Trajet *trajet)
// // Algorithme :
// //
// {
// 	listeDeTrajets->AjouterTrajet(trajet);
// }



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(unsigned int capaciteMax)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur Catalogue" << endl;
	#endif

	listeDeTrajets = new CollectionTrajets[capaciteMax];
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
void Catalogue::ParcoursProfondeur(Trajet *sommet, CollectionTrajets *listeTraitement,
	char *lieuDepart, char *lieuArrivee, int *nombreVoyagesTrouves)
// Algorithme :
//
{
	Trajet *trajet;

	for (int iTrajet = 0; iTrajet < listeDeTrajets->GetNombreTrajetsCourant(); iTrajet++)
	{
		trajet = listeDeTrajets->GetTrajet(iTrajet);
		if (strcmp(sommet->GetLieuArrivee(), trajet->GetLieuDepart()) == 0) //relation père-fils
		{
			if (!listeTraitement->EstDans(trajet)) //éviter récursivité infinie (T-B // B-C // C-T)
			{
				listeTraitement->AjouterTrajet(trajet);
				ParcoursProfondeur(trajet, listeTraitement, lieuDepart, lieuArrivee, nombreVoyagesTrouves);
			}
		}
	}

	if (strcmp(sommet->GetLieuArrivee(), lieuArrivee) == 0) //destination atteinte
	{
		cout << "VOYAGE " << ++(*nombreVoyagesTrouves) << " : " << endl;
		listeTraitement->Afficher();
	}

	listeTraitement->RetirerDernierTrajet(); //on retire le dernier trajet
}
