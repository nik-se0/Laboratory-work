// Copyright 2021 Semenova Veronika
#include <stdio.h>
#include "math.h"
#include "stdlib.h"
#include "memory.h"

typedef double (*function_t)(double);

double ctan(double x);

double step_tgX(double x, double* d, int i, double M[], double w);

double step_ctgX(double x, double* d, int i, double M[], double w);

void Taylor(double x, double s, double w, double e, double n, function_t ideal, function_t step);

