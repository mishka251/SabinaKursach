#pragma once
#include "AllMethods.h"
#include "struct_method.h"
#define UserName "Sabina"
#define VARIANT 10
//������ ������� � ��������� ��� �������� 10
const double alph = 1, bett = 0, w1 = 0.4;


template < typename T>//������� ���������   �����             ���������-���������
Method<T> methods[] = { AllMethods<T>[4],  AllMethods<T>[3], AllMethods<T>[2] };

//std::function< function_table<double, T, T>(int n, T dt, function<T(T, T)> f)>
//methods[] = { aver_speed<T>, Biman<T>, pred_corr<T> };
//std::string method_names[] = { "������� ���������", "������", "���������-���������" };