#include "Client.h"

Client Client::AdaugaClient()
{
	string nume, prenume, input;
	do
	{
		cout << FORMAT1"Introduceti numele: ";
		cin >> nume;
	} while (!ValidareString(nume));
	cin.seekg(0, ios::end);//in caz ca sunt introduse 2 cuvinte
	cin.clear();
	do
	{
		cout << FORMAT1"Introduceti prenumele: ";
		cin >> prenume;
	} while (!ValidareString(prenume));
	cin.seekg(0, ios::end);
	cin.clear();
	for (auto& c : nume) c = toupper(c);
	for (auto& c : prenume) c = toupper(c);
	Client clientNou(nume, prenume);

	bool tipAles = false;
	{
		cout << "Alegeti tipul abonamentului: 1 - Standard 2 -Premium\n";
		switch (toupper(_getch()))
		{
		case '1':
			clientNou.tipAbonament = abonament1;
			tipAles = true;
			break;
		case '2':
			clientNou.tipAbonament = abonament2;
			tipAles = true;
			break;
		default:
			cout << "Optiune invalida\n";
			break;
		}
	}while (tipAles == false);
	
	return clientNou;
}

void Client::AfisareListaAbonati(list<Client> listaClienti)
{
	if (listaClienti.empty())
	{
		cout << "- GOL - ";
		return;
	}

	for (list<Client>::iterator it = listaClienti.begin(); it != listaClienti.end(); ++it)
	{
		cout << it->ConvertToString() << "\n";
	}
}

string Client::ConvertToString()
{
	std::ostringstream table;
	table << setw(4) << left << "ID:" << setw(10) << left << cod
		  << setw(6) << left << "Nume:" << setw(20) << left << nume
		  << setw(9) << left << "Prenume:" << setw(20) << left << prenume
		  << setw(11) << left << "Abonament:" << setw(20) << left << tipAbonament;
		//return "ID: " + to_string(cod) + " \t Nume: " + nume + " \t Prenume: " + prenume + " \t Abonament: " + tipAbonament;
		string s = table.str();
		return s;
}

std::string Client::ConversieSirFisier()
{
	return to_string(cod) + " " + nume + " " + prenume + " " + tipAbonament;
}

void Client::StatisticaAbonamente(list<Client> listaClienti)
{
	int abonamentStandard = 0, abonamentPremium = 0;

	for (list<Client>::iterator it = listaClienti.begin(); it != listaClienti.end(); ++it)
	{
		if (it->tipAbonament == abonament1)
			abonamentStandard++;
		if (it->tipAbonament == abonament2)
			abonamentPremium++;
	}

	cout << "\n" << "Statistica abonamente" << endl;
	cout << "Total abonamente: " << listaClienti.size() << endl;
	cout << "Standard: " << abonamentStandard << endl;
	cout << "Premium: " << abonamentPremium << endl;
}

int Client::RandomCod(list<Client> listaPersoane)
{
	int randCod;
	srand(time(0));
	if (listaPersoane.empty())
	{
		randCod = rand() % 1000 + 100;
		return randCod;
	}
	bool codNouGasit = false;
	do
	{
		codNouGasit = true;
		randCod = rand() % 1000 + 100;
		for (list<Client>::iterator it = listaPersoane.begin(); it != listaPersoane.end(); it++)
		{
			if (randCod == it->cod)
			{
				codNouGasit = false;
				break;
			}
		}
	} while (codNouGasit == false);

	return randCod;
}