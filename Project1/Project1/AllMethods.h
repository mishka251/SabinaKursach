#pragma once
#include<string>
#include<functional>
//все варианты методов для вариантов 9 и 10
//тут только функции


//метод средних скоростей = метод полушага
template < typename T>
function_table<double, T, T> aver_speed(int n, T dt, function<T(T, T)> f)
{
	double t = 0;
	T vn = bett, xn = alph;
	function_table<double, T, T> result;
	result.add_vals(0, xn, vn);


	vn += f(xn, vn)*dt / 2.0;

	for (int i = 1; i <= n; i++)
	{
		t += dt;
		vn += dt * f(xn, vn);
		xn += vn * dt;
		result.add_vals(t, xn, vn);
	}
	return result;
}

template < typename T>
function_table<double, T, T> Eiler_Kramer(int n, T dt, function<T(T, T)> f)
{
	double t = 0;
	T xn = alph, vn = bett;
	function_table<double, T, T> result;
	result.add_vals(t, xn, vn);

	for (int i = 1; i <= n; i++)
	{
		t += dt;
		vn += dt * f(xn, vn);
		xn += dt * vn;
		result.add_vals(t, xn, vn);
	}

	return result;
}

template < typename T>
function_table<double, T, T> Biman(int n, T dt, function<T(T, T)> f)
{
	double t = 0;
	T x = alph, v = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);

	T  a_prev = 0, a = 0, a_next = 0;

	for (int i = 1; i <= n; i++)
	{
		a_prev = a;
		a = a_next;
		t += dt;
		x += dt * v + (4 * a - a_prev)*dt*dt / 6.0;
		a_next = f(x, v);
		v += dt * (2 * a_next + 5 * a - a_prev) / 6.0;
		result.add_vals(t, x, v);
	}
	return result;
}

template < typename T>
function_table<double, T, T> pred_corr(int n, T dt, function<T(T, T)> f)
{
	double t = 0;
	T x_prev, x = alph, x_next = alph + bett * dt, v = bett, v_next = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);
	T  a, a_next;
	for (int i = 1; i <= n; i++)
	{
		//a = a_next;
		x_prev = x;
		x = x_next;
		v = v_next;


		a = f(x, v);
		T pred;
		do
		{
			pred = x_prev + 2 * v*dt;//predictor
			a_next = f(pred, v);
			v_next = v + (a_next + a)*dt / 2.0;
			x_next = x + dt * (v_next + v) / 2.0;
		} while (abs(x_next - pred) > dt);



		t += dt;
		result.add_vals(t, x, v);
	}
	return result;
}

template < typename T>
function_table<double, T, T> Verle(int n, T dt, function<T(T, T)> f)
{
	double t = 0;
	T x_prev, x = alph, x_next = alph + bett * dt, v = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);
	for (int i = 1; i <= n; i++)
	{
		x_prev = x;
		x = x_next;

		x_next = 2 * x - x_prev + f(x, v)*dt*dt;
		v = (x_next - x_prev) / (2 * dt);
		t += dt;
		result.add_vals(t, x, v);
	}
	return result;
}