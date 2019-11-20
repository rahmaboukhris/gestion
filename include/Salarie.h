#pragma once
#include "Date.h"
#include "Personne.h"
#include <iostream>

class Salarie : public Personne {


public:
	constexpr static double SMIC = 1000.0;
	Salarie();
	explicit Salarie(const char* nom, int jour, int mois, int an, double salaire);
	void Augmenter(double montant);

protected:
	void Afficher(std::ostream& stream) override;
	Date dateEmbauche;
	double salaire;
};
