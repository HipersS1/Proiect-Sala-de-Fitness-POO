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
        //case '3':
        //    //MenuEquipment();
        //    break;
        case 'X':
            std::cout << ("Programul se inchide\n");
            return 0;
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }
}
