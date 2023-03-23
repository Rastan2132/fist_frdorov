#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

bool chek_file(string file) {
	ifstream in;
	in.open(file, ios::in);

	auto rez = 1;
	if (in.is_open())
	{
		if (in.peek() == char_traits<char>::eof())
			rez = 0;
		in.close();
	};
		return rez;
}
bool isalpha_r(unsigned char a)
{
	bool rez = ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '-');
	
	return rez;
}
void show(Users* people, short size)
{
	system("cls");
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << MENU << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << "				    ---=== USER BOOK ===---            your Users: " << size << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << stru << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	for (short i = 0; i < size; i++)
	{
		cout << right << setw(3) << setfill('0') << i + 1 << setfill(' ') << " " << MANIP << people[i].Name << " " << MANIP << people[i].Surname << "  " << MANIP << people[i].Year << MANIP << people[i].piesel << MANIP << people[i].sex << "\n";
	}
}

Users* create(short size)
{ 
	Users* arr = new Users[size];
	return arr;
}
Users* initForFile(Users* people, short* size)
{
	ifstream in;
	int i = 0;
	in.open("Users.txt", ios::in);
	if (!in.is_open())
	{
		*size = -1;	// if error *size = -1;
		return people;
	}
	
	if (in.eof())
		return 0;

		while (!in.eof())
		{
			people = resize(people, size, (*size) + 1);
			i = *size - 1;
			in >> people[i].Name >> people[i].Surname >> people[i].Year >> people[i].piesel >> people[i].sex;
		}

		in.close();
		return people;
	
	
}
void error()
{
	Beep(800, 150);
	cout << "ERROR!" << endl << endl;
	system("pause");
}
Users* resize(Users* people, short* size, short size_n, short num)
{
	Users* people_n;
	people_n = new Users[size_n];
	short min = *size;
	for (int i = 0; i < min; i++)
		if (i != num - 1) {
			strcpy_s(people_n[i].Name, people[i].Name);
			strcpy_s(people_n[i].Year, people[i].Year);
			strcpy_s(people_n[i].Surname, people[i].Surname);
			strcpy_s(people_n[i].sex, people[i].sex);
			strcpy_s(people_n[i].piesel, people[i].piesel);
		}
	*size = size_n;
	delete[] people;
	return people_n;
}
int rand_data(char sex[])								/// от 0 до 9 муж. от 10 до 19 жен
{
	char* _sex = new char[4] { 'm', 'a', 'n', '\0' };
	if (sex[1] == _sex[1])
		return rand() % 5;
	else
		return rand() % 5 + 5;

}
char* rand_data(int max)
{
	char* arr;
	if (max == 2)
	{
		if ((rand() % 2) == 1)
		{
			arr = new char[4]{ 'm','a','n','\0' };
		}
		else
		{
			arr = new char[6]{ 'w','o','m','e','n','\0' };
		}
		return arr;
	}
	else if (max == 4)
	{
		int year = rand() % (2023 - 1900 + 1) + 1900;
		arr = new char[5];
		snprintf(arr, 5, "%d", year);
		return arr;
	}
	else if (max == 12)
	{
		long long number = 0;
		for (int i = 0; i < 12; i++) {
			number = number * 10 + rand() % 10;
		}

		 arr = new char[13];
		snprintf(arr, 13, "%lld", number);

		return arr;
	}
	return nullptr;
}

Users* initRandUsers(Users* peoples, const char* NAMES[], const char* SURNAMES[], short i)
{
	strcpy_s(peoples[i].sex, rand_data(sex_));
	strcpy_s(peoples[i].Name, NAMES[rand_data(peoples[i].sex)]);
	strcpy_s(peoples[i].Surname, SURNAMES[rand_data(peoples[i].sex)]);
	strcpy_s(peoples[i].Year , rand_data(year_));
	strcpy_s(peoples[i].piesel, rand_data(piesel_));

	return peoples;
}

Users* add(Users* peoples, short* size)
{

	peoples = resize(peoples, size, (*size) + 1);
		record(peoples[(*size) - 1].Name, 2, " Name: ", false, false, false);
		cout << endl;
		record(peoples[(*size) - 1].Surname, 3, " Surname: ", false, false, false);
		cout << endl;
		record(peoples[(*size) - 1].Year, 4, " Year: ", false, 1, false);
		cout << endl;
		record(peoples[(*size) - 1].piesel, 11, " Num pesilu: ", false, 1, false);
		cout << endl;
		record(peoples[(*size) - 1].sex, 2, " Sex: ", false, false, false);
		cout << endl;
	return peoples;
}
bool record(char* p, unsigned short min, const char* prompt, bool chkAlpha, bool chkDigit, bool chkFirst)
{

	char s[MAXLINE] = "";
	size_t n, i;
	bool loop;
	cout << prompt;
	COORD start = getCursorPosition();
	do
	{
		Clear(start.X, start.Y, MAXLINE);
		loop = true;
		strncpy(s, p, MAXLINE - 1);
		stredit(s, MAXLINE, start.X, start.Y);		// cin >> s;
		if (strlen(s) < 1) return false;			// !!!
		strncpy(p, s, MAXLINE - 1);
		p[MAXLINE - 1] = '\0';
		n = strlen(p);
		for (i = 0; i < n; i++)
			if (chkAlpha || (chkDigit && !isdigit_r(p[i])))	//  isdigit((unsigned char)p[i])
				break;
		if (i != n || n < min || (chkFirst && isdigit_r(p[0])))
		{
			Beep(800, 150);
			Sleep(50);
		}
		else loop = false;
	} while (loop);

	return true;
}

bool isdigit_r(unsigned char a) { return (a >= '0' && a <= '9'); }

Users* del(Users* peoples, short* size)
{

	bool work = 1;

	cout << "Czy na pewno chcesz usunąć ostatniego użytkownika?" << endl;
	cout << "Naciśnij (y), jeśli jesteś pewien, naciśnij (n), jeśli nie" << endl;

	do {
		switch (_getch()) {

		case(121)://YES 

			if (*size > 0)
			{
				peoples = resize(peoples, size, *size - 1, *size);
				cout << "User was successfully deleted" << endl;
				cout << "press to continue" << endl;
				system("pause");

				return peoples;
			}
			else {
				error();
				work = 0;
			}


			break;

		case(110):// No

			work = 0;
			return peoples;

			break;
		}




	} while (work);

}

Users* edit(Users* peoples, short size, short index, bool menu)
{
	system("cls");

	if (size == 0 || index < 0 || index >= size)
	{
		error();
		return peoples;
	}

	do
	{
		system("cls");
		cout << "Uzytkownik #" << index + 1 << endl << endl;
		cout << "Enter name: ";
		stredit(peoples[index].Name, MAXLINE, 13, 2);

	} while (strlen(peoples[index].Name) == 0);

	do
	{
		system("cls");
		cout << "Uzytkownik #" << index + 1 << endl << endl;
		cout << "Enter Surname: ";
		stredit(peoples[index].Surname, MAXLINE, 16, 2);

	} while (strlen(peoples[index].Surname) == 0);
	do
	{
		system("cls");
		cout << "Uzytkownik #" << index + 1 << endl << endl;
		cout << "Enter Year: ";
		stredit(peoples[index].Year, MAXLINE, 13, 2);
	} while (strlen(peoples[index].Year) == 0);

	do
	{
		system("cls");
		cout << "Uzytkownik #" << index + 1 << endl << endl;
		cout << "Enter Pesel: ";
		stredit(peoples[index].piesel, MAXLINE, 16, 2);

	} while (strlen(peoples[index].piesel) == 0);
	do
	{
		system("cls");
		cout << "Uzytkownik #" << index + 1 << endl << endl;
		cout << "Enter sex: ";
		stredit(peoples[index].sex, MAXLINE, 12, 2);

	} while (strlen(peoples[index].sex) == 0);

	system("cls");
	if (menu) cout << "Edited!" << endl;

	return peoples;
}
int select(Users* peoples, short size)
{
	if (size == 0) return -1;
	if (size == 1) return 0;

	int index = 0;
	do
	{
		show(peoples, size);
		cout << "Numer uzytkownik: ";
		if (cin >> index)
		{
			if (index >= 1 && index <= size) break;
		}
		else
		{
			cin.clear();
			while (cin.get() != '\n');
		}
	} while (true);

	return index - 1;
}

Users* sort(Users* peoples, short size)
{

	char v;
	cout << endl << "Wybiesz:\n1 - posortowac za Name\n2 - posortowac za Year\n3 - posortowac za Surname\n4 - posortowac za pesel\n5  - posortowac za Sex\nQ - Wyjść\n"; v = _getch();
	cout << endl;
	switch (v)
	{
	case '1':
		for (short i = 0; i < size; i++) {
			for (short j = i + 1; j < size; j++) {
				if (strcmp(peoples[i].Name, peoples[j].Name) > 0) {
					swap(peoples[i].Name, peoples[j].Name);
					swap(peoples[i].Surname, peoples[j].Surname);
					swap(peoples[i].Year, peoples[j].Year);
					swap(peoples[i].sex, peoples[j].sex);
					swap(peoples[i].piesel, peoples[j].piesel);

				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case '2':
		for (short i = 0; i < size; i++) {
			for (short j = i + 1; j < size; j++) {
				if (strcmp(peoples[i].Year, peoples[j].Year) > 0) {
					swap(peoples[i].Name, peoples[j].Name);
					swap(peoples[i].Surname, peoples[j].Surname);
					swap(peoples[i].Year, peoples[j].Year);
					swap(peoples[i].sex, peoples[j].sex);
					swap(peoples[i].piesel, peoples[j].piesel);
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case '3':
		for (short i = 0; i < size; i++) {
			for (short j = i + 1; j < size; j++) {
				if (strcmp(peoples[i].Surname, peoples[j].Surname) > 0) {
					swap(peoples[i].Name, peoples[j].Name);
					swap(peoples[i].Surname, peoples[j].Surname);
					swap(peoples[i].Year, peoples[j].Year);
					swap(peoples[i].sex, peoples[j].sex);
					swap(peoples[i].piesel, peoples[j].piesel);
				}
			}
		}
	case '4':
		for (short i = 0; i < size; i++) {
			for (short j = i + 1; j < size; j++) {
				if (strcmp(peoples[i].piesel, peoples[j].piesel) > 0) {
					swap(peoples[i].Name, peoples[j].Name);
					swap(peoples[i].Surname, peoples[j].Surname);
					swap(peoples[i].Year, peoples[j].Year);
					swap(peoples[i].sex, peoples[j].sex);
					swap(peoples[i].piesel, peoples[j].piesel);
				}
			}
		}
	case '5':
		for (short i = 0; i < size; i++) {
			for (short j = i + 1; j < size; j++) {
				if (strcmp(peoples[i].sex, peoples[j].sex) > 0) {
					swap(peoples[i].Name, peoples[j].Name);
					swap(peoples[i].Surname, peoples[j].Surname);
					swap(peoples[i].Year, peoples[j].Year);
					swap(peoples[i].sex, peoples[j].sex);
					swap(peoples[i].piesel, peoples[j].piesel);
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
		cout << endl << "Paush 1, 2, 3 or Q " << endl;
		system("pause");
	}
	}
	return peoples;

}



void find(Users* peoples, short size)
{
	if (peoples == nullptr || size == 0)
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

	cout << endl << stru << endl;
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
		for (int i = 0; i < size; i++)
		{
			temp_pos = getCursorPosition();
			Clear(temp_pos.X, temp_pos.Y + i);
		}
		setCursorPosition(hat.X, hat.Y);

		//Выводим новые результаты поиска
		for (int i = 0; i < size; i++)
		{
			if (strstr_lower(peoples[i].Name, keyword)
				|| strstr_lower(peoples[i].Surname, keyword)
				|| strstr_lower(peoples[i].sex, keyword)
				|| strstr_lower(peoples[i].piesel, keyword)
				|| strstr_lower(peoples[i].Year, keyword))
			{
				cout << left << setw(3) << i + 1 << "  ";
				print_find(peoples[i].Name, MAXLINE, keyword, MAXLINE, Red);
				print_find(peoples[i].Surname, MAXLINE, keyword, MAXLINE, Red);
				print_find(peoples[i].Year, MAXLINE, keyword, MAXLINE, Red);
				print_find(peoples[i].piesel, MAXLINE, keyword, MAXLINE, Red);
				print_find(peoples[i].sex, MAXLINE, keyword, MAXLINE, Red);

				cout << endl;
			}
		}

	} while (true); //Пока не нажата Esc.

	delete[] keyword; keyword = nullptr;
}
char* strstr_lower(char* str_a, char* str_b)
{
	/*Поиск подстроки в строке без учета регистра.*/

	if (str_a == nullptr || str_b == nullptr)
		return nullptr;

	for (int i = 0;; i++)
	{
		if (str_a[i] == '\0') return nullptr;

		for (int j = 0, k = i;; j++, k++)
		{
			if (str_b[j] == '\0') return (str_a + i);
			if (tolower(str_a[k]) != tolower(str_b[j])) break;
		}
	}
}

void print_find(char* str, short str_size, char* keyword, short key_size, int text, int back)
{
	if (str == nullptr || keyword == nullptr) return;

	int str_len = strlen(str);
	int key_len = strlen(keyword);

	if (str_len > str_size || str_len < 0 || key_len > key_size || key_len < 0) return;

	COORD start, cursor;

	start = getCursorPosition();
	cout << left << setw(str_size) << str;
	cursor = getCursorPosition();
	showcursor(false);

	COLOR DefColor = GetColor();
	COLOR FindColor;

	FindColor.text = (text == -1) ? DefColor.text : text;
	FindColor.back = (back == -1) ? DefColor.back : back;

	char* ptr = strstr_lower(str, keyword);
	short index = 0;

	while (ptr != nullptr)
	{
		index = (int)(ptr - str);                    //Считаем позицию слова в строке и 
		setCursorPosition(start.X + index, start.Y); //переходим к позиции слова.

		// Выводим слово с форматом цвета.
		SetColor(FindColor);
		for (int j = 0; j < key_len; j++) cout << str[index + j];
		SetColor(DefColor);

		//Ищем далее.
		ptr = strstr_lower(ptr + key_len, keyword);
	}

	setCursorPosition(cursor.X, cursor.Y);
	showcursor(true);
}

bool save(Users* peoples, short* size)
{
	ofstream out;

	out.open("Users.txt", ios::out);
	if (!out.is_open())
		return false;

	for (int i = 0; i < *size; i++)
	{
		out << peoples[i].Name << " " << peoples[i].Surname << " " << peoples[i].Year << " " << peoples[i].piesel << " " << peoples[i].sex;
		if (i < *size - 1) out << endl;
	}

	out.close();
	return true;
}
