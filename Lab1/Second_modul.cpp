#include <iostream>
#include <fstream>
#include "Second_modul.h"
using namespace std;
void show_matrix(int* a, int h, int w)
{//вывод матрицы на экран
	cout << "\n";
	for (int i = 0; i < w * h; i++)
	{
		cout << a[i];
		cout << " ";
		if ((i+1) % w == 0)
			cout << "\n";
	}
}
void show_matrix_to_file(int* a, int h, int w, ofstream& owo)
{//вывод матрицы в файл
	owo << "\n";
	for (int i = 0; i < w * h; i++)
	{
		owo << a[i];
		owo << " ";
		if ((i + 1) % w == 0)
			owo << "\n";
	}
}
void read_from_user(int* a,int w, int h)
{
	int j = 0, i = 0;
	while (j < h)
	{
		cin >> a[i + j * w];
		if (i + 1 < w)
			i++;
		else
		{
			i = 0;
			j++;
		}
	}
}
void read_from_file(int* a, ifstream& wow, int w, int h)
{
	int j = 0, i = 0;
	while (j < h)
	{
		wow >> a[i + j * w];
		if (i + 1 < w)
			i++;
		else
		{
			i = 0;
			j++;
		}
	}
}

int sum(int* a, int from, int to)
{//находим сумму элементов строки
	int answer=0;
	for (int i = from; i <= to; i++)
		answer += a[i];
	return answer;
}
void swap(int* a, int i, int j, int w)
{//меняем две строки местами
	int from1 = i * w;
	int from2 = j * w;
	for (int k = 0; k < w; k++)
	{
		a[from1 + k] += a[from2 + k];
		a[from2 + k] = a[from1 + k] - a[from2 + k];
		a[from1 + k] -= a[from2 + k];
	}
}
void do_first_task(int* a, int h, int w)
{//упорядочить по возрастанию сумму чисел рядков
	int* p = new int[h];
	for (int i = 0; i < h; i++)
		p[i] = sum(a, i * w, i * w + w - 1);//считаем сумму элементов каждой строки
	cout << endl;
	for (int i = 0; i < h; i++)//сортировка
		for (int j = i + 1; j < h; j++)
			if (p[i] > p[j])
			{
				swap(a, i, j, w);
				p[i] += p[j];
				p[j] = p[i] - p[j];
				p[i] -= p[j];
			}
}

void do_second_task(int* a, int h, int w, int& positive, int& negative, int& neutral)
{//найти количество "хороших, плохих и никаких"
	//хорошие : суvма рядка > 0
	//плохие : сумма рядка < 0
	//никакие : сумма рядка = 0
	int j = 0, i = 0, sum=0;
	while (j < h)
	{
		if (i + 1 < w)
		{
			sum += a[i + j * w];
			i++;
		}
		else
		{
			if (sum > 0)
				positive++;
			else if (sum < 0)
				negative++;
			else
				neutral++;
			sum = 0;
			i = 0;
			j++;
		}
	}
}