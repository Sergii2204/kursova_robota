#include "Journals.h"

void Journals::FillJournals()
{
	string N[12]{ "Ara","Armia","Vesnik","Vrema","Vorota","Koval","Istorii","Nauka","Ditu","Dosug","Zakon","Vozrogdenie" };
	string P[4]{ "Art_Kompleks","Avesta","Buratino","Terminal" };
	string A[3]{ "Prusakova.A.A.","Chuprik.S.V","Ilinska.V.O" };
	string G[5]{ "Politika","Kriminal","Kultura","Dosug","Dosug" };
	int n, p, a, g, y;
	n = rand() % 12;
	p = rand() % 4;
	a = rand() % 3;
	g = rand() % 5;
	NameNewpapers = N[n];
	Publisher = P[p];
	Author = A[a];
	Genre = G[g];
	YuarPublish = 1955 + rand() % 55;
}

void Journals::PrintJournals()
{
	cout << "-----------------------------------------" << endl << endl;
	cout << "NameNewpapers" << " " << NameNewpapers << endl;
	cout << "Publisher    " << " " << Publisher << endl;
	cout << "Author       " << " " << Author << endl;
	cout << "Genre        " << " " << Genre << endl;
	cout << "YuarPublish  " << " " << YuarPublish << endl;
	cout << "-----------------------------------------" << endl << endl;
}

void Journals::Fillcreate()
{

	cout << "NameNewpaper   ";
	cin.ignore();
	getline(cin, NameNewpapers);
	cout << "Publisher      "; getline(cin, Publisher);
	cout << "Author         "; getline(cin, Author);
	cout << "Genre          "; getline(cin, Genre);
	cout << "YuarPublish    "; cin >> YuarPublish;
}

//ÔÓÍÊÖÈß ÊÀÊÀß ÑÎÇÄÀ¨Ò ÌÀÑÑÈÂ
void Fill(Journals* Journalss, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		Journalss[i].FillJournals();
	}
}
//ÔÓÍÊÖÈß ÊÀÊÀß ÄÎÑÎÇÄÀ¨Ò ÄÎÁÀÂËÅÍÈÅ ÅËÅÌÅÍÒÛ ÌÀÑÈÂÀ
void FillA(Journals* Journalss, int SIZE)
{
	for (int i = SIZE - 1; i < SIZE; i++)
	{
		Journalss[i].Fillcreate();
	}
}
//ÔÓÍÊÖÈß ÊÀÊÀß ÏÅĞÅÍÎÑÈÒ ÈÇ ÎÄÍÎÃÎ ÌÀÑÑÈÂÀ Â ÄĞÓÃÎÉ ÏĞÈ ÅÃÎ ÓÂÈËÈ×ÅÍÈÈ
void Filladditeon(Journals*& Journalss, int& SIZE)
{
	Journals* Journalss1 = new Journals[SIZE + 1];
	for (int i = 0; i < SIZE; i++)
	{
		Journalss1[i] = Journalss[i];
	}
	Journalss1[SIZE].FillJournals();
	SIZE = SIZE + 1;
	delete[]Journalss;
	Journalss = Journalss1;
}


void DeleteJournals(Journals*& Journalss, int del, int& SIZE)
{
	Journals* Journalss1 = new Journals[SIZE - 1];
	//cin >> del;
	SIZE--;
	for (int i = 0; i < SIZE; i++)
	{
		if (i < del)
		{
			Journalss1[i] = Journalss[i];
		}
		else if (i >= del)
		{
			Journalss1[i] = Journalss[i + 1];
			//CountOfDeletedPatinets++;
		}
	}
	delete[] Journalss;
	Journalss = Journalss1;
}


//ÔÓÍÊÖÈß ÊÀÊÀß ÂÛÂÎÄÈÒ ÌÀÑÑÈÂ
void Arrouput(Journals* Journalss1, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "¹" << i + 1 <<"	ÆÓĞÍÀË"<< endl;
		Journalss1[i].PrintJournals();
	}
	cout << endl;
}

void Funcmenu(Journals* Journalss, int SIZE, int z)
{
	int del;
	cout << "ÌÅÍŞ" << endl;
	Fill(Journalss, SIZE);
	Arrouput(Journalss, SIZE);

	do
	{
		cout << "1. Äîáàâèòü æóğíàë\n 2. Óäàëèòü æóğíàë\n  3. Âûõîä\n";
		cin >> z;
		if (z == 1)
		{
			system("cls");
			cout << "Äîáàâèòü æóğíàë\n\n";


			Filladditeon(Journalss, SIZE);
			FillA(Journalss, SIZE);
			Arrouput(Journalss, SIZE);


		}
		else if (z == 2)
		{
			system("cls");
			cout << "Óäàëèòü æóğíàë çà ïîğÿäêîâèì Íîìåğîì\n\n";

			cin >> del;

			DeleteJournals(Journalss, del, SIZE);
			Arrouput(Journalss, SIZE);
		}


	} while (z != 3);
}



void NameNewpapersJournals(Journals*& Journalss, int SIZE)//Âûâîäèò êîëè÷åñòâî ãàçåò ïî íàçâàíèş æóğàíëà.
{
	int counter1 = 0;
	int counter = 0;
	cout << "  Ara"<<"  Armia"<<"  Vesnik"<<"  Vrema"<<"  Vorota"<<"  Koval"<<"  Istorii\n"<<"  Nauka"<<"  Ditu"<<"Dosug  "<<"Zakon  "<<"Vozrogdenie" << endl;
	string a;
	cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Journalss[i].NameNewpapers)
			{
				counter1++;
				counter = i;
				Journalss[counter].PrintJournals();
			}
		}

	}
	if (counter == 0)
	{
		cout << " Ñ ÒÀÊÈÌ ÍÀÇÂÀÍÈÅÌ ÆÓĞÀÍËÎÂ ÍÅÒ " << endl;
	}
	else

		cout << counter1 << "   ÂÑÅÃÎ ÆÓĞÍÀËÎÂ Ñ ÒÀÊÈÌ ÍÀÇÂÀÍÈÅÌ" << endl;
}

void YuarPublishJournals(Journals*& Journalss, int SIZE)//Âûâîäèò êîëè÷åñòâî æóğíàëîâ ïî ãîäó.
{
	int counter1 = 0;
	int counter = 0;
	cout << "Ãîä âûïóñêà " << "  ñ  1955  äî  2020  " << endl;
	int a;
	cin.ignore();
	cin >> a;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Journalss[i].YuarPublish)
			{
				counter1++;
				counter = i;
				Journalss[counter].PrintJournals();
			}
		}

	}
	if (counter == 0)
	{
		cout << " ÇÀ İÒÎÒ ÃÎÄ ÆÓĞÍÀËÎÂ ÍÅÒÓ" << endl;
	}
	else
		cout << counter1 << "   ÂÑÅÃÎ ÆÓĞÀÍËÎÂ ÇÀ İÒÎÒ ÃÎÄ" << endl;

}



void CouterJournals(Journals*& Journalss, int SIZE)//Âûâîäèò êîëè÷åñòâî æóğíàëîâ ïî ğóáğèêå.
{
	int counter1 = 0;
	int counter = 0;
	cout << "Politika  " << "Kriminal  " <<"Kultura  "<<"Dosug  "<<"Dosug " << endl;
	string a;
	cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Journalss[i].Genre)
			{
				counter1++;
				counter = i;
				Journalss[counter].PrintJournals();
			}
		}

	}
	if (counter == 0)
	{
		cout << " ÍÀ İÒÓ ÒÅÌÓ ÆÓĞÀÍËÎÂ ÍÅÒ " << endl;
	}
	else

		cout << counter1 << "   ÂÑÅÃÎ ÆÓĞÍÀËÎÂ ÍÀ İÒÓ ÒÅÌÓ" << endl;
}

void AuthorJournals(Journals*& Journalss, int SIZE)//Âûâîäèò êîëè÷åñòâî æóğíàëîâ ïî àâòîğó.
{
	int counter1 = 0;
	int counter = 0;
	cout << "Prusakova.A.A.  " << "  Chuprik.S.V  " << "  Ilinska.V.O" << endl;
	string a;
	cin.ignore();
	getline(cin, a);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (a == Journalss[i].Author)
			{
				counter1++;
				counter = i;
				Journalss[counter].PrintJournals();
			}
		}

	}
	if (counter == 0)
	{
		cout << " ÏÎÄ İÒÈÌ ÀÂÒÎĞÎÌ ÆÓĞÍÀË ÍÅ ÂÛÏÓÑÊÀËÑß " << endl;
	}
	else

	cout << counter1 << "   ÂÑÅÃÎ ÆÓĞÍÀËÎÂ ÏÎÄ İÒÈÌ ÀÂÒÎĞÎÌ" << endl;
}