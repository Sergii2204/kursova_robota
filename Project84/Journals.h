#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Journals
{
	string NameNewpapers;//название журанала
	string Publisher;//название издательства
	string Author;//Автор
	string Genre;//жанр
	int YuarPublish;//год Издательства
	void FillJournals();
	void PrintJournals();
	void Fillcreate();
};

void Fill(Journals* Journalss, int SIZE);
void FillA(Journals* Journalss, int SIZE);
void Filladditeon(Journals*& Journalss, int& SIZE);
void DeleteJournals(Journals*& Journalss, int del, int& SIZE);
void Arrouput(Journals* Journalss1, int SIZE);
void Funcmenu(Journals* Journalss, int SIZE, int z);
void NameNewpapersJournals(Journals*& Journalss, int SIZE);//Выводит количество газет по названию журанла.
void YuarPublishJournals(Journals*& Journalss, int SIZE);//Выводит количество журналов по году.
void AuthorJournals(Journals*& Journalss, int SIZE);
void CouterJournals(Journals*& Journalss, int SIZE);//Выводит количество журналов по рубрике.
