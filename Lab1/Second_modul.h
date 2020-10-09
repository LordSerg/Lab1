#pragma once
#include <iostream>
using namespace std;
void show_matrix(int* a, int h, int w);
void show_matrix_to_file(int* a, int h, int w,ofstream& owo);
void read_from_file(int* a, ifstream& wow,int w,int h);
void read_from_user(int* a,int w, int h);
void do_first_task(int* a, int h, int w);
void do_second_task(int* a, int h, int w, int& positive, int& negative, int& neutral);