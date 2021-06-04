#include "Client.h"
#include "AdministrareFisiere.h"

Client Client::AdaugaClient()
{
	string nume, prenume, input;
	FORMATROW;
	do
	{
		cout << FORMAT3"Introduceti numele: ";
		cin >> nume;
	} while (!ValidareString(nume));
	cin.seekg(0, ios::end);//in caz ca sunt introduse 2 cuvinte
	cin.clear();
	do
	{
		cout << FORMAT3"Introduceti prenumele: ";
		cin >> prenume;
	} while (!ValidareString(prenume));
	cin.seekg(0, ios::end);
	cin.clear();
	for (auto& c : nume) c = toupper(c);
	for (auto& c : prenume) c = toupper(c);
	Client clientNou(nume, prenume);

	bool tipAles = false;
	do
	{
		cout << FORMAT3"Alegeti tipul abonamentului: 1 - Standard 2 -Premium\n";
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
			INVALID;
			cout << endl;
			Sleep(1500);
			continue;
		}
	}while (tipAles == false);
	time_t acum = time(0);
	clientNou.abonamentActivat = acum;

	cout << endl << FORMAT3"    \033[1;32mAbonatul a fost inregistrat cu succes.\033[0m";
	/*tm* ltm = localtime(&acum);

	cout << "Year:" << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;
	cout << "Time: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;*/

	return clientNou;
}

void Client::AfisareListaAbonati(list<Client> listaClienti)
{
	if (listaClienti.empty())
	{
		cout << "- GOL - ";
		return;
	}
	FORMATROW;
	cout << FORMAT1"|" underline << setw(5) << left << "COD" << setw(15) << left << "NUME" << setw(15) << left << "PRENUME" << setw(11) << left << "ABONAMENT" << setw(10) << left << "VALIDITATE" << "\033[0m|" <<  endl;
	for (list<Client>::iterator it = listaClienti.begin(); it != listaClienti.end(); ++it)
	{
		cout << FORMAT1"|" underline << it->ConvertToString2() << "\033[0m|" << "\n";
	}
	cout << "\033[0m";

}

string Client::ConvertToString()
{
	std::ostringstream table;
	table << setw(4) << left << "ID:" << setw(4) << left << cod
		<< setw(6) << left << "Nume:" << setw(20) << left << nume
		<< setw(9) << left << "Prenume:" << setw(20) << left << prenume
		<< setw(11) << left << "Abonament:" << setw(20) << left << tipAbonament;
	time_t acum = time(0);
	if(abonamentActivat  + zile30 > acum)
		table << setw(12) << left << "Validitate:" << setw(10) << left << "ACTIVAT";
	else
		table << setw(12) << left << "Validitate:" << setw(10) << left << "\033[0;31mDEZACTIVAT\033[0m";

		//return "ID: " + to_string(cod) + " \t Nume: " + nume + " \t Prenume: " + prenume + " \t Abonament: " + tipAbonament;
		string s = table.str();
		return s;
}

string Client::ConvertToString2()
{
	std::ostringstream table;
	table << setw(5) << left << cod << setw(15) << left << nume << setw(15) << left << prenume  << setw(11) << left << tipAbonament;
	time_t acum = time(0);
	if (abonamentActivat + zile30 > acum)
		table << setw(10) << left << "ACTIVAT";
	else
		table << setw(13) << left << "\033[0;31m\033[4mDEZACTIVAT\033[0m";

	//return "ID: " + to_string(cod) + " \t Nume: " + nume + " \t Prenume: " + prenume + " \t Abonament: " + tipAbonament;
	string s = table.str();
	return s;
}

std::string Client::ConversieSirFisier()
{
	stringstream ss;
	ss << abonamentActivat;
	return to_string(cod) + " " + nume + " " + prenume + " " + tipAbonament + " " + ss.str();
}

void Client::StatisticaAbonamente(list<Client> listaClienti)
{
	int abonamentStandard = 0, abonamentPremium = 0;
	int abonamenteActivate = 0;
	time_t acum = time(0);
	for (list<Client>::iterator it = listaClienti.begin(); it != listaClienti.end(); ++it)
	{
		if (it->tipAbonament == abonament1)
			abonamentStandard++;
		if (it->tipAbonament == abonament2)
			abonamentPremium++;
		if (it->abonamentActivat + zile30 > acum)
			abonamenteActivate++;
	}
	std::ostringstream table;
	FORMATROW;

	table << FORMAT1 underline"|" << setw(15) << left << "Nr. Abonamente " << setw(9) << left << "Standard" << setw(8) << left << "Premium" << setw(9) << left << "Activate" << setw(11) << left << "Dezactivate|"; 
	table << "\n" << FORMAT1 underline"|" << setw(6) << left << " " << setw(12) << left << listaClienti.size() << setw(9) << left << abonamentStandard << setw(8) << left << abonamentPremium << setw(9) << left << abonamenteActivate
		  << setw(8) << left << to_string(listaClienti.size() - abonamenteActivate) << "|\033[0m";
	string text = table.str();
	cout << text;
	FORMATROW;
}

//Client Client::CautareClient(list<Client> listaClienti)
//{
//	if (listaClienti.empty())
//		return;
//	string codIntrodus;
//	//AfisareListaAbonati(listaClienti);
//	cout << "Cautare abonat" << endl;
//	cout << "Introduceti codul: ";
//	cin >> codIntrodus;
//	if (ValidareNumar(codIntrodus) == false)
//	{
//		cout << "Codul a fost introdus incorect." << endl;
//		return;
//	}
//	int codSelectat = stoi(codIntrodus);
//
//	for (list<Client>::iterator it = listaClienti.begin(); it != listaClienti.end(); it++)
//	{
//		if (codSelectat == it->cod)
//			return *it;
//	}
//	cout << "Abonatul cu codul introdus nu exista.";
//}

void Client::ActivareAbonament(list<Client>& listaClienti)
{
	if (listaClienti.empty())
		return;
	string codIntrodus;
	bool abonamenteDezactivate = false;
	FORMATROW;
	for (list<Client>::iterator it = listaClienti.begin(); it != listaClienti.end(); it++)
	{
		time_t acum = time(0);
		if (it->abonamentActivat + zile30 <= acum)
		{
			cout << setw(4) << left << "ID:" << setw(6) << left << it->cod;
			cout << setw(6) << left << "Nume:" << setw(20) << left << it->nume;
			cout << setw(9) << left << "Prenume:" << setw(20) << left << it->prenume;
			cout << setw(11) << left << "Abonament:" << setw(20) << left << it->tipAbonament;
			cout << setw(12) << left << "Validitate:" << setw(10) << left << "\033[0;31mDEZACTIVAT\033[0m" << endl;
			abonamenteDezactivate = true;
		}
	}
	if (abonamenteDezactivate == false)
	{
		cout << FORMAT2"\033[1;31mNu exista abonamente dezactivate\033[0m" << endl;
		return;
	}
	 
	//cout << "Cautare abonat" << endl;
	cout << endl << FORMAT2"Introduceti codul: ";
	cin >> codIntrodus;
	if (ValidareNumar(codIntrodus) == false)
	{
		cout <<  FORMAT3"    \033[1;31mCodul a fost introdus incorect\033[0m" << endl;
		return;
	}
	int codSelectat = stoi(codIntrodus);

	for (list<Client>::iterator it = listaClienti.begin(); it != listaClienti.end(); it++)
	{
		if (codSelectat == it->cod)
		{
			time_t acum = time(0);
			if (it->abonamentActivat + zile30 > acum)
			{
				cout << endl << FORMAT3"    \033[1;31mAbonamentul este deja activat\033[0m";
			}
			else
			{
				cout << FORMAT3"    Doriti sa activati abonamentul? [Y/N] " << endl;
				switch (toupper(_getch()))
				{
				case 'Y':
					it->abonamentActivat = acum + zile30;
					cout << FORMAT3"    \033[1;32mAbonamentul a fost activat cu succes\033[0m" << endl; //\033[1; 32mAbonatul a fost inregistrat cu succes.\033[0m
					AdministrareFisiere::RescrieFisierClienti(listaClienti);
					return;
					break;
				case 'N':
					return;
					break;
				default:
					INVALID;
					Sleep(1500);
					continue;
				}
			}
		}
	}
	cout << FORMAT3 "    \033[1;31mAbonatul cu codul introdus nu exista\033[0m";
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