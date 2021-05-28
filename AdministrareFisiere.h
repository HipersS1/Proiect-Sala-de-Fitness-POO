#pragma once
#include "Client.h"
#include "Angajat.h"

class AdministrareFisiere
{
private:
	static string numeFisierClienti;
	static string numeFisierAngajati;
public:
	static void AdaugaClientFisier(Client c);
	static void AdaugaAngajatFisier(Angajat a);

	static list<Client> CitesteFisierClienti();
	static list<Angajat> CitesteFisierAngajati();
	static void RescrieFisierAngajati(list<Angajat> listaAngajati);
};

