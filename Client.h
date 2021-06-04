#pragma once
#include "Persoana.h"
#define abonament1 "STANDARD"
#define abonament2 "PREMIUM"


class Client : public Persoana
{
private:
	string tipAbonament;
	time_t abonamentActivat;
public:
	Client(const string& Nume,const string& Prenume)
	{
		nume = Nume;
		prenume = Prenume;
	}

	Client() {};
	
	void setNume(const string& Nume){ nume = Nume;}
	string getNume() { return nume; }

	void setTipAbonament(const string& TipAbonament) { tipAbonament = TipAbonament; }
	string getTipAbonament() { return tipAbonament; }

	void setCod(int Cod) { cod = Cod; }
	void setDataActivare(string s) { abonamentActivat = stoi(s); }

	//Adaugare Actualizare
	static Client AdaugaClient();
	static void ActivareAbonament(list<Client>& listaClienti);

	//Afisare
	static void AfisareListaAbonati(list<Client> listaClienti);
	string ConvertToString();
	string ConvertToString2();
	string ConversieSirFisier();
	static void StatisticaAbonamente(list<Client> listaClienti );


	static Client CautareClient(list<Client> listaClienti);
	static int RandomCod(list<Client> listaPersoane);
};

