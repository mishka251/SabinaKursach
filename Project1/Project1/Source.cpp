#include<stdlib.h>
#include <map>
#include <string>
#include<sstream>
#include <fstream>
#include<iostream>
#include<iomanip>
#include "functions.h"
#include "result_info.h"

#define ELINA

#ifdef SABINA
#include "SabinaMethods.h"
#else
#include "ElinaMethods.h"
#endif

using namespace std;




template<typename T>
void foo(T x)
{
	auto f = methods<T>;
}



template<typename T>
auto dt_arr = { (T)1E-3, (T)1E-6, (T)1E-8};


int main()
{
	cout << "Variant " << VARIANT << endl;
	cout << "User " << UserName << endl;
	auto table1 = Eiler_Kramer<double>(100, 1E-3, &a1);
	foo<double>(1);
	cout << table1.info() << endl;
	system("pause");
	return 0;
}