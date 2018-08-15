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

#define DEBUG false

#define SABINA

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
void SolveAndPrint(int n, T dt, int ur_ind, Method<T>& method)
{
#if (OUTTYPE == File)

	string s = "step1_ur" + std::to_string(ur_ind + 1) + "method_" + method.name + ".txt";
	ofstream out;
	out.open(s);

#else
	ostream &out = cout;
#endif
	auto ur = functions<T>[ur_ind];
	auto start = chrono::steady_clock::now();
	auto table = method.method(n, dt, ur);
	auto end = chrono::steady_clock::now();
	out << "”равнение " << ur_ind << endl;
	out << "ћетод: " << method.name << endl;
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	out << "¬рем€ работы: " << time.count() << " мс" << endl;
	out << "    " << endl;
	out << table.info() << endl;
	out << "        " << endl;

#if (OUTTYPE == File)
	out.close();
#endif
}


template<typename T>
void step1(int n, T dt)//часть 1 - решение обоих уравнений трем€ методами
{
	for (int i = 0; i < 2; i++)//по всем уравнени€м
	{
		//auto ur = functions<T>[i];
		for (auto j = 0; j < 3; j++)//по всем методам
		{
#if DEBUG
			try
			{
#endif
				SolveAndPrint(n, dt, i, methods<T>[j]);

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
	auto ur = functions<T>[0];//2-е уравнение
	auto method = methods<T>[0].method;//1-й метод, как раз нужный

	auto start = chrono::steady_clock::now();

	auto table = method(n, dt, ur);

	auto end = chrono::steady_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	out << "¬рем€: " << time.count() << " мс" << endl;

	out << "    " << endl;
	out << table.info() << endl;
	out << "        " << endl;
}


auto dt_arr = { 1E-3, 1E-6, 1E-8 };

void step2(int n)//часть 2 - решение 2-го уравнений 1-м методом дл€ разных dt
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


//без этой фигни не работает, не знаю почему
void initFunctions()
{
	//≈ЅјЌјя ћј√»я!!!! ’2
	AllMethods<float>;
	AllMethods<double>;
}


int main()
{
#if DEBUG
	auto start = chrono::steady_clock::now();
#endif
	int n = 1000;
	cout << "Variant " << VARIANT << endl;
	cout << "User " << UserName << endl;
	//cout << "step 1" << endl;
	step1(n, 1E-3);
	//cout << endl << "step 2" << endl;
	step2(n);
#if (OUTTYPE == File)
	cout << "Vivod v fili" << endl;
#endif
#if DEBUG
	cout << "ready" << endl;
	auto end = chrono::steady_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	cout << "time = " << time.count() << " ms" << endl;
#endif
	system("pause");
	return 0;
}
