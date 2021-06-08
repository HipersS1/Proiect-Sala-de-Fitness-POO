#include "Header.h"
#include "Client.h"
#include "Angajat.h"
#include "Echipament.h"
#include "AdministrareFisiere.h"
using namespace std;

void Menu()
{
    system("cls");
    std::cout << 
        (FORMAT2"|-------Meniu Principal-------|\n"
        FORMAT2"|1 - Administrare clienti     |\n"
        FORMAT2"|2 - Administrare angajati    |\n"
        FORMAT2"|3 - Administrare echipament  |\n"
        FORMAT2"|I - INFO                     |\n"
        FORMAT2"|X - Exit                     |\n"
        FORMAT2"|_____________________________|\n");
}

void MenuAbonati()
{
    system("cls");
    std::cout << 
        (FORMAT2"|--------Meniu Abonati--------|\n"
        FORMAT2"|1 - Afisare abonati          |\n"
        FORMAT2"|2 - Adaugare abonat          |\n"
        FORMAT2"|3 - Activare abonament       |\n"
        FORMAT2"|4 - Statistica abonamente    |\n"
        FORMAT2"|R - Meniu principal          |\n"
        FORMAT2"|X - Exit                     |\n"
        FORMAT2"|_____________________________|\n");
}

void MenuAngajati()
{
    system("cls");
    std::cout << 
        (FORMAT2"|------Meniu Angajati--------|\n"
        FORMAT2"|1 - Afisare angajati        |\n"
        FORMAT2"|2 - Adauga anagajat         |\n"
        FORMAT2"|3 - Modifica program angajat|\n"
        FORMAT2"|4 - Eliminare angajat       |\n"
        FORMAT2"|5 - Statistica angajati     |\n"
        FORMAT2"|R - Meniu principal         |\n"
        FORMAT2"|X - Exit                    |\n"
        FORMAT2"|____________________________|\n");
}

void MenuEchipamente()
{
	system("cls");
	std::cout << 
        (FORMAT2"|------Meniu Echipament------|\n"
		FORMAT2"|1 - Afisare echipamente     |\n"
		FORMAT2"|2 - Adauga echipament       |\n"
		FORMAT2"|3 - Revizie echipamente     |\n"
		FORMAT2"|4 - Eliminare echipament    |\n"
		FORMAT2"|5 - Statistica echipamente  |\n"
		FORMAT2"|R - Meniu principal         |\n"
		FORMAT2"|X - Exit                    |\n"
        FORMAT2"|____________________________|\n");
}

void MenuAbonatiInterfata()
{
    char option;
    list<Client> listaClienti = AdministrareFisiere::CitesteFisierClienti();
    Client nou;
    while (true)
    {
        MenuAbonati();
        switch (toupper(option = _getch()))
        {
        case '1':
            system("cls");
            Client::AfisareListaAbonati(listaClienti);
            break;
        case '2':
            nou = Client::AdaugaClient();
            nou.setCod(Client::RandomCod(listaClienti));
            listaClienti.push_back(nou);
            AdministrareFisiere::AdaugaClientFisier(nou);
            break;
        case '3':
            Client::ActivareAbonament(listaClienti);
            break;
        case '4':
            Client::StatisticaAbonamente(listaClienti);
            break;
        case 'R':
            return;
        case 'X':
            exit(0);
        default:
			INVALID;
			Sleep(1500);
			continue;
        }
        NEXT;
        option = _getch();
    }
}

void MenuAngajatiInterfata()
{
    char option;
    list<Angajat> listaAngajati = AdministrareFisiere::CitesteFisierAngajati();
    Angajat nou;
	time_t now = time(0);
	tm* gmtm = gmtime(&now);
    char* dt = asctime(gmtm);
    while (1)
    {
        MenuAngajati();
        switch (toupper(option = _getch()))
        {
        case '1':
            Angajat::AfisareListaAngajati(listaAngajati);
            break;
        case '2':
            if (listaAngajati.size() > numarMaximAngajati)
            {
                cout << FORMAT3 "S-a atins numarul maxim de angajati" << endl;
				continue;
            }
			nou = Angajat::AdaugaAngajat();
			nou.setCod(Angajat::RandomCod(listaAngajati));
			listaAngajati.push_back(nou);
			AdministrareFisiere::AdaugaAngajatFisier(nou);
            break;
        case '3':
            Angajat::ModificaProgramAngajat(listaAngajati);
            break;
        case '4':
            Angajat::EliminaAngajat(listaAngajati);
            break;
        case '5':
            Angajat::AfisareStatisticaAngajati(listaAngajati);
            break;
        case 'R':
            return;
        case 'X':
            exit(0);
        default:
            INVALID;
            Sleep(1500);
            continue;
        }
        NEXT;
		option = _getch();
    }
}

void MenuEchipamenteInterfata()
{
	char option;
    list<Echipament> listaEchipamente = AdministrareFisiere::CitesteFisierEchipament();
    Echipament echipamentNou;
    string input;
    int nrEchipamente = 0;
	while (true)
	{
		MenuEchipamente();
		switch (toupper(option = _getch()))
		{
		case '1':
            Echipament::AfisareListaEchipamente(listaEchipamente, 2);
			break;
		case '2':
            do 
            {
				cout << FORMAT3 "Introduceti numarul (1-10) de echipamente: ";
                cin >> input;
                if (ValidareNumar(input) == false)
                    continue;
                nrEchipamente = stoi(input);
            } while (nrEchipamente <= 0 || nrEchipamente > 10);
            
			echipamentNou = Echipament::AdaugaEchipament();
            for (int i = 0; i < nrEchipamente; i++)
            {
				echipamentNou.setCod(Echipament::RandomCod(listaEchipamente));
				AdministrareFisiere::AdaugaEchipamentFisier(echipamentNou);
				listaEchipamente.push_back(echipamentNou);
            }
			break;
        case '3':
            listaEchipamente.erase(listaEchipamente.begin(), listaEchipamente.end());
            listaEchipamente = AdministrareFisiere::CitesteFisierEchipament();
            Echipament::ActualizareRevizie(listaEchipamente);
			listaEchipamente = AdministrareFisiere::CitesteFisierEchipament();
			break;
		case '4':
            Echipament::StergeEchipament(listaEchipamente);
			break;
        case '5':
            Echipament::StatisticaEchipamente(listaEchipamente);
            break;
		case 'R':
			return;
		case 'X':
			exit(0);
		default:
			INVALID;
			Sleep(1500);
			continue;
		}
		NEXT;
		option = _getch();
	}
}


bool ValidareString(const string& s)
{
    for (int i = 0; i < s.length(); i++) 
    {
        if (!isalpha(s[i]))
            return false;
        if (isspace(s[i]))
            return false;
        if(isdigit(s[i]))
            return false;
    }
    return true;
}

bool ValidareNumar(const string& str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

