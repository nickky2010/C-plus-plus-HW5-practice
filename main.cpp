//                                                           ������������ ������ �1.
//                                                         ���� ���������������� ��++.
//                                                                 ������� 1.
// 1. �������� ����� Book.
// ���������� ������� ��������� ������:
//   �����;
//   ��������;
//   ������������;
//   ���;
//   ���������� �������;
//   ����� �������. 
// ���� ������ ����������� ����� ����������.
// 2. ������� ������ ��������.
// 3. �������:
//   a) ������ ���� ��������� ������;
//   b) ������ ����, ���������� �������� �������������;
//   c) ������ ����, ���������� ����� ��������� ����.
// 4. ��� ������������� �����������:
//   -������������� ������������;
//   -����������� �����������;
//   -����������� ������� - �����(��������, ��� ����������� ������ � ����� � �.�.).
// 5. ����� ����������� ��������� ������ � ���� � ��������� �� ����.
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
	cout << "���������� ������ ������.\n";
	while (vyb < 1 || vyb>2) {
		cout << "�������� ������ �����:\n";
		cout << "1 - ������ ����;\n";
		cout << "2 - ���� �� �����;\n";
		cout << "��� �����: ";
		cin >> vyb;
		switch (vyb)
		{
			// ������ ����
		case 1:
			short n;
			do {
				system("cls");
				head->init(head, kol);
				cout << "\n������� ����� �����?\n1 - ��\n0 - ���\n��� �����: ";
				cin >> n;
			} while (n);
			head->creatArray(head, mas, kol);              // �������� ������� ���������� �� �������� ������
			break;
			// ���� �� �����
		case 2:
			head->readData(in, head, mas, kol);
			system("pause");
			break;
		default:
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
		}
	}
	while (true) {
		int menu = -1;
		system("cls");
		cout << "1 - ������� ������ ���� ��������� ������\n";
		cout << "2 - ������� ������ ����, ���������� �������� �������������\n";
		cout << "3 - ������� ������ ����, ���������� ����� ��������� ����\n";
		cout << "4 - �������� ��� �����\n";
		cout << "5 - ��������� ���������� � ����\n";
		cout << "6 - ��������� ���������� �� �����\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "\n������� ������: ";
			cin.getline(c, 2);
			cin.getline(author, 128);
			head->search_author_and_print(mas, kol, author);
			system("pause");
			break;
		case 2:
			cout << "\n������� ������������: ";
			cin.getline(c, 2);
			cin.getline(publishing_house, 128);
			head->search_publishing_house_and_print(mas, kol, publishing_house);
			system("pause");
			break;
		case 3:
			cout << "\n������� ���: ";
			cin.getline(c, 2);
			cin >> year;
			head->search_book_after_year_and_print(mas, kol, year);
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "\t\t\t������ ���� ����:\n";
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
			cout << "�������! ��������� ����!\n";
		}
	}
	return 0;
}
