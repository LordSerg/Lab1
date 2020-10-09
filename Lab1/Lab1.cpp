#include <iostream>
#include <fstream>
#include "Second_modul.h"
using namespace std;
int main(int argc, char* argv[])
{//2011
    setlocale(LC_ALL, "Russian");
    int h = 0, w = 0, i = 0, j = 0;
    char trying[200];
    int* m = new int[0];
    bool b = false;
    char results[200];
    //проверяем аргументы строки - считываем матрицу
    try
    {
        if (argv[1] != NULL && argv[2] != NULL)
        {
            w = atoi(argv[1]);
            h = atoi(argv[2]);
        }
        else throw - 1;
        m = new int[w * h];
        for (i = 3; i < (w * h) + 3; i++)
            if (argv[i] != NULL)
                m[i - 3] = atoi(argv[i]);
            else
                throw - 1;
    }
    catch (int)
    {//если не ввести из командной строки, то вводить вручную:
        cout << "Введите матрицу целых чисел (ширина, высота, матрица),\n или файл, где находится вводимая матрица(имя файла)\n";
        cin.getline(trying, 200);
        for (int i = 0; i < 200; i++)
            if ((trying[i] > '9' || trying[i] < '0')&&trying[i]>0)
            {
                b = true;
                break;
            }
        if (b)
        {//если не удалось считать, то пользователь ввел имя файла
            ifstream wow;
            wow.open(trying);
            if (wow.is_open() == false)
            {
                cout << "Такого файла нету, или имя файла введено некорректно!\nПопробуйте еще раз\n";
            }
            else
            { 
                wow >> w;
                wow >> h;
                m = new int[w * h];
                read_from_file(m, wow, w, h);
            }
            wow.close();
        }
        else
        {
            w = atoi(trying);
            cin >> h;
            m = new int[w * h];
            read_from_user(m, w, h);
        }
    }
    //вводим файл с ответами
    ofstream owo;
    do
    {
        cout << "Введите путь к файлу для вывода:\n";
        cin.getline(results, 200);
        owo.open(results);
        if (owo.is_open() == false)
        {
            cout << "Такого файла нету, или имя файла введено некорректно!\nПопробуйте еще раз\n";
        }
    } while (owo.is_open() == false);

    //после введения матрицы и то, куда выводить выполняем задания и выводим результаты:
    cout << "Матрица на входе:\n";
    owo << "Матрица на входе:\n";
    show_matrix(m, h, w);
    show_matrix_to_file(m, h, w,owo);
    cout << "\nПервое задание: отсортировать матрицу по сумме элементов в строках\n";
    owo << "\nПервое задание: отсортировать матрицу по сумме элементов в строках\n";
    do_first_task(m, h, w);
    show_matrix(m, h, w);
    show_matrix_to_file(m, h, w,owo);
    cout << "\nВторое задание: посчитать количество 'хороших', 'плохих' и 'никаких' строк\n";
    owo << "\nВторое задание: посчитать количество 'хороших', 'плохих' и 'никаких' строк\n";
    int pos=0, neg=0, neutral=0;
    do_second_task(m, h, w, pos, neg, neutral);
    cout << "\n\n+: " << pos << "\n-: " << neg << "\n~: " << neutral << endl;
    owo << "\n\n+: " << pos << "\n-: " << neg << "\n~: " << neutral << endl;
    owo.close();
    cout << "\nВсе ответы были выведены в файл";
}