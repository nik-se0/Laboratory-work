// Copyright 2021 Semenova Veronika
#include "math.h"
#include "locale.h"
#include "stdlib.h"
#include "memory.h"
#include <windows.h>
#include "Taylor.h"


int main()
{
    int entry = -1, inlet = 0, i = 0, f = 0, n = 0, o = 1;
    double x = 0, e = 0, s = 0, w = 0;
    function_t F[2][2] = { 0 };

    F[0][0] = step_tgX;
    F[0][1] = tan;
    F[1][0] = step_ctgX;
    F[1][1] = ctan;

    setlocale(LC_ALL, "Rus");

    printf("Выбрать функцию\n\n1. Tg(x)\n2. Ctg(x)\nВвод: ");
    scanf_s("%d", &f);
    f = f - 1;

    printf("\nЗадать точку x \nВвод: ");
    scanf_s("%lf", &x);

    printf("\nЗадать точность вычисления \nВвод: ");
    scanf_s("%lf", &e);

    printf("\nЗадать число элементов ряда для выполнения расчета\n Ввод: ");
    scanf_s("%d", &n);

    switch (f)
    {
    case 0: s = x; w = 1; break;
    case 1: s = 1 / x; w = 4; s = s - x / (w - 1); break;
    }

    Taylor(x, s, w, e, n, F[f][1], F[f][0]);

}

