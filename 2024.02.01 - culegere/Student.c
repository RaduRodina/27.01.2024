#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct student
{
    char nume[20];
    char prenume[20];
    int medie;
};

void afisare_tablou(int n, struct student studenti[])
{
    printf("Tabloul este: \n");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s, %s, %d\n", studenti[i].nume, studenti[i].prenume, studenti[i].medie);
    }
}

void citire_tablou(int n, struct student studenti[])
{
    printf("Introduceti informatiile despre studenti: \n");
    for(int i = 0; i < n; i++)
    {
        printf("Numarul studentului: %d\n", i);
        printf("\n");

        printf("Introduceti numele studentului: \n");
        scanf("%s", &studenti[i].nume);

        printf("Introduceti prenumele studentului: \n");
        scanf("%s", &studenti[i].prenume);

        printf("Intorduceti media generala: \n");
        scanf("%d", &studenti[i].medie);
        printf("\n");
    }
    afisare_tablou(n, studenti);
}

void sortare_dupa_nume(int n, struct student studenti[])
{
    int s;
    int sw;
    struct student aux;
    do
    {
        sw = 0;
        for (int i = 0; i < n-1; i++)
        {
            s = strcmp(studenti[i].nume, studenti[i+1].nume);
            if(s > 0)
            {
                aux = studenti[i];
                studenti[i] = studenti[i+1];
                studenti[i+1] = aux;
                sw++;
            }
        }
    }
    while(sw!=0);

    printf("Sortarea dupa nume: \n");
    afisare_tablou(n, studenti);
    printf("\n");
}

int main()
{
    int n;
    struct student studenti[30];

    printf("Introduceti numarul de studenti: \n");
    scanf("%d", &n);

    citire_tablou(n, studenti);
    sortare_dupa_nume(n, studenti);

    return 0;
}
