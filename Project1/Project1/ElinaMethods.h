#pragma once
#include "AllMethods.h"
#include "struct_method.h"
#define UserName "Elina"
#define VARIANT 9
//массив функций и констант для варианта 9
const double alph = 5, bett = 0, w1 = 25;

template<typename T>//// Эйлера-Крамера     Бимана           предиктор-корректор
Method<T> methods[] = { AllMethods<T>[0],  AllMethods<T>[1], AllMethods<T>[2] };