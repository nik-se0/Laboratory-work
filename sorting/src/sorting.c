#include <stdio.h>
#include "sorting.h"

void menu()
{
    printf("\n1. Ввести массив\n2. Cортировать массив\n3. Печать массива \n4. Сравнение сортировок \n0. Выйти из программы\n Ввод: ");
}

void swap(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void memoru(int** l, int a, int f) {
    int i, k;
    if (f == 1) { free(*l); }
    *l = (int*)malloc(a * sizeof(int));

}

void ran(int* l, int a, int g, int h) {
    int i;
    for (i = 0; i < a; i++)
    {
        *(l + i) = g + rand() % (h - g + 1);
    }
}

void scan(int* l, int a) {
    int i;
    printf("\n Введите массив\n Ввод: ");
    for (i = 0; i < a; i++)
    {

        scanf_s("%d", (l + i));

    }
}

void scan2(int* a, int** l, int f)
{
    do { printf("\nВведите длину массива\n Ввод: "); scanf_s("%d", a); if (*a < 1) { printf("\nERROR: Указана некоректная длина\n"); } } while (*a < 1);
    memoru(l, *a, f); 
}

void read(int** l, int* a, int f)
{
    int u = 0, g, h;
    printf("1. Ввести массив вручную\n2. Заполнить массив случайными числами\n Ввод: ");
    scanf_s("%d", &u);
    switch (u)
    {
    case 1:
        scan2(a, l, f); scan(*l, *a);
        break;
    case 2: scan2(a, l, f);
        printf("Введите диапозон массива\n Ввод: "); scanf_s("%d%d", &g, &h); ran(*l, *a, g, h);
        break;
    }
}

void print(int* l, int a) {
    int i;

    for (i = 0; i < a; i++)
    {
        printf("%d ", *(l + i));
    }
    printf("\n");
}

void bubble(int** l, int n)
{
    int i = 0, j = 0, a = 0, p = 0;
    a = n - 1; p = 0;
    for (i = 0; i < n - 1; i++) {
        swap(&a, &p); a = (-1) * a;
        for (j = a; j < p; j++)
        {
            if (l[abs(j)] > l[abs(j) + 1]) { swap((l + abs(j)), (l + abs(j) + 1)); }
        }
        p = abs(p) - 1; a = abs(a) + 1;
    }

}

void inserts(int** l, int n)
{
    int i, j = 0, k=0;
        for (i = 1; i < n; i++)
        {
            j = i-1; k = *(l + i);
         // printf("\n");
          while ((*(l+j) >k)&&(j>=0))
            {
              *(l + j+1) = *(l + j);
              j = j -1;
            //printf("DFGHJKL\n");
            }
            *(l + j+1) = k;
            
        }

}

void shell(int** l, int n)
{
    int i, j = 0, k = 0, s;

    for (s = n / 2; s > 0; s = s / 2)
    {
        for (i = s; i < n; i++)
        {
            j = i - 1; k = *(l + i);
            // printf("\n");
            while ((*(l + j) > k) && (j >= 0))
            {
                *(l + j + 1) = *(l + j);
                j = j - 1;
                //printf("DFGHJKL\n");
            }
            *(l + j + 1) = k;

        }
    }


}

void unity(int** l, int first, int last)
{
    int middle, start, final, j,a;
    int* m;
    middle = (first + last) / 2;
    a = (first + last)* 2;
    m = (int*)malloc(a * sizeof(int));

    middle= (first + last) / 2;
    start = first;
    final = middle + 1;

    //printf("FGHJK %d %d\n", first, last);
    for(j=first-1;j<last;j++)
    { if((start<=middle)&&((final>last)||(*(l+start-1)<*(l+final-1))))
    {
        m[j] = *(l + start-1); start++;
    } else
    {
        m[j] = *(l + final-1); final++;
    }
    
    }

    for(j=first-1;j<last;j++)
    { 
       *(l + j) = m[j];
    }
    
    free(m);
}

void merger(int** l, int first, int last)
{
    if (first < last) {
        merger(l, first, (first + last) / 2);
        merger(l, (first + last) / 2+1, last);
        //printf("SDFGHJK %d %d\n", first, last);
        unity(l, first, last);
        //printf("SDFGHJK\n");
    }
}
     

void quickly(int** l, int first, int last)
{
    int middle, j, i;
    j = last;
    i = first;
    middle= (i + j) / 2;
    
    do {
        while (*(l + i) < middle)
        {
            i++;
        }
        while (*(l + j) > middle)
        {
            j--;
        }

        if (i <= j)
        {
            swap(l + i, l + j);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) { quickly(l, j, last );}
    if (i< last) { quickly(l, first, i ); }
}

void sort(int** l, int a )
{
    int u = 0;
    printf("1.Cортировка пузырьком \n2.Сортировка вставкой\n3.Сортировка Шелла\n4.Сортировка слиянием\n5.Быстрая сортировка\n Ввод: ");
    scanf_s("%d", &u); printf("\nМассив до сортировки: "); print(l, a);
    switch (u)
    {
    case 1:  bubble(l, a);
        break;
    case 2:  inserts(l, a);
        break;
    case 3:  shell(l, a);
        break;
    case 4:  merger(l, 1, a);
        break;
    case 5:  quickly(l, 0, a-1);
        break;
    }
    printf("\nМассив после сортировки: "); print(l, a);
}

void copy(int* a, int ** b, int h)
{
    int i;
    for (i = 0; i < h; i++)
    {
        //printf("FGHJKL %d &d &d \n",);
        *(b+i)=a[i];

    }; }
 

