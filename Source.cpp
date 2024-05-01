#include<iostream>
#include "functions.h"
using namespace std;
int _stateMenu;

void Menu() {
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод" << endl
		<< "(3) Изменение" << endl
		<< "(4) Удаление" << endl
		<< "(5) Добавление" << endl
		<< "(6) Сортировка" << endl
		<< "(7) Сохранение" << endl
		<< "(8) Поиск" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Menu();

	int _actions, amountOfData = 0;
	char fileName[16];
	Data* d = new Data[amountOfData];

	while (_stateMenu != 0) {
		switch (_stateMenu) {
		case 1:
			system("cls"); //очистка консоли
			cout << "Ввод вручную или из файла? (1/2): ";
			cin >> _actions;
			system("cls");

			if (_actions == 1) {
				//Ввод вручную
				DataEntry(d, amountOfData);
			}
			else {
				//Ввод из файла
				cout << "Введите название файла: ";
				cin >> fileName;
				ReadingData(d, amountOfData, fileName);
			}

			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			if (amountOfData != 0) {
				Print(d, amountOfData);
			}
			else {
				cout << "Данные пусты!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");
			if (amountOfData != 0) {
				AddData(d, amountOfData);
				amountOfData++;
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			system("cls");
			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
				
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 7:
			system("cls");
			cout << "Введите название файла: ";
			cin >> fileName;

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 8:
			system("cls");

			if (amountOfData != 0) {
				DataSearching(d, amountOfData);
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "Неправильно введён номер действия!" << endl;
			break;
		}
	}
}