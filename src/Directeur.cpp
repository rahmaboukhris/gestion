#include "Directeur.h"

Directeur::Directeur() : nbPersonnes(0) {
}

Directeur::Directeur(const unsigned nbPersonnes, const char* service): nbPersonnes(nbPersonnes), service(service) {
}

void Directeur::Afficher(std::ostream& stream) {
	Salarie::Afficher(stream);
	stream << "Service : " << service << "\n"
		<< "Nombre de personnes : " << nbPersonnes << "\n";
}
