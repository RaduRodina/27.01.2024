
#define N 100

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void afisare(int v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void citire(int a[], int b[], int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("A = ");
    afisare(a, n);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("B[%d]: ", i);
        scanf("%d", &b[i]);
    }
    printf("B = ");
    afisare(b, n);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("C[%d]: ", i);
        scanf("%d", &c[i]);
    }
    printf("C = ");
    afisare(c,n);
    printf("\n");
}
void suma_pt_2(int a[], int b[],int n)
{
    int s[N];
    for (int i = 0; i < n; i++)
    {
        s[i] = a[i] + b[i];
    }
    printf("A + B este: ");
    afisare(s,n);
    printf("\n");
}

void suma_pt_3(int a[], int b[], int c[], int n)
{
    int s[N];
    for (int i = 0; i < n; i++)
    {
        s[i] = a[i] + b[i] + c[i];
    }
    printf("A + B + C este: ");
    afisare(s,n);
    printf("\n");
}

void insumare(int a[], int b[], int n)
{
    int s[N];
    int i;
    for (i = 0; i < n; i++)
    {
        s[i] = a[i] + b[n-i-1];
    }
    printf("Insumarea A cu B este: ");
    afisare(s,n);
    printf("\n");
}

void sortare_cresc(int a[], int n)
{
    int aux;
    int sw;
    do
    {
        sw=0;
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] > a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                sw++;
            }
        }
    }
    while(sw!=0);

    printf("Ordinea crescatoare a lui A: ");
    afisare(a, n);
    printf("\n");
}

void sortare_descresc(int a[], int n)
{
    int aux;
    int sw;
    do
    {
        sw=0;
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] < a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                sw++;
            }
        }
    }
    while(sw!=0);

    printf("Ordinea descrescatoare a lui A: ");
    afisare(a, n);
    printf("\n");
}

int main()
{
    int n=3;
    int a[N];
    int b[N];
    int c[N];

    citire(a, b, c, n);
    suma_pt_2(a, b, n);
    suma_pt_3(a, b, c, n);
    insumare(a, b, n);
    sortare_cresc(a, n);
    sortare_descresc(a, n);

    return 0;
}
