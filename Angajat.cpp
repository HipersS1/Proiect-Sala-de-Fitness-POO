#include "Angajat.h"
#include "AdministrareFisiere.h"

Angajat Angajat::AdaugaAngajat()
{
	string nume, prenume, input;
	do
	{
		cout << FORMAT2"Introduceti numele: ";
		cin >> nume;
	} while (!ValidareString(nume));
	cin.seekg(0, ios::end);//in caz ca sunt introduse 2 cuvinte
	cin.clear();
	do
	{
		cout << FORMAT2"Introduceti prenumele: ";
		cin >> prenume;
	} while (!ValidareString(prenume));
	cin.seekg(0, ios::end);
	cin.clear();
	for (auto& c : nume) c = toupper(c);
	for (auto& c : prenume) c = toupper(c);
	Angajat angajatNou(nume, prenume);
	cout << FORMAT2"Alegeti functia angajatului\n"
		<< FORMAT2"1 - " << functie1 << endl
		<< FORMAT2"2 - " << functie2 << endl
		<< FORMAT2"3 - " << functie3 << endl
		<< FORMAT2"4 - " << functie4 << endl
		<< FORMAT2"5 - " << functie5 << endl;
	bool tipAles = false;
	do
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
			INVALID;
			cout << endl;
			Sleep(1500);
			continue;
		}
	}while (tipAles == false);
	cout << endl << FORMAT2"Functia aleasa: \033[0;32m" << angajatNou.functie << "\033[0m" << endl << endl;
	cout << FORMAT2"Alegeti programul de munca\n"
		<< FORMAT2"1 - " << orar1 << endl
		<< FORMAT2"2 - " << orar2 << endl;
	tipAles = false;
	do
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
			INVALID;
			cout << endl;
			Sleep(1500);
			continue;
		}
	}while (tipAles == false);
	cout << endl << FORMAT2"Orarul ales: \033[0;32m" << angajatNou.programMunca << "\033[0m" << endl;
	cout << endl << FORMAT2"\033[0;32mAngajatul a fost inregistrat\033[0m" << endl;

	return angajatNou;
}

void Angajat::ModificaProgramAngajat(list<Angajat>& listaAngajati)
{
	if (listaAngajati.empty())
		return;
	string codIntrodus;
	AfisareListaAngajati(listaAngajati, 2);
	cout << endl <<FORMAT3"    Introduceti codul: ";
	cin >> codIntrodus;
	if (ValidareNumar(codIntrodus) == false)
	{
		cout << FORMAT3"    \033[1;31mCodul a fost introdus incorect\033[0m" << endl;
		return;
	}
	int codSelectat = stoi(codIntrodus);

	for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); it++)
	{
		if (codSelectat == it->cod)
		{
			if (it->programMunca == orar1)
				it->programMunca = orar2;
			else
				it->programMunca = orar1;
			cout << FORMAT3"    \033[1;32mProgramul angajatului cu codul " << it->cod << " a fost actualizat in "<< it->programMunca <<"\033[0m" << endl;
			 //\033[1; 32mAbonatul a fost inregistrat cu succes.\033[
			AdministrareFisiere::RescrieFisierAngajati(listaAngajati);
			return;
		}		
	}
	cout << FORMAT3"    \033[1;31mAngajatul cu codul " + to_string(codSelectat) + " nu exista\033[0m" << endl;
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
	FORMATROW
	ostringstream table;
	table << FORMAT2 "|" underline << setw(28) << left << "Statistica angajati" << "|\n"
		<< FORMAT2 "|" underline << setw(23) << left << functie1 << setw(5) << left << totalFunctie1 << "|\n"
		<< FORMAT2 "|" underline << setw(23) << left << functie2 << setw(5) << left << totalFunctie2 << "|\n"
		<< FORMAT2 "|" underline << setw(23) << left << functie3 << setw(5) << left << totalFunctie3 << "|\n"
		<< FORMAT2 "|" underline << setw(23) << left << functie4 << setw(5) << left << totalFunctie4 << "|\n"
		<< FORMAT2 "|" underline << setw(23) << left << functie5 << setw(5) << left << totalFunctie5 << "|\n\n\n"
		<< FORMAT2 "|" underline << setw(28) << left << "Program angajati" << "|\n"
		<< FORMAT2 "|" underline << setw(23) << left << orar1 << setw(5) << left << program1 << "|\n"
		<< FORMAT2 "|" underline << setw(23) << left << orar2 << setw(5) << left << program2 << "\033[0m|\n";
	cout << table.str();
}

void Angajat::AfisareListaAngajati(list<Angajat> listaAngajati, int tip)
{
	if (listaAngajati.empty())
	{
		cout << "- GOL - ";
		return;
	}
	FORMATROW;
	if (tip == 1)
	{
		cout << FORMAT1"|" underline << setw(5) << left << "COD" << setw(15) << left << "NUME" << setw(15) << left << "PRENUME" << setw(19) << left << "FUNCTIE" << "\033[0m|\n";
		for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); ++it)
		{
			cout << it->ConvertToString() << "\n";
		}
		return;
	}
	cout << FORMAT1"|" underline << setw(5) << left << "COD" << setw(15) << left << "NUME" << setw(15) << left << "PRENUME" << setw(19) << left << "FUNCTIE" << setw(12) << left << "ORAR" << "\033[0m|\n";
	for (list<Angajat>::iterator it = listaAngajati.begin(); it != listaAngajati.end(); ++it)
	{
		cout << it->ConvertToString2() << "\n";
	}
}

string Angajat::ConvertToString()
{
	std::ostringstream table;
	table << FORMAT1 "|" underline<< setw(5) << left << cod << setw(15) << left << nume << setw(15) << left << prenume << setw(19) << left << functie  << "\033[0m|";

	return table.str();
}

string Angajat::ConvertToString2()
{
	std::ostringstream table;
	table << FORMAT1 "|" underline << setw(5) << left << cod << setw(15) << left << nume << setw(15) << left << prenume << setw(19) << left << functie << setw(12) << left << programMunca <<"\033[0m|";

	return table.str();
}

string Angajat::ConversieSirFisier()
{
	return to_string(cod) + " " + nume + " " + prenume + " " + functie + " " + programMunca;
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