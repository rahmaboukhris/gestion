#pragma once
#include "Salarie.h"

class Directeur : public Salarie {

public:
	Directeur();
	Directeur(unsigned nbPersonnes, const char* service);
	~Directeur() override = default;

protected:
	unsigned nbPersonnes;
	std::string service;
	void Afficher(std::ostream& stream) override;
};

