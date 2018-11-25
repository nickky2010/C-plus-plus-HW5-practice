//                                                           Практическая работа №1.
//                                                         Язык программирования СИ++.
//                                                                 Задание 1.
// 1. Создайте класс Book.
// Необходимо хранить следующие данные:
//   Автор;
//   Название;
//   Издательство;
//   Год;
//   Количество страниц;
//   Место издания. 
// Ввод данных осуществить через клавиатуру.
// 2. Создать массив объектов.
// 3. Вывести:
//   a) список книг заданного автора;
//   b) список книг, выпущенных заданным издательством;
//   c) список книг, выпущенных после заданного года.
// 4. При необходимости используйте:
//   -перегруженные конструкторы;
//   -конструктор копирования;
//   -константные функции - члены(например, для отображения данных о книге и т.д.).
// 5. Иметь возможность сохранять данные в файл и считывать из него.
#include <iostream>
#include <Windows.h>
#include "Book.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol = 0, vyb = 0, year = 0;
	char author[128], publishing_house[128], c[2];
	FILE *in = NULL, *out = NULL;
	Book **mas;
	Book *head = NULL;
	cout << "Необходимо ввести данные.\n";
	while (vyb < 1 || vyb>2) {
		cout << "Выберите способ ввода:\n";
		cout << "1 - ручной ввод;\n";
		cout << "2 - ввод из файла;\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		switch (vyb)
		{
			// ручной ввод
		case 1:
			short n;
			do {
				system("cls");
				head->init(head, kol);
				cout << "\nСоздать новую книгу?\n1 - да\n0 - нет\nВаш выбор: ";
				cin >> n;
			} while (n);
			head->creatArray(head, mas, kol);              // создание массива указателей на элементы списка
			break;
			// ввод из файла
		case 2:
			head->readData(in, head, mas, kol);
			system("pause");
			break;
		default:
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	while (true) {
		int menu = -1;
		system("cls");
		cout << "1 - вывести список книг заданного автора\n";
		cout << "2 - вывести список книг, выпущенных заданным издательством\n";
		cout << "3 - вывести список книг, выпущенных после заданного года\n";
		cout << "4 - показать все книги\n";
		cout << "5 - сохранить информацию в файл\n";
		cout << "6 - загрузить информацию из файла\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "\nВведите автора: ";
			cin.getline(c, 2);
			cin.getline(author, 128);
			head->search_author_and_print(mas, kol, author);
			system("pause");
			break;
		case 2:
			cout << "\nВведите издательство: ";
			cin.getline(c, 2);
			cin.getline(publishing_house, 128);
			head->search_publishing_house_and_print(mas, kol, publishing_house);
			system("pause");
			break;
		case 3:
			cout << "\nВведите год: ";
			cin.getline(c, 2);
			cin >> year;
			head->search_book_after_year_and_print(mas, kol, year);
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "\t\t\tСписок всех книг:\n";
			head->print(mas, kol);
			system("pause");
			break;
		case 5:
			head->writeData(out, mas, kol);
			system("pause");
			break;
		case 6:
			head->readData(in, head, mas, kol);
			system("pause");
			break;
		case 0:
			delete[]mas;
			quit();
			break;
		default:
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	return 0;
}
