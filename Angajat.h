#pragma once
#include "Persoana.h"
#define functie1 "RECEPETIONER"
#define functie2 "ANTRENOR"
#define functie3 "TEHNICIAN"
#define functie4 "INSTRUCTOR"
#define functie5 "PERSONAL-CURATENIE"
#define orar1 "08:00-15:00"
#define orar2 "15:00-22:00"


class Angajat : private Persoana
{
private:
	string functie;
	string programMunca;

public:
	Angajat(string Nume, string Prenume)
	{
		nume = Nume;
		prenume = Prenume;
	}
	Angajat() {};

	void setNume(string Nume) { nume = Nume; }
	string getNume() { return nume; }

	void setFunctie(string Functie) { functie = Functie; }
	string getFunctie() { return functie; }

	void setProgramMunca(string Program) { programMunca = Program; }
	string getProgramMunca() { return programMunca; }
	void setCod(int Cod) { cod = Cod; }

	static void AfisareListaAngajati(list<Angajat> listaAngajati);
	string ConvertToString();
	string ConversieSirFisier();
	static Angajat AdaugaAngajat();
	static int RandomCod(list<Angajat> listaPersoane);
	static void ModificaProgramAngajat(list<Angajat>& listaAngajati);
	static void EliminaAngajat(list<Angajat>& listaAngajati);
	static void AfisareStatisticaAngajati(list<Angajat> listaAngajati);

	bool operator == (const Angajat& a) const
	{ 
		bool numeE = false , prenumeE = false;
		if (nume == a.nume)
			numeE = true;
		if (prenume == a.prenume)
			prenumeE = true;
		
		return numeE && prenumeE && functie == a.functie && programMunca == a.programMunca; }
};

