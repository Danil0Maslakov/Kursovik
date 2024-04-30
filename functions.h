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


void DataEntry(Data* (&d), int& n); //���� ������ �������
void ReadingData(Data* (&d), int& n, string fileName);//������ ������ �� �����
void Print(Data* d, int n); //����� ������
void DataChange(Data* (&d), int n);//��������� ������
void DeleteData(Data* (&d), int& n);//�������� ������
void Copy(Data* (&d_n), Data* (&d_o), int n); //����� ������
void Copy(Data& d_n, Data& d_o); //����� ������ ��������
void AddData(Data* (&d), int& n); //�������� ������
void DataSorting(Data* d, int n);//���������� ������
void SavingData(Data* d, int n, char* fileName);//���������� ������

