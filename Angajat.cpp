#include "Angajat.h"
#include "AdministrareFisiere.h"

Angajat Angajat::AdaugaAngajat()
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
	Angajat angajatNou(nume, prenume);
	cout << "Alegeti functia angajatului\n"
		<< "1 - " << functie1 << endl
		<< "2 - " << functie2 << endl
		<< "3 - " << functie3 << endl
		<< "4 - " << functie4 << endl
		<< "5 - " << functie5 << endl;
	bool tipAles = false;
	{
		switch (toupper(_getch()))
		{
		case '1':
			angajatNou.functie = functie1;
			tipAles = true;
			break;
		case '2':
			angajatNou.functie = functie2;
			tipAles = true;
			break;
		case '3':
			angajatNou.functie = functie3;
			tipAles = true;
			break;
		case '4':
			angajatNou.functie = functie4;
			tipAles = true;
			break;
		case '5':
			angajatNou.functie = functie5;
			tipAles = true;
			break;
		default:
			cout << "Optiune invalida\n";
			break;
		}
	}while (tipAles == false);

	cout << "Alegeti programul de munca\n"
		<< "1 - " << orar1 << endl
		<< "2 - " << orar2 << endl;
	tipAles = false;
	{
		switch (toupper(_getch()))
		{
		case '1':
			angajatNou.programMunca = orar1;
			tipAles = true;
			break;
		case '2':
			angajatNou.programMunca = orar2;
			tipAles = true;
			break;
		default:
			cout << "Optiune invalida\n";
			break;
		}
	}while (tipAles == false);

	return angajatNou;
}

int Angajat::RandomCod(list<Angajat> listaPersoane)
{
	int randCod;
	srand(time(0));
	if (listaPersoane.empty())
	{
		randCod = rand() % 100 + 1;
		return randCod;
	}
	bool codNouGasit = false;
	do
	{
		codNouGasit = true;
		randCod = rand() % 100 + 1;
		for (list<Angajat>::iterator it = listaPersoane.begin(); it != listaPersoane.end(); it++)
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

void Angajat::ModificaProgramAngajat(list<Angajat>& listaAngajati)
{
	if (listaAngajati.empty())
		return;
	string codIntrodus;
	AfisareListaAngajati(listaAngajati);
	cout << "Introduceti codul: ";
	cin >> codIntrodus;
	if (ValidareNumar(codIntrodus) == false)
	{
		cout << "Codul a fost introdus incorect." << endl;
		return;
	}
	int codSelectat = stoi(codIntrodus);

	for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); it++)
	{
		if (codSelectat == it->cod)
		{
			cout << "Modificati programul de munca" << endl;
			cout << "Alegeti programul de munca\n"
				<< "1 - " << orar1 << endl
				<< "2 - " << orar2 << endl;
			bool tipAles = false;
			{
				switch (toupper(_getch()))
				{
				case '1':
					it->programMunca = orar1;
					tipAles = true;
					break;
				case '2':
					it->programMunca = orar2;
					tipAles = true;
					break;
				default:
					cout << "Optiune invalida\n";
					break;
				}
			}while (tipAles == false);
			AdministrareFisiere::RescrieFisierAngajati(listaAngajati);
			return;
		}		
	}
	cout << "Angajtul cu codul " + to_string(codSelectat) + " nu exista." << endl;
}

void Angajat::EliminaAngajat(list<Angajat>& listaAngajati)
{
	if (listaAngajati.empty())
		return;
	string codIntrodus;
	AfisareListaAngajati(listaAngajati);
	cout << "Introduceti codul: ";
	cin >> codIntrodus;
	if (ValidareNumar(codIntrodus) == false)
	{
		cout << "Codul a fost introdus incorect." << endl;
		return;
	}
	int codSelectat = stoi(codIntrodus);
	//list<Angajat> listaNoua
	for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); it++)
	{
		if (codSelectat == it->cod)
		{
			listaAngajati.remove(*it);
			AdministrareFisiere::RescrieFisierAngajati(listaAngajati);
			return;
		}
	}
	cout << "Angajtul cu codul " + to_string(codSelectat) + " nu exista." << endl;
}

void Angajat::AfisareStatisticaAngajati(list<Angajat> listaAngajati)
{
	if (listaAngajati.empty())
	{
		cout << "Lista este goala" << endl;
		return;
	}
	int totalFunctie1 = 0, totalFunctie2 = 0, totalFunctie3 = 0, totalFunctie4 = 0, totalFunctie5 = 0;
	int program1 = 0, program2 = 0;

	for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); it++)
	{
		if (it->functie == functie1)
			totalFunctie1++;
		if (it->functie == functie2)
			totalFunctie2++;
		if (it->functie == functie3)
			totalFunctie3++;
		if (it->functie == functie4)
			totalFunctie4++;
		if (it->functie == functie5)
			totalFunctie5++;
		if (it->programMunca == orar1)
			program1++;
		if (it->programMunca == orar2)
			program2++;
	}
	cout << "Statistica angajati" << endl;
	ostringstream table;
	table << setw(20) << left << functie1 << setw(10) << left << totalFunctie1 << endl
		<< setw(20) << left << functie2 << setw(20) << left << totalFunctie2 << endl
		<< setw(20) << left << functie3 << setw(20) << left << totalFunctie3 << endl
		<< setw(20) << left << functie4 << setw(20) << left << totalFunctie4 << endl
		<< setw(20) << left << functie5 << setw(11) << left << totalFunctie5 << endl
		<< setw(20) << left << orar1 << setw(11) << left << program1 << endl
		<< setw(20) << left << orar2 << setw(11) << left << program2 << endl;
	cout << table.str();
}

void Angajat::AfisareListaAngajati(list<Angajat> listaAngajati)
{
	if (listaAngajati.empty())
	{
		cout << "- GOL - ";
		return;
	}

	for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); ++it)
	{
		cout << it->ConvertToString() << "\n";
	}
}

string Angajat::ConvertToString()
{
	std::ostringstream table;
	table << setw(3) << left << "ID:" << setw(10) << left << cod
		<< setw(5) << left << "Nume:" << setw(20) << left << nume
		<< setw(8) << left << "Prenume:" << setw(20) << left << prenume
		<< setw(8) << left << "Functie:" << setw(20) << left << functie
		<< setw(8) << left << "Program:" << setw(11) << left << programMunca;
	return table.str();
}

string Angajat::ConversieSirFisier()
{
	return to_string(cod) + " " + nume + " " + prenume + " " + functie + " " + programMunca;
}