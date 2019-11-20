//============================================================================
// Name        : TClassesDuProjet.cpp
// Author      : psc
// Version     : 2012
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "Date.h"
#include <iostream>
#include "Adresse.h"
#include "Personne.h"
#include "Salarie.h"
#include "Commercial.h"
#include "Directeur.h"
#include "Log.h"

void testAdresse()
{
  std::cout << "tests de la classe adresse :"<<std::endl;
  //creation d'un objet adresse non initialise :
  Adresse sans;
  std::cout<< "adresse non initialisee : ";
  sans.Afficher();
  std::cout << std::endl;

  //initialisation de cet objet :
  sans.MettreAJour("12345", "PARIS" );
  std::cout<< "adresse apres initialisation : ";
  sans.Afficher();
  std::cout << std::endl;

  //initialisation de cet objet :
  sans.MettreAJourLaRue("Place des vosges" );
  std::cout<< "adresse apres initialisation : ";
  sans.Afficher();
  std::cout << std::endl;

  std::cout<< "instanciation avec bonne initialisation :  ";
  Adresse loin( "29", "Quimper", "3 rue des prunelles");
  loin.Afficher();
  std::cout << std::endl;

}

void testDate()
{
  std::cout<<"tests de la classe date"<<std::endl;
  //creation d'un objet date non initialise :
  Date vide;
  std::cout<< "date vide : ";
  vide.Afficher();
  std::cout << std::endl;

  //creation d'un objet date erronne :
  Date fausse(56,13,-33);
  std::cout<< "date erronnee rectifiee en : ";
  fausse.Afficher();
  std::cout << std::endl;

  //creation d'un objet date erronne annee non bissextile :
  Date fausse2(29,2,1900);
  std::cout<< "date erronnee annee non bissextile rectifiee en  : ";
  fausse2.Afficher();
  std::cout << std::endl;

  //creation d'un objet date annee bissextile :
  Date autre(29,2,2000);
  std::cout<< "date  annee bissextile  : ";
  autre.Afficher();
  std::cout << std::endl;

  Date autre2(1,1,2001);
  std::cout<< "date autre : ";
  autre2.Afficher();
  autre2.Modifier(2,2,2002);
  autre2.Afficher();
  std::cout << "c etait en l'an : " << autre2.Annee() << std::endl;
  std::cout << std::endl;
}


void testPersonne()
{
	  std::cout << "tests de la classe personne :"<<std::endl;
	  std::cout << "tests du constructeur I :"<<std::endl;
	  Personne p1("Dupont", 1,1,1933);
	  std::cout << "test methode Afficher :"<<std::endl;
	  p1.Afficher();		
	  std::cout << "test methode Epouser :"<<std::endl;
	  p1.Epouser("Moulinot");             
	  std::cout << "test methode Demenager :"<<std::endl;
	  p1.Demenager("12 rue du Port");
	  std::cout<<"***** p1 apres mariage et demenagement :";
	  p1.Afficher();		
	  std::cout << "test methode Age :"<<std::endl;
	  std::cout << "Age de p1 : " << p1.Age()<<std::endl;

	  Date d1(2,2, 1992);
	  Adresse a1("69100", "Villeurbanne", "20 avenue Albert Einstein");
	  std::cout << "tests du constructeur II :"<<std::endl;
	  Personne p2("Dupont", d1, a1);
	  p2.Afficher();

}



void testSalarie()
{

	  // liste du personnel simplifiee allouée a la compilation
	  // sous forme d'un tableau de pointeurs sur Personne
	  Personne * personnel[10];

	  auto *pt1= new Personne("Dupont");
	  pt1->Epouser("LENORMAND");
	  pt1->Demenager("12 rue du Port");
	  personnel[0]=pt1;
	  Personne p1("Dupont");
	  personnel[1]=&p1;


	  std::cout << "tests de la classe Salarie"<<std::endl;
	  std::cout << "test du constructeur I :"<<std::endl;
	  auto pt2= new Salarie("RICH", 1,1,1970, 1000.0 ); // date de naissance ou embauche ?:)
	  pt2->Augmenter(15000.0);
	
	  personnel[2]=pt2;
	  Salarie p2("PLUSRICH", 1,1, 1990, 2000.0);
	  
	  personnel[3]=&p2;
	  const int nbPersonnes = 4;
	  std::cout << "*****liste du personnel de l'entreprise : "<< std::endl;
	
	  for ( int i=0;i<nbPersonnes;i++) {
	  		std::cout << *personnel[i];
	  }
	  std::cout << "*****fin de liste du personnel de l'entreprise"<<std::endl;
	  delete pt1;
	  delete pt2;

	  std::cout<<"***** c'est fini "	<<std::endl;
	  
}

void testCommercial() {
	std::cout << "Test Commercial *********************************" << std::endl;
	
	auto commercial = new Commercial(5000, 8000);

	std::cout << *commercial << std::endl;
	commercial->MajVent(4e3);
	std::cout << *commercial << std::endl;

	delete commercial;
}

void testDirecteur() {
	std::cout << "Test Directeur *********************************" << std::endl;
	auto directeur = new Directeur(50, "Marketing");
	std::cout << *directeur;
	delete directeur;
}


int main() {
	LOG("Hello world"); // print nothing when MAP (like your project) is 0
	// testDate(); //OK
	 //testAdresse(); //OK
	//testPersonne(); // OK
	//testSalarie();  // OK
	//testCommercial(); // OK
	testDirecteur();
	return 0;
}
