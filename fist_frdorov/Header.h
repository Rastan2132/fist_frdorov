#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctype.h>
#include <windows.h>


#define MANIP setw(MAXLINE) <<  left 
#define MANIP_2 setw(10) <<  left 

#define MENU "| q-Zamkac |  a-ADD uzytkownika  |  d-Usuwanie uzytkownika |  e-Redaktor |  s-Sortowac |  y-Szukaj |" 
#define stru "#   Name                 Surname	       Year		   Piesel 	       Sex"

#define MAXLINE 20

#define num_ 3
#define sex_ 2
#define year_ 4
#define piesel_ 12

using namespace std;

struct Users
{
	char Name[MAXLINE] = "";
	char Surname[MAXLINE] = "";
	char Year[MAXLINE] = "";
	char piesel[MAXLINE] = "";
	char sex[MAXLINE] = "";
};
struct Uzond
{
	char Name[MAXLINE] = "";
	char Numer[MAXLINE] = "";
};
struct COLOR
{
	short text;
	short back;
};
enum ConsoleColor
{
	Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

enum Keys { Enter = 13, Backspace = 8 };
enum SpecialKeys { Left = 75, Right = 77, End = 79, Home = 71, Esc = 27, Del = 83 };



Uzond** create(int rows, int cols);
void show(Uzond** Uzonds, short rows, short cols);
bool save(Uzond** Uzonds, short rows, short cols);

Uzond** initRand(Uzond** Uzonds, short rows, short cols, const char* NAMES[]);

void error();
Users* create(short size);
void show(Users* people, short size);
Users* initForFile(Users* people, short* size);
Users* resize(Users* people, short* size, short size_n, short num = 0);
int rand_data(char sex[]);
char* rand_data(int max);
Users* initRand(Users* peoples, const char* NAMES[], const char* SURNAMES[], short i = 0);
Users* add(Users* peoples, short* size);
bool record(char* p, unsigned short min, const char* prompt, bool chkAlpha, bool chkDigit, bool chkFirst);
bool isdigit_r(unsigned char a);
Users* edit(Users* peoples, short size, short index, bool menu);
Users* del(Users* peoples, short* size);
int select(Users* peoples, short size);
Users* sort(Users* peoples, short size);
char* strstr_lower(char* str_a, char* str_b);
void find(Users* peoples, short size);
bool isalpha_r(unsigned char a);
void find(Users* peoples, short size);
bool save(Users* peoples, short* size);
bool chek_file(string file);



COORD getCursorPosition(void);
void Clear(int x, int y, long cnt = 100);
void print_find(char* str, short str_size, char* keyword, short key_size, int text = -1, int back = -1);
bool stredit(char* str, int buffer_size, int x, int y, int cursor = 0, bool clear_after = true);
void showcursor(bool flag);
void setCursorPosition(int x, int y);
COORD getConsoleSize();
COLOR GetColor();
WORD GetColorWord();
void SetColor(COLOR Color);


void DeleteCh(char* str, int& cursor, int& term);
void InsertCh(char* str, int buffer_size, int& cursor, int& term, char symb);
