#pragma once
#include<functional>
//два варианты функций для двух уравнений
template < typename T>
T a1(T x, T v)
{
	return -w1 * w1 * x;
}

template < typename T>
T a2(T x, T v)
{
	return w1 * w1 * x;
}


template < typename T>
std::function<T(T, T)> f1 = a1<T>;
template < typename T>
std::function<T(T, T)> f2 = a2<T>;
template < typename T>
std::function<T(T, T)> functions[] = { f1<T>, f2<T> };
