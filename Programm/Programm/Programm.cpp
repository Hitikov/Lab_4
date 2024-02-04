#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int it, n, k, k_true, mode, mem;
	int mtr[100];

	// Указание длины массива в диапазоне от 1 до 50
	cout << "Введите длину массива: ";
	do {
		cin >> n;
		if ((n > 50) || (n < 1)) {
			cout << "Не корректная длина массива, повторите ввод: ";
		}
	} while ((n > 50) || (n < 1));
	cout << endl;

	// Создание массива
	cout << "Укажите режим создания массива: 1. ручной / 2. автоматический: ";
	do {
		cin >> mode;
		if ((mode != 1) && (mode != 2)) {
			cout << "Не корректное указание режима, повторите ввод: ";
		}
	} while ((mode != 1) && (mode != 2));
	cout << endl;

	switch (mode)
	{
	case 1:
		cout << "Вводите элементы массива: " << endl;
		for (int i = 0; i < n; ++i) {
			cin >> mtr[i];
		}
		cout << endl;
		break;
	case 2:
		srand(time(0));
		for (int i = 0; i < n; ++i) {
			mtr[i] = rand() % 100;
		}
		break;
	default:
		break;
	}
	

	// Отображение массива с К-ого элемента
	cout << "Введите K: ";
	do {
		cin >> k;
		if ((k > n) || (k < 1)) {
			cout << "Не корректное K, повторите ввод: ";
		}
	} while ((k > n) || (k < 1));
	cout << endl;

	it = k - 1; // Получение индекса К-ого элемента 

	cout << "Вывод массива: " << endl;
	do {
		cout << mtr[it] << " ";
		++it;
		if (it == n) {
			it = 0;
		}
	} while (it != (k - 1));
	cout << endl << endl;

	// Выполненеие сортировки
	for (int i = 0; i < n - 1; ++i) {
		int j = i + 1;
		while ((j > 0) && (mtr[j - 1] > mtr[j])) {
			mem = mtr[j - 1];
			mtr[j - 1] = mtr[j];
			mtr[j] = mem;
			--j;
		}
	}

	// Удаление четных элементов
	int i = 0;
	while (i < n) {
		if (mtr[i] % 2 == 0) {
			for (int j = i; j < n - 1; ++j) {
				mtr[j] = mtr[j + 1];
			}
			--n;
		}
		else {
			++i;
		}
	}

	// Отображение массива с К-ого элемента
	cout << "Введите K: ";
	do {
		cin >> k;
		if ((k > n) || (k < 1)) {
			cout << "Не корректное K, повторите ввод: ";
		}
	} while ((k > n) || (k < 1));
	cout << endl;

	it = k - 1; // Получение индекса К-ого элемента 

	cout << "Вывод массива: " << endl;
	do {
		cout << mtr[it] << " ";
		++it;
		if (it == n) {
			it = 0;
		}
	} while (it != (k - 1));
	cout << endl << endl;
}