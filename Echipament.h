#pragma once
#include "Header.h"

enum CategorieEchipament{ Cardio = 1, Rezistenta = 2, Greutati = 3};

class Echipament
{
private:
	int cod;
	int perioadaRevizie;
	string nume;
	CategorieEchipament categorie;
	time_t dataRevizie;
public:
	//Constructori
	Echipament(string nume) { this->nume = nume; }
	Echipament() {};

	//Getter & Setter
	void setCod(int value) { cod = value; }
	void setPerioadaRevizie(int value) { perioadaRevizie = value; }
	void setNume(string value) { nume = value; }
	void setRevizie(string value) { dataRevizie = stoi(value); }
	void setCategorie(int value) { categorie = static_cast<CategorieEchipament>(value); }
	string getCategorie() {
		if (categorie == Cardio)
			return "Cardio";
		if (categorie == Rezistenta)
			return "Rezistenta";
		if (categorie == Greutati)
			return "Greutati";
		return "NONE";
	}
	//Afisare
	static void AfisareListaEchipamente(list<Echipament> listaEchipamente,int tip = 1);
	string ConversieSir();
	string ConversieSir2();
	string ConversieSirFisier();
	static void StatisticaEchipamente(list<Echipament> listaEchipmanete);

	//Adaugare//ACTUALIZARE//
	static Echipament AdaugaEchipament();
	static void ActualizareRevizie(list<Echipament> listaEchipamente);
	static void StergeEchipament(list<Echipament>& listaEchipamente);
	string ConversieNumeFaraBara(string nume);

	static int RandomCod(list<Echipament> listaEchipamente);
	bool operator == (const Echipament& a) const
	{
		return cod == a.cod && nume == a.nume && categorie == a.categorie && perioadaRevizie == a.perioadaRevizie && dataRevizie == a.dataRevizie;
	}
};

