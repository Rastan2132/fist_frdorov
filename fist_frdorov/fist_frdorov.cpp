#include "Header.h"

int main()
{
	bool work = 1;
	short size = 0;
	Users* peoples = nullptr;
	const char* NAMES[] = { "John", "Jane", "Jack", "Mary", "Bob", "Alice", "Tom", "Sara", "Peter", "Kate" };
	const char* SURNAMES[] = { "Petrov", "Smith", "Johnson", "Brown", "Linkoln", "Wilson", "Taylor", "Anderson", "Clark", "Wright" };
	if (initForFile(peoples, &size) == nullptr)
	{
		size = rand() % 10 + 1;
		peoples = create(size);
		for(int i =0;i<size;i++)
			peoples = initRandUsers(peoples, NAMES, SURNAMES,i);
	}
	else
		peoples = initForFile(peoples, &size);

	if (size < 0)
	{
		error();
		size = 0;
	}
	do
	{
		show(peoples, size);
		switch (_getch())
		{
		case (113):
			work = false;
			break;
		case (97):
			cout << "Chcesz dodać sam czy losowo" << endl;
			switch (_getch())
			{
			case (115):
				peoples = add(peoples, &size);
				break;
			case (114):
				peoples = resize(peoples, &size, size+ 1);
				peoples = initRandUsers(peoples, NAMES, SURNAMES, size-1);
				break;
			}
			break;
		case (100):
			peoples = del(peoples, &size);
			break;
		case (101):
			peoples = edit(peoples, size, select(peoples, size), true);
			break;
		case (115):
			sort(peoples, size);
			break;
		case (121):
			find(peoples, size);
			break;
		}
	} while (work);
//	if (!(work = save(pb, &size)))	// save
//		error();

	delete[] peoples;

	return !(work);
}


// треба написати текстовий інтерфейс юзера иниціализіровать 2 структури та					+
// стровити меню виділення памьяти при тому функция мусить генерувати розмір массиву		+
// іноцюлюввти массив рандомно																+
// шоуу массиву																				+
//додади обьект рандомни 
// видалити рандомний обект



//
//5 6 7 8 9 10 зробити то само тільки в массиві х2
// 13 визід з программи та звілнення памьяті 
// 
// 
//11 save
//12 innit
// сорт
// зміна стану об
// пошук