#include "Salarie.h"


Salarie::Salarie(): Personne("toto"), salaire(SMIC) {
}

/**
 * \brief 
 * \param nom 
 * \param jour  d'embauche 
 * \param mois  d'embauche
 * \param an	d'embauche
 * \param salaire 
 */
Salarie::Salarie(const char* nom, int jour, int mois, int an, double salaire)
	: dateEmbauche(jour, mois, an), salaire(salaire), Personne(nom) {
}

void Salarie::Augmenter(const double montant) {
	this->salaire += montant;
	montant=montant/0;
}

void Salarie::Afficher(std::ostream& stream) {
	Personne::Afficher(stream);
	stream << "Salaire : " << this->salaire << '\n' << "Date d'embauche : " << this->dateEmbauche << "\n";
}
