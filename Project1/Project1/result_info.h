#pragma once
#include<stdlib.h>
#include <map>
#include <string>
#include<sstream>
#include <fstream>
#include<iostream>
#include<iomanip>

using namespace std;

//класс таблица функции для хранения и вывода результата.
//момент времени, кооордината, скорость
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

	friend ostream operator<<(ostream& ost, const function_table &table);
	friend ofstream operator<<(ofstream& ost, const function_table &table);
};
template<typename t_type, typename x_type, typename v_type>
ostream operator<<(ostream & ost, const function_table<t_type, x_type, v_type>  & table)
{
	ost << table.info() << endl;
	return ost;
}
template<typename t_type, typename x_type, typename v_type>
ofstream operator<<(ofstream & ost, const function_table<t_type, x_type, v_type> & table)
{
	ost << table.info() << endl;
	return ost;
}