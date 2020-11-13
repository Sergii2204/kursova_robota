#include "Newspapers.h"
//#include<iostream>
//#include<string>
//#include<iomanip>
//#include<time.h>
//#include <conio.h>
//#include<fstream>
//#include <windows.h>
//void SetColor(int col)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
//}
//
//void SetPos(int x, int y)
//{
//	COORD c;
//	c.X = x;
//	c.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}
//void Size_Console(int x, int y)
//{
//	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD crd = { x, y };
//	SMALL_RECT src = { -30, 5, crd.X , crd.Y };
//	SetConsoleWindowInfo(out_handle, true, &src);
//	SetConsoleScreenBufferSize(out_handle, crd);
//}
//int Menu(string menu_items[], int SIZE) {
//	int key = 0;
//	int code;
//	do {
//		key = (key + SIZE) % SIZE;
//		for (int i = 0; i < SIZE; i++)
//		{
//			SetPos(15, 15 + i);
//			if (key == i)
//			{
//				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
//			}
//			else
//			{
//				cout << " "; cout << menu_items[i]; cout << " " << endl;
//			}
//		}
//		code = _getch();
//		if (code == 224)
//		{
//			code = _getch();
//			if (code == 80) key++;
//			if (code == 72) key--;
//		}
//	} while (code != 13);
//	system("cls");
//	return key;
//}



void Newspapers::create()
{
	string N[12]{ "Zirka","Pravda","Slovo","Kiev","Moskva","Minsk","Golos","Patriot","Voin","Ogorod","Esquire","Times" };
	string P[4]{ "Zora","Bukva","Maiak","Luch" };
	string A[3]{ "Ivanov_Sergii","Pavlov_Maksim","Rabochapka" };
	string G[4]{ "Politika","Kriminal","Stati","Teleprogramma" };
	int n, p, a, g, y;
	n= rand() % 12;
	p= rand() % 4;
	a= rand() % 3;
	g= rand() % 4;
	NameNewpapers = N[n];
	Publisher = P[p];
	Author = A[a];
	Genre = G[g];
	/*count++;*/
	YuarPublish=1955+rand() % 65;
	del;
	//issued;

}

void Newspapers::Printcreat()
{
	cout << "-----------------------------------------" << endl<<endl;
	cout << "NameNewpapers" << " " << NameNewpapers << endl;
	cout << "Publisher    " << " " << Publisher << endl;
	cout << "Author       " << " " << Author << endl;
	cout << "Genre        " << " " << Genre << endl;
	cout << "YuarPublish  " << " " << YuarPublish << endl;
	cout << "-----------------------------------------" << endl << endl;

}

void Newspapers::Fillcreate()
{
cout << "NameNewpaper   ";
cin.ignore();
getline(cin,NameNewpapers);
cout << "Publisher      ";getline(cin,Publisher);
cout << "Author         "; getline(cin,Author);
cout << "Genre          "; getline(cin,Genre);
cout << "YuarPublish    "; cin >>YuarPublish;
}

//ÔÓÍÊÖÈß ÊÀÊÀß ÑÎÇÄÀ¨Ò ÌÀÑÑÈÂ
void Fill(Newspapers* Newspaperss, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		Newspaperss[i].create();
	}
}

//ÔÓÍÊÖÈß ÊÀÊÀß ÄÎÑÎÇÄÀ¨Ò ÄÎÁÀÂËÅÍÈÅ ÅËÅÌÅÍÒÛ ÌÀÑÈÂÀ
void FillA(Newspapers* Newspaperss, int SIZE)
{
	for (int i = SIZE-1; i < SIZE; i++)
	{
		Newspaperss[i].Fillcreate();
	}
}
//ÔÓÍÊÖÈß ÊÀÊÀß ÏÅĞÅÍÎÑÈÒ ÈÇ ÎÄÍÎÃÎ ÌÀÑÑÈÂÀ Â ÄĞÓÃÎÉ ÏĞÈ ÅÃÎ ÓÂÈËÈ×ÅÍÈÈ
void Filladditeon( Newspapers*& Newspaperss, int& SIZE)
{
	Newspapers* Newspaperss1 = new Newspapers[SIZE + 1];
	for (int i = 0; i < SIZE; i++)
	{
		Newspaperss1[i] = Newspaperss[i];
	}
	Newspaperss1[SIZE].create();
	SIZE = SIZE + 1;
	delete[]Newspaperss;
	Newspaperss = Newspaperss1;
}


void DeleteNewspapers(Newspapers*& Newspaperss,int del,int &SIZE)
{
	Newspapers* Newspaperss1 = new Newspapers[SIZE - 1];
	//cin >> del;
	SIZE--;
	for (int i = 0; i < SIZE; i++)
	{
		if (i < del)
		{
			Newspaperss1[i] = Newspaperss[i];
		}
		else if (i >= del)
		{
			Newspaperss1[i] = Newspaperss[i + 1];
			//CountOfDeletedPatinets++;
		}
	}
	delete[] Newspaperss;
	Newspaperss = Newspaperss1;
}


//ÔÓÍÊÖÈß ÊÀÊÀß ÂÛÂÎÄÈÒ ÌÀÑÑÈÂ
void Arrouput(Newspapers* Newspaperss1, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "¹" << i + 1 << "	ÃÀÇÅÒÀ"<< endl;
		Newspaperss1[i].Printcreat();
	}
	cout << endl;
}

void Funcmenu(Newspapers* Newspaperss, int SIZE, int z)
{

}
//{
//
//	//int m = 0;
//	setlocale(LC_ALL, "rus");
//	int del;
//	cout << "ÃÀÇÅÒÛ" << endl;
//	Fill(Newspaperss, SIZE);
//	Arrouput(Newspaperss, SIZE);
//	Size_Console(45, 35);
//	//int z;
//	do
//	{
//		string menu[] = { "ÄÎÁÀÂÈÒÜ ÃÀÇÅÒÓ","ÓÄÀËÈÒÜ ÃÀÇÅÒÓ","ÈÑÊÀÒÜ ÏÎ ÍÀÇÂÀÍÈŞ ÃÀÇÅÒÓ ","ÈÑÊÀÒÜ ÏÎ ÃÎÄÓ ÂÛÏÓÑÊÀ ÃÀÇÅÒÓ ","ÈÑÊÀÒÜ ÏÎ ÀÂÒÎĞÓ ÃÀÇÅÒÓ ","ÈÑÊÀÒÜ ÏÎ ÆÀÍĞÓ ÃÀÇÅÒÓ ","ÂÛÕÎÄ" };
//		z = Menu(menu, size(menu));
//
//		if (z == 0)
//		{
//			system("cls");
//			cout << "Äîáàâèòü æóğíàë\n\n";
//
//
//			Filladditeon(Newspaperss, SIZE);
//			FillA(Newspaperss, SIZE);
//			Arrouput(Newspaperss, SIZE);
//		}
//		if (z == 1)
//		{
//			system("cls");
//			cout << "Óäàëèòü æóğíàë çà ïîğÿäêîâèì Íîìåğîì\n\n";
//			cin >> del;
//			DeleteNewspapers(Newspaperss, del, SIZE);
//			Arrouput(Newspaperss, SIZE);
//		}
//		if (z == 2)
//		{
//			NameNewpapersNewspapers(Newspaperss, SIZE);
//		}
//		if (z == 3)
//		{
//			YuarPublishNewspapers(Newspaperss, SIZE);
//		}
//		if (z == 4)
//		{
//			AvtorNewspapers(Newspaperss, SIZE);
//		}if (z == 5)
//		{
//			CouterNewspapers(Newspaperss, SIZE);
//		}
//		cout << "\n\n\t\t\tÂÛÕÎÄ\n\n";
//		system("pause");
//		system("cls");
//	} while (z != 6);
//}
	/*do
	{
		cout << "1. Äîáàâèòü æóğíàë\n 2. Óäàëèòü æóğíàë\n  3. Âûõîä\n";
		cin >> z;
		if (z == 1)
		{
			system("cls");
			cout << "Äîáàâèòü æóğíàë\n\n";
			
			
			Filladditeon(Newspaperss, SIZE);
			FillA(Newspaperss, SIZE);
			Arrouput(Newspaperss, SIZE);


		}
		else if (z == 2)
		{
			system("cls");
			cout << "Óäàëèòü æóğíàë çà ïîğÿäêîâèì Íîìåğîì\n\n";

			cin >> del;

			DeleteNewspapers(Newspaperss, del, SIZE);
				Arrouput(Newspaperss, SIZE);
		}


	} while (z != 3);
}*/


void NameNewpapersNewspapers(Newspapers*& Newspaperss, int SIZE)//Âûâîäèò êîëè÷åñòâî ãàçåò ïî íàçâàíèş æóğàíëà.
{
	int counter2 = 0;
	int counter = 0;
	cout << "Zirka  "<<"Pravda  "<<"Slovo  "<<"Kiev  "<<"Moskva  "<<"Minsk  \n"<<"Golos  "<<"Patriot  "<<"Voin  "<<"Ogorod  "<<  "Esquire  "<<  "Times" << endl;
	
	string a;
	cout << "NameNewpapers\t";
	//cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Newspaperss[i].NameNewpapers)
			{
				counter2++;
				counter = i;
				Newspaperss[counter].Printcreat();
			}
		}

	}
	if (counter2 == 0)
	{
		cout << " Ñ ÒÀÊÈÌ ÍÀÇÂÀÍÈÅÌ ÃÀÇÅÒ ÍÅÒ " << endl;
	}
	else

		cout << counter2 << "   ÂÑÅÃÎ ÃÀÇÅÒ Ñ ÒÀÊÈÌ ÍÀÇÂÀÍÈÅÌ" << endl;
}

void YuarPublishNewspapers(Newspapers*& Newspaperss, int SIZE)//Âûâîäèò êîëè÷åñòâî ãàçåò ïî ãîäó.
{
	int counter1 = 0;
	int counter = 0;
	cout << "Ãîä âûïóñêà "<<"  ñ  1950  äî  2020  " << endl;
	int a;
	cout << "YuarPublish\t";
	//cin.ignore();
	cin >> a;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Newspaperss[i].YuarPublish)
			{
				counter1++;
				counter = i;
				Newspaperss[counter].Printcreat();
			}
		}

	}
	if (counter1 == 0)
	{
		cout << " ÇÀ İÒÎÒ ÃÎÄ ÃÀÇÅÒ ÍÅÒÓ" << endl;
	}
	else
	cout << counter1 << "   ÂÑÅÃÎ ÃÀÇÅÒ ÇÀ İÒÎÒ ÃÎÄ" << endl;
}



void CouterNewspapers(Newspapers*& Newspaperss, int SIZE)//Âûâîäèò êîëè÷åñòâî ãàçåò ïî ğóáğèêå.
{
	int counter1 = 0;
	int counter = 0;
	cout << "Politika  " << "Kriminal  " << "Stati  " << "Teleprogramma" << endl;
	string a;
	cout << "Genre";
	//cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Newspaperss[i].Genre)
			{
				counter1++;
				counter = i;
	           Newspaperss[counter].Printcreat();
			}
		}

	}
	if (counter1 == 0)
	{
		cout << " ÍÀ İÒÓ ÒÅÌÓ ÃÀÇÅÒ ÍÅÒ " << endl;
	}
	else

	cout << counter1 << "   ÂÑÅÃÎ ÃÀÇÅÒ ÍÀ İÒÓ ÒÅÌÓ" << endl;
}
void AvtorNewspapers(Newspapers*& Newspaperss, int SIZE)//Âûâîäèò êîëè÷åñòâî ãàçåò àâòîğà.
{
	int counter1 = 0;
	int counter = 0;
	cout << "Ivanov_Sergii  "<< "Pavlov_Maksim  "<< "Rabochapka" << endl;
	string a;
	cout << "Author";
	//cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Newspaperss[i].Author)
			{
				counter1++;
				counter = i;
				Newspaperss[counter].Printcreat();
			}
		}

	}
	if (counter1 == 0)
	{
		cout << " ÏÎÄ İÒÈÌ ÀÂÒÎĞÎÌ ÃÀÇÅÒ ÍÅ ÂÛÏÓÑÊÀËÎÑÜ " << endl;
	}
	else

	cout << counter1 << "   ÊÎËÈ×ÅÑÒÂÎ ÃÀÇÅÒ ÀÂÒÎĞÀ" << endl;
}


