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
    //��������� ��������� ������ - ��������� �������
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
    {//���� �� ������ �� ��������� ������, �� ������� �������:
        cout << "������� ������� ����� ����� (������, ������, �������),\n ��� ����, ��� ��������� �������� �������(��� �����)\n";
        cin.getline(trying, 200);
        for (int i = 0; i < 200; i++)
            if ((trying[i] > '9' || trying[i] < '0')&&trying[i]>0)
            {
                b = true;
                break;
            }
        if (b)
        {//���� �� ������� �������, �� ������������ ���� ��� �����
            ifstream wow;
            wow.open(trying);
            if (wow.is_open() == false)
            {
                cout << "������ ����� ����, ��� ��� ����� ������� �����������!\n���������� ��� ���\n";
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
    //������ ���� � ��������
    ofstream owo;
    do
    {
        cout << "������� ���� � ����� ��� ������:\n";
        cin.getline(results, 200);
        owo.open(results);
        if (owo.is_open() == false)
        {
            cout << "������ ����� ����, ��� ��� ����� ������� �����������!\n���������� ��� ���\n";
        }
    } while (owo.is_open() == false);

    //����� �������� ������� � ��, ���� �������� ��������� ������� � ������� ����������:
    cout << "������� �� �����:\n";
    owo << "������� �� �����:\n";
    show_matrix(m, h, w);
    show_matrix_to_file(m, h, w,owo);
    cout << "\n������ �������: ������������� ������� �� ����� ��������� � �������\n";
    owo << "\n������ �������: ������������� ������� �� ����� ��������� � �������\n";
    do_first_task(m, h, w);
    show_matrix(m, h, w);
    show_matrix_to_file(m, h, w,owo);
    cout << "\n������ �������: ��������� ���������� '�������', '������' � '�������' �����\n";
    owo << "\n������ �������: ��������� ���������� '�������', '������' � '�������' �����\n";
    int pos=0, neg=0, neutral=0;
    do_second_task(m, h, w, pos, neg, neutral);
    cout << "\n\n+: " << pos << "\n-: " << neg << "\n~: " << neutral << endl;
    owo << "\n\n+: " << pos << "\n-: " << neg << "\n~: " << neutral << endl;
    owo.close();
    cout << "\n��� ������ ���� �������� � ����";
}