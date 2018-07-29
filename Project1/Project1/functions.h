#pragma once
//два варианты функций для двух уравнений
template < typename T>
T a1(T x, T v)
{
	return -w1 * w1*x;
}
template < typename T>
T a2(T x, T v)
{
	return w1 * w1*x;
}
template < typename T>
auto funcrions = { &a1<T>, &a2<T> };