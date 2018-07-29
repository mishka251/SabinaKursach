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

#define ELINA

#ifdef SABINA
#include "SabinaMethods.h"
#else
#include "ElinaMethods.h"
#endif

using namespace std;

template<typename T>
void step1(int n, T dt)//часть 1 - решение обоих уравнений тремя методами
{
	for (auto ur = functions<T>.begin(); ur != functions<T>.end(); ur++)//по всем уравнениям
	{
		for (auto it = methods<T>.begin(); it != methods<T>.end(); it++)//по всем методам
		{
			auto table = (*it)(n, dt, (*ur));
			cout << "    " << endl;
			cout << table.info() << endl;
			cout << "        " << endl;
		}
	}
}


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



template<typename T>
auto dt_arr = { (T)1E-3, (T)1E-6, (T)1E-8 };


int main()
{
	cout << "Variant " << VARIANT << endl;
	cout << "User " << UserName << endl;

	step1(10, 1E-3);


#//if DEBUG
	auto f = methods<double>;
	for (auto it = f.begin(); it != f.end(); it++)
	{
		auto tabl = (*it)(100, 0.01, &a1);
	}
	auto table1 = Eiler_Kramer<double>(100, 1E-3, &a1);
	foo<double>(1);
	cout << table1.info() << endl;
//#endif
	

	system("pause");
	return 0;
}