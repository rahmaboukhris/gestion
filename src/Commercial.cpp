#include "Commercial.h"

/**
 * \brief 
 * \param vente 
 * \param commission 
 */
Commercial::Commercial(const double vente, const double commission) : vente(vente), commission(commission) {
}

void Commercial::MajVent(const double vente) {
	this->vente = vente;
}

void Commercial::Afficher(std::ostream& stream) {
	Salarie::Afficher(stream);
	stream << "Ventes : " << vente << "\n" << "Commission : " << commission << "\n";
}
