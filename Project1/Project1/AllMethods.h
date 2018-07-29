#pragma once
#include<string>
//все варианты методов для вариантов 9 и 10

template < typename T>
function_table<double, T, T> aver_speed(int n, double dt, T(*func)(T x, T y))
{
	T vn = bett, xn = alph;

	function_table<double, T, T> result;
	result.add_vals(0, xn, vn);
	double t = 0;
	for (int i = 0; i < n; i++)
	{
		t += dt;
		vn += alph * func(xn, vn);
		xn = xn * vn*dt + (func(xn, vn)*dt*dt) / 2.0;
		result.add_vals(t, xn, vn);
	}
	return result;
}

template < typename T>
function_table<double, T, T> Eiler_Kramer(int n, T dt, T(*func) (T x, T y))
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
function_table<double, T, T> Biman(int n, T dt, T(*func) (T x, T y))
{
	double t = 0;
	T x = alph, v = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);
	T a = 0, a_prev, a_next = 0;
	for (int i = 1; i <= n; i++)
	{
		a_prev = a;
		a = a_next;
		t += dt;
		x += dt * v + (4 * a - a_prev)*dt*dt / 6.0;
		a_next = func(x, v);
		v += dt * (2 * a_next + 5 * a - a_prev) / 6.0;
		result.add_vals(t, x, v);
	}

	return result;
}

template < typename T>
function_table<double, T, T> pred_corr(int n, T dt, T(*func) (T x, T y))
{
	double t = 0;
	T x_prev, x = alph, x_next = alph, v = 0, v_next = bett;
	function_table<double, T, T> result;
	result.add_vals(t, x, v);
	T  a_prev, a, a_next = 0;
	for (int i = 1; i <= n; i++)
	{
		a = a_next;
		x_prev = x;
		x = x_next;
		v = v_next;
		a_prev = a;
		x_next = x_prev + 2 * v*dt;//predictor
		a_next = func(x_next, v);
		v_next += (a_next + a)*dt / 2.0;
		x_next = x + dt * (v_next + v) / 2.0;
		t += dt;
		result.add_vals(t, x, v);
	}
	return result;
}

template < typename T>
function_table<double, T, T> Verle(int n, T dt, T(*func) (T x, T y))
{
	double t = 0;
	T x_prev, x, x_next = alph, v = bett;
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