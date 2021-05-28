#include "AdministrareFisiere.h"

string AdministrareFisiere::numeFisierClienti = "Clienti.txt";
string AdministrareFisiere::numeFisierAngajati = "Angajati.txt";

void AdministrareFisiere::AdaugaClientFisier(Client c)
{
	ofstream f;
	f.open(numeFisierClienti, std::ios_base::app);

	if (f.fail())
	{
		cout << "Fisierul nu a putut fi deschis.";
		return;
	}
	else
		f << c.ConversieSirFisier() << endl;
	f.close();
}

void AdministrareFisiere::AdaugaAngajatFisier(Angajat a)
{
	ofstream f;
	f.open(numeFisierAngajati, std::ios_base::app);

	if (f.fail())
	{
		cout << "Fisierul nu a putut fi deschis.";
		return;
	}
	else
		f << a.ConversieSirFisier() << endl;
	f.close();
}

std::list<Client> AdministrareFisiere::CitesteFisierClienti()
{
	ifstream f;
	f.open(numeFisierClienti);
	string line_info, input_result;
	vector<string> vectorString;
	list<Client> listaClienti;
	if(!f.fail()) // has the file
	{
		while(getline(f, line_info)) // line breaks are not included in the line
		{
			stringstream input(line_info);
			while (input >> input_result)
				vectorString.push_back(input_result);

			Client newClient(vectorString[1], vectorString[2]);
			newClient.setCod(stoi(vectorString[0]));
			newClient.setTipAbonament(vectorString[3]);
			listaClienti.push_back(newClient);

			vectorString.clear();
		}
		f.close();
	}
	else
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}
	return listaClienti; 
}

std::list<Angajat> AdministrareFisiere::CitesteFisierAngajati()
{
	ifstream f;
	f.open(numeFisierAngajati);
	string line_info, input_result;
	vector<string> vectorString;
	list<Angajat> listaAngajati;
	if (!f.fail())
	{
		while (getline(f, line_info))
		{
			stringstream input(line_info);
			while (input >> input_result)
				vectorString.push_back(input_result);

			Angajat newAngajat(vectorString[1], vectorString[2]);
			newAngajat.setCod(stoi(vectorString[0]));
			newAngajat.setFunctie(vectorString[3]);
			newAngajat.setProgramMunca(vectorString[4]);

			listaAngajati.push_back(newAngajat);

			vectorString.clear();
		}
		f.close();
	}
	else
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}
	return listaAngajati;
}

void AdministrareFisiere::RescrieFisierAngajati(list<Angajat> listaAngajati)
{
	ofstream f;
	f.open(numeFisierAngajati, ios::out | ios::trunc);

	if (f.fail())
	{
		cout << "Fisierul nu a putut fi deschis.";
		return;
	}
	else
	{
		for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); it++)
		{
			f << it->ConversieSirFisier() << endl;
		}
	}
	f.close();
}
