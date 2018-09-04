#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// ***Написать программу «расширенный телефонный справочник».Создайте массив указателей из двух элементов.
// Каждый указатель массива ссылается на динамический массив целых чисел.
// Первый динамический массив – это список кодов, второй массив – это список номеров.
// Таким образом, каждая запись в телефонном справочнике содержит код города и номер телефона.
// Напишите функции для добавления нового телефона в массив,
// для удаления указанного телефона из справочника,
// поиск телефона по номеру,
// сортировку по номеру телефона, сортировку по коду города.
// Создайте меню для пользователя.

void add(int **&a, int &n, int kod, int nomer) {
	int **tmp;
	tmp = new int*[2];
	tmp[0] = new int[n + 1];
	tmp[1] = new int[n + 1];
	
	for (int i = 0; i < n; i++)
	{
		tmp[0][i] = a[0][i];
		tmp[1][i] = a[1][i];
	}
	tmp[0][n] = kod;
	tmp[1][n] = nomer;

	if (n != 0)
	{
		delete[] a[0], delete[] a[1];
		delete[] a;
	}
	a = tmp;
	n++;
}
bool search(int **a, int n, int kod, int nomer) {
	int k = -1, k1 = -1;;
	for (int i = 0; i < n; i++)
	{
		if (a[0][i] == kod) k = i;
		if (a[1][i] == nomer) k1 = i;
	}
	if (k < 0 || k1 < 0)
	{
		cout << "number (" << kod << " " << nomer << ") is not found" << endl;
		return false;
	}
	else if (k == k1)
	{
		cout << "telephone number (" << kod << " " << nomer << ") is under the index: " << k << endl;
		return true;
	}
}
void erase(int **&a, int &n, int kod, int nomer) {
	int **tmp;
	int j = 0, j1 = 0;
	tmp = new int*[2];
	tmp[0] = new int[n - 1];
	tmp[1] = new int[n - 1];

	if (!search(a, n, kod, nomer)) return;
	else if(search(a, n, kod, nomer))
	{
		for (int i = 0; i < n; i++)
		{
			if (a[0][i] != kod)
				tmp[0][j++] = a[0][i];
			if (a[1][i] != nomer)
				tmp[1][j1++] =a[1][i];
		}
	}
	cout << "(is deleted now)" << endl;
	delete[] a[0], delete[] a[1];
	delete[] a;
	a = tmp;
	n = j;
}
void sort_kod(int **a, int n) {
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if ((a[0][i] > a[0][i + 1]))
			{
				swap(a[0][i], a[0][i + 1]);
				swap(a[1][i], a[1][i + 1]);
			}
		}
	}
	cout << "sorted by key:" << endl;
}
void sort_nomer(int **a, int n) {
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if ((a[1][i] > a[1][i + 1]))
			{
				swap(a[0][i], a[0][i + 1]);
				swap(a[1][i], a[1][i + 1]);
			}
		}
	}
	cout << "sorted by number:" << endl;
}
void print(int **a, int n) {
	cout << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

		int n;
		cin >> n;
		int **a;
		a = new int*[2];

		for (int i = 0; i < 2; i++)
			a[i] = new int[n];

		for (int i = 0; i < 2; i++)
		{
			if (i == 0) cout << "список кодов:   ";
			else cout << "список номеров: ";
			for (int j = 0; j < n; j++)
			{
				a[i][j] = rand() % 901 + 100;
				cout << a[i][j] << "   ";
			}
			cout << endl;
		}
		cout << endl;

		int choice;
		bool f = true;
		while (f)
		{
			cout << "Выберите действие:" << endl;
			cout << "1 - добавление номера в справочник" << endl;
			cout << "2 - поиск телефона по номеру" << endl;
			cout << "3 - удаление указанного телефона из справочника" << endl;
			cout << "4 - сортировка по номеру телефона" << endl;
			cout << "5 - сортировка по коду город" << endl;
			cout << "0 - выход" << endl << endl;

			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				add(a, n, 7212, 335010);
				add(a, n, 7272, 337788);
				print(a, n);
			}
			break;
			case 2:
			{
				search(a, n, 7272, 888888);
				search(a, n, 7212, 335010);
				print(a, n);
			}
			break;
			case 3:
			{
				erase(a, n, 7272, 888888);
				erase(a, n, 7272, 337788);
				print(a, n);
			}
			break;
			case 4:
			{
				sort_kod(a, n);
				print(a, n);
			}
			break;
			case 5:
			{
				sort_nomer(a, n);
				print(a, n);
			}
			break;
			case 0:
			{
				f = false;
			}
			break;
			}
		}

		for (int i = 0; i < 2; i++)
			delete[] a[i];
		delete[] a;

	system("pause");
	return 0;
}