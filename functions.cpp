#include "functions.h"
#include<algorithm>

#pragma warning(disable:4996)
int StrLen(char *str,int i, Data* d) {
	char* iter = (char*)d[i].title;
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
		if (StrLen((char*)d[i].title,i,d)> sz) { sz = StrLen((char*)d[i].title, i, d); }
	}
	return sz;
	
}

int m_AuthLen(Data* d, int n) {
	int sz = 0;
	for (int i = 0; i < n; i++) {
		if (StrLen((char*)d[i].author, i, d) > sz) { sz = StrLen((char*)d[i].author, i, d); }
	}
	return sz;
}

int m_PricLen(Data* d, int n) {
	int sz = 0, temp = 0;
	for (int i{}; i < n; i++) {
		int tempd = d[i].price;
		while (tempd != 0) {
			tempd /= 10;
			temp++;
		}
		if (temp > sz) { sz = temp; }
	}
	return sz;
}



int m_AmouLen(Data* d, int n) {
	int sz = 0, temp = 0;
	for (int i{}; i < n; i++) {
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
		cout << "������� ��������: ";
		cin >> d[i].title;
		//cin.getline(d[i].title,32);

		cout << "������� ��� ������: ";
		cin >> d[i].author;
		//cin.getline(d[i].author, 32);

		cout << "������� ����������: ";
		cin >> d[i].amount;

		cout << "������� ����: ";
		cin >> d[i].price;

		cout << "----------------------------------" << endl;
	}

}

void ReadingData(Data* (&d), int& n, string fileName) {
	ifstream reading(fileName);//����� ��� ������
	
	if (reading) {
		reading >> n;

		//������� ������
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i].title;
			reading >> d[i].author;
			reading >> d[i].amount;
			reading >> d[i].price;
		}
		cout << "������ �������!" << endl;
	}
	else {
		cout << "������ ����������..." << endl;
	}
	reading.close();
}

void Print(Data* d, int n) {
		int pr_size=0, am_size=0, ar=0;
		int arr_size = sizeof(d) / sizeof(d[0]);
		while (arr_size != 0) {
			arr_size /= 10;
			ar++;
		}
	for (int i = 0; i < n; i++) {
		

		

		int risAm = 6;
		if (m_AmouLen(d, n) > 10) { risAm += (m_AmouLen(d,n)*3)/2; }
		if (m_AmouLen(d, n) <= 10) { risAm += 10; }
		if (m_PricLen(d, n) > 4) { risAm += (m_PricLen(d, n)*3)/2; }
		if (m_PricLen(d, n) <= 4) { risAm += 4; }
		if (m_AuthLen(d, n) > 5) { risAm += m_AuthLen(d, n); }
		if (m_AuthLen(d, n) <= 5) { risAm += 5; }
		if (m_NazvLen(d, n) > 8) { risAm += (m_NazvLen(d, n)*3)/2; }
		if (m_NazvLen(d, n) <= 8) { risAm += 8; }
		if (ar > 1) { risAm += (ar*3)/2; }
		if(ar == 1){risAm+=1;}
		int k = 0;
		for (int i = 0; i <=risAm; i++) {
			cout << "-"; k++;
		}
		cout << k;
		
		//��������� �������
		cout << endl;
		cout << "|";
		for (int i = 0; i < ar / 2; i++) { cout << ' '; }
		cout << "�";
		for (int i = 0; i < ar / 2; i++) { cout << ' '; }
		cout << "|";

		//��������� ��������
		
		for (int i = 0; i < m_NazvLen(d, n) / 2; i++) { cout << ' '; }
		cout << "��������";
		for (int i = 0; i < m_NazvLen(d, n) / 2; i++) { cout << ' '; }
		cout << "|";
		
		for (int i = 0; i < m_AuthLen(d, n) / 2; i++) { cout << ' '; }
		cout << "�����";
		for (int i = 0; i < m_AuthLen(d, n) / 2; i++) { cout << ' '; }
		cout << "|";
		
		for (int i = 0; i < m_AmouLen(d, n) / 2; i++) { cout << ' '; }
		cout << "����������";
		for (int i = 0; i < m_AmouLen(d, n) / 2; i++) { cout << ' '; }
		cout << "|";

		for (int i = 0; i < m_PricLen(d, n) / 2; i++) { cout << ' '; }
		cout << "����";
		for (int i = 0; i < m_PricLen(d, n) / 2; i++) { cout << ' '; }
		cout << "|" << endl;

		for (int i = 0; i <= risAm; i++) {
			cout << "-";
		}
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
		cout << "������� ��������: ";
		cin >> d[_n].title;
		cout << "������� ��� ������: ";
		cin >> d[_n].author;
		cout << "������� ����������: ";
		cin >> d[_n].amount;
		cout << "������� ����: ";
		cin >> d[_n].price;
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
		Data* buf = new Data[n];

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
		delete[]buf;
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
	Data* buf;
	buf = new Data[n];

	Copy(buf, d, n);
	//�������� ����� ������
	n++;
	d = new Data[n];

	//���������� ������
	Copy(d, buf, --n);

	cout << "������� ��������: ";
	cin >> d[n].title;
	cout << "������� ��� ������: ";
	cin >> d[n].author;
	cout << "������� ����������: ";
	cin >> d[n].amount;
	cout << "������� ����: ";
	cin >> d[n].price;

	system("cls");
	cout << "������ ���������!" << endl;
	delete[]buf;
}

void DataSorting(Data* d, int n) {
	
	//��������� ����������
	Data buf;
	char dasc;
	cout << "���������� �� �����������? (y/n): ";
	cin >> dasc;
	if (dasc == 'y') {
		cout << "������� �������� ��� ����������: 1 - ���-��; 2 - ����; 3 - �����; 4 - ��������; 5 - �����" << endl;
		switch (dasc) {
		case 1:
			//���������� ���������
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].amount < d[j].amount;j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].price < d[j].price; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].author < d[j].author; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].title < d[j].title; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;
		}
	}
	if (dasc == 'n') {
		cout << "������� �������� ��� ����������: 1 - ���-��; 2 - ����; 3 - �����; 4 - ��������; 5 - �����" << endl;
		switch (dasc) {
		case 1:
			//���������� ���������
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].amount < d[j].amount;j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].price < d[j].price; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].author < d[j].author; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].title < d[j].title; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		default:
			cout << "�������� ������� �������!" << endl;
			break;
		}
	}

	if (dasc == 'n') {
		cout << "������� �������� ��� ����������: 1 - ���-��; 2 - ����; 3 - �����; 4 - ��������; 5 - �����" << endl;
		switch (dasc) {
		case 1:
			//���������� ���������
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].amount > d[j].amount; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].price > d[j].price; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].author > d[j].author; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].title > d[j].title; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "������ �������������!" << endl;
			break;

		default:
			cout << "�������� ������� �������!" << endl;
			break;
		}
	}
}

void Copy(Data& d_n, Data& d_o){
	d_n.amount = d_o.amount;
	strncpy(d_n.author, d_o.author, 32);
	d_n.price = d_o.price;
	strncpy(d_n.title, d_o.title, 32);
}

void SavingData(Data* d, int n, char* fileName) {
	ofstream record(fileName, ios::out);

	if(record){
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i].title << endl;
			record << d[i].author << endl;
			record << d[i].amount << endl;
			if (i < n - 1) {
				record << d[i].price << endl;
			}
			else {
				record << d[i].price;
			}
		}
	}
	else {
		cout << "������ �������� �����" << endl;
	}

	record.close();
}