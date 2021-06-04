#pragma once
#include "Client.h"
#include "Angajat.h"
#include "Echipament.h"

class AdministrareFisiere
{
private:
	static string numeFisierClienti;
	static string numeFisierAngajati;
	static string numeFisierEchipament;
public:
	static void AdaugaClientFisier(Client c);
	static void AdaugaAngajatFisier(Angajat a);
	static void AdaugaEchipamentFisier(Echipament e);

	static list<Client> CitesteFisierClienti();
	static list<Angajat> CitesteFisierAngajati();
	static list<Echipament> CitesteFisierEchipament();

	static void RescrieFisierAngajati(list<Angajat> listaAngajati);
	static void RescrieFisierClienti(list<Client> listaClienti);
	static void RescrieFisierEchipament(list<Echipament> listaEchipament);
};

