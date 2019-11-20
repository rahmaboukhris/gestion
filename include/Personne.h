#pragma once
#include <string>
#include "Adresse.h"
#include "Date.h"

class Personne {

public:
	Personne() = delete; // Instantiation sans paramètre impossible
	explicit Personne(const char* nom, int jour=0, int mois=0, int an=0, const char* rue="", const char* codePostal="", const char* ville="");
	Personne(const char* nom, const Date& dateNaissance, const Adresse& adresse);
	virtual ~Personne();
	void Afficher() const;

	int Age() const;
	void Epouser(const char* nom);
	void Demenager(const char* rue);
	friend std::ostream& operator<<(std::ostream& stream, Personne& personne);

protected:
	std::string nom;
	Adresse adresse;
	Date dateNaissance;

	virtual void Afficher(std::ostream& stream);
	
};
