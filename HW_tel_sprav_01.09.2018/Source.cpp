#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

/// ***Написать программу «расширенный телефонный справочник».Создайте массив указателей из двух элементов.
/// Каждый указатель массива ссылается на динамический массив целых чисел.
/// Первый динамический массив – это список кодов, второй массив – это список номеров.
/// Таким образом, каждая запись в телефонном справочнике содержит код города и номер телефона.
// Напишите функции для добавления нового телефона в массив,
// для удаления указанного телефона из справочника,
// поиск телефона по номеру,
/// сортировку по номеру телефона, сортировку по коду города.
// Создайте меню для пользователя.

void add(int **&a, int &n, int kod, int nomer) {
	int **tmp, *p, *p1, *p2;
	tmp = new int*[2];

	for (p = a[0], p1 = tmp[0]; p < a[0] + n + 1; p++, p1++)
		*p1 = *p;
	*p1 = kod;

	for (p = a[1], p2 = tmp[1]; p < a[1] + n +1; p++, p1++)
		*p2 = *p;
	*p2 = nomer;

	if (n != 0) delete[] a[0], delete[] a[1];
	delete[] a;
	for (int i = 0; i < n; i++)
		a[i] = tmp[i];
	n++;
}

void sort_kod(int *a[], int n) {
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
}
void sort_nomer(int *a[], int n) {
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
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	while (true)
	{
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
				a[i][j] = rand() % 1000 + 100;
				cout << a[i][j] << "   ";
			}
			cout << endl;
		}
		cout << endl;

		/*sort_kod(a, n);
		sort_nomer(a, n);*/
		add(a, n, 178, 999);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[i][j] << "   ";
			}
			cout << endl;
		}
		cout << endl;


		for (int i = 0; i < 2; i++)
			delete[] a[i];
		delete[] a;
	}
	system("pause");
	return 0;
}