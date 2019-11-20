/*************************************************************************
                           Adresse  -  description
                             -------------------
    début                : 10 déc. 2008
    copyright            : (C) 2008 par pcoquard
*************************************************************************/

//---------- Interface de la classe <Adresse> (fichier Adresse.h) ------
#ifndef ADRESSE_H_
#define ADRESSE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes
const int LG_RUE=30;
const int LG_COD=6;
const int LG_VIL=20;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Adresse>
//
// Classe qui permet de manipuler des adresses simples composees d'informations
// sur la rue, le code postal et la ville.
//
//------------------------------------------------------------------------
class Adresse
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void MettreAJour(const char * codePostal, const char * ville="", const char * rue="");
    // Affectation de nouvelles valeurs aux attributs (suite à déménagement par exemple)

    void MettreAJourLaRue(const char * nouvelleRue);
    // Affectation d'une nouvelle valeur exclusivement à la rue
    // la ville et le code restent inchangés

    void Afficher() const;
    // Affichage des informations sur une seule ligne

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	Adresse();
    explicit Adresse (const char * codePostal, const char * ville, const char * rue);
	Adresse(const Adresse& adresse);
    // Constructeur avec trois parametres et trois valeurs par defaut


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	std::string codepostal;// la valeur du code postal 
	std::string ville;     // le nom de la ville
	std::string rue;       // les informations de voirie (numero et nom de rue)
};


//--------------------------- Autres définitions dépendantes de <Adresse>

#endif // ADRESSE_H_
