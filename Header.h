#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <list>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "string.h"
#include <sstream>
#include <iomanip>
#include <cstdio>


using namespace std;

#define FORMAT1 "\t\t\t\t\t\t"
#define FORMAT2 "\t\t\t\t"

void Menu();
void MenuAbonati();
void MenuAngajati();
void MenuAbonatiInterfata();
void MenuAngajatiInterfata();
bool ValidareString(const string& str);
bool ValidareNumar(const string& str);
