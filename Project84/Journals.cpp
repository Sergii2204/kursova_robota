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

//������� ����� ������� ������
void Fill(Journals* Journalss, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		Journalss[i].FillJournals();
	}
}
//������� ����� ��������� ���������� �������� ������
void FillA(Journals* Journalss, int SIZE)
{
	for (int i = SIZE - 1; i < SIZE; i++)
	{
		Journalss[i].Fillcreate();
	}
}
//������� ����� ��������� �� ������ ������� � ������ ��� ��� ����������
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


//������� ����� ������� ������
void Arrouput(Journals* Journalss1, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "�" << i + 1 <<"	������"<< endl;
		Journalss1[i].PrintJournals();
	}
	cout << endl;
}

void Funcmenu(Journals* Journalss, int SIZE, int z)
{
	int del;
	cout << "����" << endl;
	Fill(Journalss, SIZE);
	Arrouput(Journalss, SIZE);

	do
	{
		cout << "1. �������� ������\n 2. ������� ������\n  3. �����\n";
		cin >> z;
		if (z == 1)
		{
			system("cls");
			cout << "�������� ������\n\n";


			Filladditeon(Journalss, SIZE);
			FillA(Journalss, SIZE);
			Arrouput(Journalss, SIZE);


		}
		else if (z == 2)
		{
			system("cls");
			cout << "������� ������ �� ���������� �������\n\n";

			cin >> del;

			DeleteJournals(Journalss, del, SIZE);
			Arrouput(Journalss, SIZE);
		}


	} while (z != 3);
}



void NameNewpapersJournals(Journals*& Journalss, int SIZE)//������� ���������� ����� �� �������� �������.
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
		cout << " � ����� ��������� �������� ��� " << endl;
	}
	else

		cout << counter1 << "   ����� �������� � ����� ���������" << endl;
}

void YuarPublishJournals(Journals*& Journalss, int SIZE)//������� ���������� �������� �� ����.
{
	int counter1 = 0;
	int counter = 0;
	cout << "��� ������� " << "  �  1955  ��  2020  " << endl;
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
		cout << " �� ���� ��� �������� ����" << endl;
	}
	else
		cout << counter1 << "   ����� �������� �� ���� ���" << endl;

}



void CouterJournals(Journals*& Journalss, int SIZE)//������� ���������� �������� �� �������.
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
		cout << " �� ��� ���� �������� ��� " << endl;
	}
	else

		cout << counter1 << "   ����� �������� �� ��� ����" << endl;
}

void AuthorJournals(Journals*& Journalss, int SIZE)//������� ���������� �������� �� ������.
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
		cout << " ��� ���� ������� ������ �� ���������� " << endl;
	}
	else

	cout << counter1 << "   ����� �������� ��� ���� �������" << endl;
}