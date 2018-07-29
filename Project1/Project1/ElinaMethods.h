#pragma once
#include "AllMethods.h"
#define UserName "Elina"
#define VARIANT 9
//массив функций и констант для варианта 9
const double alph = 5, bett = 0, w1 = 25;
template<typename T>
auto methods = { &Eiler_Kramer<T>, &Biman<T>, &pred_corr<T> };
