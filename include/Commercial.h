#pragma once
#include "Salarie.h"

class Commercial : public Salarie {


public:
	~Commercial() override = default;
	Commercial(double vente, double commission);
	void MajVent(double vente);


protected:
	void Afficher(std::ostream& stream) override;
	double commission;
	double vente;
};