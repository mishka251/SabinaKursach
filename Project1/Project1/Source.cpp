#include<stdlib.h>
#include <map>
#include <string>
#include<sstream>
#include <fstream>
#include<iostream>
#include<iomanip>
#include<chrono>
#include "functions.h"
#include "result_info.h"

#define DEBUG true

#define ELINA

#ifdef SABINA
#include "SabinaMethods.h"
#else 
#ifdef ELINA
#include "ElinaMethods.h"
#else
#error UNKNOWN_USER
#endif
#endif


using namespace std;

#define OUTTYPE File


template<typename T>
void step1(int n, T dt)//����� 1 - ������� ����� ��������� ����� ��������
{
	for (int i = 0; i < 2; i++)//�� ���� ����������
	{
		auto ur = functions<T>[i];
		for (auto j = 0; j < 3; j++)//�� ���� �������
		{
#if DEBUG
			try
			{
#endif


#if (OUTTYPE == File)

				string s = "step1_ur" + std::to_string(i + 1) + "method_" + methods<T>[j].name + ".txt";
				ofstream out;
				out.open(s);

#else
				ostream &out = cout;
#endif
				auto &method = methods<T>[j].method;
				auto start = chrono::steady_clock::now();
				auto table = method(n, dt, ur);
				auto end = chrono::steady_clock::now();
				out << "��������� " << i << endl;
				out << "�����: " << methods<T>[j].name << endl;
				auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
				out << "����� ������: " << time.count() << " ��" << endl;
				out << "    " << endl;
				out << table.info() << endl;
				out << "        " << endl;

#if (OUTTYPE == File)
				out.close();
#endif

#if DEBUG
		}
			catch (exception ex)
			{
				cout << "ERROR" << endl;
				cout << ex.what() << endl;
				cout << "i=" << i << " j=" << j << endl;
			}
#endif

	}
}
}


template<typename T>
void foo(int n, T dt, ostream& out)
{
	auto ur = functions<T>[0];//2-� ���������
	auto method = methods<T>[0].method;//1-� �����, ��� ��� ������

	auto start = chrono::steady_clock::now();

	auto table = method(n, dt, ur);

	auto end = chrono::steady_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	out << "�����: " << time.count() << " ��" << endl;

	out << "    " << endl;
	out << table.info() << endl;
	out << "        " << endl;
}


auto dt_arr = { 1E-3, 1E-6, 1E-8 };

void step2(int n)//����� 2 - ������� 2-�� ��������� 1-� ������� ��� ������ dt
{
	for (auto it = dt_arr.begin(); it != dt_arr.end(); it++)
	{
		double dt = *it;

#if (OUTTYPE == File)
		string s = "step2_n=";
		s += std::to_string(dt);
		ofstream out;
		out.open(s + "float.txt");
#else
		ostream& out = cout;
#endif
		out << "float" << endl;
		foo<float>(n, (float)dt, out);
#if (OUTTYPE == File)
		out.close();
		out.open(s + "double.txt");
#endif
		out << "double" << endl;
		foo(n, dt, out);
#if (OUTTYPE == File)
		out.close();
#endif
	}
}

template<typename T>
void fuckingMagic()
{
	f1<T>(1, 1);
	f2<T>(1, 1);
	AllMethods<T>;
}

//��� ���� ����� �� ��������, �� ���� ������
void initFunctions()
{
	//������ �����!!!! 
	f1<float>(1, 1);
	f2<float>(1, 1);
	f1<double>(1, 1);
	f2<double>(1, 1);

	//������ �����!!!! �2
	AllMethods<float>;
	AllMethods<double>;
}


int main()
{
#if DEBUG
	auto start = chrono::steady_clock::now();
#endif
	//initFunctions();
	fuckingMagic<float>();
	fuckingMagic<double>();
	int n = 1000;
	cout << "Variant " << VARIANT << endl;
	cout << "User " << UserName << endl;
	cout << "step 1" << endl;
	step1(n, 1E-3);
	cout << endl << "step 2" << endl;
	step2(n);
#if DEBUG
	cout << "ready" << endl;
	auto end = chrono::steady_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	cout << "time = " << time.count() << " ms" << endl;
#endif
	system("pause");
	return 0;
}