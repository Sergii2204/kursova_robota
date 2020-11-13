#pragma once
#include<iostream>
#include<string>
//#include<iomanip>
//#include<time.h>
//#include <conio.h>
//#include<fstream>
//#include <windows.h>
using namespace std;
struct Newspapers
{
	
	string NameNewpapers;//название газеты
	string Publisher;//название издательства
	string Author;//Автор
	string Genre;//жанр
	int YuarPublish;//год Издательства
	int del;
	void create();
	void Printcreat();
	void Fillcreate();
	


};

void Fill(Newspapers* Newspaperss, int SIZE);
void FillA(Newspapers* Newspaperss, int SIZE);
void Filladditeon(Newspapers*& Newspaperss, int& SIZE);
void DeleteNewspapers(Newspapers*& Newspaperss,int del,int &SIZE);
void Arrouput(Newspapers* Newspaperss1, int SIZE);
void Funcmenu(Newspapers* Newspaperss, int SIZE,int z);
//void Search1(Newspapers*& NameNewpaperss, int SIZE);
void NameNewpapersNewspapers(Newspapers*& Newspaperss, int SIZE);//Выводит количество газет по названию журанла.
void CouterNewspapers(Newspapers*& Newspaperss, int SIZE);
void AvtorNewspapers(Newspapers*& Newspaperss, int SIZE);//Выводит количество газет автора.
void YuarPublishNewspapers(Newspapers*& Newspaperss, int SIZE);//Выводит количество газет по году.