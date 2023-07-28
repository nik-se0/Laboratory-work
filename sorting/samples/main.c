#include <stdio.h>
#include "sorting.h"
#include "locale.h"

int main()
{
    int a = -1, s = -1, i, f = 0, t = 0, u = 0;
    int* l = a;
    int* h = a;

    setlocale(LC_ALL, "Rus");

    while (s != 0) {
        menu(); scanf_s("%d", &s); printf("\n");
        switch (s)
        {
        case 1:
            read(&l, &a, f); f = 1; break;
        case 2: copy(l, &h, a); sort(&h, a);
            //    if (f == 0) { printf("Warning! Enter an array and try again\n"); }
            //     else { sort1(l, a); } 
            break;
        case 3:if (f == 0) { printf("ERROR: Введите массив и попробуйте снова\n"); }
              else {
            print(l, a);
        } break;
        }
    }


}
