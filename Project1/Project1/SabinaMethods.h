#pragma once
#include "AllMethods.h"
#define UserName "Sabina"
#define VARIANT 10
//массив методов и константы для варианта 10
const double alph = 1, bett = 0, w1 = 0.4;
template<typename T>
std::function< function_table<double, T, T>(int n, T dt, function<T(T, T)> f)>
 methods[] = { &aver_speed<T>, &Biman<T>, &pred_corr<T> };
std::string method_names[] = { "Средних скоростей", "Бимана", "Предиктор-корректор" };