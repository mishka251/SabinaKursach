#include<stdlib.h>
#include <map>
#include <string>
#include<sstream>
#include <fstream>
#include<iostream>
#include<iomanip>
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
#if(OUTTYPE==File)
#define out cout
#else
#define out fout
#endif



template<typename T>
void step1(int n, T dt)//часть 1 - решение обоих уравнений тремя методами
{
	for (int i = 0; i < 2; i++)//по всем уравнениям
	{
		auto ur = functions<T>[i];
		for (auto j = 0; j < 3; j++)//по всем методам
		{
#if DEBUG
			try
			{
#endif
				auto method = methods<T>[j];
				auto table = method(n, dt, ur);
				out << "    " << endl;
				out << table.info() << endl;
				out << "        " << endl;
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
void foo(int n, T dt)
{
	auto ur = functions<T>[0];//2-е уравнение
	auto method = methods<T>[0];//1-й метод, как раз нужный

	auto table = method(n, dt, ur);
	out << "    " << endl;
	out << table.info() << endl;
	out << "        " << endl;
}


auto dt_arr = { 1E-3, 1E-6, 1E-8 };

void step2(int n)//часть 2 - решение 2-го уравнений 1-м методом для разных dt
{
	for (auto it = dt_arr.begin(); it != dt_arr.end(); it++)
	{
		double dt = *it;
		out << "float" << endl;
		foo(n, (float)dt);
		out << "double" << endl;
		foo(n, dt);
	}
}

void initFunctions()
{
	f1<float>(1, 1);
	f2<float>(1, 1);
	f1<double>(1, 1);
	f2 < double > (1, 1);
}


int main()
{
	initFunctions();
	cout << "Variant " << VARIANT << endl;
	cout << "User " << UserName << endl;
	cout << f1<double>(2, 3) << endl;
	functions<double>[1](2, 3);
	out << "step 1" << endl;
	step1<double>(10, 1E-3);
	out << endl << "step 2" << endl;
	step2(10);

	system("pause");
	return 0;
}

void worked_code()
{

	foo<float>(1, 0.1);
	auto d1 = f1<double>(3.0, 4.0);
	auto d2 = f1<double>(3.0, 4.0);
	auto d3 = functions<double>[0](3.0, 4.0);

	Eiler_Kramer(10, 0.01, functions<double>[0]);

	cout << d1 << "   " << d2 << "   " << d3 << endl;

	auto ff1 = f1<float>(3.0f, 4.0f);
	auto ff2 = f1<float>(3.0f, 4.0f);
	auto ff3 = functions<float>[0](3.0f, 4.0f);

	Eiler_Kramer(10, 0.01f, functions<float>[0]);

	cout << ff1 << "   " << ff2 << "   " << ff3 << endl;

	foo<float>(10, 0.1f);
	foo<double>(10, 0.1f);
}