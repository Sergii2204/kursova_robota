#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Books
{
	string NameNewpapers;//название журанала
	string Publisher;//название издательства
	string Author;//Автор
	string Genre;//жанр
	int YuarPublish;//год Издательства
	void FillBooks();
	void PrintBooks();
	void Fillcreate();
};
void Fill(Books* Bookss, int SIZE);
void FillA(Books* Bookss, int SIZE);
void Filladditeon(Books*& Bookss, int& SIZE);
void DeleteBooks(Books*& Bookss, int del, int& SIZE);
void Arrouput(Books* Bookss1, int SIZE);
void Funcmenu(Books* Bookss, int SIZE, int z);
void CouterBooks(Books* Bookss, int SIZE);
void YuarPublishBooks(Books* Bookss, int SIZE);//Выводит количество книга по году.
void CouterBooks(Books* Bookss, int SIZE);//Выводит количество книг по рубрике.
void AuthorBooks(Books* Bookss, int SIZE);//Выводит количество книг по автору.
void NameNewpapersBooks(Books* Bookss, int SIZE);//Выводит количество книг по названию.
