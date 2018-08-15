#pragma once
#include "AllMethods.h"
#include "struct_method.h"
#define UserName "Sabina"
#define VARIANT 10
//массив методов и константы для варианта 10
const double alph = 1, bett = 0, w1 = 0.4;

template < typename T>//средних скоростей   Верле             Предиктор-корректор
Method<T> methods[] = { AllMethods<T>[4],  AllMethods<T>[3], AllMethods<T>[2] };