#include <iostream>
#include <Windows.h>
#include "Book.h"
using namespace std;

Book::Book()  // �����������
{
	book.author = new char[128];
	book.name_book = new char[128];
	book.publishing_house = new char[128];
	book.year = new int;
	book.count_pages = new int;
	book.place_of_publication = new char[128];
}
Book::Book(const Book& ob)                   // ����������� �����
{

}
Book::~Book() // ����������
{
	delete[] book.author;
	book.author = NULL;
	delete[] book.name_book;
	book.name_book = NULL;
	delete[] book.publishing_house;
	book.publishing_house = NULL;
	delete book.year;
	delete book.count_pages;
	delete[] book.place_of_publication;
	book.place_of_publication = NULL;
}
	//������� ������
void Book::printOne(Book *b)               // ������� ������ ����� ��������� 
{
	cout << "\n�����: ";
	cout << b->book.author << endl;
	cout << "��������: ";
	cout << b->book.name_book << endl;
	cout << "������������: ";
	cout << b->book.publishing_house << endl;
	cout << "���: ";
	cout << *b->book.year << endl;
	cout << "���������� �������: ";
	cout << *b->book.count_pages << endl;
	cout << "����� �������: ";
	cout << b->book.place_of_publication << endl;
}
void Book::print(Book **mas, int kol)                 // ������� ��������� ��������� �������
{
	for (int i = 0; i < kol; i++) {
		printOne(mas[i]);
	}
}
void Book::print(Book **mas, int kol, char* author)   // ������� ��������� ������ ���� ��������� ������
{
	for (int i = 0; i < kol; i++) {
		if (strcmp(mas[i]->book.author, author) == 0) {
			printOne(mas[i]);
		}
	}
}
void Book::search_author_and_print(Book **mas, int kol, char* author)   // ������� ��������� ������ ���� ��������� ������
{
	for (int i = 0; i < kol; i++) {
		if (strcmp(mas[i]->book.author, author) == 0) {
			printOne(mas[i]);
		}
	}
}
void Book::search_publishing_house_and_print(Book **mas, int kol, char* publishing_house)   // ������� ��������� ������ ���� ��������� ������
{
	for (int i = 0; i < kol; i++) {
		if (strcmp(mas[i]->book.publishing_house, publishing_house) == 0) {
			printOne(mas[i]);
		}
	}
}
void Book::search_book_after_year_and_print(Book **mas, int kol, int year)   // ������� ��������� ������ ���� ��������� ������
{
	for (int i = 0; i < kol; i++) {
		if (*mas[i]->book.year > year) {
			printOne(mas[i]);
		}
	}
}
void Book::clear(Book *&head) {                       // ������������ ������ ��� �������
	while (head != NULL) {
		Book *tmp = head;
		head = head->book.next;
		delete tmp;
	}
}
void Book::creatArray(Book *head, Book **&mas, int kol)     // �������� ������� ���������� �� �������� ������
{
	mas = new Book*[kol];                               // �������� ������ ��� ������ ����������
	int i = kol - 1;
	while (head != NULL) {
		mas[i] = head;
		i--;
		head = head->book.next;
	}
	clear(head);                                            // ������� ������
}
void Book::init(Book *&head, int &kol)                            // ������� ������� ����� ������ 
{
	char c[2];
	Book *elem = new Book;
	cout << "������� ������ �� ����� � " << kol + 1 << ":\n";
	cout << "�����: ";
	cin.getline(c, 2);
	cin.getline(elem->book.author, 128);
	cout << "��������: ";
	cin.getline(elem->book.name_book, 128);
	cout << "������������: ";
	cin.getline(elem->book.publishing_house, 128);
	cout << "���: ";
	cin >> *elem->book.year;
	cout << "���������� �������: ";
	cin >> *elem->book.count_pages;
	cin.getline(c, 2);
	cout << "����� �������: ";
	cin.getline(elem->book.place_of_publication, 128);
	elem->book.next = head;
	head = elem;
	kol++;
}
void Book::creatOneStr(Book *b, int n, char *buff)
{
	char tmp[6];
	//����� �����
	_itoa_s(n + 1, tmp, 10);
	strcat(buff, tmp);
	tmp[0] = 0;
	strcat(buff, ". ");
	// �����
	strcat(buff, b->book.author);
	strcat(buff, ",");
	// ��������
	strcat(buff, b->book.name_book);
	strcat(buff, ",");
	// ������������
	strcat(buff, b->book.publishing_house);
	strcat(buff, ",");
	// ���
	_itoa_s(*b->book.year, tmp, 10);
	strcat(buff, tmp);
	tmp[0] = 0;
	// ���������� �������
	strcat(buff, ",");
	_itoa_s(*b->book.count_pages, tmp, 10);
	strcat(buff, tmp);
	tmp[0] = 0;
	strcat(buff, ",");
	// ����� �������
	strcat(buff, b->book.place_of_publication);
	strcat(buff, "\n");
}
void Book::readData(FILE *in, Book *&head, Book **&mas, int &kol) {          // ������ ������ �� ����� � ������
	char filename[128];
	cout << "������� ��� ����� ��� ������: ";
	cin >> filename;
	if (fopen_s(&in, filename, "r") != 0) {
		cout << "�� ������� ������� ���� " << filename << " ��� ������\n";
		system("pause");
		exit(1);
	}
	kol = 0;
	char buffer[600];
	for (int i = 0; fgets(buffer, 600, in) != NULL; i++) {
		Book *tmp = new Book;
		char *word, *next;
		word = strtok_s(buffer, ". ", &next);
		word = strtok_s(NULL, ",", &next);
		strcpy_s(tmp->book.author, strlen(word)+1,word);
		word = strtok_s(NULL, ",", &next);
		strcpy_s(tmp->book.name_book, strlen(word) + 1, word);
		word = strtok_s(NULL, ",", &next);
		strcpy_s(tmp->book.publishing_house, strlen(word) + 1, word);
		word = strtok_s(NULL, ",", &next);
		*tmp->book.year = atoi(word);
		word = strtok_s(NULL, ",", &next);
		*tmp->book.count_pages = atoi(word);
		word = strtok_s(NULL, "\n", &next);
		strcpy_s(tmp->book.place_of_publication, strlen(word) + 1, word);
		tmp->book.next = head;
		head = tmp;
		kol++;
	}
	head->creatArray(head, mas, kol);
	if (fclose(in) != 0)
	{
		cout << "������ �������� ����� ��� ������\n";
		system("pause");
		exit(2);
	}
	cout << "������ ������� ��������� �� ����� " << filename << "\n";
}
void Book::writeData(FILE *out, Book **mas, int kol) { // ������� ������ � ����
	char buffer[600];
	char filename[128];
	cout << "������� ��� ����� ��� ������: ";
	cin >> filename;
	if (fopen_s(&out, filename, "w") != 0) {
		cout << "�� ������� ������� ���� " << filename << " ��� ������\n";
		system("pause");
		exit(3);
	}
	buffer[0] = 0;
	for (int i = 0; i < kol; i++) {
		creatOneStr(mas[i], i, buffer);
		fputs(buffer, out);
		buffer[0] = 0;
	}
	if (fclose(out) != 0)
	{
		cout << "�� ������� ������� ���� " << filename << " ����� ������\n";
		system("pause");
		exit(4);
	}
	cout << "������ ������� ��������� � ����� " << filename << "\n";
}

void quit() {                                         // ������� ������
	cout << "\n���������� ������!\n";
	system("pause");
	exit(0);
}
