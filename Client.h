#pragma once
#include "Persoana.h"
#define abonament1 "STANDARD"
#define abonament2 "PREMIUM"


class Client : public Persoana
{
private:
	string tipAbonament;
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


	static Client AdaugaClient();
	static void AfisareListaAbonati(list<Client> listaClienti);
	string ConvertToString();
	string ConversieSirFisier();
	static void StatisticaAbonamente(list<Client> listaClienti );

	static int RandomCod(list<Client> listaPersoane);
};

