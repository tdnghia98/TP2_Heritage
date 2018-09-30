//
// Created by dntran on 9/27/2018.
//

#ifndef TP2_HERITAGE_TRAJETCOMPOSE_H
#define TP2_HERITAGE_TRAJETCOMPOSE_H


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes
const int TAILLE_MAXIMALE_DEFAUT = 5;

//------------------------------------------------------------------ Types
enum CODE_RETOUR_AJOUT {PLEIN, CONTRAINTE_NON_VERIFIEE, AJOUTE};

//------------------------------------------------------------------------
// Rôle de la classe <${file_base}>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
    int AjouterTrajet(Trajet *trajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char* GetLieuDepart() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char* GetLieuArrivee() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //


    //------------------------------------------------- Surcharge d'opérateurs
    //${file_base} & operator = ( const ${file_base} & un${file_base} );
    // Mode d'emploi :
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur

    TrajetCompose(unsigned int nbTrajetsM = TAILLE_MAXIMALE_DEFAUT);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

    private:
    //------------------------------------------------------- Méthodes privées
    bool VerifierContrainte(const Trajet & trajet) const;

    //------------------------------------------------------- Attributs privés
    int nbTrajetsCourant;

    int nbTrajetsMax;

    Trajet** tableauTrajets;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <${file_base}>


#endif //TP2_HERITAGE_TRAJETCOMPOSE_H
