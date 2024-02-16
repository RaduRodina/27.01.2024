#include <stdio.h>
#include <string.h>
#include <ctype.h>

int convert(char w[])
{
    int nr = 0;
    printf("w = %s\n", w);
    for(int j = 0; j < strlen(w); j++)
    {
        if(isdigit(w[j]))
        {
            nr = nr*10 + (w[j] - '0');
        }
    }
    printf("nr = %d\n", nr);
    return nr;
}

void citire()
{
    int max = -1;
    char c;
    char w[10];
    int j = 0;
    int stare = 0;
    int n;

    FILE *f;
    f = fopen("linie.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }

    c = fgetc(f);
    while(1)
    {
        w[j]=0;
        printf("stare = %d c = %d w = %s\n", stare, c, w);

        if(stare == 0)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                stare = 1;
                c = fgetc(f);
            }
            else if (c == 10)
            {
                stare = 3;
            }
            else
            {
                c = fgetc(f);
                stare = 0;
            }
        }
        else if (stare == 1)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                c = fgetc(f);
                stare = 1;
            }
            else if (c == ' ' || c == 10)
            {
                stare = 2;
            }
            else
            {
                stare = 4;
            }
        }
        else if (stare == 2)
        {
            n = convert(w);
            printf("n = %d\n", n);
            if(n>max)
            {
                max = n;
            }

            w[j] = 0;
            printf("%s\n", w);
            j = 0;
            w[0] = 0;
            stare = 0;


        }
        else if (stare == 3)
        {
            break;
        }
        else if(stare == 4)
        {
            printf("Dupa numar nu am primit spatiu sau rand nou\n");
            w[0] = 0;
            j = 0;
            stare = 0;
        }
    }
    fclose(f);

    printf("max = %d\n", max);
}

int main()
{
    citire();
    return 0;
}
