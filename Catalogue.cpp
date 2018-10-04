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

enum CHOIX_UTILISATEUR {AFFICHAGE_CATALOGUE = 1, AJOUT_TRAJET, RECHERCHE_VOYAGE_SIMPLE, RECHERCHE_VOYAGE_COMPOSE, FIN};
enum CREATION_TRAJET {TRAJET_SIMPLE = 1};

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

// void Catalogue::AjouterTrajet(Trajet *trajet)
// // Algorithme :
// //
// {
// 	listeDeTrajets->AjouterTrajet(trajet);
// }

void Catalogue::Menu()
// Algorithme :
//
{
	int saisieUtilisateur = 0;

	while (saisieUtilisateur != FIN)
	{
		AfficherMenu();
		saisieUtilisateur = SaisirChoix(AFFICHAGE_CATALOGUE, FIN);

		switch (saisieUtilisateur) {
			case AFFICHAGE_CATALOGUE:
				Afficher();
				break;
			case AJOUT_TRAJET:
				AjouterTrajet();
				break;
			case RECHERCHE_VOYAGE_SIMPLE:
				RechercherVoyageSimple();
				break;
			case RECHERCHE_VOYAGE_COMPOSE:
				RechercherVoyageCompose();
				break;
		}
	}
}

void Catalogue::RechercherVoyageSimple()
{
	char *lieuDepart = new char[100],
	*lieuArrivee = new char[100];

	cout << endl << "--- Recherche d'un voyage ---" << endl;
	cout << "Saisir le lieu de depart : ";
	cin >> lieuDepart;
	cout << "Saisir le lieu d'arrivee : ";
	cin >> lieuArrivee;

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

void Catalogue::RechercherVoyageCompose()
// Algorithme :
//
{
	char *lieuDepart = new char[100],
	*lieuArrivee = new char[100];

	cout << endl << "--- Recherche d'un voyage ---" << endl;
	cout << "Saisir le lieu de depart : ";
	cin >> lieuDepart;
	cout << "Saisir le lieu d'arrivee : ";
	cin >> lieuArrivee;

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
			ParcoursProfondeur(listeDeTrajets, trajet, listeTraitement, lieuDepart, lieuArrivee, nombreVoyagesTrouves);
			listeTraitement->RetirerDernierTrajet();
		}
	}

	if (*nombreVoyagesTrouves == 0)
	{
		cout << "Aucun voyage trouve !" << endl;
	}

	delete nombreVoyagesTrouves;
}

void Catalogue::RechercherTrajet(char *lieuDepart, char *lieuArrivee)
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
			ParcoursProfondeur(listeDeTrajets, trajet, listeTraitement, lieuDepart, lieuArrivee, nombreVoyagesTrouves);
			listeTraitement->RetirerDernierTrajet();
		}
	}

	if (*nombreVoyagesTrouves == 0)
	{
		cout << "Aucun voyage trouve !" << endl;
	}

	delete nombreVoyagesTrouves;
}

void Catalogue::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
	listeDeTrajets->AjouterTrajet(trajet);
}

void Catalogue::AjouterTrajet()
// Algorithme :
//
{
	Trajet *t;
	int saisieUtilisateur;

	cout << "Type de trajet :" << endl;
	cout << "1 - Trajet simple" << endl;
	cout << "2 - Trajet compose" << endl;

	saisieUtilisateur = SaisirChoix(1, 2);

	if (saisieUtilisateur == TRAJET_SIMPLE)
	{
		t = CreerTrajetSimple();
	}
	else
	{
		t = CreerTrajetCompose();
	}

	listeDeTrajets->AjouterTrajet(t);
}

TrajetSimple* Catalogue::CreerTrajetSimple()
// Algorithme :
//
{
	TrajetSimple *ts;

	char *lieuDepart = new char[100],
	*lieuArrivee = new char[100],
	*moyenTransport = new char[100];

	cout << endl << "--- Creation d'un trajet simple ---" << endl;
	cout << "Saisir le lieu de depart : ";
	cin >> lieuDepart;
	cout << "Saisir le lieu d'arrivee : ";
	cin >> lieuArrivee;
	cout << "Saisir le moyen de transport : ";
	cin >> moyenTransport;

	ts = new TrajetSimple(lieuDepart, lieuArrivee, moyenTransport);

	cout << endl << "Trajet cree : ";
	ts->Afficher();

	return ts;
}

TrajetCompose* Catalogue::CreerTrajetCompose()
// Algorithme :
//
{
	TrajetCompose *tc = new TrajetCompose;
	TrajetSimple *ts;
	int nombreTrajetsSimples = SaisirNombreTrajets();

	for (int iInsertion = 0; iInsertion < nombreTrajetsSimples; iInsertion++)
	{
		ts = CreerTrajetSimple();
		while (tc->AjouterTrajet(ts) == CONTRAINTE_NON_VERIFIEE)
		{
			cout << "/!\\ ERREUR : contrainte non verifiee. Resaisir." << endl;
			ts = CreerTrajetSimple();
		}
	}

	return tc;
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
void Catalogue::ParcoursProfondeur(CollectionTrajets *listeDeTrajets, Trajet *sommet, CollectionTrajets *listeTraitement,
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
				ParcoursProfondeur(listeDeTrajets, trajet, listeTraitement, lieuDepart, lieuArrivee, nombreVoyagesTrouves);
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

void Catalogue::AfficherMenu()
// Algorithme :
//
{
	cout << endl << "--- Menu de gestion d'un catalogue de voyage ---" << endl;
	cout << "1 - Afficher le catalogue" << endl;
	cout << "2 - Inserer un trajet" << endl;
	cout << "3 - Rechercher un voyage (simple)" << endl;
	cout << "4 - Rechercher un voyage (compose)" << endl;
	cout << "5 - Quitter" << endl << endl;
} //----- fin de AfficherMenu

int Catalogue::SaisirChoix(int borneInf, int borneSup)
// Algorithme :
//
{
	int saisieUtilisateur = 0;

	cout << "Saisir choix : ";
	cin >> saisieUtilisateur;

	while (saisieUtilisateur > borneSup || saisieUtilisateur < borneInf) //contrôle de la saisie
	{
		cout << "/!\\ ERREUR : mauvaise entree. Resaisir." << endl;
		cout << "Saisir choix : ";
		cin >> saisieUtilisateur;
	}

	return saisieUtilisateur;
} //----- fin de SaisirChoix

int Catalogue::SaisirNombreTrajets()
// Algorithme :
//
{
	int saisieUtilisateur = 0;

	cout << "Nombre de trajets simples : ";
	cin >> saisieUtilisateur;

	while (saisieUtilisateur < 2) //contrôle de la saisie
	{
		cout << "/!\\ ERREUR : mauvaise entree (au moins 2 trajets simples). Resaisir." << endl;
		cout << "Saisir nombre : ";
		cin >> saisieUtilisateur;
	}

	return saisieUtilisateur;
}
