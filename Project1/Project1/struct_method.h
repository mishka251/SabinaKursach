#pragma once
#include<string>
#include"AllMethods.h"

template<typename T>
struct Method
{
	std::string name;
	std::function< function_table<double, T, T>(int n, T dt, function<T(T, T)> f)>  method;
	Method(std::string name, std::function< function_table<double, T, T>(int n, T dt, function<T(T, T)> f)> func)
	{
		this->name = name;
		this->method = func;
	}
};
template<typename T>
Method<T> AllMethods[] =
{
	Method<T>{"������-�������", Eiler_Kramer<T>},
	Method<T>{ "������", Biman<T> },
	Method<T>{ "���������-��������", pred_corr<T> },
	Method<T>{ "�����", Verle<T> },
	Method<T>{ "������� ���������", aver_speed<T> }
};
