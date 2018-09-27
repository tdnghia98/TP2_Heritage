//
// Created by dntran on 9/27/2018.
//

#ifndef TP2_HERITAGE_TRAJET_H
#define TP2_HERITAGE_TRAJET_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
// type Méthode ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

    virtual char* GetLieuDepart() const = 0;
    virtual char* GetLieuArrivee() const = 0;

//------------------------------------------------- Surcharge d'opérateurs
// ${file_base} & operator = ( const ${file_base} & un${file_base} );
// Mode d'emploi :
//
// Contrat :
//


//-------------------------------------------- Constructeurs - destructeur
//${file_base} ( const ${file_base} & un${file_base} );
//// Mode d'emploi (constructeur de copie) :
////
//// Contrat :
////
//
//${file_base} ( );
//// Mode d'emploi :
////
//// Contrat :
////
//
//virtual ~${file_base} ( );
//// Mode d'emploi :
////
//// Contrat :
////

//------------------------------------------------------------------ PRIVE

//protected:
//----------------------------------------------------- Méthodes protégées

//private:
//------------------------------------------------------- Méthodes privées

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <${file_base}>

#endif //TP2_HERITAGE_TRAJET_H
