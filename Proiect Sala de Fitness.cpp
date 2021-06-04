#include "Header.h"


int main()
{
    char optiune;
    while(true)
    {
        Menu();
        optiune = _getch();
        switch(toupper(optiune))
        {
        case '1':
            MenuAbonatiInterfata();
            break;
        case '2':
            MenuAngajatiInterfata();
            break;
        case '3':
            MenuEchipamenteInterfata();
            break;
        case 'I':
            FORMATROW
            cout << FORMAT4 "\033[0;32mProiect realizat de" << endl;
            cout << FORMAT4 "Bruma Sebastian" << endl;
            cout << FORMAT4 "Calculatoare An II" << endl;
            cout << FORMAT4 "Grupa 3123 B\033[0m" << endl;
            
            _getch();
            break;
        case 'X':
            std::cout << ("Programul se inchide\n");
            return 0;
        default:
			INVALID;
			Sleep(1500);
			continue;
        }
        
    }
}
