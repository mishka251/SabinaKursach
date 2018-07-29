#pragma once
#include<stdlib.h>
#include <map>
#include <string>
#include<sstream>
#include <fstream>
#include<iostream>
#include<iomanip>

using namespace std;

//����� ������� ������� ��� �������� � ������ ����������.
//������ �������, �����������, ��������
template<typename t_type, typename x_type, typename v_type>

class function_table
{
	map<t_type, pair<x_type, v_type>> table;

public:
	function_table()
	{

	}

	void add_vals(t_type t, x_type x, v_type v)
	{

		table.insert(make_pair(t, make_pair(x, v)));
	}
	string info()
	{
		stringstream ss, ss1;
		ss << "function table" << endl;
		string line = "-------------------------------------------------------------------------------";
		auto m = setw(13);
		ss1 << "|" << m << "t" << m << "|" << m << "x" << m << "|" << m << "v" << m << "|";
		string head = ss1.str();
		ss << line << endl;
		ss << head << endl;
		ss << line << endl;
		ss << line << endl;
		for (auto it = table.begin(); it != table.end(); it++)
		{
			auto t = it->first;
			auto x = it->second.first;
			auto v = it->second.second;
			ss << "|" << m << t << m << "|" << m << x << m << "|" << m << v << m << "|" << endl;
			ss << line << endl;
		}

		ss << endl << "End table" << endl << endl;
		return ss.str();
	}

	//static function_table create_table(x_type(*y)(x_type x), t_type a, t_type b, t_type dt)
	//{
	//	function_table table;
	//	for (arg i = a; a <= b; a += dt)
	//		table.add_vals(i, y(i));

	//	return table;
	//}

};