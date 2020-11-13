#include<iostream>
#include<string>
#include<iomanip>
#include<time.h>
#include <conio.h>
#include<fstream>
#include <windows.h>
#include"Newspapers.h"
#include"Journals.h"
#include"Books.h"
using namespace std;


void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { -30, 5, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}
int Menu(string menu_items[], int SIZE) {
	int key = 0;
	int code;
	do {
		key = (key + SIZE) % SIZE;
		for (int i = 0; i < SIZE; i++)
		{
			SetPos(15, 15 + i);
			if (key == i)
			{
				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}
		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}



void main()
{

	//srand(time(0));
	setlocale(LC_ALL, "rus");

	Size_Console(45, 35);
	int SIZE = 20;
	Newspapers* Newspaperss = new Newspapers[SIZE];
	{
		Fill(Newspaperss, SIZE);
	}
	Books* Bookss = new Books[SIZE];
	{
		Fill(Bookss, SIZE);

	}
	Journals* Journalss = new Journals[SIZE];
	{
		Fill(Journalss, SIZE);
	}
	int del;
	int z = 0;
	//	int m = 0;
	int m = 0;
	do
	{
		string menu[] = { "ÃÀÇÅÒÛ","ÆÓÐÍÀËÛ","ÊÍÈÃÈ","ÏÎËÍÛÉ ÑÏÈÑÎÊ","ÂÛÕÎÄ" };
		m = Menu(menu, size(menu));

		if (m == 0)
		{
		
			do
			{
				string menu[] = { "ÄÎÁÀÂÈÒÜ ÃÀÇÅÒÓ","ÓÄÀËÈÒÜ ÃÀÇÅÒÓ","ÈÑÊÀÒÜ ÏÎ ÍÀÇÂÀÍÈÞ ÃÀÇÅÒÓ ","ÈÑÊÀÒÜ ÏÎ ÃÎÄÓ ÂÛÏÓÑÊÀ ÃÀÇÅÒÓ ","ÈÑÊÀÒÜ ÏÎ ÀÂÒÎÐÓ ÃÀÇÅÒÓ ","ÈÑÊÀÒÜ ÏÎ ÆÀÍÐÓ ÃÀÇÅÒÓ ","ÂÛÕÎÄ" };
						z = Menu(menu, size(menu));
				
						if (z == 0)
						{
							system("cls");
							cout << "Äîáàâèòü ãàçåòó\n\n";
							Filladditeon(Newspaperss, SIZE);
							FillA(Newspaperss, SIZE);
							Arrouput(Newspaperss, SIZE);
						}
						if (z == 1)
						{
							system("cls");
							cout << "Óäàëèòü ãàçåòó çà ïîðÿäêîâèì Íîìåðîì\n\n";
							cin >> del;
							DeleteNewspapers(Newspaperss, del, SIZE);
							Arrouput(Newspaperss, SIZE);
						}
						if (z == 2)
						{
							NameNewpapersNewspapers(Newspaperss, SIZE);
						}
						if (z == 3)
						{
							YuarPublishNewspapers(Newspaperss, SIZE);
						}
						if (z == 4)
						{
							AvtorNewspapers(Newspaperss, SIZE);
						}if (z == 5)
						{
							CouterNewspapers(Newspaperss, SIZE);
						}
						cout << "\n\n\t\t\tÂÛÕÎÄ\n\n";
						system("pause");
						system("cls");
			} while (z != 6);
	
		}
		if (m == 1)
		{
			do
			{
				string menu[] = { "ÄÎÁÀÂÈÒÜ ÆÓÐÍÀË","ÓÄÀËÈÒÜ ÆÓÐÍÀË","ÈÑÊÀÒÜ ÏÎ ÍÀÇÂÀÍÈÞ ÆÓÐÀÍË ","ÈÑÊÀÒÜ ÏÎ ÃÎÄÓ ÂÛÏÓÑÊÀ ÆÓÐÀÍËÓ ","ÈÑÊÀÒÜ ÏÎ ÀÂÒÎÐÓ ÆÓÐÀÍË ","ÈÑÊÀÒÜ ÏÎ ÆÀÍÐÓ ÆÓÐÀÍÀË ","ÂÛÕÎÄ" };
				z = Menu(menu, size(menu));
				if (z == 0)
				{
					system("cls");
					cout << "Äîáàâèòü æóðíàë\n\n";
					Filladditeon(Journalss, SIZE);
					FillA(Journalss, SIZE);
					Arrouput(Journalss, SIZE);
				}
				if (z == 1)
				{
					system("cls");
					cout << "Óäàëèòü æóðíàë çà ïîðÿäêîâèì Íîìåðîì\n\n";
					cin >> del;
					DeleteJournals(Journalss, del, SIZE);
					Arrouput(Journalss, SIZE);
				}
				if (z == 2)
				{ 
					NameNewpapersJournals(Journalss, SIZE);
				}
				if (z == 3)
				{
					YuarPublishJournals(Journalss, SIZE);
				}
				if (z == 4)
				{
					AuthorJournals(Journalss, SIZE);
				}if (z == 5)
				{
					CouterJournals(Journalss, SIZE);
				}
				cout << "\n\n\t\t\tÂÛÕÎÄ\n\n";
				system("pause");
				system("cls");
			} while (z != 6);
		}
		if (m == 2)
		{
			do
			{
				string menu[] = { "ÄÎÁÀÂÈÒÜ ÊÍÈÃÓ","ÓÄÀËÈÒÜ ÊÍÈÃÓ","ÈÑÊÀÒÜ ÏÎ ÍÀÇÂÀÍÈÞ ÊÍÈÃÓ ","ÈÑÊÀÒÜ ÏÎ ÃÎÄÓ ÂÛÏÓÑÊÀ ÊÍÈÃÓ ","ÈÑÊÀÒÜ ÏÎ ÀÂÒÎÐÓ ÊÍÈÃÓ ","ÈÑÊÀÒÜ ÏÎ ÆÀÍÐÓ ÊÍÈÃÓ ","ÂÛÕÎÄ" };
				z = Menu(menu, size(menu));
				if (z == 0)
				{
					system("cls");
					cout << "Äîáàâèòü êíèãó\n\n";
					Filladditeon(Bookss, SIZE);
					FillA(Bookss, SIZE);
					Arrouput(Bookss, SIZE);
				}
				if (z == 1)
				{
					system("cls");
					cout << "Óäàëèòü êíèãó çà ïîðÿäêîâèì Íîìåðîì\n\n";
					cin >> del;
					DeleteBooks(Bookss, del, SIZE);
					Arrouput(Bookss, SIZE);
				}
				if (z == 2)
				{
					NameNewpapersBooks(Bookss, SIZE);
				}
				if (z == 3)
				{
					YuarPublishBooks(Bookss, SIZE);
				}
				if (z == 4)
				{
					AuthorBooks(Bookss, SIZE);
				}if (z == 5)
				{
					CouterBooks(Bookss, SIZE);
				}
				cout << "\n\n\t\t\tÂÛÕÎÄ\n\n";
				system("pause");
				system("cls");
			} while (z != 6);
		}
		if (m == 3)
		{
			Arrouput(Newspaperss, SIZE);
			Arrouput(Journalss,SIZE);
			Arrouput(Bookss, SIZE);
		}
		cout << "\n\n\t\t\tÂÛÕÎÄ\n\n";
		system("pause");
		system("cls");
	} while (m != 4);
}