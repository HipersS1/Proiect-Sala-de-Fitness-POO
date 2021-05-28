#include "Header.h"
#include "Client.h"
#include "Angajat.h"
#include "AdministrareFisiere.h"
using namespace std;

void Menu()
{
    system("cls");
    std::cout << (FORMAT1"|------Meniu Principal-----|\n"
        FORMAT1"|1-Administrare abonamente |\n"
        FORMAT1"|2-Administrare angajati   |\n"
        //FORMAT1"|3-Administrare echipamente|\n"
        FORMAT1"|X-Exit                    |\n"
        FORMAT1"|--------------------------|\n");
}

void MenuAbonati()
{
    system("cls");
    std::cout << (FORMAT1"|------Meniu Abonati-------|\n"
        FORMAT1"|1-Afisare abonati         |\n"
        FORMAT1"|2-Adaugare abonat         |\n"
        //FORMAT1"|3-Activare abonament      |\n"
        FORMAT1"|4-Statistica abonati      |\n"
        FORMAT1"|R-Meniu principal         |\n"
        FORMAT1"|X-Exit                    |\n"
        FORMAT1"|--------------------------|\n");
}

void MenuAngajati()
{
    system("cls");
    std::cout << (FORMAT1"|------Meniu Angajati------|\n"
        FORMAT1"|1-Afisare angajati        |\n"
        FORMAT1"|2-Adaugare anagajat       |\n"
        FORMAT1"|3-Modifica program angajat|\n"
        FORMAT1"|4-Eliminare angajat       |\n"
        FORMAT1"|5-Statistica angajati     |\n"
        FORMAT1"|R-Meniu principal         |\n"
        FORMAT1"|X-Exit                    |\n"
        FORMAT1"|--------------------------|\n");
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
            Client::AfisareListaAbonati(listaClienti);
            break;
        case '2':
            nou = Client::AdaugaClient();
            nou.setCod(Client::RandomCod(listaClienti));
            listaClienti.push_back(nou);
            AdministrareFisiere::AdaugaClientFisier(nou);
            break;
        case '3':

            break;
        case '4':
            Client::StatisticaAbonamente(listaClienti);
            break;
        case 'R':
            return;
        case 'X':
            exit(0);
        default:
            cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
        cout << "\nApasati orice tasta pentru a continua" << endl;
        option = _getch();
    }
}

void MenuAngajatiInterfata()
{
    char option;
    list<Angajat> listaAngajati = AdministrareFisiere::CitesteFisierAngajati();
    Angajat nou;
    while (1)
    {
        MenuAngajati();
        switch (toupper(option = _getch()))
        {
        case '1':
            Angajat::AfisareListaAngajati(listaAngajati);
            break;
        case '2':
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
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
		cout << "\nApasati orice tasta pentru a continua" << endl;
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

