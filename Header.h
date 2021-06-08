#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
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
#include <time.h>

using namespace std;

#define FORMAT1 "\t\t\t\t\t\b\b\b\b"
#define BACKSPACEFORMAT "\b\b\b\b"
#define FORMAT2 "\t\t\t\t\t\t"
#define FORMAT3 "\t\t\t\t\t"
#define FORMAT4 "\t\t\t\t\t\t\t\b"
#define FORMATROW  cout << "\n\n";
#define underline "\033[4m"
#define NEXT cout << "\n\t\t\t\t\t    Apasati orice tasta pentru a continua";
#define INVALID cout << FORMAT2"\t\b\b\033[0;31mOptiune invalida\033[0m";
#define SPATIU "    "

void Menu();
void MenuAbonati();
void MenuAngajati();
void MenuEchipamente();
void MenuAbonatiInterfata();
void MenuAngajatiInterfata();
void MenuEchipamenteInterfata();
bool ValidareString(const string& str);
bool ValidareNumar(const string& str);


const int zile30 = 2592000;
const int numarMaximAngajati = 98;
