#include "functions.h"
#include<algorithm>

int m_NazvLen(Data* d, int n) {
	int sz = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].title.size() > sz) { sz = d[i].title.size(); }
	}
	return sz;
}

int m_AuthLen(Data* d, int n) {
	int sz = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].author.size() > sz) { sz = d[i].author.size(); }
	}
	return sz;
}

int m_PricLen(Data* d, int n) {
	int sz = 0, temp = 0;
	for (int i{}; i < n; i++) {
		while (d[i].price != 0) {
			d[i].price /= 10;
			temp++;
		}
		if (temp > sz) { sz = temp; }
	}
	return sz;
}



int m_AmouLen(Data* d, int n) {
	int sz = 0, temp = 0;
	for (int i{}; i < n; i++) {
		while (d[i].amount != 0) {
			d[i].amount /= 10;
			temp++;
		}
		if (temp > sz) { sz = temp; }
	}
	return sz;
}

void DataEntry(Data* (&d), int& n) {
	cout << "Введите количество данных: ";
	cin >> n;

	//Выделение памяти
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите название: ";
		cin >> d[i].title;

		cout << "Введите имя автора: ";
		cin >> d[i].author;

		cout << "Введите количество: ";
		cin >> d[i].amount;

		cout << "Введите цену: ";
		cin >> d[i].price;

		cout << "----------------------------------" << endl;
	}
}

void ReadingData(Data* (&d), int& n, string fileName) {
	ifstream reading(fileName);//поток для чтения
	
	if (reading) {
		reading >> n;

		//Выделим память
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i].title;
			reading >> d[i].author;
			reading >> d[i].amount;
			reading >> d[i].price;
		}
		cout << "Данные считаны!" << endl;
	}
	else {
		cout << "Ошибка считывания..." << endl;
	}
	reading.close();
}

void Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		int pr_size=0, am_size=0, ar=0;
		int arr_size = sizeof(d) / sizeof(d[0]);
		while (arr_size != 0) {
			arr_size /= 10;
			ar++;
		}

		

		
		int op = 0;
		int nazv_size = 0;
		for (int i = 0; i < n; i++) {

		}
		
		for (int i = 0; i <=(m_AmouLen(d,n)+ m_PricLen(d,n) + m_AuthLen(d,n)+ m_NazvLen(d,n)); i++) {
			cout << "-";
			op++;
		}
		cout << op;
		//заголовок индекса
		cout << endl;
		cout << "|";
		for (int i = 0; i < ar/2; i++) { cout << ' '; }
		cout << "№";
		for (int i = 0; i < ar / 2; i++) { cout << ' '; }
		cout << "|";

		//заголовок названия
		for (int i = 0; i < m_NazvLen(d, n) / 2; i++) { cout << ' '; }
		cout << "Название";
		for (int i = 0; i < m_NazvLen(d, n) / 2; i++) { cout << ' '; }
		cout << "|";

		

		/*cout << "Данные №" << i + 1 << ":"<<endl;
		
		cout << "Название: " << d[i].title<<endl;
		cout << "Автор: " << d[i].author << endl;
		cout << "Количество: " << d[i].amount<<endl;
		cout << "Цена: " << d[i].price << endl;

		cout << "----------------------------------" << endl;*/
	}
}

void DataChange(Data* (&d), int n) {
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	//проверка, что ввели правильное значение
	if (_n >= 0 && _n < n) {
		cout << "Введите название: ";
		cin >> d[_n].title;
		cout << "Введите имя автора: ";
		cin >> d[_n].author;
		cout << "Введите количество: ";
		cin >> d[_n].amount;
		cout << "Введите цену: ";
		cin >> d[_n].price;
	}
	else {
		cout << "Номер был введён неверно..." << endl;
	}
}

void DeleteData(Data* (&d), int& n) {
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	if (_n >= 0 && _n < n) {
		//временный массив
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//Выделяем новую память
		--n;
		d = new Data[n];

		int q = 0;

		//Запоминаем все данные кроме  ненужных
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}

		system("cls");
		delete[]buf;
		cout << "Данные удалены!" << endl;
	}
	else {
		cout << "Номер введён неверно!" << endl;
	}
}

void Copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0; i <= n; i++) {
		d_n[i] = d_o[i];
	}
}

void AddData(Data* (&d), int& n) {
	//Временный массив данных
	Data* buf;
	buf = new Data[n];

	Copy(buf, d, n);
	//выделяем новую память
	n++;
	d = new Data[n];

	//Возвращаем данные
	Copy(d, buf, --n);

	cout << "Введите название: ";
	cin >> d[n].title;
	cout << "Введите имя автора: ";
	cin >> d[n].author;
	cout << "Введите количество: ";
	cin >> d[n].amount;
	cout << "Введите цену: ";
	cin >> d[n].price;

	system("cls");
	cout << "Данные добавлены!" << endl;
	delete[]buf;
}

void DataSorting(Data* d, int n) {
	
	//временная переменная
	Data buf;
	char dasc;
	cout << "сортировка по возрастанию? (y/n): ";
	cin >> dasc;
	if (dasc == 'y') {
		cout << "Введите критерий для сортировки: 1 - Кол-во; 2 - Цена; 3 - Автор; 4 - Название; 5 - Выход" << endl;
		switch (dasc) {
		case 1:
			//сортировка вставками
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].amount < d[j].amount;j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].price < d[j].price; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].author < d[j].author; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].title < d[j].title; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;
		}
	}
	if (dasc == 'n') {
		cout << "Введите критерий для сортировки: 1 - Кол-во; 2 - Цена; 3 - Автор; 4 - Название; 5 - Выход" << endl;
		switch (dasc) {
		case 1:
			//сортировка вставками
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].amount < d[j].amount;j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].price < d[j].price; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].author < d[j].author; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].title < d[j].title; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		default:
			cout << "Значение введено неверно!" << endl;
			break;
		}
	}

	if (dasc == 'n') {
		cout << "Введите критерий для сортировки: 1 - Кол-во; 2 - Цена; 3 - Автор; 4 - Название; 5 - Выход" << endl;
		switch (dasc) {
		case 1:
			//сортировка вставками
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].amount > d[j].amount; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].price > d[j].price; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].author > d[j].author; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i; j >= 0 && d[j - 1].title > d[j].title; j--) {
					Copy(buf, d[j]);
					Copy(d[j - 1], d[j]);
					Copy(d[j], buf);
				}
			}
			cout << "Данные отсортированы!" << endl;
			break;

		default:
			cout << "Значение введено неверно!" << endl;
			break;
		}
	}
}

void Copy(Data& d_n, Data& d_o){
	d_n.amount = d_o.amount;
	d_n.author = d_o.author;
	d_n.price = d_o.price;
	d_n.title = d_o.title;
}

void SavingData(Data* d, int n, string fileName) {
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
		cout << "Ошибка открытия файла" << endl;
	}

	record.close();
}