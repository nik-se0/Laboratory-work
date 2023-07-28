#include <stdio.h>
#include "Taylor.h"

typedef double (*function_t)(double);

double ctan(double x)
{
    return 1 / (tan(x));
}

double step_tgX(double x, double* d, int i, double M[], double w){
    int j, k, o1;

    o1 = 1;
    k = 2;
    *d = *d * (2 * i) * (2 * i + 1);

    M[i] = (double)1.0 / (*d) * pow(-1, i % 2);

    for (j = i; j > 0; j--)
    {
        M[i] = (double)M[i] + (o1 * M[j - 1]) / k;
        k = k * (2 * (i - j + 1) + 1) * (2 * (i - j + 1) + 2);
        o1 = o1 * (-1);
    }

    return M[i];
}

double step_ctgX(double x, double* d, int i, double M[], double w) {
    int j, k, o1;

        o1 = 1;
        k = 2;
        *d = *d * (2 * i) * (2 * i + 1);

        M[i] = (double)1.0 / (*d) * pow(-1, i % 2);

        for (j = i; j > 0; j--)
        {
            M[i] = (double)M[i] + (o1 * M[j - 1]) / k;
            k = k * (2 * (i - j + 1) + 1) * (2 * (i - j + 1) + 2);
            o1 = o1 * (-1);
        }

        return -M[i] / (w - 1);
}

void Taylor(double x, double s, double w, double e, double n, function_t ideal, function_t step)
{
    int i, u, j, k;
    double y, b, d, r;
    r = ideal(x);

    u= (int)n + 1;
    double* M = (double*)malloc(sizeof(double) * u);
    M[0] = 1;

    y = x;
    d = 1;
    i = 1;

    while ((i < n) && (fabs(r-s) > e))
    {
        y = y * x * x;
        w = w * 4;
        s = s + y*step(x, &d, i, M, w);
        //printf("\n%f\n", M[i]);
        i++;
    }

    printf("\nЭталонное значение: %f\nВычисленное значение: %f\nКоличество слогаемых: %d\n", r, s, i);

}



