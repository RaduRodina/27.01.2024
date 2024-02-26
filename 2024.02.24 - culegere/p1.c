#include <stdio.h>
#include <string.h>
#include <ctype.h>

int convert(char w[])
{
    int nr = 0;
    for(int i = 0; i < strlen(w); i++)
    {
        if(isdigit(w[i]))
        {
            nr = nr*10 + (w[i] - '0');
        }
        else
        {
            printf("Error\n");
        }
    }
    return nr;
}

int sum_buf(int buff[], int k)
{
    int s = 0;
    for(int i = 0; i < k; i++)
    {
        s = s + buff[i];
    }
    return s;
}



void reading()
{
    char c;
    char w[100];
    int j;
    int st = 0;
    int buff[50];
    int k = 0;
    int s = 0;
    int p = 1;


    FILE *f;
    f = fopen("input.txt", "rt");
    if(f == NULL)
    {
        printf("Error at input\n");
        return;
    }

    /*char buf[100];
    fgets(buf, sizeof(buf), f);*/

    c = fgetc(f);
    while(!feof(f))
    {
        w[j]=0;
        printf("st=%d, c=%c w=%s\n", st, c, w);
        if(st == 0)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 1;
                c = fgetc(f);
            }
            else if(c == '(')
            {
                st = 3;
                c = fgetc(f);
            }
            else if(c == '[')
            {
                st = 7;
                c = fgetc(f);
            }
            else if(c == 10)
            {
                st = 11;
            }
            else
            {
                st = 0;
                c = fgetc(f);
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
            else
            {
                st = 2;
            }
        }
        else if(st == 2)
        {
            w[j] = 0;
            j = 0;
            int x = convert(w);
            printf("Am gasit un numar: %d\n", x);
            buff[k] = x;
            k++;
            st = 0;
            c = fgetc(f);
        }
        else if(st == 3)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 4;
                c = fgetc(f);
            }
            else if(c == ')')
            {
                st = 6;
            }
            else
            {
                st = 3;
                c = fgetc(f);
            }
        }
        else if(st == 4)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 4;
                c = fgetc(f);
            }
            else
            {
                st = 5;
            }
        }
        else if(st == 5)
        {
            w[j] = 0;
            j = 0;
            int y = convert(w);
            printf("Am gasit un termen dintr-o suma: %d\n", y);
            s = s + y;
            printf("Suma: %d\n", s);
            if(c == ')')
            {
                st = 6;
            }
            else
            {
                st = 3;
            }
            c = fgetc(f);
        }
        else if(st == 6)
        {
            printf("Am incheiat de parcurs o paranteza\n");
            buff[k] = s;
            k++;
            st = 0;
            c = fgetc(f);
        }
        else if(st == 7)
        {
            if (isdigit(c))
            {
                w[j] = c;
                j++;
                st = 8;
                c = fgetc(f);
            }
            else if(c == ']')
            {
                st = 10;
            }
            else
            {
                st = 7;
                c = fgetc(f);
            }
        }
        else if(st == 8)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 8;
                c = fgetc(f);
            }
            else
            {
                st = 9;
            }
        }
        else if (st == 9)
        {
            w[j] = 0;
            j = 0;
            int q = convert(w);
            printf("Am gasit un factor: %d\n", q);
            p = p*q;
            printf("Produs: %d\n", p);
            if(c == ']')
            {
                st = 10;
            }
            else
            {
                st = 7;
            }
        }
        else if(st == 10)
        {
            printf("Am incheiat de parcurs o paranteza\n");
            buff[k] = p;
            k++;
            st = 0;
            c = fgetc(f);
        }
        else if(st == 11)
        {
            printf("buff = ");
            for(int v = 0; v < k; v++)
            {
                printf(" %d ", buff[v]);
            }
            printf("\n");

            int sb = sum_buf(buff, k);
            printf("Suma de pe aceasta linie este: %d\n", sb);

            for (int v = 0; v < k; v++)
            {
                buff[v] = 0;
            }
            st = 0;
            s = 0;
            p = 1;
            c = fgetc(f);
        }
    }
    fclose(f);
}


int main()
{
    reading();
    return 0;
}
