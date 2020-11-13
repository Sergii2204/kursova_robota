#include "Books.h"

void Books::FillBooks()
{
	string N[12]{ "Ugrum_Reka","Asia","Vavilon","Dva_Kapitana","Titanik","Igla","Strax","Na_Grani","Forsach","Pro_Eto","Maria","Svolochi" };
	string P[4]{ "Zora","Bukva","Maiak","Luch" };
	string A[4]{ "Averin_Sergii","Titov_Maksim","Tolstoi_Lev","Chehov" };
	string G[4]{ "Melodrama","Dedektiv","Uzasi","fentazi" };
	int n, p, a, g, y;
	n = rand() % 12;
	p = rand() % 4;
	a = rand() % 4;
	g = rand() % 4;
	NameNewpapers = N[n];
	Publisher = P[p];
	Author = A[a];
	Genre = G[g];
	YuarPublish = 1955 + rand() % 65;
}

void Books::PrintBooks()
{
	cout << "-----------------------------------------" << endl << endl;
	cout << "NameNewpapers" << " " << NameNewpapers << endl;
	cout << "Publisher    " << " " << Publisher << endl;
	cout << "Author       " << " " << Author << endl;
	cout << "Genre        " << " " << Genre << endl;
	cout << "YuarPublish  " << " " << YuarPublish << endl;
	cout << "-----------------------------------------" << endl << endl;
}
void Books::Fillcreate()
{

	cout << "NameNewpaper   ";
	cin.ignore();
	getline(cin, NameNewpapers);
	cout << "Publisher      "; getline(cin, Publisher);
	cout << "Author         "; getline(cin, Author);
	cout << "Genre          "; getline(cin, Genre);
	cout << "YuarPublish    "; cin >> YuarPublish;
}

//ФУНКЦИЯ КАКАЯ СОЗДАЁТ МАССИВ
void Fill(Books* Bookss, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		Bookss[i].FillBooks();
	}
}
//ФУНКЦИЯ КАКАЯ ДОСОЗДАЁТ ДОБАВЛЕНИЕ ЕЛЕМЕНТЫ МАСИВА
void FillA(Books* Bookss, int SIZE)
{
	for (int i = SIZE - 1; i < SIZE; i++)
	{
		Bookss[i].Fillcreate();
	}
}
//ФУНКЦИЯ КАКАЯ ПЕРЕНОСИТ ИЗ ОДНОГО МАССИВА В ДРУГОЙ ПРИ ЕГО УВИЛИЧЕНИИ
void Filladditeon(Books*& Bookss, int& SIZE)
{
	Books* Bookss1 = new Books[SIZE + 1];
	for (int i = 0; i < SIZE; i++)
	{
		Bookss1[i] = Bookss[i];
	}
	Bookss1[SIZE].FillBooks();
	SIZE = SIZE + 1;
	delete[]Bookss;
	Bookss = Bookss1;
}


void DeleteBooks(Books*& Bookss, int del, int& SIZE)
{
	Books* Bookss1 = new Books[SIZE - 1];
	//cin >> del;
	SIZE--;
	for (int i = 0; i < SIZE; i++)
	{
		if (i < del)
		{
			Bookss1[i] = Bookss[i];
		}
		else if (i >= del)
		{
			Bookss1[i] = Bookss[i + 1];
			//CountOfDeletedPatinets++;
		}
	}
	delete[] Bookss;
	Bookss = Bookss1;
}


//ФУНКЦИЯ КАКАЯ ВЫВОДИТ МАССИВ
void Arrouput(Books* Bookss1, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "№" << i + 1 << "	КНИГИ" << endl;
		Bookss1[i].PrintBooks();
	}
	cout << endl;
}

void Funcmenu(Books* Bookss, int SIZE, int z)
{
	int del;
	cout << "МЕНЮ" << endl;
	Fill(Bookss, SIZE);
	Arrouput(Bookss, SIZE);

	do
	{
		cout << "1. Добавить журнал\n 2. Удалить журнал\n  3. Выход\n";
		cin >> z;
		if (z == 1)
		{
			system("cls");
			cout << "Добавить журнал\n\n";


			Filladditeon(Bookss, SIZE);
			FillA(Bookss, SIZE);
			Arrouput(Bookss, SIZE);


		}
		else if (z == 2)
		{
			system("cls");
			cout << "Удалить журнал за порядковим Номером\n\n";

			cin >> del;

			DeleteBooks(Bookss, del, SIZE);
			Arrouput(Bookss, SIZE);
		}


	} while (z != 3);
}

void YuarPublishBooks(Books* Bookss, int SIZE)//Выводит количество книга по году.
{
	int counter1 = 0;
	int counter = 0;
	cout << "Год выпуска " << "  с  1955  до  2020  " << endl;
	int a;
	cout << "YuarPublish";
	cin.ignore();
	cin >> a;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Bookss[i].YuarPublish)
			{
				counter1++;
				counter = i;
				Bookss[counter].PrintBooks();
			}
		}

	}
	if (counter == 0)
	{
		cout << " ЗА ЭТОТ ГОД КНИГ НЕТУ" << endl;
	}
	else
		cout << counter1 << "   ВСЕГО КНИГ ЗА ЭТОТ ГОД" << endl;
}



void CouterBooks(Books* Bookss, int SIZE)//Выводит количество книг по рубрике.
{
	int counter1 = 0;
	int counter = 0;
	cout <<"Melodrama  "<<"Dedektiv  "<<"Uzasi  "<<"fentazi" << endl;
	string a;
	cout << "Genre  ";
	cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Bookss[i].Genre)
			{
				counter1++;
				counter = i;
				Bookss[counter].PrintBooks();
			}
		}

	}
	if (counter == 0)
	{
		cout << " НА ЭТУ ТЕМУ КНИГ НЕТ " << endl;
	}
	else

		cout << counter1 << "   ВСЕГО КНИГ НА ЭТУ ТЕМУ" << endl;
}

void AuthorBooks(Books* Bookss, int SIZE)//Выводит количество книг по автору.
{
	int counter1 = 0;
	int counter = 0;
	cout << "  Averin_Sergii"<<"  Titov_Maksim"<<"  Tolstoi_Lev"<<"  Chehov" << endl;
	string a;
	cout << "Author  ";
	cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Bookss[i].Author)
			{
				counter1++;
				counter = i;
				Bookss[counter].PrintBooks();
			}
		}

	}
	if (counter == 0)
	{
		cout << " ПОД ЭТИМ АВТОРОМ КНИГ НЕ ВЫПУСКАЛСЯ " << endl;
	}
	else

		cout << counter1 << "   ВСЕГО КНИГ НАПИСАЛ ЄТОТ АВТОР" << endl;
}
void NameNewpapersBooks(Books* Bookss, int SIZE)//Выводит количество книг по названию.
{
	int counter1 = 0;
	int counter = 0;
	cout<< "Ugrum_Reka  "<<"Asia "<<"Vavilon  "<<"Dva_Kapitana  "<<"Titanik  "<<"Igla  "<<"Strax  "<<"Na_Grani  "<<"Forsach  "<<"Pro_Eto  "<<"Maria  "<<"Svolochi"<<endl;
	string a;
	cout << "NameNewpapers  ";
	cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Bookss[i].NameNewpapers)
			{
				counter1++;
				counter = i;
				Bookss[counter].PrintBooks();
			}
		}

	}
	if (counter == 0)
	{
		cout << " ТАКОЙ КНИГИ НЕТ " << endl;
	}
	else

	cout << counter1 << "  ПОД ТАКИМ НАЗВАНИЕМ " << endl;
}