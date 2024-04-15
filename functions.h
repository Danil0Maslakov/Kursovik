#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

struct Data {
	unsigned int price, amount;
	string author, title;
};


void DataEntry(Data* (&d), int& n); //Ввод данных вручную
void ReadingData(Data* (&d), int& n, string fileName);//Чтение данных из файла
void Print(Data* d, int n); //вывод данных
void DataChange(Data* (&d), int n);//изменение данных
void DeleteData(Data* (&d), int& n);//удаление данных
void Copy(Data* (&d_n), Data* (&d_o), int n); //копия данных
void Copy(Data& d_n, Data& d_o); //копия данных элемента
void AddData(Data* (&d), int& n); //Добавить данные
void DataSorting(Data* d, int n);//Сортировка данных
void SavingData(Data* d, int n, string fileName);//сохранение данных

