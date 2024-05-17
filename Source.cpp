#include<iostream>
#include "functions.h"

#pragma warning (disable:4996)
using namespace std;
int _stateMenu;


void Menu() {
	cout << "�������� ��������: " << endl
		<< "(0) ����� �� ���������" << endl
		<< "(1) ���� ������" << endl
		<< "(2) �����" << endl
		<< "(3) ���������" << endl
		<< "(4) ��������" << endl
		<< "(5) ����������" << endl
		<< "(6) ����������" << endl
		<< "(7) ����������" << endl
		<< "(8) �����" << endl
		<< "(9) ����� �������������" << endl
		<< "��� �����: ";
	cin >> _stateMenu;
}

int is_saved;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	is_saved = 0;
	Menu();

	int _actions, amountOfData = 0;
	char fileName[16];
	Data* d = new Data[17];

	while (_stateMenu != 0) {
		switch (_stateMenu) {
		case 1:
			system("cls"); 
			cout << "���� ������� ��� �� �����? (1/2): ";
			cin >> _actions;
			system("cls");

			if (_actions == 1) {
				
				DataEntry(d, amountOfData);
				system("cls");
				Print(d, amountOfData,is_saved);
				Menu();
				break;
			}
			else {
				
				cout << "������� �������� �����: ";
				cin >> fileName;
				ReadingData(d, amountOfData, fileName);
				system("cls");
				Print(d, amountOfData, is_saved);
				Menu();
				break;
			}

		case 2:
			system("cls");
				ReadingData(d, amountOfData, (char*)"head.txt");
				Print(d, amountOfData, is_saved);
			Menu();
			break;
		case 3:
			is_saved = 0;
			system("cls");
			if (amountOfData != 0) {
				Print(d, amountOfData, is_saved);
				DataChange(d, amountOfData);
				system("cls");
				Print(d, amountOfData, is_saved);
				Menu();
				break;
			}
			else {
				cout << "������ �����!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			is_saved = 0;
			system("cls");
			if (amountOfData != 0) {
				Print(d, amountOfData, is_saved);
				DeleteData(d, amountOfData);
				system("cls");
				Print(d, amountOfData, is_saved);
				Menu();
				break;
			}
			else {
				cout << "������ �����!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			is_saved = 0;
			system("cls");
			if (amountOfData != 0) {
				Print(d, amountOfData, is_saved);
				AddData(d, amountOfData);
				amountOfData++;
				system("cls");
				Print(d, amountOfData, is_saved);
				Menu();
				break;
			}
			else {
				cout << "������ �����!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			is_saved = 0;
			system("cls");
			if (amountOfData != 0) {
				Print(d, amountOfData, is_saved);
				DataSorting(d, amountOfData);
				system("cls");
				Print(d, amountOfData, is_saved);
				Menu();
				break;
			}
			else {
				cout << "������ �����!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 7:
			system("cls");
			if (amountOfData != 0) {
				int format;
				system("cls");
				Print(d, amountOfData, is_saved);
				cout << "������� �������� �����: ";
				cin >> fileName;
				char c = '.';
				char* fl;
				fl = strchr(fileName, c);
				/*bool f = find(fileName, fileName + 16, c);*/
				if (fl) { 
					cout << "������ ������ ������ �������" << endl; 
					ZeroMemory(fileName, 16);
					Menu();
					break;
				}
				cout << "�������� ������ �����: "<<endl
					<<"(1) - .txt"<<endl
					<<"(2) - .bin";
				cin >> format;
				switch (format) {
				case 1:
					strcat(fileName, ".txt");
					SavingData(d, amountOfData, fileName);
					is_saved = 1;
					break;
				case 2:
					strcat(fileName, ".bin");
					SavingData(d, amountOfData, fileName);
					is_saved = 1;
					break;
				default:
					cout << "������� ������� ��������" << endl;
					break;
				}
				Menu();
				break;
				
			}
			else {
				cout << "������ �����!" << endl;
				system("pause");
				system("cls");
				Menu();
				break;
			}
			
			

		case 8:
			//system("cls");

			if (amountOfData != 0) {
				//Print(d, amountOfData);
				DataSearching(d, amountOfData);
				system("pause");
				system("cls");
				Print(d, amountOfData, is_saved);
				Menu();
				
				break;
			}
			else {
				cout << "������ �����!" << endl;
				system("pause");
				system("cls");
				Menu();
				break;
			}

			

		case 9:
			system("cls");

			if (amountOfData != 0) {
				Print(d, amountOfData, is_saved);
				FindMax(d, amountOfData);
				system("cls");
				Print(d, amountOfData, is_saved);
				Menu();
				break;
			}
			else {
				cout << "������ �����!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "����������� ����� ����� ��������!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	if (is_saved == 0)
	{
		int ext;
		cout << "����� ��� ���������� ������?" << endl
			<< "(1) - ��, (2) - ��������� � �����" << endl;
		cin >> ext;
		switch (ext) {
		case 1:
			exit(0);
		case 2:
			system("cls");
			if (amountOfData != 0) {
				int format;
				system("cls");
				Print(d, amountOfData, is_saved);
				cout << "������� �������� �����: ";
				cin >> fileName;
				char c = '.';
				char* fl;
				fl = strchr(fileName, c);
				if (fl) {
					cout << "������ ������ ������ �������" << endl;
					ZeroMemory(fileName, 16);
					Menu();
					break;
				}
				cout << "�������� ������ �����: " << endl
					<< "(1) - .txt" << endl
					<< "(2) - .bin";
				cin >> format;
				switch (format) {
				case 1:
					strcat(fileName, ".txt");
					SavingData(d, amountOfData, fileName);
					is_saved = 1;
					break;
				case 2:
					strcat(fileName, ".bin");
					SavingData(d, amountOfData, fileName);
					is_saved = 1;
					break;
				default:
					cout << "������� ������� ��������" << endl;
					break;
				}
				exit(0);
				break;

			}
			else {
				exit(0);
				break;
			}
		default:
			cout<<"������� ������� ��������" << endl;
			break;
		}
	}
}