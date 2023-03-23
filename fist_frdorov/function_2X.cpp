﻿#include "Header.h"

Uzond** create(int rows, int cols) {
	Uzond** Uzonds = new Uzond * [rows];
	for (int i = 0; i < rows; i++) {
		Uzonds[i] = new Uzond[cols];
	}
	return Uzonds;
}
void show(Uzond** Uzonds, short rows, short cols)
{

    system("cls");
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << MENU << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << "				    ---=== UZOND BOOK ===---            your Uzond: " << rows<< "*" << cols << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << "    " << stru_2 << stru_2 << stru_2 << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";
    for (short i = 0; i < rows; i++)
    {
        cout << right << setw(3) << setfill('0') << i + 1 << setfill(' ') << " ";
        for (short j = 0; j < cols; j++)
        {
            if (!(j % 3)) {
                cout << endl; cout <<"    ";
            }
            cout << MANIP << Uzonds[i][j].Name << " " << MANIP_2 << Uzonds[i][j].Numer << "  ";
        }
        cout << endl<<endl;
    }
}
bool save(Uzond** Uzonds, short rows, short cols)
{
    ofstream out;

    out.open("Uzonds.txt", ios::out);
    if (!out.is_open())
        return false;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            out << Uzonds[i][j].Name << " " << Uzonds[i][j].Numer << "  ";
        }
        if (i < rows - 1) out << endl;
    }

    out.close();
    return true;
}

Uzond** initRand(Uzond** Uzonds, short rows, short cols, const char* NAMES[]){
    for(int i=0;i < rows;i++)
        for (int j = 0; j < cols; j++)
        {
            strcpy(Uzonds[i][j].Numer, rand_data(num_));
            strcpy(Uzonds[i][j].Name, NAMES[rand() % 4]);
        }
    return Uzonds;
}


Uzond** edit(Uzond** Uzonds, short rows, short cols, short index_1, short index_2, bool menu)
{
	system("cls");

	if (index_1 < 0 || index_2 >= cols|| index_1 >= rows|| index_2 < 0)
	{
		error();
		return Uzonds;
	}
	do
	{
		system("cls");
		cout << "Urzond #" << index_1 << "*"<< index_2 << endl << endl;
		cout << "Enter name: ";
		stredit(Uzonds[index_1][index_2].Name, MAXLINE, 12, 2);

	} while (strlen(Uzonds[index_1][index_2].Name) == 0);
	do
	{
        system("cls");
        cout << "Urzond #" << index_1 << "*" << index_2 << endl << endl;
        cout << "Enter numer: ";
        stredit(Uzonds[index_1][index_2].Numer, MAXLINE, 13, 2);

	} while (strlen(Uzonds[index_1][index_2].Numer) == 0);

	if (menu) cout << "Edited!" << endl;

	return Uzonds;
}

Uzond** sort(Uzond** Uzonds, short rows, short cols)
{
	cout << endl << "Wybiesz:\n1 - posortowac za Name\n2 - posortowac za Numb\nQ - Wyjść\n";
	cout << endl;
	switch (_getch())
	{
	case '1':
		for (short l = 0; l < rows; l++)
		for (short i = 0; i < cols; i++) {
			for (short j = i + 1; j < cols; j++) {
				if (strcmp(Uzonds[l][i].Name, Uzonds[l][j].Name) > 0) {
					swap(Uzonds[l][i].Name, Uzonds[l][j].Name);
					swap(Uzonds[l][i].Numer, Uzonds[l][j].Numer);
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case '2':

		for (short l = 0; l < rows; l++)
		for (short i = 0; i < cols; i++) {
			for (short j = i + 1; j < cols; j++) {
				if (strcmp(Uzonds[l][i].Numer, Uzonds[l][j].Numer) > 0) {
					swap(Uzonds[l][i].Name, Uzonds[l][j].Name);
					swap(Uzonds[l][i].Numer, Uzonds[l][j].Numer);
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case 'q':
	case 'Q':
		break;
	default:
	{
		cout << endl << "Paush 1, 2 or Q " << endl;
		system("pause");
	}
	}
	return Uzonds;

}

void find(Uzond** Uzonds, short rows, short cols)
{
	if (Uzonds == nullptr || rows == 0||cols == 0)
	{
		error();
		return;
	}

	char* keyword = new char[MAXLINE]; keyword[0] = '\0';

	COORD enter, hat;

	system("cls");
	cout << " Esc - Wejscie" << endl << endl;
	cout << "Szukaj: ";
	enter = getCursorPosition();

	cout << endl <<" #   " stru_2 << endl;
	hat = getCursorPosition();

	COORD temp_pos;
	short len = 0;

	do
	{
		//Вводим ключевое слово для поиска.
		{
			int i = 0;
			do
			{

				if (!stredit(keyword, MAXLINE, enter.X, enter.Y, len, false)) return;
				len = (short)strlen(keyword);

				for (i = 0; i < len; i++)
				{
					if (!(isdigit_r(keyword[i]) || isalpha_r(keyword[i]))) break;
				}

			} while (i != len || len == 0);
		}

		// Выводим результаты. 

		setCursorPosition(hat.X, hat.Y);

		//Очищаем предыдущие результаты поиска.
		for (int i = 0; i < cols; i++)
		{
			temp_pos = getCursorPosition();
			Clear(temp_pos.X, temp_pos.Y + i);
		}
		setCursorPosition(hat.X, hat.Y);

		//Выводим новые результаты поиска
		for (short l = 0; l < rows; l++)
		{
			cout << "Rezultat o " << l + 1 << " linii" << endl;
			for (short i = 0; i < cols; i++)
			{
				if (strstr_lower(Uzonds[l][i].Name, keyword)
					|| strstr_lower(Uzonds[l][i].Numer, keyword))
				{
					cout << left << setw(3) << i + 1 << "  ";
					print_find(Uzonds[l][i].Name, MAXLINE, keyword, MAXLINE, Red);
					print_find(Uzonds[l][i].Numer, MAXLINE, keyword, MAXLINE, Red);

					cout << endl;

				}
			}
			cout << endl;

	}
	} while (true); //Пока не нажата Esc.

	delete[] keyword; keyword = nullptr;
}
Uzond** resize(Uzond** Uzonds, short* rows, short rows_n, short* cols, short cols_n, short num)
{
	Uzond** Uzonds_n = new Uzond * [rows_n];
	for (int i = 0; i < rows_n; i++) {
		Uzonds_n[i] = new Uzond[cols_n];
	}
	for (short l = 0; l < *rows; l++)
		for (short i = 0; i < *cols; i++)
			if (i != num - 1)
				{
				strcpy_s(Uzonds_n[l][i].Name, Uzonds[l][i].Name);
				strcpy_s(Uzonds_n[l][i].Numer, Uzonds[l][i].Numer);
				}
	*rows = rows_n;
	*cols = cols_n;
	delete[] Uzonds;
	return Uzonds_n;
}
Uzond** add(Uzond** Uzonds, short *rows, short *cols, short index_1, short index_2)
{
	if (index_1 < 0 || index_2 < 0)
	{
		error();
		return Uzonds;
	}
		Uzonds = resize(Uzonds, rows, index_1, cols, index_2);
	record(Uzonds[index_1][index_2].Name, 2, " Name: ", false, false, false);
	cout << endl;
	record(Uzonds[index_1][index_2].Numer, 1, " Numer: ", false, 1, false);
	cout << endl;
	return Uzonds;
}