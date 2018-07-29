#include<stdlib.h>
#include <map>
#include <string>
#include<sstream>
#include <fstream>
#include<iostream>
#include<iomanip>
#include "functions.h"
#include "result_info.h"

using namespace std;


const double w1 = 0.1;

template < typename T>
function_table<int, T, T> aver_speed(T alph, T bett, int n, int dt, T(*func)(T x, T y))
{
	T vn = bett, xn = alph;

	function_table<int, T, T> result;
	result.add_vals(0, xn, vn);

	for (int i = 0; i < n; i++)
	{
		vn += alph * func(xn, vn);
		xn = xn * vn*dt + (func(xn, vn)*dt*dt) / 2.0;
		result.add_vals(i, xn, vn);
	}
	return result;
}

template < typename T>
function_table<double, T, T> Eiler_Kramer(T alph, T bett, int n, T dt, T(*func) (T x, T y))
{
	double t = 0;
	T x = alph, v = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);

	for (int i = 1; i <= n; i++)
	{
		t += dt;
		v += dt * func(x, v);
		x += dt * v;
		result.add_vals(t, x, v);
	}

	return result;
}

template < typename T>
function_table<double, T, T> Biman(T alph, T bett, int n, T dt, T(*func) (T x, T y))
{
	double t = 0;
	T x = alph, v = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);
	double a, a_prev, a_next = 0;
	for (int i = 1; i <= n; i++)
	{
		a_prev = a;
		a = a_next;
		t += dt;
		x += dt * v + (4 * a - a_prev)*dt*dt / 6.0;
		a + next = func(x, v);
		v += dt * (2 * a_next + 5 * a - a_prev) / 6.0;
		result.add_vals(t, x, v);
	}

	return result;
}

template < typename T>
function_table<double, T, T> pred_corr(T alph, T bett, int n, T dt, T(*func) (T x, T y))
{
	double t = 0;
	T x_prev, x = alph, x_next, v = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);
	double a, a_prev, a_next = 0;
	for (int i = 1; i <= n; i++)
	{
		a_prev = a;
		a = a_next;
		t += dt;
		x += dt * v + (4 * a - a_prev)*dt*dt / 6.0;
		a + next = func(x, v);
		v += dt * (2 * a_next + 5 * a - a_prev) / 6.0;
		result.add_vals(t, x, v);
	}

	return result;
}
//template<typename  T>
//auto funcs =/* T() (T x, T y)*/ { &a1, &a2 };

template<typename T>
void foo(T x)
{

}


int main()
{

	auto table1 = Eiler_Kramer<double>(1, 0, 100, 1E-3, &a1);
	cout << table1.info() << endl;
	system("pause");
	return 0;
}