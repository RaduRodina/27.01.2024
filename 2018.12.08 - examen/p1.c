#include <stdio.h>
#include <string.h>
#include <ctype.h>

int convert(char w[])
{
    int nr = 0;
    for (int i = 0; i < strlen(w); i++)
    {
        if (isdigit(w[i]))
        {
            nr = nr*10 + (w[i] - '0');
        }
    }
    return nr;
}


void citire()
{
    char c;
    int n;
    char w[10];
    int j = 0;
    int st = 0;
    int max = -1;

    FILE *f;
    f = fopen("input.txt", "rt");

    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }

    while(1)
    {
        w[j] = 0;
        printf("stare = %d c = %d w = %s\n", st, c, w);
        if(st == 0)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                c = fgetc(f);
                st = 1;
            }
            else if (c == 10)
            {
                st = 3;
            }
            else
            {
                c = fgetc(f);
                st = 0;
            }
        }
        else if(st == 1)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                c = fgetc(f);
                st = 1;
            }

            else if (c == ' ' || c == 10)
            {
                st = 2;
            }

            else
            {
                st = 4;
            }
        }
        else if (st == 2)
        {
            n = convert(w);
            printf("n = %d\n", n);

            if(n > max)
            {
                max = n;
            }
            w[j] = 0;
            printf("%s\n", w);
            j = 0;
            w[j] = 0;
            st = 0;
        }
            else if (st == 3)
            {
                break;
            }
            else if (st == 4)
            {
                w[0] = 0;
                j = 0;
                st = 0;
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
