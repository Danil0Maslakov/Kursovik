#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

struct Data {
	unsigned int price, amount;
	char author[32];
	char title[32];
};


void DataEntry(Data* (&d), int& n); //¬вод данных вручную
void ReadingData(Data* (&d), int& n, string fileName);//„тение данных из файла
void Print(Data* d, int n); //вывод данных
void DataChange(Data* (&d), int n);//изменение данных
void DeleteData(Data* (&d), int& n);//удаление данных
void Copy(Data* (&d_n), Data* (&d_o), int n); //копи€ данных
void Copy(Data& d_n, Data& d_o); //копи€ данных элемента
void AddData(Data* (&d), int& n); //ƒобавить данные
void DataSorting(Data* d, int n);//—ортировка данных
void SavingData(Data* d, int n, char* fileName);//сохранение данных
void dSwap(Data& d_n, Data& d_o);  //помен€ть местами данные в структуре
int TitleLen(char* str, int i, Data* d); 
int AuthLen(char* str, int i, Data* d);
int m_NazvLen(Data* d, int n);
int m_AuthLen(Data* d, int n);
int m_PricLen(Data* d, int n);
int m_AmouLen(Data* d, int n);
int IntLen(Data* d, int integer);
void DataSearching(Data* d, int n);