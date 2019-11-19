#pragma once
#include <string>
#include "Adresse.h"
#include "Date.h"

class Personne {

public:
	Personne() = delete; // Instantiation sans paramètre impossible
	Personne(const char* nom, int jour, int mois, int an, const char* rue="", const char* codePostal="", const char* ville="");
	Personne(const char* nom, const Date& dateNaissance, const Adresse& adresse);

	void Afficher() const;

	int Age() const;
	void Epouser(const char* nom);
	void Demenager(const char* rue);


protected:
	std::string nom;
	Adresse adresse;
	Date dateNaissance;
	
};
