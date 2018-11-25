#pragma once
#include <iostream>
using namespace std;
class Book
{
	struct Data // структура данных
	{
		char* author;
		char* name_book;
		char* publishing_house;
		int* year;
		int* count_pages;
		char* place_of_publication;
		Book *next;
	} book;
public:
	Book();
	Book(const Book& ob);
	~Book();
	void printOne(Book *b);
	void print(Book **mas, int kol);
	void print(Book **mas, int kol, char* author);
	void search_author_and_print(Book **mas, int kol, char* author);
	void search_publishing_house_and_print(Book **mas, int kol, char* publishing_house);
	void search_book_after_year_and_print(Book **mas, int kol, int year);
	void clear(Book *&head);
	void creatArray(Book *head, Book **&mas, int kol);
	void init(Book *&head, int &kol);
	void creatOneStr(Book *b, int n, char *buff);
	void readData(FILE *in, Book *&head, Book **&mas, int &kol);
	void writeData(FILE *out, Book **mas, int kol);
};
void quit();