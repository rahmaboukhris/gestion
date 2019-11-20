#include "Personne.h"
#include <iostream>

Personne::Personne(const char* nom, int jour, int mois, int an, const char* rue, const char* codePostal,
	const char* ville) : nom(nom), adresse(codePostal, ville, rue), dateNaissance(jour, mois, an) {
	
}

Personne::Personne(const char* nom, const Date& dateNaissance, const Adresse& adresse)
: nom(nom), adresse(adresse), dateNaissance(dateNaissance) {
}

Personne::~Personne() = default;

void Personne::Afficher() const {
	std::cout << nom << "   ";
	dateNaissance.Afficher();
	adresse.Afficher();
}

int Personne::Age() const {
	return Date().yearDiff(dateNaissance);
}

void Personne::Epouser(const char* nom) {
	this->nom = nom;
}

void Personne::Demenager(const char* rue) {
	adresse.MettreAJourLaRue(rue);
}

void Personne::Afficher(std::ostream& stream) {
	stream << "Nom : " << this->nom << "\n" << "Date de naissance : " << this->dateNaissance << "\n";
}

std::ostream& operator<<(std::ostream& stream, Personne& personne) {
	personne.Afficher(stream);
	return stream;
}
