#include<stdlib.h>
#include <map>
#include <string>
#include<sstream>
#include <fstream>
#include<iostream>
#include<iomanip>
#include "functions.h"
#include "result_info.h"

#define DEBUG false

#define SABINA

#ifdef SABINA
#include "SabinaMethods.h"
#else
#include "ElinaMethods.h"
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
	for (auto ur = functions<T>.begin(); ur != functions<T>.end(); ur++)//по всем уравнениям
	{
		for (auto it = methods<T>.begin(); it != methods<T>.end(); it++)//по всем методам
		{
			auto table = (*it)(n, dt, (*ur));
			out << "    " << endl;
			out << table.info() << endl;
			out << "        " << endl;
		}
	}
}

template<typename T>
void foo(int n, T dt)
{
	auto ur = *functions<T>.end();//2-е уравнение
	auto method = methods<T>.begin();//1-й метод, как раз нужный

	auto table = (*method)(n, dt, ur);
	out << "    " << endl;
	out << table.info() << endl;
	out << "        " << endl;
}

auto dt_arr = { 1E-3, 1E-6, 1E-8 };

void step2(int n)//часть 2 - решение 2-го уравнений 1-м методом для разных dt
{
	for (auto it = dt_arr.begin(); it!=dt_arr.end(); it++)
	{
		double dt = *it;
		out << "float" << endl;
		foo<float>(n, dt);
		out << "double" << endl;
		foo<double>(n, dt);
	}
}

#if DEBUG
template<typename T>
void foo(T x)
{
	auto f = methods<T>;
	for (auto it = f.begin(); it != f.end(); it++)
	{

	}
	//	for each (auto method in methods<T>)
		//{

	//	}
}
#endif






int main()
{
	cout << "Variant " << VARIANT << endl;
	cout << "User " << UserName << endl;

	step1(10, 1E-3);
	out << endl << "step 2" << endl;
	step2(10);

#if DEBUG
	auto f = methods<double>;
	for (auto it = f.begin(); it != f.end(); it++)
	{
		auto tabl = (*it)(100, 0.01, &a1);
	}
	auto table1 = Eiler_Kramer<double>(100, 1E-3, &a1);
	foo<double>(1);
	cout << table1.info() << endl;
#endif
	

	system("pause");
	return 0;
}