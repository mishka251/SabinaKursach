#pragma once
#include<string>
#include"AllMethods.h"

template<typename T>
struct Method//метод 0 функция с названием
{
	std::string name;
	std::function< function_table<double, T, T>(int n, T dt, function<T(T, T)> f)>  method;
	Method(std::string name, std::function< function_table<double, T, T>(int n, T dt, function<T(T, T)> f)> func)
	{
		this->name = name;
		this->method = func;
	}
};
//все методы
template<typename T>
Method<T> AllMethods[] =
{
	Method<T>{"Эйлера-Крамера", Eiler_Kramer<T>},
	Method<T>{ "Бимана", Biman<T> },
	Method<T>{ "Предиктор-корретор", pred_corr<T> },
	Method<T>{ "Верле", Verle<T> },
	Method<T>{ "Средних скоростей", aver_speed<T> }
};
