#include <stdio.h>
#include <ctype.h>
#include <string.h>

void afisare(int c[], char t[][100], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s %d\n", t[i], c[i]);
    }
}

void sortare(int c[], char t[][100], int n)
{
    int auxC;
    char auxS[100];
    int sch;
    do
    {
        sch = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(c[i] < c[i+1])
            {
                auxC = c[i];
                c[i] = c[i+1];
                c[i+1] = auxC;

                strcpy(auxS, t[i]);
                strcpy(t[i], t[i+1]);
                strcpy(t[i+1], auxS);

                sch++;
            }
        }
    }
    while(sch!=0);

}

void prelucrare(int c[], char t[][100], int *n)
{
    FILE *f;
    char buf[100];
    int i;
    char w[100];
    int j;
    int count;
    int m = 0;

    f = fopen("sample.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare.\n");
    }

    while(!feof(f))
    {
        buf[0] = 0;
        fgets(buf, sizeof(buf), f);
        buf[strlen(buf)-1] = 0;
        strcpy(t[m], buf);
        printf("buf=%s\ns=%d\n", buf, strlen(buf));

        i = 0;
        count = 0;
        while(buf[i] != 0)
        {
            if (buf[i] != ' ' && i < strlen(buf))
            {
                w[j] = buf[i];
                j++;
            }
            else
            {
                w[j] = 0;
                j = 0;
                count++;
            }
            i++;
        }

        printf("%d\n", count);
        c[m] = count;
        m++;
    }

    fclose(f);
    *n = m;
}


int main()
{
    char t[100][100];
    int c[100];
    int n;

    prelucrare(c, t, &n);
    sortare(c, t, n);
    afisare(c, t, n);

    return 0;
}
