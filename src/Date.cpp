/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 10 déc. 2008
    copyright            : (C) 2008 par pcoquard
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <ctime>
#include <string>
//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes
int Date::nbjours[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string Date::nomdumois[]={"JANVIER","FEVRIER","MARS","AVRIL","MAI","JUIN",
	"JUILLET","AOUT","SEPTEMBRE","OCTOBRE","NOVEMBRE","DECEMBRE"};
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Date::Modifier(int nouveauJour, int nouveauMois, int nouveauAn)
{
#ifdef MAP
cout << "Date::Modifier()"<<endl;
#endif
  // a faire : les memes tests de validite que dans le constructeur!!
  jour=nouveauJour;
  mois=nouveauMois;
  an=nouveauAn;
}

void Date::Afficher() const
{
#ifdef MAP
cout << "Date::Afficher()"<<endl;
#endif
  cout.width(2);cout.fill('0');cout.setf(ios::right,ios::adjustfield);
  cout<<jour<<"/";
  cout.fill('*');cout.setf(ios::left,ios::adjustfield); cout.width(10);
  cout<<nomdumois[mois-1].c_str()<<"/";
  cout.width(4);cout.fill('0');cout.setf(ios::right, ios::adjustfield);
  cout<<an<<endl;
}

int Date::Annee() const
{
	return an;
}

int Date::yearDiff(const Date& date) const {
	auto yearDiff = this->an - date.an;
	if (this->isAfter(date)) {
		if (this->mois < date.mois || (this->mois == date.mois && this->jour < date.jour)) {
			--yearDiff;
		}
	} else {
		if (this->mois > date.mois || (this->mois == date.mois && this->jour > date.jour)) {
			++yearDiff;
		}
	}
	return yearDiff;
}

bool Date::isAfter(const Date& date) const {
	return this->an > date.an || (this->an == date.an && (this->mois > date.mois || (this->mois == date.mois && this->jour > date.jour)));
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Date::Date(): Date(0, 0, 0) {
	
}

Date::Date(int jour, int mois, int an)
{
  // pour connaitre la date systeme locale, utiliser la struct tm :
  /*
   int tm_sec;    // Seconds after the minute - [0,59]
   int tm_min;    // Minutes after the hour - [0,59]
   int tm_hour;   // Hours since midnight - [0,23]
   int tm_mday;   // Day of the month - [1,31]
   int tm_mon;    // Months since January - [0,11]
   int tm_year;   // Years since 1900
   int tm_wday;   // Days since Sunday - [0,6]
   int tm_yday;   // Days since January 1 - [0,365]
   int tm_isdst;  // Daylight-saving-time flag
*/
  int max; // nb jours du mois tenant compte des annees bissextiles
  bool erreur = false;
  struct tm *aujourdhui;
  time_t today;
  time( &today ); 	             	// donne la date en secondes dans un entier long today
  aujourdhui  = localtime( &today );	// convertit les secondes en jour, mois, an dans la structure aujourd'hui
  this->jour =  jour ? jour : aujourdhui->tm_mday;
  this->mois =  mois ? mois : aujourdhui->tm_mon+1 ;
  this->an   =  an ? an : aujourdhui->tm_year+1900;
  // on verifie l'année
  if ( this->an < 0 )
  {
	  erreur = true;
  }
  // on verifie le mois
  if ( this->mois < 0 || this->mois > 12 )
  {
	  erreur=true;
  }
  // on verifie le jour
  max = nbjours[this->mois-1];
  if (  // annee bissextile
  	((this->an % 400 == 0) ||  ( (this->an % 100!=0) && (this->an%4==0) ) )
  	// et fevrier
  	&& this->mois ==2 )
  {
	max++;
  }
  if ( this->jour < 0 || this->jour > max )
  {
	erreur = true;
  }
  if (erreur == true)
  {
	this->an=aujourdhui->tm_year+1900;
	this->mois = aujourdhui->tm_mon+1;
	this->jour = aujourdhui->tm_mday;
  }
}

Date::Date(const Date& date) {
	this->jour = date.jour;
	this->mois = date.mois;
	this->an = date.an;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
ostream& operator<<(ostream& stream, const Date& date) {
	stream << date.jour << '/' << date.mois << '/' << date.an;
	return stream;
}
