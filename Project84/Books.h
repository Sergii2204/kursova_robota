#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Books
{
	string NameNewpapers;//�������� ��������
	string Publisher;//�������� ������������
	string Author;//�����
	string Genre;//����
	int YuarPublish;//��� ������������
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
void YuarPublishBooks(Books* Bookss, int SIZE);//������� ���������� ����� �� ����.
void CouterBooks(Books* Bookss, int SIZE);//������� ���������� ���� �� �������.
void AuthorBooks(Books* Bookss, int SIZE);//������� ���������� ���� �� ������.
void NameNewpapersBooks(Books* Bookss, int SIZE);//������� ���������� ���� �� ��������.
