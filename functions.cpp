#include "functions.h"
#include<stdio.h>
#include<algorithm>
#include<cstring>
#pragma warning(disable:4996)
int TitleLen(char *str,int i, Data* d) {
	char* iter = (char*)d[i].title;
	int ret = 0;
	while (*iter) {
		iter++;
		ret++;
	}
	int ans = ret;
	return ans;
}

int AuthLen(char* str, int i, Data* d) {
	char* iter = (char*)d[i].author;
	int ret = 0;
	while (*iter) {
		iter++;
		ret++;
	}
	int ans = ret;
	return ans;
}
int m_NazvLen(Data* d, int n) {
	int sz = 0;
	for (int i = 0; i < n; i++) {
		//if (TitleLen((char*)d[i].title,i,d)> sz) { sz = TitleLen((char*)d[i].title, i, d); }
		if (strlen(d[i].title) > sz)sz = strlen(d[i].title);
	}
	return sz;
	
}

int m_AuthLen(Data* d, int n) {
	int sz = 0;
	for (int i = 0; i < n; i++) {
		//if (TitleLen((char*)d[i].author, i, d) > sz) { sz = TitleLen((char*)d[i].author, i, d); }
		if (strlen(d[i].author) > sz)sz = strlen(d[i].author);
	}
	return sz;
}



int m_PricLen(Data* d, int n) {
	int sz = 0;
	for (int i{}; i < n; i++) {
		int temp=0;
		int tempd = d[i].price;
		while (tempd != 0) {
			tempd /= 10;
			temp++;
		}
		if (temp > sz) { sz = temp; }
	}
	return sz;
}

int IntLen(Data* d, int integer) {
	int sz = 0,tempd = integer;
	while (tempd != 0) {
		tempd /= 10;
		sz++;
	}
	return sz;
}

int m_AmouLen(Data* d, int n) {
	int sz = 0;
	for (int i{}; i < n; i++) {
		int temp = 0;
		int tempd = d[i].amount;
		while (tempd != 0) {
			tempd /= 10;
			temp++;
		}
		if (temp > sz) { sz = temp; }
	}
	return sz;
}

void DataEntry(Data* (&d), int& n) {
	cout << "������� ���������� ������: ";
	cin >> n;

	//��������� ������
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ����������: ";
		cin >> d[i].amount;
		cin.ignore();

		cout << "������� ����: ";
		cin >> d[i].price;
		cin.ignore();


		cout << "������� ��������: ";
		cin.getline(d[i].title,32,'\n');

		cout << "������� ��� ������: ";
		cin.getline(d[i].author,32,'\n');
		
		cout << "----------------------------------" << endl;
	}

}

void ReadingData(Data* (&d), int& n, char fileName[16]) {
	ifstream reading(fileName);
	
	if (reading) {
		reading >> n;
		
		
		d = new Data[n];

		for (int i = 0; !reading.eof() && i < n; i++) {
			reading >> d[i].amount >> d[i].price;
			reading.clear();
			reading.ignore();
			reading.getline(d[i].author, 32);
			reading.clear();
			reading.getline(d[i].title, 32);
			reading.clear();
		}
		cout << "������ �������!" << endl;
	}
	else {
		cout << "������ ����������..." << endl;
	}
	reading.close();
}

void Print(Data* d, int n,int is_saved) {
	if (is_saved == 0) { cout << "*" << endl; }
	int mN = m_NazvLen(d, n);
	int mA = m_AuthLen(d, n);
	int mAm = m_AmouLen(d, n);
	int mP = m_PricLen(d, n);

		int pr_size=0, am_size=0, ar=0;
		int arr_size = sizeof(d) / sizeof(d[0]), temp_arr = sizeof(d) / sizeof(d[0]);
		while (temp_arr != 0) {
			temp_arr /= 10;
			ar++;
		}
		int m_Stolb = max(max(max(mN, 8), max(mA, 5)), max(max(mAm, 10), max(mP, 4)));

		int risAm = m_Stolb*4+6;
		int mNs = m_Stolb - 8;
		int mAs = m_Stolb - 5;
		int mAms = m_Stolb - 10;
		int mPs = m_Stolb - 4;
		
		//if (m_AmouLen(d, n) > 10) { risAm += m_AmouLen(d, n); }
		////if (m_AmouLen(d, n) <= 10) { risAm += 10; }
		//if (m_PricLen(d, n) > 4) { risAm += m_PricLen(d, n); }
		////if (m_PricLen(d, n) <= 4) { risAm += 4; }
		//if (m_AuthLen(d, n) > 5) { risAm += m_AuthLen(d, n); }
		////if (m_AuthLen(d, n) <= 5) { risAm += 5; }
		//if (m_NazvLen(d, n) > 8) { risAm += m_NazvLen(d, n); }
		////if (m_NazvLen(d, n) <= 8) { risAm += 8; }
		//if (ar > 1) { risAm += ar; }
		
		
		for (int i = 0; i <= risAm; i++) {
			cout << "-";
		}
		


		//��������� �������
		cout << endl;
		cout << "|";
		for (int i = 0; i < ar / 2; i++) { cout << ' '; }
		cout << "�";
		for (int i = 0; i < ar / 2; i++) { cout << ' '; }
		cout << "|";
		
		

		//��������� ��������
		
		
		cout << "��������";
		for (int i = 0; i < mNs; i++) { cout << " "; }
		cout << "|";

		
		cout << "�����";
		for (int i = 0; i < mAs; i++) { cout << " "; }
		cout << "|";

		
		cout << "����������";
		for (int i = 0; i < mAms; i++){ cout << " "; };
		cout << "|";

		
		cout << "����";
		
		for (int i = 0; i < mPs; i++) { cout << " "; }
		
		cout << "|" << endl;

		for (int i = 0; i <= risAm; i++) {
			cout << "-";
		}
		cout << endl;
	for (int i = 0; i < n; i++) {
		
		
		
		//�����
		
		cout <<"|" << i + 1 << "|";

		//��������
		cout << d[i].title;
		int j = TitleLen(d[i].title, i, d);
		
		

		for (; j < m_Stolb; j++) {
			cout << ' ';
		}
		cout << '|';

		//�����
		cout << d[i].author;
		j = AuthLen(d[i].author, i, d);
		
		
		for (; j < m_Stolb; j++) {
			cout << ' ';
		}
		cout << '|';

		//����������
		cout << d[i].amount;
		j = IntLen(d, d[i].amount);
		
		
		for (; j < m_Stolb; j++) {
			cout << " ";
		}
		cout << "|";

		//����
		cout << d[i].price;
		j = IntLen(d, d[i].price);
		
		
		for (; j < m_Stolb; j++) {
			cout << " ";
		}
		cout << "|"<<endl;

		for (int i = 0; i <= risAm; i++) {
			cout << "-";
		}cout << endl;
		
		/*cout << "������ �" << i + 1 << ":"<<endl;
		
		cout << "��������: " << d[i].title<<endl;
		cout << "�����: " << d[i].author << endl;
		cout << "����������: " << d[i].amount<<endl;
		cout << "����: " << d[i].price << endl;

		cout << "----------------------------------" << endl;*/
	}
}

void DataChange(Data* (&d), int n) {
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	//��������, ��� ����� ���������� ��������
	if (_n >= 0 && _n < n) {
		/*cout << "������� ��������: ";
		cin.getline(d[_n].title,32);
		cout << "������� ��� ������: ";
		cin.getline(d[_n].author,32);
		cout << "������� ����������: ";
		cin >> d[_n].amount;
		cout << "������� ����: ";
		cin >> d[_n].price;*/

		cout << "������� ����������: ";
		cin >> d[_n].amount;
		cin.ignore();

		cout << "������� ����: ";
		cin >> d[_n].price;
		cin.ignore();


		cout << "������� ��������: ";
		cin.getline(d[_n].title, 32, '\n');

		cout << "������� ��� ������: ";
		cin.getline(d[_n].author, 32, '\n');
	}
	else {
		cout << "����� ��� ����� �������..." << endl;
	}
}

void DeleteData(Data* (&d), int& n) {
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	if (_n >= 0 && _n < n) {
		//��������� ������
		Data* buf = d;//new Data[n];

		Copy(buf, d, n);

		//�������� ����� ������
		--n;
		d = new Data[n];

		int q = 0;

		//���������� ��� ������ �����  ��������
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}

		system("cls");
		//delete[]buf;
		cout << "������ �������!" << endl;
	}
	else {
		cout << "����� ����� �������!" << endl;
	}
}

void Copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0; i <= n; i++) {
		d_n[i] = d_o[i];
	}
}

void AddData(Data* (&d), int& n) {
	//��������� ������ ������
	Data* buf = d;
	//buf = new Data[n];

	Copy(buf, d, n);
	
	//�������� ����� ������
	n++;
	d = new Data[n];

	//���������� ������
	Copy(d, buf, --n);

	/*cout << "������� ��������: ";
	cin.getline(d[n].title,32);
	cout << "������� ��� ������: ";
	cin.getline(d[n].author,32);
	cout << "������� ����������: ";
	cin >> d[n].amount;
	cout << "������� ����: ";
	cin >> d[n].price;*/
	cout << "������� ����������: ";
	cin >> d[n].amount;
	cin.ignore();

	cout << "������� ����: ";
	cin >> d[n].price;
	cin.ignore();


	cout << "������� ��������: ";
	cin.getline(d[n].title, 32, '\n');

	cout << "������� ��� ������: ";
	cin.getline(d[n].author, 32, '\n');
	
	cout << "������ ���������!" << endl;
	system("cls");
	//delete[]buf;
}

void DataSorting(Data* d, int n) {
	
	//��������� ����������
	//Data buf;
	int dasc,cs;
	cout << "���������� �� �����������? 1 - ��, 2 - ���: ";
	cin >> dasc;
	if (dasc == 1) {
		cout << "������� �������� ��� ����������: 1 - ���-��; 2 - ����; 3 - �����; 4 - ��������; 5 - �����   ";
		cin >> cs;
		switch (cs) {
		case 1:
			//���������� ���������
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && d[j - 1].amount > d[j].amount;) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 2:
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && d[j - 1].price > d[j].price; ) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 3:
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && strcmp(d[j - 1].author,d[j].author)>0; ) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 4:
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && strcmp(d[j - 1].title,d[j].title) > 0; ) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;
		}
	}
	if (dasc == 2) {
		cout << "������� �������� ��� ����������: 1 - ���-��; 2 - ����; 3 - �����; 4 - ��������; 5 - �����    ";
		cin >> cs;
		switch (cs) {
		case 1:
			//���������� ���������
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && d[j - 1].amount < d[j].amount;) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 2:
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && d[j - 1].price < d[j].price; ) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 3:
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && strcmp(d[j - 1].author,d[j].author)<0; ) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 4:
			for (int i = 1; i < n; i++) {
				for (int j = i; j > 0 && strcmp(d[j - 1].title , d[j].title)<0; ) {
					dSwap(d[j], d[j - 1]);
					j--;
				}
			}
			cout << "������ �������������!" << endl;
			break;

		default:
			cout << "�������� ������� �������!" << endl;
			break;
		}
	}

	//if (dasc == 'n') {
	//	cout << "������� �������� ��� ����������: 1 - ���-��; 2 - ����; 3 - �����; 4 - ��������; 5 - �����" << endl;
	//	switch (dasc) {
	//	case 1:
	//		//���������� ���������
	//		for (int i = 0; i < n; i++) {
	//			for (int j = i; j >= 0 && d[j - 1].amount > d[j].amount; j--) {
	//				Copy(buf, d[j]);
	//				Copy(d[j - 1], d[j]);
	//				Copy(d[j], buf);
	//			}
	//		}
	//		cout << "������ �������������!" << endl;
	//		break;

	//	case 2:
	//		for (int i = 0; i < n; i++) {
	//			for (int j = i; j >= 0 && d[j - 1].price > d[j].price; j--) {
	//				Copy(buf, d[j]);
	//				Copy(d[j - 1], d[j]);
	//				Copy(d[j], buf);
	//			}
	//		}
	//		cout << "������ �������������!" << endl;
	//		break;

	//	case 3:
	//		for (int i = 0; i < n; i++) {
	//			for (int j = i; j >= 0 && d[j - 1].author > d[j].author; j--) {
	//				Copy(buf, d[j]);
	//				Copy(d[j - 1], d[j]);
	//				Copy(d[j], buf);
	//			}
	//		}
	//		cout << "������ �������������!" << endl;
	//		break;

	//	case 4:
	//		for (int i = 0; i < n; i++) {
	//			for (int j = i; j >= 0 && d[j - 1].title > d[j].title; j--) {
	//				Copy(buf, d[j]);
	//				Copy(d[j - 1], d[j]);
	//				Copy(d[j], buf);
	//			}
	//		}
	//		cout << "������ �������������!" << endl;
	//		break;

	//	default:
	//		cout << "�������� ������� �������!" << endl;
	//		break;
	//	}
	//}
}

void Copy(Data& d_n, Data& d_o){
	d_n.amount = d_o.amount;
	strncpy(d_n.author, d_o.author, 32);
	d_n.price = d_o.price;
	strncpy(d_n.title, d_o.title, 32);
}

void dSwap(Data& d_n, Data& d_o) {
	Data temp = d_o;
	d_o = d_n;
	d_n = temp;
	/*Data temp = d_n;
	d_n.amount = d_o.amount;
	strncpy(d_n.author, d_o.author, 18);
	d_n.price = d_o.price;
	strncpy(d_n.title, d_o.title, 18);

	d_o.amount = temp.amount;
	strncpy(d_o.author, temp.author, 18);
	d_o.price = temp.price;
	strncpy(d_o.title, temp.title, 18);*/
}

void SavingData(Data* d, int n, char* fileName) {
	ofstream record(fileName, ios::out);

	if(record){
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i].amount << endl;
			record << d[i].price << endl;
			record << d[i].title << endl;
			record << d[i].author<<endl;
		}
	}
	else {
		cout << "������ �������� �����" << endl;
	}

	record.close();
}


void DataSearching(Data* d, int n) {
	char nazv[32];
	Data* buf = new Data[n];
	char flag = 0;
	cout << "������� �������� ��� ������: ";
	
	cin.clear();
	cin.ignore();
	cin.getline(nazv, 32);
	int w = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(nazv, d[i].title) == 0) {
			buf[w] = d[i];
			flag++;
			w++;
		}
	}
	if (flag == 0) { 
		cout << "������ �� �������..." << endl;
		return;
	}
	system("cls");
	Print(buf, w,is_saved);
	delete[]buf;
}

void FindMax(Data* d, int n) {
	int a;
	Data buf[1];
	cout << "������������ ���������� ��� ����? (1/2): ";
	cin >> a;
	switch (a) {
	case 1:
		//���������� ���������
		for (int i = 1; i < n; i++) {
			for (int j = i; j > 0 && d[j - 1].amount < d[j].amount;) {
				dSwap(d[j], d[j - 1]);
				j--;
			}
		}
		buf[0] = d[0];
		Print(buf, 1,is_saved);
		//delete[]buf;
		break;

	case 2:
		for (int i = 1; i < n; i++) {
			for (int j = i; j > 0 && d[j - 1].price < d[j].price; ) {
				dSwap(d[j], d[j - 1]);
				j--;
			}
		}
		buf[0] = d[0];
		Print(buf, 1,is_saved);
		//delete[]buf;
		break;
		
	default:
		cout << "�������� ������� �������..."; break;
	}

}