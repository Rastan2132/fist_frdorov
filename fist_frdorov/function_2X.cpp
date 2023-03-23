#include "Header.h"

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
    cout << stru_2 << endl;
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
        stredit(Uzonds[index_1][index_2].Numer, MAXLINE, 12, 2);

	} while (strlen(Uzonds[index_1][index_2].Numer) == 0);

	if (menu) cout << "Edited!" << endl;

	return Uzonds;
}