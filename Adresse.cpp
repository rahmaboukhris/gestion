#include "Adresse.h"
#include <iostream>


void Adresse::MettreAJour(const char* codePostal, const char* ville, const char* rue) {
	this->codepostal = codePostal;
	if(strlen(ville) > 0) {
		this->ville = ville;
	}
	if(strlen(rue) > 0) {
		this->rue = rue;
	}
}

void Adresse::MettreAJourLaRue(const char* nouvelleRue) {
	this->rue = nouvelleRue;
}

void Adresse::Afficher() const {
	std::cout.fill('*');
	std::cout.width(LG_RUE);
	std:: cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << rue.c_str();
	std::cout.width(LG_COD);
	std::cout.fill('*');
	std::cout << codepostal.c_str();
	std::cout.width(LG_VIL);
	std::cout.fill('*');
	std::cout << ville.c_str() << std::endl;
}

Adresse::Adresse() : Adresse("69100", "Villeurbanne", "") {}

Adresse::Adresse(const char* codePostal, const char* ville, const char* rue) {
	this->codepostal = codePostal;
	this->ville = ville;
	this->rue = rue;
}

Adresse::Adresse(const Adresse& adresse) {
	this->codepostal = adresse.codepostal;
	this->ville= adresse.ville;
	this->rue = adresse.rue;
}
