#include "Echipament.h"
#include "AdministrareFisiere.h"
const int NUME = 3;
const int NUMEMAX = 25;

Echipament Echipament::AdaugaEchipament()
{
	vector<string> buffer;
	string nume;
	string perioada;
	FORMATROW;
	cin.seekg(0, ios::end);
	cin.clear();
	do
	{
		cout << FORMAT3"Introduceti numele echipamentului: ";
		getline(cin, nume);
		if (nume.length() > NUME && nume.length() <= NUMEMAX)
		{
			for (int i = 0; i < nume.length(); i++)
			{
				if (isspace(nume[i]))
					nume[i] = '_';
			}
			break;
		}
		
	} while (true);
	for (auto& c : nume) c = toupper(c);
	Echipament echipament(nume);
	bool tipAles = false;
	do
	{
		cout << FORMAT3"Alegeti tipul abonamentului\n";
		cout << FORMAT3"1 - Cardio 2 - Rezistenta 3 - Greutati\n";
		switch (toupper(_getch()))
		{
		case '1':
			echipament.categorie = Cardio;
			tipAles = true;
			break;
		case '2':
			echipament.categorie = Rezistenta;
			tipAles = true;
			break;
		case '3':
			echipament.categorie = Greutati;
			tipAles = true;
			break;
		default:
			INVALID;
			cout << endl;
			Sleep(1500);
			continue;
		}
	} while (tipAles == false);
	
	do
	{
		cin.seekg(0, ios::end);//in caz ca sunt introduse 2 cuvinte
		cin.clear();
		cout << FORMAT3"Introduceti perioada de revizie (1-12): ";
		cin >> perioada;
		
		if (ValidareNumar(perioada))
		{
			int n = stoi(perioada);
			if (n >= 1 && n <= 12)
			{
				echipament.perioadaRevizie = n;
				break;
			}
		}
		cout << FORMAT3"\033[0;31mAlegeti o perioada intre 1 - 12 luni\033[0m\n";
	} while (true);
	time_t acum = time(0);
	echipament.dataRevizie = acum + echipament.perioadaRevizie * zile30;
	return echipament;
}

void Echipament::ActualizareRevizie(list<Echipament> listaEchipamente)
{
	if (listaEchipamente.empty())
	{
		cout << FORMAT4"\b\b\b\033[0;31mBaza de date este goala\033[0m" << endl;
		return;
	}
	string codIntrodus;
	bool necesitaRevizie = false;
	FORMATROW;
	time_t acum = time(0);
	bool header = false;
	for (list<Echipament>::iterator it = listaEchipamente.begin(); it != listaEchipamente.end(); it++)
	{
		if (it->dataRevizie + zile30 * it->perioadaRevizie <= acum)
		{
			if (header == false)
			{
				header = true;
				cout << FORMAT1 "|" underline << setw(6) << left << "Cod" << setw(NUMEMAX) << left << "Nume" << setw(13) << left << "Categorie" << setw(17) << left << "Perioada Revizie" << setw(14) << left << "Stare Revizie" << "\033[0m|" << endl;
			}
			necesitaRevizie = true;
			cout << it->ConversieSir2() << endl;
		}
	}
	if (necesitaRevizie == false)
	{
		cout << FORMAT2"\b\b\b\b\033[1;31mNu exista ehipamente ce necesita revizie\033[0m" << endl;
		return;
	}

	cout << endl << FORMAT3"Introduceti codul: ";
	cin >> codIntrodus;
	if (ValidareNumar(codIntrodus) == false)
	{
		cout << FORMAT3"    \033[1;31mCodul a fost introdus incorect\033[0m" << endl;
		return;
	}
	int codSelectat = stoi(codIntrodus);

	for (list<Echipament>::iterator it = listaEchipamente.begin(); it != listaEchipamente.end(); it++)
	{
		if (codSelectat == it->cod)
		{
			if (it->dataRevizie + zile30*it->perioadaRevizie > acum)
			{
				cout << endl << FORMAT3"    \033[1;31mNu e necesara revizia\033[0m";
			}
			else
			{
				cout << FORMAT3"    Doriti sa actualizati revizia? [Y/N] " << endl;
				switch (toupper(_getch()))
				{
				case 'Y':
					it->dataRevizie = acum + zile30 *it->perioadaRevizie;
					cout << FORMAT3"    \033[1;32mRevizia a fost actualizata cu succes\033[0m" << endl; //\033[1; 32mAbonatul a fost inregistrat cu succes.\033[0m
					AdministrareFisiere::RescrieFisierEchipament(listaEchipamente);
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
	cout << FORMAT3 "    \033[1;31mEchipamentul cu codul introdus nu exista\033[0m";
}

void Echipament::StergeEchipament(list<Echipament>& listaEchipamente)
{
	if (listaEchipamente.empty())
	{
		cout << FORMAT4"\b\b\b\033[0;31mBaza de date este goala\033[0m" << endl;
		return;
	}

	string codIntrodus;
	AfisareListaEchipamente(listaEchipamente);
	cout << endl << FORMAT3"    Introduceti codul: ";
	cin >> codIntrodus;
	if (ValidareNumar(codIntrodus) == false)
	{
		cout << FORMAT3"    \033[1;31mCodul a fost introdus incorect\033[0m" << endl;
		return;
	}
	int codSelectat = stoi(codIntrodus);

	for (list<Echipament>::iterator it = listaEchipamente.begin(); it != listaEchipamente.end(); it++)
	{
		if (codSelectat == it->cod)
		{
			listaEchipamente.remove(*it);
			AdministrareFisiere::RescrieFisierEchipament(listaEchipamente);
			cout << FORMAT3"    \033[0;32mEchipamentul cu codul " + to_string(codSelectat) + " a fost sters\033[0m" << endl;
			return;
		}
	}
	cout << FORMAT3"    \033[1;31mEchipamentul cu codul " + to_string(codSelectat) + " nu exista\033[0m" << endl;

}

int Echipament::RandomCod(list<Echipament> listaEchipamente)
{
	int randCod;
	srand(time(0));
	if (listaEchipamente.empty())
	{
		randCod = rand() % 9000 + 1000;
		return randCod;
	}
	bool codNouGasit = false;
	do
	{
		codNouGasit = true;
		randCod = rand() % 9000 + 1000;
		for (list<Echipament>::iterator it = listaEchipamente.begin(); it != listaEchipamente.end(); it++)
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

void Echipament::AfisareListaEchipamente(list<Echipament> listaEchipamente, int tip)
{
	if (listaEchipamente.empty())
	{
		cout << FORMAT4"\b\b\b\033[0;31mBaza de date este goala\033[0m" << endl;
		return;
	}
	FORMATROW;
	if (tip == 1)
	{
		cout << FORMAT1 "|" underline << setw(6) << left << "Cod" << setw(NUMEMAX) << left << "Nume" << setw(13) << left << "Categorie" << setw(17) << left << "Perioada Revizie" << "\033[0m|" << endl;
		for (list<Echipament>::iterator it = listaEchipamente.begin(); it != listaEchipamente.end(); ++it)
		{
			cout << it->ConversieSir() << "\n";
		}
		return;
	}
	cout << FORMAT1 "|" underline << setw(6) << left << "Cod" << setw(NUMEMAX) << left << "Nume" << setw(13) << left << "Categorie" << setw(17) << left << "Perioada Revizie" << setw(14) << left << "Stare Revizie" << "\033[0m|" << endl;

	for (list<Echipament>::iterator it = listaEchipamente.begin(); it != listaEchipamente.end(); ++it)
	{
		cout << it->ConversieSir2() << "\n";
	}
}

void Echipament::StatisticaEchipamente(list<Echipament> listaEchipmanete)
{
	int cardio = 0, rezistenta = 0, greutati = 0;
	int revizie = 0;
	time_t acum = time(0);
	for (list<Echipament>::iterator it = listaEchipmanete.begin(); it != listaEchipmanete.end(); ++it)
	{
		if (it->categorie == Cardio)
			cardio++;
		if (it->categorie == Rezistenta)
			rezistenta++;
		if (it->categorie == Greutati)
			greutati++;
		if (it->dataRevizie + zile30 * it->perioadaRevizie < acum)
			revizie++;
	}
	std::ostringstream table;
	FORMATROW;

	table << FORMAT1  "|" underline << setw(15) << left << "Nr. Echipamente " << setw(7) << left << "Cardio" << setw(11) << left << "Rezistenta" << setw(9) << left << "Greutati" << setw(17) << left << "Necesita revizie\033[0m|";
	table << "\n" << FORMAT1 "|" underline << setw(6) << left << " " << setw(12) << left << listaEchipmanete.size() << setw(9) << left << to_string(cardio) << setw(11) << left << to_string(rezistenta) << setw(13) << left << to_string(greutati)
		<< setw(8) << left << to_string(revizie) << "\033[0m|";
	string text = table.str();
	cout << text;
	FORMATROW;

}

std::string Echipament::ConversieSir()
{
	std::ostringstream table;
	table << FORMAT1 "|" underline << setw(6) << left << cod << setw(NUMEMAX) << left << ConversieNumeFaraBara(nume) << setw(13) << left << getCategorie() << setw(17) << left << perioadaRevizie << "\033[0m|";

	return table.str();
}

std::string Echipament::ConversieSir2()
{
	std::ostringstream table;
	table << FORMAT1 "|" underline << setw(6) << left << cod << setw(NUMEMAX) << left << ConversieNumeFaraBara(nume) << setw(13) << left << getCategorie() << setw(17) << left << perioadaRevizie;
	time_t acum = time(0);

	if (dataRevizie + zile30 * perioadaRevizie > acum)
		table << setw(14) << left << "OK" << "\033[0m|";
	else
		table << setw(33) << left << "\033[0;31m\033[4mVerifica\033[0m" underline << "\033[0m|";

	return table.str();
}

std::string Echipament::ConversieSirFisier()
{
	//stringstream ss;
	return to_string(cod) + " " + nume + " " + to_string(categorie) + " " + to_string(perioadaRevizie) + " " + to_string(dataRevizie);
}

string Echipament::ConversieNumeFaraBara(string nume)
{
	for (int i = 0; i < nume.length(); i++)
	{
		if (nume[i] == '_')
			nume[i] = ' ';
	}
	return nume;
}